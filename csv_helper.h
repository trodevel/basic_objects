/*

CSV helper.

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

#include "basic_objects.h"          // ClosedJobStatus, ...
#include <sstream>                  // std::ostream

namespace basic_objects
{

class CsvHelper
{
public:
    static std::ostream & write( std::ostream & os, const Date & r );
    static std::ostream & write( std::ostream & os, const TimePoint24 & r );
    static std::ostream & write( std::ostream & os, const TimeWindow & r );
    static std::ostream & write( std::ostream & os, const LocalTime & r );
    static std::ostream & write( std::ostream & os, const LocalTimeRange & r );
    static std::ostream & write( std::ostream & os, const Weekdays & r );
    static std::ostream & write( std::ostream & os, const Email & r );
};

} // namespace basic_objects

#endif // LIB_BASIC_OBJECTS__CSV_HELPER_H
