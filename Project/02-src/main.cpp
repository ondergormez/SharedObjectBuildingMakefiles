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
#include "Array.hpp"
#include "Sorting.hpp"
#include "Utility.hpp"

using namespace std;

int main(void)
{
    cout << "This is a test project" << endl;
    //Array *arrayOperations = new Array();
    //Sorting *sortingOperations = new Sorting();
    //Utility *utilityOperations = new Utility();   

    Array::DisplayLibraryVersion();
    Sorting::DisplayLibraryVersion();
    Utility::DisplayLibraryVersion();

    vector<uint32_t> testArray = vector<uint32_t>(7);
    Array::FillRandomValue(testArray);
    Utility::DisplayVector(testArray);
    Sorting::SortArray(testArray);
    Utility::DisplayVector(testArray);

    return 0;
}