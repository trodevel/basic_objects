#ifndef APG_BASIC_OBJECTS__DUMMY_CREATOR_H
#define APG_BASIC_OBJECTS__DUMMY_CREATOR_H

// includes
#include "protocol.h"

namespace basic_objects
{

namespace dummy
{

// objects

TimePoint24 create__TimePoint24();
TimeWindow create__TimeWindow();
LocalTime create__LocalTime();
Weekdays create__Weekdays();
TimeRange create__TimeRange();
LocalTimeRange create__LocalTimeRange();
Date create__Date();
Email create__Email();

// messages


} // namespace dummy

} // namespace basic_objects

#endif // APG_BASIC_OBJECTS__DUMMY_CREATOR_H
