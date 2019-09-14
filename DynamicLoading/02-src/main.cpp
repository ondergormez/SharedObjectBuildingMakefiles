#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#include <fstream>                      /* NOTE: ofstream */
#include <iostream>                     /* NOTE: std::cout, std::fixed */
#include <iomanip>                      /* NOTE: std::setprecision */

using namespace std;

double (*sine)(double);
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

   /* Writing: sine = (double (*)(double)) dlsym(handle, "sin");
       would seem more natural, but the C99 standard leaves
       casting from "void *" to a function pointer undefined.
       The assignment used below is the POSIX.1-2003 (Technical
       Corrigendum 1) workaround; see the Rationale for the
       POSIX specification of dlsym(). */

   *(void **) (&sine) = dlsym(handle, "sin");

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
    /* TODO: Make frequency generic */
    /* TODO: Delete unused part of this function */
    /* TODO: Review all code */
    /* TODO: Use standart PI notation in C++ */
    /* TODO: Remove underlined name convention */

    //
    //  Create the data file.
    //
    string data_filename = "sine_wave_timeline_data.txt";
    ofstream data;

    data.open ( data_filename.c_str ( ) );

    for (int milliSecond = 0; milliSecond <= 120; ++milliSecond)
    {
        data << fixed << setw(12) << setprecision(3) << 0.001 * milliSecond
                      << setw(20) << setprecision(7) << 220 * (*sine)(2 * 3.14 * 50 * 0.001 * milliSecond) << endl;

        cout << fixed << setw(12) << setprecision(3) << 0.001 * milliSecond
                      << setw(20) << setprecision(7) << 220 * (*sine)(2 * 3.14 * 50 * 0.001 * milliSecond) << endl;
    }

    data.close ( );

    cout << " \n";
    cout << "  Data stored in \"" << data_filename << "\".\n";
    //
    //  Create the command file.
    //
    string command_filename = "sine_wave_timeline_commands.txt";
    string createdImageFileName = "sine_wave_timeline.png";
    ofstream command;
    

    command.open ( command_filename.c_str ( ) );

    command << "# " << command_filename << endl;
    command << "#" << endl;
    command << "# Usage:" << endl;
    command << "#  gnuplot < " << command_filename << endl;
    command << "#" << endl;
    command << "set term png" << endl;
    command << "set output '" << createdImageFileName << "'" << endl;
    command << "set style data lines" << endl;
    command << "set xlabel 'Time'" << endl;
    command << "set ylabel 'AC Voltage (Volt)'" << endl;
    command << "set title 'Time-dependent Change of Mains Voltage'" << endl;
    command << "set grid" << endl;
    command << "plot '" << data_filename << "' using 1:2 title \"f(t)=220sin(wt)\" lw 2" << endl;
    command << "quit";

    command.close ( );

    cout << "  Plot commands stored in \"" << command_filename << "\"." << endl;
}
