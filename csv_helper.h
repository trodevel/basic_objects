#ifndef APG_BASIC_OBJECTS__CSV_HELPER_H
#define APG_BASIC_OBJECTS__CSV_HELPER_H

// system includes
#include <sstream>

// includes
#include "protocol.h"

namespace basic_objects
{

namespace csv_helper
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

// generic
std::ostream & write( std::ostream & os, const basic_parser::Object & r );

template<class T>
std::string to_csv( const T & l )
{
    std::ostringstream os;

    write( os, l );

    return os.str();
}

} // namespace csv_helper

} // namespace basic_objects

#endif // APG_BASIC_OBJECTS__CSV_HELPER_H
