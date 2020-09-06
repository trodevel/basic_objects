<?php

namespace basic_objects;


// includes
require_once 'protocol.php';

// objects

function initialize__TimePoint24( & $res
    , $hh // uint8_t
    , $mm // uint8_t
 )
{
    $res->hh = $hh;
    $res->mm = $mm;
}

function initialize__TimeWindow( & $res
    , $from // TimePoint24
    , $to // TimePoint24
 )
{
    $res->from = $from;
    $res->to = $to;
}

function initialize__LocalTime( & $res
    , $year // uint32_t
    , $month // uint8_t
    , $day // uint8_t
    , $hh // uint8_t
    , $mm // uint8_t
    , $ss // uint8_t
 )
{
    $res->year = $year;
    $res->month = $month;
    $res->day = $day;
    $res->hh = $hh;
    $res->mm = $mm;
    $res->ss = $ss;
}

function initialize__Weekdays( & $res
    , $mask // uint32_t
 )
{
    $res->mask = $mask;
}

function initialize__TimeRange( & $res
    , $from // uint32_t
    , $to // uint32_t
 )
{
    $res->from = $from;
    $res->to = $to;
}

function initialize__LocalTimeRange( & $res
    , $from // LocalTime
    , $to // LocalTime
 )
{
    $res->from = $from;
    $res->to = $to;
}

function initialize__Date( & $res
    , $year // uint32_t
    , $month // uint8_t
    , $day // uint8_t
 )
{
    $res->year = $year;
    $res->month = $month;
    $res->day = $day;
}

function initialize__Email( & $res
    , $email // string
 )
{
    $res->email = $email;
}

// base messages

// messages

// objects (constructors)

function create__TimePoint24(
    $hh // uint8_t
    , $mm // uint8_t
 )
{
    $res = new TimePoint24;

    initialize__TimePoint24( $res, $hh, $mm );

    return $res;
}

function create__TimeWindow(
    $from // TimePoint24
    , $to // TimePoint24
 )
{
    $res = new TimeWindow;

    initialize__TimeWindow( $res, $from, $to );

    return $res;
}

function create__LocalTime(
    $year // uint32_t
    , $month // uint8_t
    , $day // uint8_t
    , $hh // uint8_t
    , $mm // uint8_t
    , $ss // uint8_t
 )
{
    $res = new LocalTime;

    initialize__LocalTime( $res, $year, $month, $day, $hh, $mm, $ss );

    return $res;
}

function create__Weekdays(
    $mask // uint32_t
 )
{
    $res = new Weekdays;

    initialize__Weekdays( $res, $mask );

    return $res;
}

function create__TimeRange(
    $from // uint32_t
    , $to // uint32_t
 )
{
    $res = new TimeRange;

    initialize__TimeRange( $res, $from, $to );

    return $res;
}

function create__LocalTimeRange(
    $from // LocalTime
    , $to // LocalTime
 )
{
    $res = new LocalTimeRange;

    initialize__LocalTimeRange( $res, $from, $to );

    return $res;
}

function create__Date(
    $year // uint32_t
    , $month // uint8_t
    , $day // uint8_t
 )
{
    $res = new Date;

    initialize__Date( $res, $year, $month, $day );

    return $res;
}

function create__Email(
    $email // string
 )
{
    $res = new Email;

    initialize__Email( $res, $email );

    return $res;
}

// messages (constructors)

# namespace_end basic_objects


?>
