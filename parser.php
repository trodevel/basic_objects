<?php

namespace basic_objects;


// includes
require_once __DIR__.'/../basic_parser/parser.php';

// objects

function parse_TimePoint24( & $csv_arr, & $offset )
{
    $res = new TimePoint24;

    $res->hh = \basic_parser\parse_int( $csv_arr, $offset );
    $res->mm = \basic_parser\parse_int( $csv_arr, $offset );

    return $res;
}

function parse_TimeWindow( & $csv_arr, & $offset )
{
    $res = new TimeWindow;

    $res->from = parse_TimePoint24( $csv_arr, $offset );
    $res->to = parse_TimePoint24( $csv_arr, $offset );

    return $res;
}

function parse_LocalTime( & $csv_arr, & $offset )
{
    $res = new LocalTime;

    $res->year = \basic_parser\parse_int( $csv_arr, $offset );
    $res->month = \basic_parser\parse_int( $csv_arr, $offset );
    $res->day = \basic_parser\parse_int( $csv_arr, $offset );
    $res->hh = \basic_parser\parse_int( $csv_arr, $offset );
    $res->mm = \basic_parser\parse_int( $csv_arr, $offset );
    $res->ss = \basic_parser\parse_int( $csv_arr, $offset );

    return $res;
}

function parse_Weekdays( & $csv_arr, & $offset )
{
    $res = new Weekdays;

    $res->mask = \basic_parser\parse_int( $csv_arr, $offset );

    return $res;
}

function parse_TimeRange( & $csv_arr, & $offset )
{
    $res = new TimeRange;

    $res->from = \basic_parser\parse_int( $csv_arr, $offset );
    $res->to = \basic_parser\parse_int( $csv_arr, $offset );

    return $res;
}

function parse_LocalTimeRange( & $csv_arr, & $offset )
{
    $res = new LocalTimeRange;

    $res->from = parse_LocalTime( $csv_arr, $offset );
    $res->to = parse_LocalTime( $csv_arr, $offset );

    return $res;
}

function parse_Date( & $csv_arr, & $offset )
{
    $res = new Date;

    $res->year = \basic_parser\parse_int( $csv_arr, $offset );
    $res->month = \basic_parser\parse_int( $csv_arr, $offset );
    $res->day = \basic_parser\parse_int( $csv_arr, $offset );

    return $res;
}

function parse_Email( & $csv_arr, & $offset )
{
    $res = new Email;

    $res->email = \basic_parser\parse_string( $csv_arr, $offset );

    return $res;
}

// base messages

// messages

// generic

class Parser
{

protected static function parse_csv_array( $csv_arr )
{
    if( sizeof( $csv_arr ) < 1 )
        return self::create_parse_error();

    $handler_map = array(
        // messages
    );

    $type = $csv_arr[0][0];

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\basic_objects\\' . $handler_map[ $type ];
        return $func( $obj );
    }

    return NULL;
}

}

# namespace_end basic_objects


?>
