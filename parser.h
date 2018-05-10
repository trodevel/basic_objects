/*

Parser.

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

// $Revision: 9131 $ $Date:: 2018-05-09 #$ $Author: serge $

#include <stdexcept>            // std::runtime_error

#include "generic_request/request.h"                // generic_request::Request
#include "basic_parser/malformed_request.h"         // MalformedRequest

#include "basic_objects.h"              // Date

namespace basic_objects
{

class Parser
{
public:
    typedef basic_parser::MalformedRequest  MalformedRequest;

public:
    static void                         to_TimeRange( TimeRange * res, const std::string & prefix, const generic_request::Request & r );
    static void                         to_LocalTimeRange( LocalTimeRange * res, const std::string & prefix, const generic_request::Request & r );
    static LocalTime *                  to_LocalTime( LocalTime * res, const std::string & prefix, const generic_request::Request & r );
    static TimePoint24 *                to_TimePoint24( TimePoint24 * res, const std::string & prefix, const generic_request::Request & r );
    static TimeWindow *                 to_TimeWindow( TimeWindow * res, const std::string & prefix, const generic_request::Request & r );
    static void                         to_Weekdays( Weekdays & res, const generic_request::Request & r );
    static Date *                       to_Date( Date * res, const std::string & key, const generic_request::Request & r );
};

} // namespace basic_objects

