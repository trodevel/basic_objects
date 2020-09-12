#ifndef APG_BASIC_OBJECTS__PROTOCOL_H
#define APG_BASIC_OBJECTS__PROTOCOL_H

// system includes
#include <vector>
#include <map>

// includes
#include "basic_parser/object.h"

// includes for used modules

namespace basic_objects
{

// Enum
enum class weekdays_e
{
    MO                   = 1,
    TU                   = 2,
    WE                   = 4,
    TH                   = 8,
    FR                   = 16,
    SA                   = 32,
    SU                   = 64,
};

// Enum
enum class gender_e
{
    UNDEF                = 0,
    MALE                 = 1,
    FEMALE               = 2,
    OTHER                = 3,
};

// Object
struct TimePoint24
{
    uint8_t              hh        ; // valid range: [0, 23]
    uint8_t              mm        ; // valid range: [0, 59]
};

// Object
struct TimeWindow
{
    TimePoint24          from      ;
    TimePoint24          to        ;
};

// Object
struct LocalTime
{
    uint32_t             year      ; // valid range: [1800, 3000]
    uint8_t              month     ; // valid range: [1, 12]
    uint8_t              day       ; // valid range: [1, 31]
    uint8_t              hh        ; // valid range: [0, 23]
    uint8_t              mm        ; // valid range: [0, 59]
    uint8_t              ss        ; // valid range: [0, 59]
};

// Object
struct Weekdays
{
    enum weekdays_e
    {
        MO = 1,
        TU = 2,
        WE = 4,
        TH = 8,
        FR = 16,
        SA = 32,
        SU = 64
    };

    uint32_t             mask      ;
};

// Object
struct TimeRange
{
    uint32_t             from      ;
    uint32_t             to        ;
};

// Object
struct LocalTimeRange
{
    LocalTime            from      ;
    LocalTime            to        ;
};

// Object
struct Date
{
    uint32_t             year      ; // valid range: [1800, 3000]
    uint8_t              month     ; // valid range: [1, 12]
    uint8_t              day       ; // valid range: [1, 31]
};

// Object
struct Email
{
    std::string          email     ;
};

} // namespace basic_objects

#endif // APG_BASIC_OBJECTS__PROTOCOL_H

