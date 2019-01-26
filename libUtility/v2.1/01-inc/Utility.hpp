/**
 * Copyright (C) 2015 Önder Görmez

 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation, either version 3 of the License, or (at your 
 * option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY 
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along with this program. If not, see 
 * http://www.gnu.org/licenses/.

 * For any questions, please contact me @ ondergormez@gmail.com.
 */

#ifndef __UTILITY__HPP__
#define __UTILITY__HPP__

#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdint>

/*
* Note:
* In general, avoid putting using directives in header files (*.h)
* because any file that includes that header will bring everything
* in the namespace into scope, which can cause name hiding and name
* collision problems that are very difficult to debug.
*/

/**
 * <p>
 *
 * This class implements the utility methods.
 *
 * </p>
 *
 * @author Önder Görmez
 * @version 1.0
 * @since October 11, 2017
 *
 */
class Utility
{
private:

public:
    Utility();
    ~Utility();
    static std::vector<double> linspace(double startNumber, double endNumber, uint32_t nPoints);
    static std::vector<uint32_t> setdiff(std::vector<uint32_t>a, std::vector<uint32_t>b);
    static unsigned int numel(std::vector<double> inputParam);
    static unsigned int numel(std::vector<std::vector<double>> inputParam);
    static void DisplayVector(std::vector<uint32_t> &vectorToBeDisplayed);
    static void DisplayMatrix(std::vector<std::vector<uint32_t>> &matrixToBeDisplayed);
    static void DisplayLibraryVersion(std::string functionName);
};

#endif /* __UTILITY__HPP__ */
