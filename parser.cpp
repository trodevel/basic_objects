// system includes
#include <map>
#include <memory>

// includes
#include "parser.h"
#include "basic_parser/parser.h"
#include "basic_parser/malformed_request.h"
#include "validator.h"
#include "request_type_parser.h"

namespace basic_objects
{

namespace parser
{

using ::basic_parser::parser::get_value_or_throw;
using ::basic_parser::parser::get_value_or_throw_t;

// enums

void get_value_or_throw( weekdays_e * res, const std::string & key, const generic_request::Request & r )
{
    uint32_t res_i;

    get_value_or_throw( & res_i, key, r );

    * res = static_cast<weekdays_e>( res_i );
}

void get_value_or_throw( gender_e * res, const std::string & key, const generic_request::Request & r )
{
    uint32_t res_i;

    get_value_or_throw( & res_i, key, r );

    * res = static_cast<gender_e>( res_i );
}

// objects

void get_value_or_throw( TimePoint24 * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->hh, prefix + ".HH", r );
    get_value_or_throw( & res->mm, prefix + ".MM", r );
}

void get_value_or_throw( TimeWindow * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->from, prefix + ".FROM", r );
    get_value_or_throw( & res->to, prefix + ".TO", r );
}

void get_value_or_throw( LocalTime * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->year, prefix + ".YEAR", r );
    get_value_or_throw( & res->month, prefix + ".MONTH", r );
    get_value_or_throw( & res->day, prefix + ".DAY", r );
    get_value_or_throw( & res->hh, prefix + ".HH", r );
    get_value_or_throw( & res->mm, prefix + ".MM", r );
    get_value_or_throw( & res->ss, prefix + ".SS", r );
}

void get_value_or_throw( Weekdays * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->mask, prefix + ".MASK", r );
}

void get_value_or_throw( TimeRange * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->from, prefix + ".FROM", r );
    get_value_or_throw( & res->to, prefix + ".TO", r );
}

void get_value_or_throw( LocalTimeRange * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->from, prefix + ".FROM", r );
    get_value_or_throw( & res->to, prefix + ".TO", r );
}

void get_value_or_throw( Date * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->year, prefix + ".YEAR", r );
    get_value_or_throw( & res->month, prefix + ".MONTH", r );
    get_value_or_throw( & res->day, prefix + ".DAY", r );
}

void get_value_or_throw( Email * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->email, prefix + ".EMAIL", r );
}

// base messages

// messages

// to object

// to forward message

basic_parser::Object* to_forward_message( const generic_request::Request & r )
{
    auto type = detect_request_type( r );

    typedef request_type_e KeyType;

    typedef Object* (*PPMF)( const generic_request::Request & r );

#define HANDLER_MAP_ENTRY(_v)       { KeyType::_v,    & to_##_v }

    static const std::map<KeyType, PPMF> funcs =
    {
    };

#undef HANDLER_MAP_ENTRY

    auto it = funcs.find( type );

    if( it != funcs.end() )
        return it->second( r );

    return nullptr;
}

using basic_parser::MalformedRequest;

request_type_e  detect_request_type( const generic_request::Request & r )
{
    std::string cmd;

    if( r.get_value( "CMD", cmd ) == false )
        throw MalformedRequest( "CMD is not defined" );

    return RequestTypeParser::to_request_type( cmd );
}

} // namespace parser

} // namespace basic_objects

