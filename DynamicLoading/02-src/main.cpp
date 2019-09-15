#include <dlfcn.h>                                                              /* NOTE: Dynamic Loading functions */
#include <cmath>                                                                /* NOTE: M_PI */
#include <fstream>                                                              /* NOTE: ofstream */
#include <iostream>                                                             /* NOTE: std::cout, std::fixed */
#include <iomanip>                                                              /* NOTE: std::setprecision */

//#define NDEBUG

using namespace std;

double (*FPSine)(double);
double (*FPSquareRoot)(double);
void SineWaveGenerator();

int main(int argc, char **argv)
{
    void *handle;
    char *error;

    dlerror();                                                                  /* NOTE: Clear any existing error */

    handle = dlopen("libm.so", RTLD_LAZY);
    if (!handle) {
        cerr << dlerror() << endl;
        exit(EXIT_FAILURE);
    }

    dlerror();                                                                  /* NOTE: Clear any existing error */

    FPSine = (double (*)(double)) dlsym(handle, "sin");
    if ((error = dlerror()) != NULL)  {
        cerr << error << endl;
        exit(EXIT_FAILURE);
    }

    FPSquareRoot = (double (*)(double)) dlsym(handle, "sqrt");
    if ((error = dlerror()) != NULL)  {
        cerr << error << endl;
        exit(EXIT_FAILURE);
    }

    SineWaveGenerator();

    int errorCode = 0;
    if ((errorCode = dlclose(handle)) != 0)  {
        cerr << "Failed to close \"handle\"!" << endl;
        cerr << "Error Code: " << errorCode << endl;
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}

void SineWaveGenerator()
{
    int frequency = 50;
    int RMSVoltageAmplitude = 220;
    double peakAmplitude = RMSVoltageAmplitude * FPSquareRoot(2);

    //
    //  Create the data file.
    //
    string dataFileName = "sine_wave_timeline_data.txt";
    ofstream data;

    data.open(dataFileName.c_str());
    for (int millisecond = 0; millisecond <= 120; ++millisecond)
    {
        data << fixed << setw(15) << setprecision(3) << 0.001 * millisecond
                      << setw(22) << setprecision(7) << peakAmplitude * FPSine(2 * M_PI * frequency * 0.001 * millisecond) << endl;
#ifndef NDEBUG
        cout << fixed << setw(15) << setprecision(3) << 0.001 * millisecond
                      << setw(22) << setprecision(7) << peakAmplitude * FPSine(2 * M_PI * frequency * 0.001 * millisecond) << endl;
#endif
    }
    data.close();

#ifndef NDEBUG
    cout << " " << endl;
    cout << "  Data stored in \"" << dataFileName << "\"." << endl;
#endif

    //
    //  Create the GNU Plot command file.
    //
    string commandFileName = "sine_wave_timeline_commands.txt";
    string createdImageFileName = "sine_wave_timeline.png";
    ofstream command;    

    command.open(commandFileName.c_str());
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
    command.close();

#ifndef NDEBUG
    cout << "  Plot commands stored in \"" << commandFileName << "\"." << endl;
#endif
}
