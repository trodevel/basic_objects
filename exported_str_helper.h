#ifndef BASIC_OBJECTS__EXPORTED_STR_HELPER_H
#define BASIC_OBJECTS__EXPORTED_STR_HELPER_H

// system includes
#include <sstream>

// includes
#include "protocol.h"

namespace basic_parser
{

namespace str_helper
{

std::ostream & write( std::ostream & os, const basic_objects::Date & r );
std::ostream & write( std::ostream & os, const basic_objects::TimePoint24 & r );
std::ostream & write( std::ostream & os, const basic_objects::TimeWindow & r );
std::ostream & write( std::ostream & os, const basic_objects::LocalTime & r );
std::ostream & write( std::ostream & os, const basic_objects::LocalTimeRange & r );
std::ostream & write( std::ostream & os, const basic_objects::Weekdays & r );
std::ostream & write( std::ostream & os, const basic_objects::Email & r );

} // namespace str_helper

} // namespace basic_parser

#endif // BASIC_OBJECTS__EXPORTED_STR_HELPER_H
