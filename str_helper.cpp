// system includes
#include <map>
#include <iomanip>                  // std::setfill

// includes
#include "str_helper.h"
#include "basic_parser/str_helper.h"

namespace basic_objects
{

namespace str_helper
{

using ::basic_parser::str_helper::write;
using ::basic_parser::str_helper::write_t;

// enums

#define TUPLE_VAL_STR(_x_)  _x_,#_x_

std::ostream & write( std::ostream & os, const weekdays_e r )
{
    typedef weekdays_e Type;
    static const std::map< Type, std::string > m =
    {
        { Type:: TUPLE_VAL_STR( MO ) },
        { Type:: TUPLE_VAL_STR( TU ) },
        { Type:: TUPLE_VAL_STR( WE ) },
        { Type:: TUPLE_VAL_STR( TH ) },
        { Type:: TUPLE_VAL_STR( FR ) },
        { Type:: TUPLE_VAL_STR( SA ) },
        { Type:: TUPLE_VAL_STR( SU ) },
    };

    auto it = m.find( r );

    static const std::string undef( "undef" );

    if( it != m.end() )
        return write( os, it->second );

    return write( os, undef );
}

std::ostream & write( std::ostream & os, const gender_e r )
{
    typedef gender_e Type;
    static const std::map< Type, std::string > m =
    {
        { Type:: TUPLE_VAL_STR( UNDEF ) },
        { Type:: TUPLE_VAL_STR( MALE ) },
        { Type:: TUPLE_VAL_STR( FEMALE ) },
        { Type:: TUPLE_VAL_STR( OTHER ) },
    };

    auto it = m.find( r );

    static const std::string undef( "undef" );

    if( it != m.end() )
        return write( os, it->second );

    return write( os, undef );
}

// objects

std::ostream & write( std::ostream & os, const TimePoint24 & l )
{
    os << std::setfill( '0' );

    os << std::setw( 2 ) << (unsigned)l.hh << ":" << std::setw( 2 ) << (unsigned)l.mm;

    return os;
}

std::ostream & write( std::ostream & os, const TimeWindow & l )
{
    os << l.from << "-" << l.to;

    return os;
}

std::ostream & write( std::ostream & os, const LocalTime & l )
{
    os << l.year << "-"
            << std::setfill( '0' ) << std::setw( 2 ) << (unsigned)l.month << "-"
            << std::setfill( '0' ) << std::setw( 2 ) << (unsigned)l.day << " "
            << std::setfill( '0' ) << std::setw( 2 ) << (unsigned)l.hh << ":"
            << std::setfill( '0' ) << std::setw( 2 ) << (unsigned)l.mm << ":"
            << std::setfill( '0' ) << std::setw( 2 ) << (unsigned)l.ss;

    return os;
}

std::ostream & write( std::ostream & os, const Weekdays & l )
{
    static const char *days[] =
    {
            "Mo", "Tu", "We", "Th", "Fr", "Sa", "So"
    };

    for( unsigned i = 0; i < 7; ++i )
    {
        auto e = 1 << i;

        if( l.mask & e )
        {
            os << days[i];
        }
        else
        {
            os << "__";
        }
    }

    return os;
}

std::string to_string_YYYYMMDD( const Date & l )
{
    std::ostringstream os;

    os << std::setfill( '0' );

    os << std::setw( 4 ) << (unsigned) l.year << std::setw( 2 ) << (unsigned) l.month << std::setw( 2 ) << (unsigned) l.day;

    return os.str();
}

std::string to_string_HHMM( const TimePoint24 & l )
{
    std::ostringstream os;

    os << std::setfill( '0' ) << std::setw( 2 ) << (unsigned) l.hh << std::setfill( '0' ) << std::setw( 2 ) << (unsigned) l.mm;

    return os.str();
}

std::ostream & write( std::ostream & os, const TimeRange & l )
{
    os << l.from;
    os << "-";
    os << l.to;

    return os;
}

std::ostream & write( std::ostream & os, const LocalTimeRange & l )
{
    write( os, l.from );
    os << "-";
    write( os, l.to );

    return os;
}

std::ostream & write( std::ostream & os, const Date & l )
{
    os << std::setfill( '0' );

    os << std::setw( 4 ) << (unsigned) l.year << std::setw( 2 ) << (unsigned) l.month << std::setw( 2 ) << (unsigned) l.day;

    return os;
}

std::ostream & write( std::ostream & os, const Email & l )
{
    os << l.email;

    return os;
}

// base messages

// messages

} // namespace str_helper

} // namespace basic_objects

