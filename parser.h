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

// $Revision: 13058 $ $Date:: 2020-05-15 #$ $Author: serge $

#include <stdexcept>            // std::runtime_error

#include "generic_request/request.h"                // generic_request::Request
#include "basic_parser/malformed_request.h"         // MalformedRequest

#include "protocol.h"              // Date

namespace basic_objects
{

namespace parser
{

typedef basic_parser::MalformedRequest  MalformedRequest;

void get_value_or_throw( TimeRange * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( LocalTimeRange * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( LocalTime * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( TimePoint24 * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( TimeWindow * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( Weekdays * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( Date * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( Email * res, const std::string & key, const generic_request::Request & r );

} // namespace parser

} // namespace basic_objects
