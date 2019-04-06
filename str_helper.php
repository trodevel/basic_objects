<?php

/*

String Helper.

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

// $Revision: 9895 $ $Date:: 2018-10-19 #$ $Author: serge $

namespace basic_objects;

require_once 'basic_objects.php';
require_once __DIR__.'/../php_snippets/html_elems.php';      // get_html_table_row_header

function to_string_TimePoint24( & $obj )
{
    return sprintf( "%02d:%02d", $obj->hh, $obj->mm );
}

function to_string_LocalTime( & $obj )
{
    return sprintf( "%04d-%02d-%02d %02d:%02d:%02d", $obj->year, $obj->month, $obj->day, $obj->hh, $obj->mm, $obj->ss );
}

function get_header_Weekdays()
{
    return get_html_table_header_elems( array( 'WEEKDAYS_MASK' ) );
}

function to_html_Weekdays( & $obj )
{
    return get_html_table_data_elems( array(
            $obj->mask
    ) );
}

function to_string_Date( & $obj )
{
    return sprintf( "%04d-%02d-%02d", $obj->year, $obj->month, $obj->day );
}

function to_string_Email( & $obj )
{
    return $obj->email;
}

?>
