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

// $Revision: 9895 $ $Date:: 2018-10-19 #$ $Author: serge $

#ifndef LIB_BASIC_OBJECTS__CSV_HELPER_H
#define LIB_BASIC_OBJECTS__CSV_HELPER_H

#include <sstream>              // std::ostream

#include "basic_objects.h"      // LocalTime

namespace basic_objects
{

class StrHelper
{
public:

    static std::ostream & write( std::ostream & os, const TimePoint24 & l );
    static std::ostream & write( std::ostream & os, const TimeWindow & l );
    static std::ostream & write( std::ostream & os, const LocalTime & l );
    static std::ostream & write( std::ostream & os, const Weekdays & l );
    static std::ostream & write( std::ostream & os, const Email & l );

    template<class T>
    static std::string to_string( const T & l )
    {
        std::ostringstream os;

        write( os, l );

        return os.str();
    }

    static std::string to_string_YYYYMMDD( const Date & l );
    static std::string to_string_HHMM( const TimePoint24 & l );
};

inline std::ostream& operator<<( std::ostream& os, const TimePoint24 & l )
{
    return StrHelper::write( os, l );
}

inline std::ostream& operator<<( std::ostream& os, const TimeWindow & l )
{
    return StrHelper::write( os, l );
}

inline std::ostream& operator<<( std::ostream& os, const LocalTime & l )
{
    return StrHelper::write( os, l );
}

inline std::ostream& operator<<( std::ostream& os, const Weekdays & l )
{
    return StrHelper::write( os, l );
}

inline std::ostream& operator<<( std::ostream& os, const Email & l )
{
    return StrHelper::write( os, l );
}

} // namespace basic_objects

#endif // LIB_BASIC_OBJECTS__CSV_HELPER_H
