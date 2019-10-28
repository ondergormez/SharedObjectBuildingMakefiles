#include <iostream>                                                             /* NOTE: std::cout */
#include "CalculateArea.h"

using namespace std;

int main(int argc, char **argv)
{
    unsigned int length = 5;
    unsigned int width = 10;

    cout << "Rectangle Length: " << length << endl;
    cout << "Rectangle Width: " << width << endl;

    cout << "Area of Rectangle: " << CalculateRectangleArea(length, width) << endl << endl;

    exit(EXIT_SUCCESS);
}