/*

Parser.

Copyright (C) 2020 Sergey Kolevatov

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

// $Revision: 12745 $ $Date:: 2020-02-15 #$ $Author: serge $

#include "exported_parser.h"    // self

#include "parser.h"

namespace basic_parser
{

void get_value_or_throw( basic_objects::TimeRange * res, const std::string & key, const generic_request::Request & r )
{
    basic_objects::Parser::to_TimeRange( res, key, r );
}

void get_value_or_throw( basic_objects::LocalTimeRange * res, const std::string & key, const generic_request::Request & r )
{
    basic_objects::Parser::to_LocalTimeRange( res, key, r );
}

void get_value_or_throw( basic_objects::LocalTime * res, const std::string & key, const generic_request::Request & r )
{
    basic_objects::Parser::to_LocalTime( res, key, r );
}

void get_value_or_throw( basic_objects::TimePoint24 * res, const std::string & key, const generic_request::Request & r )
{
    basic_objects::Parser::to_TimePoint24( res, key, r );
}

void get_value_or_throw( basic_objects::TimeWindow * res, const std::string & key, const generic_request::Request & r )
{
    basic_objects::Parser::to_TimeWindow( res, key, r );
}

void get_value_or_throw( basic_objects::Weekdays & res, const std::string & key, const generic_request::Request & r )
{
    basic_objects::Parser::to_Weekdays( res, key, r );
}

void get_value_or_throw( basic_objects::Date * res, const std::string & key, const generic_request::Request & r )
{
    basic_objects::Parser::to_Date( res, key, r );
}

void get_value_or_throw( basic_objects::Email * res, const std::string & key, const generic_request::Request & r )
{
    basic_objects::Parser::to_Email( res, key, r );
}

} // namespace basic_objects