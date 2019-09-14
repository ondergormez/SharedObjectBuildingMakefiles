#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#include <cmath>                        /* NOTE: M_PI */
#include <fstream>                      /* NOTE: ofstream */
#include <iostream>                     /* NOTE: std::cout, std::fixed */
#include <iomanip>                      /* NOTE: std::setprecision */

using namespace std;

double (*Sine)(double);
double (*SquareRoot)(double);
void SineWaveGenerator();

int
main(int argc, char **argv)
{
    void *handle;
    char *error;

   handle = dlopen("libm.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

   dlerror();    /* Clear any existing error */

   /* Writing: Sine = (double (*)(double)) dlsym(handle, "sin");
       would seem more natural, but the C99 standard leaves
       casting from "void *" to a function pointer undefined.
       The assignment used below is the POSIX.1-2003 (Technical
       Corrigendum 1) workaround; see the Rationale for the
       POSIX specification of dlsym(). */

   *(void **) (&Sine) = dlsym(handle, "sin");

   if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }

   *(void **) (&SquareRoot) = dlsym(handle, "sqrt");

   if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }

    SineWaveGenerator();

    dlclose(handle);
    exit(EXIT_SUCCESS);
}

void SineWaveGenerator()
{
    int frequency = 50;
    int RMSVoltageAmplitude = 220;
    double peakAmplitude = RMSVoltageAmplitude * SquareRoot(2);

    //
    //  Create the data file.
    //
    string dataFileName = "sine_wave_timeline_data.txt";
    ofstream data;

    data.open(dataFileName.c_str());

    for (int millisecond = 0; millisecond <= 120; ++millisecond)
    {
        data << fixed << setw(12) << setprecision(3) << 0.001 * millisecond
                      << setw(20) << setprecision(7) << peakAmplitude * (*Sine)(2 * M_PI * frequency * 0.001 * millisecond) << endl;

        cout << fixed << setw(12) << setprecision(3) << 0.001 * millisecond
                      << setw(20) << setprecision(7) << peakAmplitude * (*Sine)(2 * M_PI * frequency * 0.001 * millisecond) << endl;
    }

    data.close ( );

    cout << " " << endl;
    cout << "  Data stored in \"" << dataFileName << "\"." << endl;

    //
    //  Create the command file.
    //
    string commandFileName = "sine_wave_timeline_commands.txt";
    string createdImageFileName = "sine_wave_timeline.png";
    ofstream command;
    

    command.open ( commandFileName.c_str ( ) );

    command << "# " << commandFileName << endl;
    command << "#" << endl;
    command << "# Usage:" << endl;
    command << "#  gnuplot < " << commandFileName << endl;
    command << "#" << endl;
    command << "set term png" << endl;
    command << "set output '" << createdImageFileName << "'" << endl;
    command << "set style data lines" << endl;
    command << "set xlabel 'Time'" << endl;
    command << "set ylabel ' Domestic Mains Supply Voltage (" << RMSVoltageAmplitude << " VAC rms)'" << endl;
    command << "set title 'Time-dependent Change of Mains Supply Voltage'" << endl;
    command << "set grid" << endl;
    command << "plot '" << dataFileName << "' using 1:2 title \"f(t)=" << setprecision(7) << peakAmplitude <<"sin(wt)\" lw 2" << endl;
    command << "quit";

    command.close ( );

    cout << "  Plot commands stored in \"" << commandFileName << "\"." << endl;
}
