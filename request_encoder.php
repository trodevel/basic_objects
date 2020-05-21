<?php

/*

Request Encoder.

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

// $Revision: 13104 $ $Date:: 2020-05-21 #$ $Author: serge $

namespace basic_objects;

require_once 'protocol.php';

function to_generic_request__TimePoint24( $name, $obj )
{
    $res = \basic_parser\to_generic_request__int( $name,  $obj->hh * 100 + $obj->mm );

    return $res;
}

function to_generic_request__TimeWindow( $name, $obj )
{
    $res = to_generic_request__TimePoint24( $name + ".FROM", $obj->from );
    $res = "&" . to_generic_request__TimePoint24( $name + ".TO", $obj->to );

    return $res;
}

function to_generic_request__LocalTime( $name, $obj )
{
    $res = \basic_parser\to_generic_request__int( $name,  $obj->year * 10000000000 + $obj->month * 100000000 + $obj->day * 1000000
            + $obj->hh * 10000 + $obj->mm * 100 + $obj->ss );

    return $res;
}

function to_generic_request__Weekdays( $name, $obj )
{
    $res = \basic_parser\to_generic_request__int( $name + ".MASK", $obj->mask );

    return $res;
}

function to_generic_request__TimeRange( $name, $obj )
{
    $res = \basic_parser\to_generic_request__int( $name + ".FROM", $obj->from );
    $res = "&" . \basic_parser\to_generic_request__int( $name + ".TO", $obj->to );

    return $res;
}

function to_generic_request__LocalTimeRange( $name, $obj )
{
    $res = to_generic_request__LocalTime( $name + ".FROM", $obj->from );
    $res = "&" . to_generic_request__LocalTime( $name + ".TO", $obj->to );

    return $res;
}

function to_generic_request__Date( $name, $obj )
{
    $res = \basic_parser\to_generic_request__int( $name, $obj->year * 10000 + $obj->month * 100 + $obj->day );

    return $res;
}

function to_generic_request__Email( $name, $obj )
{
    $res = \basic_parser\to_generic_request__string( $name + ".MASK", $obj->email );

    return $res;
}

?>
