<?php

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

// $Revision: 9134 $ $Date:: 2018-05-09 #$ $Author: serge $

namespace basic_objects;

require_once __DIR__.'/../basic_parser/parser.php';    // basic_parser\parse_int()
require_once 'basic_objects.php';

function parse_TimePoint24( & $csv_arr, $offset )
{
    $res = new TimePoint24;

    $v = intval( $csv_arr[ $offset + 0 ] );

    //echo "parse_TimePoint24: v = $v, offset = $offset\n<br>\n"; // DEBUG

    $res->hh = intval( $v / 100 );
    $res->mm = intval( $v % 100 );

    return $res;
}

function parse_TimeWindow( & $csv_arr, $offset )
{
    $res = new TimeWindow;

    $res->from = parse_TimePoint24( $csv_arr, $offset + 0 );
    $res->to   = parse_TimePoint24( $csv_arr, $offset + 1 );

    return $res;
}

function parse_Weekdays( & $csv_arr, $offset )
{
    $res = new Weekdays;

    $res->mask = intval( $csv_arr[ $offset + 0 ] );

    return $res;
}

function parse_LocalTime( & $csv_arr, & $offset )
{
    $v = intval( $csv_arr[ $offset + 0 ] );

    // 201805041739
    // 10000000000 + r.m * 100000000 + r.d * 1000000 + r.hh * 10000 + r.mm * 100 + r.ss;

    $year   = $v / 10000000000;  $v %= 10000000000;
    $month  = $v / 100000000;    $v %= 100000000;
    $day    = $v / 1000000;      $v %= 1000000;
    $hh     = $v / 10000;        $v %= 10000;
    $mm     = $v / 100;          $v %= 100;
    $ss     = $v;

    $offset++;

    $res = new LocalTime( $year, $month, $day, $hh, $mm, $ss );

    return $res;
}

function parse_LocalTimeRange( & $csv_arr, & $offset )
{
    $res = new LocalTimeRange;

    $res->from = parse_LocalTime( $csv_arr, $offset );
    $res->to   = parse_LocalTime( $csv_arr, $offset );

    return $res;
}

function parse_Date( & $csv_arr, $offset )
{
    // 19590725

    $v = intval( $csv_arr[ $offset + 0 ] );

    $year  = intval( $v / 10000 );
    $month = intval( ( $v % 10000 ) / 100 );
    $day   = intval( $v % 100 );

    return new Date( $year, $month, $day );
}

?>
