#include <iostream>                                                             /* NOTE: std::cout */

using namespace std;
unsigned int CalculateRectangleArea(unsigned int length, unsigned int width);

int main(int argc, char **argv)
{
	unsigned int length = 5;
	unsigned int width = 10;

    cout << "Rectangle Length: " << length << endl;
    cout << "Rectangle Width: " << width << endl;
    cout << "Area of Rectangle: " << CalculateRectangleArea(length, width) << endl;

    exit(EXIT_SUCCESS);
}