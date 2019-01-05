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
#include "Array.hpp"
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

}

/*
 * Destructer
 */
Array::~Array()
{

}

/*
* Create Array
*/
vector<uint32_t> &Array::CreateArray(uint32_t size)
{
#ifndef NDEBUG
    DisplayLibraryVersion("Array::CreateArray");
#endif
    /* initialize random seed: */
    srand(time(NULL));
    vector<uint32_t> array = vector<uint32_t>(size);
    for (uint32_t i = 0; i < size; ++i) {
        array[i] = rand() % 200 + 1;;
    }
    Utility::DisplayVector(array);
    return array;
};

void Array::DisplayLibraryVersion(string functionName)
{
    cout << "**************************************" << endl;
    cout << "Random Array Library v1.0 used" << endl;
    cout << "libRandomArray.so.1.0 linked dynamically" << endl;
    cout << functionName << "function called!" << endl;
    cout << "**************************************" << endl;
}