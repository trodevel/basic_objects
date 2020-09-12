// includes
#include "validator.h"
#include "basic_parser/validator.h"

#include "utils/regex_match.h"  // utils::regex_match()
#include "basic_parser/malformed_request.h" // basic_parser::MalformedRequest

#include "parser.h"             // MalformedRequest
#include "converter.h"          // to_val

namespace basic_objects
{

namespace validator
{

using ::basic_parser::validator::validate;
using ::basic_parser::validator::validate_t;

// enums

bool validate( const std::string & prefix, const weekdays_e r )
{
    validate( prefix, static_cast<unsigned>( r ), true, true, static_cast<unsigned>( weekdays_e::MO ), true, true, static_cast<unsigned>( weekdays_e::SU ) );

    return true;
}

bool validate( const std::string & prefix, const gender_e r )
{
    validate( prefix, static_cast<unsigned>( r ), true, true, static_cast<unsigned>( gender_e::UNDEF ), true, true, static_cast<unsigned>( gender_e::OTHER ) );

    return true;
}

// objects

bool validate( const std::string & prefix, const TimePoint24 & r )
{
    if( r.hh > 23 )
        throw basic_parser::MalformedRequest( prefix + ".HH > 23" );

    if( r.mm > 59 )
        throw basic_parser::MalformedRequest( prefix + ".MM > 59" );

    return true;
}

bool validate( const std::string & prefix, const TimeWindow & r )
{
    validate( prefix + ".FROM", r.from );
    validate( prefix + ".TO", r.to );

    return true;
}

bool validate( const std::string & prefix, const LocalTime & r )
{
    if( r.year == 0 )
        throw basic_parser::MalformedRequest( prefix + ": year is 0" );

    if( r.month == 0 )
        throw basic_parser::MalformedRequest( prefix + ": month is 0" );

    if( r.day == 0 )
        throw basic_parser::MalformedRequest( prefix + ": day is 0" );

    if( r.year > 9999 )
        throw basic_parser::MalformedRequest( prefix + ": year > 9999" );

    if( r.month > 12 )
        throw basic_parser::MalformedRequest( prefix + ": month > 12" );

    if( r.day > 31 )
        throw basic_parser::MalformedRequest( prefix + ": day > 31" );

    if( r.hh > 23 )
        throw basic_parser::MalformedRequest( prefix + ": hh > 23" );

    if( r.mm > 59 )
        throw basic_parser::MalformedRequest( prefix + ": mm > 59" );

    if( r.ss > 59 )
        throw basic_parser::MalformedRequest( prefix + ": ss > 59" );

    return true;
}

bool validate( const std::string & prefix, const Weekdays & r )
{
    if( r.mask <= 0 || r.mask > 127 )
        throw basic_parser::MalformedRequest( prefix + " is invalid" );

    return true;
}

bool validate( const std::string & prefix, const TimeRange & r )
{
    if( ( r.from > 0  ) && ( r.to > 0 ) && ( r.from > r.to ) )
        return false;

    return true;
}

bool validate( const std::string & prefix, const LocalTimeRange & r )
{
    auto from   = to_val( r.from );
    auto to     = to_val( r.to );

    if( from > 0 )
        validate( prefix, r.from );

    if( to > 0 )
        validate( prefix, r.to );

    if( ( from > 0 ) && ( to > 0 ) && ( from > to ) )
        return false;

    return true;
}

bool validate( const std::string & prefix, const Date & r )
{
    if( r.year == 0 && r.month == 0 && r.day == 0 )
        return true;

    if( ( r.year < 1900 || r.year > 2100 ) && r.year != 0 )
        throw basic_parser::MalformedRequest( prefix + ": year not in [1900, 2100]" );

    if( r.month < 1 || r.month > 12 )
        throw basic_parser::MalformedRequest( prefix + ": month not in [1, 12]" );

    if( r.day < 1 || r.day > 31 )
        throw basic_parser::MalformedRequest( prefix + ": day not in [1, 31]" );

    return true;
}

bool validate( const std::string & prefix, const Email & r )
{
    if( utils::regex_match( r.email, "^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\\.[a-zA-Z0-9.\\-]+$" ) == false )
        throw basic_parser::MalformedRequest( prefix + ": malformed email" );

    return true;
}

// base messages

// messages

} // namespace validator

} // namespace basic_objects

