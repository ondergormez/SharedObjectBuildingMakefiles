/**
 * Copyright (C) 2017 Önder Görmez

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
#include "Matrix.hpp"
#include "Utility.hpp"

using namespace std;
/*
 * Global Defitions
 */

/*
 * Constructor
 */
Matrix::Matrix()
{

}

/*
 * Destructer
 */
Matrix::~Matrix()
{

}

/*
* Create Matrix
*/
vector<vector<uint32_t>> &Matrix::CreateMatrix(uint32_t row, uint32_t col)
{
#ifndef NDEBUG
    DisplayLibraryVersion("Matrix::CreateMatrix");
#endif
    /* initialize random seed: */
    srand (time(NULL));
    vector<vector<uint32_t>> matrix = vector<vector<uint32_t>>(row, vector<uint32_t>(col));
    for (uint32_t i = 0; i < row; ++i) {
        for (uint32_t k = 0; k < col; ++k) {
            matrix[i][k] = rand() % 200 + 1;;
        }
    }
    Utility::DisplayMatrix(matrix);
    return matrix;
};

void Matrix::DisplayLibraryVersion(string functionName)
{
    cout << "**************************************" << endl;
    cout << "Matrix Library v1.5 used" << endl;
    cout << "libMatrix.so.1.5 linked dynamically" << endl;
    cout << functionName << "function called!" << endl;
    cout << "**************************************" << endl;
}