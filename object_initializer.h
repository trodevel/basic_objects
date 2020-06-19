#ifndef APG_BASIC_OBJECTS__OBJECT_INITIALIZER_H
#define APG_BASIC_OBJECTS__OBJECT_INITIALIZER_H

// includes
#include "protocol.h"

namespace basic_objects
{

// objects

void initialize( TimePoint24 * res
    , uint8_t hh
    , uint8_t mm
 );
void initialize( TimeWindow * res
    , const TimePoint24 &  from
    , const TimePoint24 &  to
 );
void initialize( LocalTime * res
    , uint32_t year
    , uint8_t month
    , uint8_t day
    , uint8_t hh
    , uint8_t mm
    , uint8_t ss
 );
void initialize( Weekdays * res
    , uint32_t mask
 );
void initialize( TimeRange * res
    , uint32_t from
    , uint32_t to
 );
void initialize( LocalTimeRange * res
    , const LocalTime &  from
    , const LocalTime &  to
 );
void initialize( Date * res
    , uint32_t year
    , uint8_t month
    , uint8_t day
 );
void initialize( Email * res
    , const std::string &  email
 );

// base messages


// messages


// messages (constructors)


} // namespace basic_objects

#endif // APG_BASIC_OBJECTS__OBJECT_INITIALIZER_H
