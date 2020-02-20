// includes
#include "exported_str_helper.h"
#include "str_helper.h"

namespace basic_parser
{

namespace str_helper
{

std::ostream & write( std::ostream & os, const basic_objects::Date & r )
{
    return basic_objects::StrHelper::write( os, r );
}

std::ostream & write( std::ostream & os, const basic_objects::TimePoint24 & r )
{
    return basic_objects::StrHelper::write( os, r );
}

std::ostream & write( std::ostream & os, const basic_objects::TimeWindow & r )
{
    return basic_objects::StrHelper::write( os, r );
}

std::ostream & write( std::ostream & os, const basic_objects::LocalTime & r )
{
    return basic_objects::StrHelper::write( os, r );
}

std::ostream & write( std::ostream & os, const basic_objects::LocalTimeRange & r )
{
    return basic_objects::StrHelper::write( os, r );
}

std::ostream & write( std::ostream & os, const basic_objects::Weekdays & r )
{
    return basic_objects::StrHelper::write( os, r );
}

std::ostream & write( std::ostream & os, const basic_objects::Email & r )
{
    return basic_objects::StrHelper::write( os, r );
}

} // namespace str_helper

} // namespace basic_parser

