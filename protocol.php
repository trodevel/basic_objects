<?php

namespace basic_objects;


// includes
require_once __DIR__.'/../basic_parser/object.php';

// includes for used modules

// Object
class TimePoint24
{
    public $hh                  ; // type: uint8_t // valid range: [0, 23]
    public $mm                  ; // type: uint8_t // valid range: [0, 59]
};

// Object
class TimeWindow
{
    public $from                ; // type: TimePoint24
    public $to                  ; // type: TimePoint24
};

// Object
class LocalTime
{
    public $year                ; // type: uint32_t // valid range: [1800, 3000]
    public $month               ; // type: uint8_t // valid range: [1, 12]
    public $day                 ; // type: uint8_t // valid range: [1, 31]
    public $hh                  ; // type: uint8_t // valid range: [0, 23]
    public $mm                  ; // type: uint8_t // valid range: [0, 59]
    public $ss                  ; // type: uint8_t // valid range: [0, 59]
};

// Object
class Weekdays
{
    // enum weekdays_e
    const MO = 1;
    const TU = 2;
    const WE = 4;
    const TH = 8;
    const FR = 16;
    const SA = 32;
    const SU = 64;

    public $mask                ; // type: uint32_t
};

// Object
class TimeRange
{
    public $from                ; // type: uint32_t
    public $to                  ; // type: uint32_t
};

// Object
class LocalTimeRange
{
    public $from                ; // type: LocalTime
    public $to                  ; // type: LocalTime
};

// Object
class Date
{
    public $year                ; // type: uint32_t // valid range: [1800, 3000]
    public $month               ; // type: uint8_t // valid range: [1, 12]
    public $day                 ; // type: uint8_t // valid range: [1, 31]
};

// Object
class Email
{
    public $email               ; // type: string
};

# namespace_end basic_objects


?>

