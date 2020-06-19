<?php

namespace basic_objects;


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

// messages (constructors)

# namespace_end basic_objects


?>
