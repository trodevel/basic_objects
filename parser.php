<?php

namespace basic_objects;


// includes
require_once __DIR__.'/../basic_parser/parser.php';

// enums

function parse__weekdays_e( & $csv_arr, & $offset )
{
    $res = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__gender_e( & $csv_arr, & $offset )
{
    $res = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

// objects

function parse__TimePoint24( & $csv_arr, & $offset )
{
    $res = new TimePoint24;

    $res->hh = \basic_parser\parse__int( $csv_arr, $offset );
    $res->mm = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__TimeWindow( & $csv_arr, & $offset )
{
    $res = new TimeWindow;

    $res->from = parse__TimePoint24( $csv_arr, $offset );
    $res->to = parse__TimePoint24( $csv_arr, $offset );

    return $res;
}

function parse__LocalTime( & $csv_arr, & $offset )
{
    $res = new LocalTime;

    $res->year = \basic_parser\parse__int( $csv_arr, $offset );
    $res->month = \basic_parser\parse__int( $csv_arr, $offset );
    $res->day = \basic_parser\parse__int( $csv_arr, $offset );
    $res->hh = \basic_parser\parse__int( $csv_arr, $offset );
    $res->mm = \basic_parser\parse__int( $csv_arr, $offset );
    $res->ss = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__Weekdays( & $csv_arr, & $offset )
{
    $res = new Weekdays;

    $res->mask = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__TimeRange( & $csv_arr, & $offset )
{
    $res = new TimeRange;

    $res->from = \basic_parser\parse__int( $csv_arr, $offset );
    $res->to = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__LocalTimeRange( & $csv_arr, & $offset )
{
    $res = new LocalTimeRange;

    $res->from = parse__LocalTime( $csv_arr, $offset );
    $res->to = parse__LocalTime( $csv_arr, $offset );

    return $res;
}

function parse__Date( & $csv_arr, & $offset )
{
    $res = new Date;

    $res->year = \basic_parser\parse__int( $csv_arr, $offset );
    $res->month = \basic_parser\parse__int( $csv_arr, $offset );
    $res->day = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__Email( & $csv_arr, & $offset )
{
    $res = new Email;

    $res->email = \basic_parser\parse__string( $csv_arr, $offset );

    return $res;
}

// base messages

// messages

// generic

class Parser extends \basic_parser\Parser
{

protected static function parse_csv_array( $csv_arr )
{
    if( sizeof( $csv_arr ) < 1 )
        return NULL;

    $handler_map = array(
        // messages
    );

    $type = $csv_arr[0][0];

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\basic_objects\\' . $handler_map[ $type ];
        return $func( $csv_arr[0] );
    }

    return NULL;
}

}

# namespace_end basic_objects


?>
