<?php

namespace basic_objects;


// includes
require_once __DIR__.'/../basic_parser/html_helper.php';
require_once 'str_helper.php';

// enums

// objects

function to_html__TimePoint24( & $r )
{
    $header = array( 'HH', 'MM' );

    $data = array(
        \basic_parser\to_html__int( $r->hh ),
        \basic_parser\to_html__int( $r->mm )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__TimeWindow( & $r )
{
    $header = array( 'FROM', 'TO' );

    $data = array(
        to_html__TimePoint24( $r->from ),
        to_html__TimePoint24( $r->to )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__LocalTime( & $r )
{
    $header = array( 'YEAR', 'MONTH', 'DAY', 'HH', 'MM', 'SS' );

    $data = array(
        \basic_parser\to_html__int( $r->year ),
        \basic_parser\to_html__int( $r->month ),
        \basic_parser\to_html__int( $r->day ),
        \basic_parser\to_html__int( $r->hh ),
        \basic_parser\to_html__int( $r->mm ),
        \basic_parser\to_html__int( $r->ss )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__Weekdays( & $r )
{
    $header = array( 'MASK' );

    $data = array(
        \basic_parser\to_html__int( $r->mask )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__TimeRange( & $r )
{
    $header = array( 'FROM', 'TO' );

    $data = array(
        \basic_parser\to_html__int( $r->from ),
        \basic_parser\to_html__int( $r->to )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__LocalTimeRange( & $r )
{
    $header = array( 'FROM', 'TO' );

    $data = array(
        to_html__LocalTime( $r->from ),
        to_html__LocalTime( $r->to )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__Date( & $r )
{
    $header = array( 'YEAR', 'MONTH', 'DAY' );

    $data = array(
        \basic_parser\to_html__int( $r->year ),
        \basic_parser\to_html__int( $r->month ),
        \basic_parser\to_html__int( $r->day )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__Email( & $r )
{
    $header = array( 'EMAIL' );

    $data = array(
        \basic_parser\to_html__string( $r->email )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

// base messages

// messages

// generic

function to_html( $obj )
{
    $handler_map = array(
        // objects
        'basic_objects\TimePoint24'         => 'to_html__TimePoint24',
        'basic_objects\TimeWindow'         => 'to_html__TimeWindow',
        'basic_objects\LocalTime'         => 'to_html__LocalTime',
        'basic_objects\Weekdays'         => 'to_html__Weekdays',
        'basic_objects\TimeRange'         => 'to_html__TimeRange',
        'basic_objects\LocalTimeRange'         => 'to_html__LocalTimeRange',
        'basic_objects\Date'         => 'to_html__Date',
        'basic_objects\Email'         => 'to_html__Email',
        // messages
    );

    $type = get_class( $obj );

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\basic_objects\\' . $handler_map[ $type ];
        return $func( $obj );
    }

    return NULL;
}

# namespace_end basic_objects


?>
