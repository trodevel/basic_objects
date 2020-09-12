// system includes
#include <map>
#include <typeindex>

// includes
#include "csv_helper.h"
#include "basic_parser/csv_helper.h"

namespace basic_objects
{

namespace csv_helper
{

using ::basic_parser::csv_helper::write;
using ::basic_parser::csv_helper::write_t;

// enums

std::ostream & write( std::ostream & os, const weekdays_e r )
{
    write( os, static_cast<unsigned>( r ) );

    return os;
}

std::ostream & write( std::ostream & os, const gender_e r )
{
    write( os, static_cast<unsigned>( r ) );

    return os;
}

// objects

std::ostream & write( std::ostream & os, const TimePoint24 & r )
{
    write( os, r.hh );
    write( os, r.mm );

    return os;
}

std::ostream & write( std::ostream & os, const TimeWindow & r )
{
    write( os, r.from );
    write( os, r.to );

    return os;
}

std::ostream & write( std::ostream & os, const LocalTime & r )
{
    write( os, r.year );
    write( os, r.month );
    write( os, r.day );
    write( os, r.hh );
    write( os, r.mm );
    write( os, r.ss );

    return os;
}

std::ostream & write( std::ostream & os, const Weekdays & r )
{
    write( os, r.mask );

    return os;
}

std::ostream & write( std::ostream & os, const TimeRange & r )
{
    write( os, r.from );
    write( os, r.to );

    return os;
}

std::ostream & write( std::ostream & os, const LocalTimeRange & r )
{
    write( os, r.from );
    write( os, r.to );

    return os;
}

std::ostream & write( std::ostream & os, const Date & r )
{
    write( os, r.year );
    write( os, r.month );
    write( os, r.day );

    return os;
}

std::ostream & write( std::ostream & os, const Email & r )
{
    write( os, r.email );

    return os;
}

// base messages

// messages


std::ostream & write( std::ostream & os, const basic_parser::Object & r )
{
    typedef std::ostream & (*PPMF)( std::ostream & os, const basic_parser::Object & );

#define HANDLER_MAP_ENTRY(_v)       { typeid( _v ),        & write_##_v }

    static const std::map<std::type_index, PPMF> funcs =
    {
    };

#undef HANDLER_MAP_ENTRY

    auto it = funcs.find( typeid( r ) );

    if( it != funcs.end() )
        return it->second( os, r );

    return os;
}

} // namespace csv_helper

} // namespace basic_objects

