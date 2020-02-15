/*

Persek Protocol messages.

Copyright (C) 2015 Sergey Kolevatov

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

// $Revision: 12692 $ $Date:: 2020-02-03 #$ $Author: serge $

#ifndef LIB_BASIC_OBJECTS__BASIC_OBJECTS_H
#define LIB_BASIC_OBJECTS__BASIC_OBJECTS_H

#include <cstdint>             // uint32_t
#include <string>               // std::string

namespace basic_objects
{

struct TimePoint24
{
    uint8_t             hh;
    uint8_t             mm;
};

struct TimeWindow
{
    TimePoint24         from;
    TimePoint24         to;
};

struct LocalTime
{
    uint32_t            year;
    uint8_t             month;
    uint8_t             day;

    uint8_t             hh;
    uint8_t             mm;
    uint8_t             ss;
};

struct Weekdays
{
    enum weekdays_e
    {
        MO = 1,
        TU = 2,
        WE = 4,
        TH = 8,
        FR = 16,
        SA = 32,
        SU = 64
    };

    uint32_t            mask;
};

struct TimeRange
{
    TimeRange():
        from( 0 ), to( 0 )
    {
    }

    uint32_t        from;   // epoch (seconds)
    uint32_t        to;     // epoch (seconds)
};

struct LocalTimeRange
{
    LocalTimeRange()
    {
    }

    LocalTime       from;
    LocalTime       to;
};

struct Date
{
    uint32_t        year;
    uint8_t         month;
    uint8_t         day;
};

struct Email
{
    std::string     email;
};

} // namespace basic_objects

#endif // LIB_BASIC_OBJECTS__BASIC_OBJECTS_H
