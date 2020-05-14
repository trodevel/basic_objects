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

// $Revision: 13059 $ $Date:: 2020-05-15 #$ $Author: serge $


#include "validator.h"          // self

#include "utils/regex_match.h"  // utils::regex_match()

#include "parser.h"             // MalformedRequest
#include "converter.h"          // to_val

namespace basic_objects
{

namespace validator
{

bool validate( const std::string & prefix, const Weekdays & r )
{
    if( r.mask <= 0 || r.mask > 127 )
        throw parser::MalformedRequest( prefix + " is invalid" );

    return true;
}

bool validate( const std::string & prefix, const TimeRange & r )
{
    if( ( r.from > 0  ) && ( r.to > 0 ) && ( r.from > r.to ) )
        return false;

    return true;
}

bool validate( const std::string & prefix, const LocalTimeRange & r )
{
    auto from   = to_val( r.from );
    auto to     = to_val( r.to );

    if( from > 0 )
        validate( prefix, r.from );

    if( to > 0 )
        validate( prefix, r.to );

    if( ( from > 0 ) && ( to > 0 ) && ( from > to ) )
        return false;

    return true;
}

bool validate( const std::string & prefix, const Date & r )
{
    if( r.year == 0 && r.month == 0 && r.day == 0 )
        return true;

    if( ( r.year < 1900 || r.year > 2100 ) && r.year != 0 )
        throw parser::MalformedRequest( prefix + ": year not in [1900, 2100]" );

    if( r.month < 1 || r.month > 12 )
        throw parser::MalformedRequest( prefix + ": month not in [1, 12]" );

    if( r.day < 1 || r.day > 31 )
        throw parser::MalformedRequest( prefix + ": day not in [1, 31]" );

    return true;
}

bool validate( const std::string & prefix, const TimePoint24 & r )
{
    if( r.hh > 23 )
        throw parser::MalformedRequest( prefix + ".HH > 23" );

    if( r.mm > 59 )
        throw parser::MalformedRequest( prefix + ".MM > 59" );

    return true;
}

bool validate( const std::string & prefix, const TimeWindow & r )
{
    validate( prefix, r.from );
    validate( prefix, r.to );

    return true;
}

bool validate( const std::string & prefix, const LocalTime & r )
{
    if( r.year == 0 )
        throw parser::MalformedRequest( prefix + ": year is 0" );

    if( r.month == 0 )
        throw parser::MalformedRequest( prefix + ": month is 0" );

    if( r.day == 0 )
        throw parser::MalformedRequest( prefix + ": day is 0" );

    if( r.year > 9999 )
        throw parser::MalformedRequest( prefix + ": year > 9999" );

    if( r.month > 12 )
        throw parser::MalformedRequest( prefix + ": month > 12" );

    if( r.day > 31 )
        throw parser::MalformedRequest( prefix + ": day > 31" );

    if( r.hh > 23 )
        throw parser::MalformedRequest( prefix + ": hh > 23" );

    if( r.mm > 59 )
        throw parser::MalformedRequest( prefix + ": mm > 59" );

    if( r.ss > 59 )
        throw parser::MalformedRequest( prefix + ": ss > 59" );

    return true;
}

bool validate( const std::string & prefix, const Email & r )
{
    if( utils::regex_match( r.email, "^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\\.[a-zA-Z0-9.\\-]+$" ) == false )
        throw parser::MalformedRequest( prefix + ": malformed email" );

    return true;
}

} // namespace validator

} // namespace basic_parser
