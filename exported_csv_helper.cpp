// includes
#include "exported_csv_helper.h"
#include "csv_helper.h"

namespace basic_parser
{

namespace csv_encoder
{

std::ostream & write( std::ostream & os, const basic_objects::Date & r )
{
    return basic_objects::CsvHelper::write( os, r );
}

std::ostream & write( std::ostream & os, const basic_objects::TimePoint24 & r )
{
    return basic_objects::CsvHelper::write( os, r );
}

std::ostream & write( std::ostream & os, const basic_objects::TimeWindow & r )
{
    return basic_objects::CsvHelper::write( os, r );
}

std::ostream & write( std::ostream & os, const basic_objects::LocalTime & r )
{
    return basic_objects::CsvHelper::write( os, r );
}

std::ostream & write( std::ostream & os, const basic_objects::LocalTimeRange & r )
{
    return basic_objects::CsvHelper::write( os, r );
}

std::ostream & write( std::ostream & os, const basic_objects::Weekdays & r )
{
    return basic_objects::CsvHelper::write( os, r );
}

std::ostream & write( std::ostream & os, const basic_objects::Email & r )
{
    return basic_objects::CsvHelper::write( os, r );
}

} // namespace csv_encoder

} // namespace basic_parser

