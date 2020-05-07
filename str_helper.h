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

// $Revision: 12975 $ $Date:: 2020-05-07 #$ $Author: serge $

#ifndef LIB_BASIC_OBJECTS__STR_HELPER_H
#define LIB_BASIC_OBJECTS__STR_HELPER_H

#include <sstream>              // std::ostream

#include "protocol.h"      // LocalTime

namespace basic_objects
{

namespace str_helper
{

std::ostream & write( std::ostream & os, const TimePoint24 & l );
std::ostream & write( std::ostream & os, const TimeWindow & l );
std::ostream & write( std::ostream & os, const LocalTime & l );
std::ostream & write( std::ostream & os, const LocalTimeRange & r );
std::ostream & write( std::ostream & os, const Weekdays & l );
std::ostream & write( std::ostream & os, const Date & l );
std::ostream & write( std::ostream & os, const Email & l );

template<class T>
std::string to_string( const T & l )
{
    std::ostringstream os;

    write( os, l );

    return os.str();
}

std::string to_string_YYYYMMDD( const Date & l );
std::string to_string_HHMM( const TimePoint24 & l );

} // namespace str_helper

inline std::ostream& operator<<( std::ostream& os, const TimePoint24 & l )
{
    return str_helper::write( os, l );
}

inline std::ostream& operator<<( std::ostream& os, const TimeWindow & l )
{
    return str_helper::write( os, l );
}

inline std::ostream& operator<<( std::ostream& os, const LocalTime & l )
{
    return str_helper::write( os, l );
}

inline std::ostream& operator<<( std::ostream& os, const Weekdays & l )
{
    return str_helper::write( os, l );
}

inline std::ostream& operator<<( std::ostream& os, const Email & l )
{
    return str_helper::write( os, l );
}

} // namespace basic_objects

#endif // LIB_BASIC_OBJECTS__STR_HELPER_H

