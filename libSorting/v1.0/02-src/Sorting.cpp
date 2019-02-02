/**
 * Copyright (C) 2019 Önder Görmez

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
#include "Sorting.hpp"

using namespace std;
/*
 * Global Defitions
 */

/*
 * Constructor
 */
Sorting::Sorting()
{
    cout << endl;
    cout << "**************************************" << endl;
    if (!Sorting::InstanceCount) {
        cout << "Sorting Library v1.0 used" << endl;
        cout << "libSorting.so.1.0 linked dynamically" << endl;
    }
    cout << "Sorting Library Created Instance Count: " << ++Sorting::InstanceCount << endl;
    cout << "**************************************" << endl;
}

/*
 * Destructer
 */
Sorting::~Sorting()
{

}

uint32_t Sorting::InstanceCount = 0;

/*
* Fill Random Value
*/
vector<uint32_t> &Sorting::SortArray(vector<uint32_t> &array)
{
#ifndef NDEBUG
    cout << endl;
    cout << "**************************************" << endl;
    std::cout << "Sorting::SortArray function called!" << std::endl;
#endif

    uint32_t minIndex;
    for (uint32_t i = 0; i < array.size() - 1; ++i) {
        minIndex = i;
        for (uint32_t j = i + 1; j < array.size(); ++j) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
            SwapOneElement(array, minIndex, i);
        }
    }

#ifndef NDEBUG
    std::cout << "Sorting::SortArray function call ended!" << std::endl;
    cout << "**************************************" << endl;
#endif
    return array;
};

/*
* Swap One Element
*/
void Sorting::SwapOneElement(vector<uint32_t> &array, uint32_t idx1, uint32_t idx2)
{
    uint32_t temp = array[idx1];
    array[idx1] = array[idx2];
    array[idx2] = temp;
}

void Sorting::DisplayLibraryVersion()
{
    cout << endl;
    cout << "**************************************" << endl;
    cout << "Sorting Library v1.0 used" << endl;
    cout << "libSorting.so.1.0 linked dynamically" << endl;
    cout << "**************************************" << endl;
}