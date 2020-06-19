// includes
#include "object_initializer.h"

namespace basic_objects
{

// objects

void initialize( TimePoint24 * res
    , uint8_t hh
    , uint8_t mm
 )
{
    res->hh = hh;
    res->mm = mm;
}

void initialize( TimeWindow * res
    , const TimePoint24 &  from
    , const TimePoint24 &  to
 )
{
    res->from = from;
    res->to = to;
}

void initialize( LocalTime * res
    , uint32_t year
    , uint8_t month
    , uint8_t day
    , uint8_t hh
    , uint8_t mm
    , uint8_t ss
 )
{
    res->year = year;
    res->month = month;
    res->day = day;
    res->hh = hh;
    res->mm = mm;
    res->ss = ss;
}

void initialize( Weekdays * res
    , uint32_t mask
 )
{
    res->mask = mask;
}

void initialize( TimeRange * res
    , uint32_t from
    , uint32_t to
 )
{
    res->from = from;
    res->to = to;
}

void initialize( LocalTimeRange * res
    , const LocalTime &  from
    , const LocalTime &  to
 )
{
    res->from = from;
    res->to = to;
}

void initialize( Date * res
    , uint32_t year
    , uint8_t month
    , uint8_t day
 )
{
    res->year = year;
    res->month = month;
    res->day = day;
}

void initialize( Email * res
    , const std::string &  email
 )
{
    res->email = email;
}

// base messages

// messages

// messages (constructors)

} // namespace basic_objects

