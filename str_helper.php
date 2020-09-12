<?php

namespace basic_objects;


// includes
require_once __DIR__.'/../basic_parser/str_helper.php';

// enums

function to_string__weekdays_e( $r )
{
    $map = array
    (
        weekdays_e__MO => 'MO',
        weekdays_e__TU => 'TU',
        weekdays_e__WE => 'WE',
        weekdays_e__TH => 'TH',
        weekdays_e__FR => 'FR',
        weekdays_e__SA => 'SA',
        weekdays_e__SU => 'SU',
    );

    if( array_key_exists( $r, $map ) )
    {
        return $map[ $r ];
    }

    return '?';
}

function to_string__gender_e( $r )
{
    $map = array
    (
        gender_e__UNDEF => 'UNDEF',
        gender_e__MALE => 'MALE',
        gender_e__FEMALE => 'FEMALE',
        gender_e__OTHER => 'OTHER',
    );

    if( array_key_exists( $r, $map ) )
    {
        return $map[ $r ];
    }

    return '?';
}

// objects

function to_string__TimePoint24( & $obj )
{
    return sprintf( "%02d:%02d", $obj->hh, $obj->mm );
}

function to_string__TimeWindow( & $obj )
{
    return to_string__TimePoint24( $obj->from ) . "-" . to_string__TimePoint24( $obj->to );
}

function to_string__LocalTime( & $obj )
{
    return sprintf( "%04d-%02d-%02d %02d:%02d:%02d", $obj->year, $obj->month, $obj->day, $obj->hh, $obj->mm, $obj->ss );
}

function to_string__Weekdays( & $r )
{
    $res = "(";

    $res .= " mask=" . \basic_parser\to_string__int( $r->mask );

    $res .= ")";

    return $res;
}

function to_string__TimeRange( $obj )
{
    return "from=" . $obj->from . " to=" . $obj->to;
}

function to_string__LocalTimeRange( $obj )
{
    return to_string__LocalTime( $obj->from ) . " - " . to_string__LocalTime( $obj->to );
}

function to_string__Date( & $obj )
{
    return sprintf( "%04d-%02d-%02d", $obj->year, $obj->month, $obj->day );
}

function to_string__Email( & $obj )
{
    return $obj->email;
}

// base messages

// messages

// generic

function to_string( $obj )
{
    $handler_map = array(
        // objects
        'basic_objects\TimePoint24'         => 'to_string__TimePoint24',
        'basic_objects\TimeWindow'         => 'to_string__TimeWindow',
        'basic_objects\LocalTime'         => 'to_string__LocalTime',
        'basic_objects\Weekdays'         => 'to_string__Weekdays',
        'basic_objects\TimeRange'         => 'to_string__TimeRange',
        'basic_objects\LocalTimeRange'         => 'to_string__LocalTimeRange',
        'basic_objects\Date'         => 'to_string__Date',
        'basic_objects\Email'         => 'to_string__Email',
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
