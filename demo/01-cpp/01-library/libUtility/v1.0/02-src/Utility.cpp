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

#include "Utility.hpp"

using namespace std;
/*
 * Global Defitions
 */

/*
 * Constructor
 */
Utility::Utility()
{
    cout << endl;
    std::cout << "**************************************" << std::endl;
    if (!Utility::InstanceCount) {
        std::cout << "Utility Library v1.0 used" << std::endl;
        std::cout << "libUtility.so.1.0 linked dynamically" << std::endl;
    }
    cout << "Utility Library Created Instance Count: " << ++Utility::InstanceCount << endl;
    std::cout << "**************************************" << std::endl;

}

/*
 * Destructer
 */
Utility::~Utility()
{

}

uint32_t Utility::InstanceCount = 0;

vector<double> Utility::linspace(double startNumber, double endNumber, uint32_t nPoints){
#ifndef NDEBUG
    cout << endl;
    cout << "**************************************" << endl;
    std::cout << "Utility::linspace function called!" << std::endl;
#endif
    vector<double> tempLinspace;

    for( uint32_t i = 0 ; i < nPoints ; ++i ){
        tempLinspace.push_back( startNumber + ( ( i * ( endNumber - startNumber ) / (nPoints-1) ) ) );
    }
#ifndef NDEBUG
    std::cout << "Utility::linspace function call ended!" << std::endl;
    cout << "**************************************" << endl;
#endif
    return(tempLinspace);
}

vector<uint32_t> Utility::setdiff(std::vector<uint32_t>a, std::vector<uint32_t>b) {
#ifndef NDEBUG
    cout << endl;
    cout << "**************************************" << endl;
    std::cout << "Utility::setdiff function called!" << std::endl;
#endif
    vector<uint32_t>result;

    int findFlag = 0;

    for (unsigned int i = 0; i < a.size(); ++i) {

        for (unsigned int j = 0; j < b.size(); ++j) {
            if (a[i] == b[j]) {
                ++findFlag;
            }
        }

        if (findFlag == 0) {
            for (unsigned int k = 0; k < result.size(); ++k) {
                if (a[i] == result[k]) {
                    ++findFlag;
                }
            }

            if (findFlag == 0) {
                result.push_back(a[i]);
            }
            else {
                findFlag = 0;
            }

        }
        else {
            findFlag = 0;
        }
    }
#ifndef NDEBUG
    std::cout << "Utility::setdiff function call ended!" << std::endl;
    cout << "**************************************" << endl;
#endif
    return(result);
}

unsigned int Utility::numel(std::vector<double> inputParam) {
#ifndef NDEBUG
    cout << endl;
    cout << "**************************************" << endl;
    std::cout << "Utility::numel function called!" << std::endl;
#endif
#ifndef NDEBUG
    std::cout << "Utility::numel function call ended!" << std::endl;
    cout << "**************************************" << endl;
#endif
    return(inputParam.size());
}

unsigned int Utility::numel(std::vector<std::vector<double>> inputParam) {
#ifndef NDEBUG
    cout << endl;
    cout << "**************************************" << endl;
    std::cout << "Utility::numel function called!" << std::endl;
#endif
#ifndef NDEBUG
    std::cout << "Utility::numel function call ended!" << std::endl;
    cout << "**************************************" << endl;
#endif
    return(inputParam.size()*inputParam[0].size());
}

/*
* Display Vector
*/
void Utility::DisplayVector(std::vector<uint32_t> &vectorToBeDisplayed)
{
#ifndef NDEBUG
    cout << endl;
    cout << "**************************************" << endl;
    std::cout << "Utility::DisplayVector function called!" << std::endl;
#endif
    std::cout << "Size: " << vectorToBeDisplayed.size() << std::endl;
    for (uint32_t i = 0; i < vectorToBeDisplayed.size(); ++i)
        std::cout << std::setprecision(3) << std::left << std::setw(10) << vectorToBeDisplayed[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;
#ifndef NDEBUG
    std::cout << "Utility::DisplayVector function call ended!" << std::endl;
    cout << "**************************************" << endl;
#endif
};

/*
* Display Matrix
*/
void Utility::DisplayMatrix(std::vector<std::vector<uint32_t>> &matrixToBeDisplayed)
{
#ifndef NDEBUG
    cout << endl;
    cout << "**************************************" << endl;
    std::cout << "Utility::DisplayMatrix function called!" << std::endl;
#endif
    std::cout << "A " << matrixToBeDisplayed.size() << " * " <<
        matrixToBeDisplayed[0].size() << " matrix will be displayed:" << std::endl;

    for (uint32_t i = 0; i < matrixToBeDisplayed.size(); ++i) {
        for (uint32_t k = 0; k < matrixToBeDisplayed[i].size(); ++k) {
            std::cout << std::setprecision(3) << std::left << std::setw(10) << matrixToBeDisplayed[i][k];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
#ifndef NDEBUG
    std::cout << "Utility::DisplayMatrix function call ended!" << std::endl;
    cout << "**************************************" << endl;
#endif
};

/*
* Display Library Version
*/
void Utility::DisplayLibraryVersion()
{
    cout << endl;
    std::cout << "**************************************" << std::endl;
    std::cout << "Utility Library v1.0 used" << std::endl;
    std::cout << "libUtility.so.1.0 linked dynamically" << std::endl;
    std::cout << "**************************************" << std::endl;
};