#ifndef APG_BASIC_OBJECTS__REQUEST_TYPE_PARSER_H
#define APG_BASIC_OBJECTS__REQUEST_TYPE_PARSER_H

// includes
#include "enums.h"

namespace basic_objects
{

class RequestTypeParser
{
public:
    static request_type_e   to_request_type( const std::string & s );
};
} // namespace basic_objects

#endif // APG_BASIC_OBJECTS__REQUEST_TYPE_PARSER_H
