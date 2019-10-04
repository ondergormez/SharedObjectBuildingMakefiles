#include <iostream>                                                             /* NOTE: std::cout */
#include "my_strcmp.h"
#include "my_strlen.h"

using namespace std;

int main(int argc, char **argv)
{
    string left = " ";
    string rigth = "";

    if (!my_strcmp(left.c_str(), rigth.c_str())) {
        cout << "Left and right strings are the same!" << endl;
    }
    else {
        cout << "Different string input!" << endl;
    }

    cout << "Character length of the left: " << my_strlen(left.c_str()) << endl << endl;

    exit(EXIT_SUCCESS);
}