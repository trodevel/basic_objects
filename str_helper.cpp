/*

String Helper. Provides to_string() function.

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

// $Revision: 9063 $ $Date:: 2018-05-04 #$ $Author: serge $

#include "str_helper.h"             // self

#include <iomanip>                  // std::setfill

namespace basic_objects
{

std::ostream & StrHelper::write( std::ostream & os, const TimePoint24 & l )
{
    os << std::setfill( '0' );

    os << std::setw( 2 ) << (unsigned)l.hh << ":" << std::setw( 2 ) << (unsigned)l.mm;

    return os;
}

std::ostream & StrHelper::write( std::ostream & os, const TimeWindow & l )
{
    os << l.from << "-" << l.to;

    return os;
}

std::ostream & StrHelper::write( std::ostream & os, const LocalTime & l )
{
    os << l.year << "-"
            << std::setfill( '0' ) << std::setw( 2 ) << (unsigned)l.month << "-"
            << std::setfill( '0' ) << std::setw( 2 ) << (unsigned)l.day << " "
            << std::setfill( '0' ) << std::setw( 2 ) << (unsigned)l.hh << ":"
            << std::setfill( '0' ) << std::setw( 2 ) << (unsigned)l.mm << ":"
            << std::setfill( '0' ) << std::setw( 2 ) << (unsigned)l.ss;

    return os;
}

std::ostream & StrHelper::write( std::ostream & os, const Weekdays & l )
{
    static const char *days[] =
    {
            "Mo", "Tu", "We", "Th", "Fr", "Sa", "So"
    };

    for( unsigned i = 0; i < 7; ++i )
    {
        auto e = 1 << i;

        if( l.mask & e )
        {
            os << days[i];
        }
        else
        {
            os << "__";
        }
    }

    return os;
}

} // namespace basic_objects
