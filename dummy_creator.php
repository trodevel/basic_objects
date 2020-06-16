<?php

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

// $Revision: 13280 $ $Date:: 2020-06-16 #$ $Author: serge $

namespace basic_objects;

require_once 'protocol.php';

require_once __DIR__.'/../basic_parser/dummy_creator.php';     // \basic_parser\create_dummy__uint8

function create_dummy__TimePoint24()
{
    $res = new TimePoint24;

    $res->hh = \basic_parser\create_dummy__uint8() % 24;
    $res->mm = \basic_parser\create_dummy__uint8() % 60;

    return $res;
}

function create_dummy__TimeWindow()
{
    $res = new TimeWindow;

    $res->from = create_dummy__TimePoint24();
    $res->to = create_dummy__TimePoint24();

    return $res;
}

function create_dummy__LocalTime()
{
    $res = new LocalTime;

    $res->year   = \basic_parser\create_dummy__uint8() % 24 + 2010;
    $res->month  = \basic_parser\create_dummy__uint8() % 12 + 1;
    $res->day    = \basic_parser\create_dummy__uint8() % 30 + 1;
    $res->hh = \basic_parser\create_dummy__uint8() % 24;
    $res->mm = \basic_parser\create_dummy__uint8() % 60;
    $res->ss = \basic_parser\create_dummy__uint8() % 60;

    return $res;
}

function create_dummy__Weekdays()
{
    $res = new Weekdays;

    $res->mask   =
            Weekdays::MO * \basic_parser\create_dummy__bool() +
            Weekdays::TU * \basic_parser\create_dummy__bool() +
            Weekdays::WE * \basic_parser\create_dummy__bool() +
            Weekdays::TH * \basic_parser\create_dummy__bool() +
            Weekdays::FR * \basic_parser\create_dummy__bool() +
            Weekdays::SA * \basic_parser\create_dummy__bool() +
            Weekdays::SU * \basic_parser\create_dummy__bool();

    return $res;
}

function create_dummy__TimeRange()
{
    $res = new TimeRange;

    $res->from = \basic_parser\create_dummy__uint32() + 1500000000;
    $res->to = \basic_parser\create_dummy__uint32() + 1500000000;

    return $res;
}

function create_dummy__LocalTimeRange()
{
    $res = new LocalTimeRange;

    $res->from = \basic_parser\create_dummy__LocalTime();
    $res->to = \basic_parser\create_dummy__LocalTime();

    return $res;
}

function create_dummy__Date()
{
    $res = new Date;

    $res->year   = \basic_parser\create_dummy__uint8() % 24 + 2010;
    $res->month  = \basic_parser\create_dummy__uint8() % 12 + 1;
    $res->day    = \basic_parser\create_dummy__uint8() % 30 + 1;

    return $res;
}

function create_dummy__Email()
{
    $res = new Email;

    $res->email = \basic_parser\create_dummy__string() + "@" + \basic_parser\create_dummy__string() + ".com";

    return $res;
}

?>
