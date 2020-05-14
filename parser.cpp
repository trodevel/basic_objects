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

#include "parser.h"             // self

#include "basic_parser/parser.h"     // basic_parser::get_value_or_throw

namespace basic_objects
{

namespace parser
{

using basic_parser::parser::get_value_or_throw;
using basic_parser::parser::get_value_or_throw_t;

void get_value_or_throw( TimePoint24 * res, const std::string & prefix, const generic_request::Request & r )
{
    uint32_t v = 0;

    r.get_value_converted( prefix, v );

    res->hh = v / 100;
    res->mm = v % 100;
}

void get_value_or_throw( TimeWindow * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->from, prefix + ".FROM", r );
    get_value_or_throw( & res->to, prefix + ".TO", r );
}

void get_value_or_throw( LocalTime * res, const std::string & prefix, const generic_request::Request & r )
{
    uint64_t v = 0;

    r.get_value_converted( prefix, v );

    // 10000000000 + r.m * 100000000 + r.d * 1000000 + r.hh * 10000 + r.mm * 100 + r.ss;

    res->year   = v / 10000000000;  v %= 10000000000;
    res->month  = v / 100000000;    v %= 100000000;
    res->day    = v / 1000000;      v %= 1000000;
    res->hh = v / 10000;        v %= 10000;
    res->mm = v / 100;          v %= 100;
    res->ss = v;
}

void get_value_or_throw( Weekdays * res, const std::string & prefix, const generic_request::Request & r )
{
    res->mask   =
            Weekdays::weekdays_e::MO +
            Weekdays::weekdays_e::TU +
            Weekdays::weekdays_e::WE +
            Weekdays::weekdays_e::TH +
            Weekdays::weekdays_e::FR +
            Weekdays::weekdays_e::SA +
            Weekdays::weekdays_e::SU;

    r.get_value_converted( prefix + ".MASK", res->mask );
}

void get_value_or_throw( TimeRange * res, const std::string & prefix, const generic_request::Request & r )
{
    r.get_value_converted( prefix + ".FROM",    res->from );
    r.get_value_converted( prefix + ".TO",      res->to );
}

void get_value_or_throw( LocalTimeRange * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->from,  prefix + ".FROM",    r );
    get_value_or_throw( & res->to,    prefix + ".TO",      r );
}

void get_value_or_throw( Date * res, const std::string & key, const generic_request::Request & r )
{
    res->year   = 0;
    res->month  = 0;
    res->day    = 0;

    uint32_t birthday;

    if( r.get_value_converted( key, birthday ) )
    {
        res->year   = birthday / 10000;
        res->month  = ( birthday / 100 ) % 100;
        res->day    = birthday % 100;
    }
}

void get_value_or_throw( Email * res, const std::string & key, const generic_request::Request & r )
{
    res->email.clear();

    r.get_value( key, res->email );
}

} // namespace parser

} // namespace basic_objects
