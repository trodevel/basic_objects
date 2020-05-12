/*

Validator.

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

// $Revision: 13028 $ $Date:: 2020-05-13 #$ $Author: serge $


#include "validator.h"          // self

#include "utils/regex_match.h"  // utils::regex_match()

#include "parser.h"             // MalformedRequest
#include "converter.h"          // to_val

namespace basic_objects
{

namespace validator
{

bool validate( const Weekdays & r )
{
    if( r.mask <= 0 || r.mask > 127 )
        throw Parser::MalformedRequest( "WEEKDAYS_MASK is invalid" );

    return true;
}

bool validate( const TimeRange & r )
{
    if( ( r.from > 0  ) && ( r.to > 0 ) && ( r.from > r.to ) )
        return false;

    return true;
}

bool validate( const LocalTimeRange & r )
{
    auto from   = to_val( r.from );
    auto to     = to_val( r.to );

    if( from > 0 )
        validate( r.from );

    if( to > 0 )
        validate( r.to );

    if( ( from > 0 ) && ( to > 0 ) && ( from > to ) )
        return false;

    return true;
}

bool validate( const Date & r )
{
    if( r.year == 0 && r.month == 0 && r.day == 0 )
        return true;

    if( ( r.year < 1900 || r.year > 2100 ) && r.year != 0 )
        throw Parser::MalformedRequest( "year not in [1900, 2100]" );

    if( r.month < 1 || r.month > 12 )
        throw Parser::MalformedRequest( "month not in [1, 12]" );

    if( r.day < 1 || r.day > 31 )
        throw Parser::MalformedRequest( "day not in [1, 31]" );

    return true;
}

bool validate( const TimePoint24 & r )
{
    if( r.hh > 23 )
        throw Parser::MalformedRequest( "TimePoint24: HH > 23" );

    if( r.mm > 59 )
        throw Parser::MalformedRequest( "TimePoint24: MM > 59" );

    return true;
}

bool validate( const TimeWindow & r )
{
    validate( r.from );
    validate( r.to );

    return true;
}

bool validate( const LocalTime & r )
{
    if( r.year == 0 )
        throw Parser::MalformedRequest( "LocalTime: year is 0" );

    if( r.month == 0 )
        throw Parser::MalformedRequest( "LocalTime: month is 0" );

    if( r.day == 0 )
        throw Parser::MalformedRequest( "LocalTime: day is 0" );

    if( r.year > 9999 )
        throw Parser::MalformedRequest( "LocalTime: year > 9999" );

    if( r.month > 12 )
        throw Parser::MalformedRequest( "LocalTime: month > 12" );

    if( r.day > 31 )
        throw Parser::MalformedRequest( "LocalTime: day > 31" );

    if( r.hh > 23 )
        throw Parser::MalformedRequest( "LocalTime: hh > 23" );

    if( r.mm > 59 )
        throw Parser::MalformedRequest( "LocalTime: mm > 59" );

    if( r.ss > 59 )
        throw Parser::MalformedRequest( "LocalTime: ss > 59" );

    return true;
}

bool validate( const Email & r )
{
    if( utils::regex_match( r.email, "^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\\.[a-zA-Z0-9.\\-]+$" ) == false )
        throw Parser::MalformedRequest( "malformed email" );

    return true;
}

} // namespace validator

} // namespace basic_parser
