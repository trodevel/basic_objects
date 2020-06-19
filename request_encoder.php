<?php

namespace basic_objects;


// includes
require_once __DIR__.'/../basic_parser/request_encoder.php';

// objects

function to_generic_request__TimePoint24( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".HH", $r->hh );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".MM", $r->mm );

    return $res;
}

function to_generic_request__TimeWindow( $prefix, & $r )
{
    $res = "";
    $res .= "&" . to_generic_request__TimePoint24( $prefix . ".FROM", $r->from );
    $res .= "&" . to_generic_request__TimePoint24( $prefix . ".TO", $r->to );

    return $res;
}

function to_generic_request__LocalTime( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".YEAR", $r->year );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".MONTH", $r->month );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".DAY", $r->day );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".HH", $r->hh );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".MM", $r->mm );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".SS", $r->ss );

    return $res;
}

function to_generic_request__Weekdays( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".MASK", $r->mask );

    return $res;
}

function to_generic_request__TimeRange( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".FROM", $r->from );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".TO", $r->to );

    return $res;
}

function to_generic_request__LocalTimeRange( $prefix, & $r )
{
    $res = "";
    $res .= "&" . to_generic_request__LocalTime( $prefix . ".FROM", $r->from );
    $res .= "&" . to_generic_request__LocalTime( $prefix . ".TO", $r->to );

    return $res;
}

function to_generic_request__Date( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".YEAR", $r->year );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".MONTH", $r->month );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".DAY", $r->day );

    return $res;
}

function to_generic_request__Email( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".EMAIL", $r->email );

    return $res;
}

// base messages

// messages

// generic

function to_generic_request( $obj )
{
    $handler_map = array(
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
