/*

Dummy Creator.

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

// $Revision: 13268 $ $Date:: 2020-06-15 #$ $Author: serge $

#include "dummy_creator.h"             // self

#include "basic_parser/dummy_creator.h"     // basic_parser::dummy::create__uint8

namespace basic_objects
{

namespace dummy
{

using ::basic_parser::dummy::create__uint8;
using ::basic_parser::dummy::create__uint32;
using ::basic_parser::dummy::create__bool;

TimePoint24 create__TimePoint24()
{
    TimePoint24 res;

    res.hh = ::basic_parser::dummy::create__uint8() % 24;
    res.mm = ::basic_parser::dummy::create__uint8() % 60;

    return res;
}

TimeWindow create__TimeWindow()
{
    TimeWindow res;

    res.from = create__TimePoint24();
    res.to = create__TimePoint24();

    return res;
}

LocalTime create__LocalTime()
{
    LocalTime res;

    res.year   = ::basic_parser::dummy::create__uint8() % 24 + 2010;
    res.month  = ::basic_parser::dummy::create__uint8() % 12;
    res.day    = ::basic_parser::dummy::create__uint8() % 30;
    res.hh = ::basic_parser::dummy::create__uint8() % 24;
    res.mm = ::basic_parser::dummy::create__uint8() % 60;
    res.ss = ::basic_parser::dummy::create__uint8() % 60;

    return res;
}

Weekdays create__Weekdays()
{
    Weekdays res;

    res.mask   =
            Weekdays::weekdays_e::MO * ::basic_parser::dummy::create__bool()+
            Weekdays::weekdays_e::TU * ::basic_parser::dummy::create__bool() +
            Weekdays::weekdays_e::WE * ::basic_parser::dummy::create__bool() +
            Weekdays::weekdays_e::TH * ::basic_parser::dummy::create__bool() +
            Weekdays::weekdays_e::FR * ::basic_parser::dummy::create__bool() +
            Weekdays::weekdays_e::SA * ::basic_parser::dummy::create__bool() +
            Weekdays::weekdays_e::SU * ::basic_parser::dummy::create__bool();

    return res;
}

TimeRange create__TimeRange()
{
    TimeRange res;

    res.from = ::basic_parser::dummy::create__uint32() + 1500000000;
    res.to = ::basic_parser::dummy::create__uint32() + 1500000000;

    return res;
}

LocalTimeRange create__LocalTimeRange()
{
    LocalTimeRange res;

    res.from = create__LocalTime();
    res.to = create__LocalTime();

    return res;
}

Date create__Date()
{
    Date res;

    res.year   = ::basic_parser::dummy::create__uint8() % 24 + 2010;
    res.month  = ::basic_parser::dummy::create__uint8() % 12;
    res.day    = ::basic_parser::dummy::create__uint8() % 30;

    return res;
}

Email create__Email()
{
    Email res;

    res.email = ::basic_parser::dummy::create__string() +
        "@" +
        ::basic_parser::dummy::create__string() + 
        ".com";

    return res;
}

} // namespace dummy

} // namespace basic_objects
