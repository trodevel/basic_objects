// includes
#include "dummy_creator.h"
#include "basic_parser/dummy_creator.h"
#include "object_initializer.h"

namespace basic_objects
{

namespace dummy
{

using ::basic_parser::dummy::create__uint8;
using ::basic_parser::dummy::create__uint32;
using ::basic_parser::dummy::create__bool;
using ::basic_parser::dummy::create__string;


// enums

weekdays_e create__weekdays_e()
{
    static const unsigned SIZE = 7;

    static const weekdays_e values[SIZE] = { weekdays_e::MO, weekdays_e::TU, weekdays_e::WE, weekdays_e::TH, weekdays_e::FR, weekdays_e::SA, weekdays_e::SU,  };

    auto res = values[ ::basic_parser::dummy::create__uint32() % SIZE ];

    return res;
}

gender_e create__gender_e()
{
    static const unsigned SIZE = 4;

    static const gender_e values[SIZE] = { gender_e::UNDEF, gender_e::MALE, gender_e::FEMALE, gender_e::OTHER,  };

    auto res = values[ ::basic_parser::dummy::create__uint32() % SIZE ];

    return res;
}

// objects

TimePoint24 create__TimePoint24()
{
    TimePoint24 res;

    res.hh = create__uint8() % 24;
    res.mm = create__uint8() % 60;

    return res;
}

TimeWindow create__TimeWindow()
{
    TimeWindow res;

    ::basic_objects::initialize( & res
        , dummy::create__TimePoint24()
        , dummy::create__TimePoint24()
        );

    return res;
}

LocalTime create__LocalTime()
{
    LocalTime res;

    res.year   = create__uint8() % 24 + 2010;
    res.month  = create__uint8() % 12 + 1;
    res.day    = create__uint8() % 30 + 1;
    res.hh = create__uint8() % 24;
    res.mm = create__uint8() % 60;
    res.ss = create__uint8() % 60;

    return res;
}

Weekdays create__Weekdays()
{
    Weekdays res;

    res.mask   =
            Weekdays::weekdays_e::MO * create__bool() +
            Weekdays::weekdays_e::TU * create__bool() +
            Weekdays::weekdays_e::WE * create__bool() +
            Weekdays::weekdays_e::TH * create__bool() +
            Weekdays::weekdays_e::FR * create__bool() +
            Weekdays::weekdays_e::SA * create__bool() +
            Weekdays::weekdays_e::SU * create__bool();

    return res;
}

TimeRange create__TimeRange()
{
    TimeRange res;

    res.from = create__uint32() + 1500000000;
    res.to = create__uint32() + 1500000000;

    return res;
}

LocalTimeRange create__LocalTimeRange()
{
    LocalTimeRange res;

    ::basic_objects::initialize( & res
        , dummy::create__LocalTime()
        , dummy::create__LocalTime()
        );

    return res;
}

Date create__Date()
{
    Date res;

    res.year   = create__uint8() % 24 + 2010;
    res.month  = create__uint8() % 12 + 1;
    res.day    = create__uint8() % 30 + 1;

    return res;
}

Email create__Email()
{
    Email res;

    res.email = create__string() + "@" + create__string() + ".com";

    return res;
}

// messages

} // namespace dummy

} // namespace basic_objects

