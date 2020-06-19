#ifndef APG_BASIC_OBJECTS__PARSER_H
#define APG_BASIC_OBJECTS__PARSER_H

// includes
#include "generic_request/request.h"
#include "enums.h"
#include "protocol.h"

namespace basic_objects
{

namespace parser
{

typedef basic_parser::Object    Object;

basic_parser::Object * to_forward_message( const generic_request::Request & r );

request_type_e detect_request_type( const generic_request::Request & r );

// objects

void get_value_or_throw( TimePoint24 * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( TimeWindow * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( LocalTime * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( Weekdays * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( TimeRange * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( LocalTimeRange * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( Date * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( Email * res, const std::string & key, const generic_request::Request & r );

// base messages


// messages


// to_... functions


} // namespace parser

} // namespace basic_objects

#endif // APG_BASIC_OBJECTS__PARSER_H
