<?php

namespace basic_objects;


// includes
require_once __DIR__.'/../basic_parser/dummy_creator.php';
require_once 'object_initializer.php';

// enums

function create_dummy__weekdays_e()
{
    $SIZE = 7;

    $values = array( weekdays_e__MO, weekdays_e__TU, weekdays_e__WE, weekdays_e__TH, weekdays_e__FR, weekdays_e__SA, weekdays_e__SU,  );

    $res = $values[ \basic_parser\create_dummy__int32() % $SIZE ];

    return $res;
}

function create_dummy__gender_e()
{
    $SIZE = 4;

    $values = array( gender_e__UNDEF, gender_e__MALE, gender_e__FEMALE, gender_e__OTHER,  );

    $res = $values[ \basic_parser\create_dummy__int32() % $SIZE ];

    return $res;
}

// objects

function create_dummy__TimePoint24()
{
    $res = new TimePoint24;

    $res->hh = \basic_parser\create_dummy__int8() % 24;
    $res->mm = \basic_parser\create_dummy__int8() % 60;

    return $res;
}

function create_dummy__TimeWindow()
{
    $res = new TimeWindow;

    initialize__TimeWindow( $res
        , create_dummy__TimePoint24()
        , create_dummy__TimePoint24()
        );
    return $res;
}

function create_dummy__LocalTime()
{
    $res = new LocalTime;

    $res->year   = \basic_parser\create_dummy__int32() % 24 + 2010;
    $res->month  = \basic_parser\create_dummy__int8() % 12 + 1;
    $res->day    = \basic_parser\create_dummy__int8() % 30 + 1;
    $res->hh = \basic_parser\create_dummy__int8() % 24;
    $res->mm = \basic_parser\create_dummy__int8() % 60;
    $res->ss = \basic_parser\create_dummy__int8() % 60;

    return $res;
}

function create_dummy__Weekdays()
{
    $res = new Weekdays;

    $res->mask   =
            Weekdays::MO * \basic_parser\create_dummy__bool() +
            Weekdays::TU * \basic_parser\create_dummy__bool() +
            Weekdays::WE * \basic_parser\create_dummy__bool() +
            Weekdays::TH * \basic_parser\create_dummy__bool() +
            Weekdays::FR * \basic_parser\create_dummy__bool() +
            Weekdays::SA * \basic_parser\create_dummy__bool() +
            Weekdays::SU * \basic_parser\create_dummy__bool();

    return $res;
}

function create_dummy__TimeRange()
{
    $res = new TimeRange;

    $res->from = \basic_parser\create_dummy__int32() + 1500000000;
    $res->to = \basic_parser\create_dummy__int32() + 1500000000;

    return $res;
}

function create_dummy__LocalTimeRange()
{
    $res = new LocalTimeRange;

    initialize__LocalTimeRange( $res
        , create_dummy__LocalTime()
        , create_dummy__LocalTime()
        );
    return $res;
}

function create_dummy__Date()
{
    $res = new Date;

    $res->year   = \basic_parser\create_dummy__int32() % 24 + 2010;
    $res->month  = \basic_parser\create_dummy__int8() % 12 + 1;
    $res->day    = \basic_parser\create_dummy__int8() % 30 + 1;

    return $res;
}

function create_dummy__Email()
{
    $res = new Email;

    $res->email = \basic_parser\create_dummy__string() . "@" . \basic_parser\create_dummy__string() . ".com";

    return $res;
}

// messages

# namespace_end basic_objects


?>
