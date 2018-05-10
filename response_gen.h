/*

Response generator.

Copyright (C) 2018 Sergey Kolevatov

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

*/

// $Revision: 9142 $ $Date:: 2018-05-09 #$ $Author: serge $

#ifndef LIB_BASIC_OBJECTS__RESPONSE_GEN_H
#define LIB_BASIC_OBJECTS__RESPONSE_GEN_H

#include "basic_objects.h"        // Date

namespace basic_objects
{

inline LocalTime * init_LocalTime(
        LocalTime       * res,
        uint32_t        year,
        uint8_t         month,
        uint8_t         day,
        uint32_t        hh,
        uint8_t         mm,
        uint8_t         ss )
{
    res->year       = year;
    res->month      = month;
    res->day        = day;
    res->hh         = hh;
    res->mm         = mm;
    res->ss         = ss;

    return res;
}

inline Date * init_Date(
        Date            * res,
        uint32_t        year,
        uint8_t         month,
        uint8_t         day )
{
    res->year       = year;
    res->month      = month;
    res->day        = day;

    return res;
}

} // namespace basic_objects

#endif // LIB_BASIC_OBJECTS__RESPONSE_GEN_H
