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

#ifndef __ARRAY__HPP__
#define __ARRAY__HPP__

#include <vector>
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
 * This class implements the generating random array methods.
 *
 * </p>
 *
 * @author Önder Görmez
 * @version 1.0
 * @since December 01, 2018
 *
 */
class Array
{
private:
    static uint32_t InstanceCount;

public:
    Array();
    ~Array();
    static std::vector<uint32_t> &FillRandomValue(std::vector<uint32_t> &array);
    static void DisplayLibraryVersion();
};

#endif /* __ARRAY__HPP__ */
