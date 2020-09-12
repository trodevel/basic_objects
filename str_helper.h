#ifndef APG_BASIC_OBJECTS__STR_HELPER_H
#define APG_BASIC_OBJECTS__STR_HELPER_H

// system includes
#include <sstream>

// includes
#include "protocol.h"

namespace basic_objects
{

namespace str_helper
{

// enums
std::ostream & write( std::ostream & os, const weekdays_e r );
std::ostream & write( std::ostream & os, const gender_e r );

// objects
std::ostream & write( std::ostream & os, const TimePoint24 & r );
std::ostream & write( std::ostream & os, const TimeWindow & r );
std::ostream & write( std::ostream & os, const LocalTime & r );
std::ostream & write( std::ostream & os, const Weekdays & r );
std::ostream & write( std::ostream & os, const TimeRange & r );
std::ostream & write( std::ostream & os, const LocalTimeRange & r );
std::ostream & write( std::ostream & os, const Date & r );
std::ostream & write( std::ostream & os, const Email & r );

// base messages

// messages

template<class T>
std::string to_string( const T & l )
{
    std::ostringstream os;

    write( os, l );

    return os.str();
}

std::string to_string_YYYYMMDD( const Date & l );
std::string to_string_HHMM( const TimePoint24 & l );

} // namespace str_helper

inline std::ostream& operator<<( std::ostream& os, const TimePoint24 & l )
{
    return str_helper::write( os, l );
}

inline std::ostream& operator<<( std::ostream& os, const TimeWindow & l )
{
    return str_helper::write( os, l );
}

inline std::ostream& operator<<( std::ostream& os, const LocalTime & l )
{
    return str_helper::write( os, l );
}

inline std::ostream& operator<<( std::ostream& os, const Weekdays & l )
{
    return str_helper::write( os, l );
}

inline std::ostream& operator<<( std::ostream& os, const Email & l )
{
    return str_helper::write( os, l );
}

} // namespace basic_objects

#endif // APG_BASIC_OBJECTS__STR_HELPER_H
