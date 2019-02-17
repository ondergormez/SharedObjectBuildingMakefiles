/**
 * Copyright (C) 2018 Önder Görmez

 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation, either version 3 of the License, or (at your 
 * option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY 
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along with this program. If not, see 
 * http://www.gnu.org/licenses/.

 * For any questions, please contact me @ ondergormez@gmail.com.
 */

#include <iostream>
#include <cstdlib>    /* srand, rand */
#include <ctime>      /* time */
#include "RandomArray.hpp"
#include "Utility.hpp"

using namespace std;
/*
 * Global Defitions
 */

/*
 * Constructor
 */
Array::Array()
{
    cout << endl;
    cout << "**************************************" << endl;
    if (!Array::InstanceCount) {
        cout << "Random Array Library v1.0 used" << endl;
        cout << "libRandomArray.so.1.0 linked dynamically" << endl;
    }
    cout << "Random Array Library Created Instance Count: " << ++Array::InstanceCount << endl;
    cout << "**************************************" << endl;
}

/*
 * Destructer
 */
Array::~Array()
{

}

uint32_t Array::InstanceCount = 0;

/*
* Fill Random Value
*/
vector<uint32_t> &Array::FillRandomValue(vector<uint32_t> &array)
{
#ifndef NDEBUG
    cout << endl;
    cout << "**************************************" << endl;
    std::cout << "Array::FillRandomValue function called!" << std::endl;
#endif
    /* initialize random seed */
    srand(time(NULL));
    for (uint32_t i = 0; i < array.size(); ++i) {
        array[i] = rand() % 200 + 1;
    }
    //Utility::DisplayVector(array);
#ifndef NDEBUG
    std::cout << "Array::FillRandomValue function call ended!" << std::endl;
    cout << "**************************************" << endl;
#endif
    return array;
};

void Array::DisplayLibraryVersion()
{
    cout << endl;
    cout << "**************************************" << endl;
    cout << "Random Array Library v1.0 used" << endl;
    cout << "libRandomArray.so.1.0 linked dynamically" << endl;
    cout << "**************************************" << endl;
}