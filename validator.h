#ifndef APG_BASIC_OBJECTS__VALIDATOR_H
#define APG_BASIC_OBJECTS__VALIDATOR_H

// includes
#include "protocol.h"

namespace basic_objects
{

namespace validator
{

// enums
bool validate( const std::string & prefix, const weekdays_e r );
bool validate( const std::string & prefix, const gender_e r );

// objects
bool validate( const std::string & prefix, const TimePoint24 & r );
bool validate( const std::string & prefix, const TimeWindow & r );
bool validate( const std::string & prefix, const LocalTime & r );
bool validate( const std::string & prefix, const Weekdays & r );
bool validate( const std::string & prefix, const TimeRange & r );
bool validate( const std::string & prefix, const LocalTimeRange & r );
bool validate( const std::string & prefix, const Date & r );
bool validate( const std::string & prefix, const Email & r );

// base messages

// messages

} // namespace validator

} // namespace basic_objects

#endif // APG_BASIC_OBJECTS__VALIDATOR_H
