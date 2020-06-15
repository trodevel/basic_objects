#include <iostream>

#include "parser.h"
#include "str_helper.h"     // to_string()
#include "csv_helper.h"     // CsvHelper::to_csv()
#include "validator.h"
#include "dummy_creator.h"

template <class T>
void validate( const T & o, const std::string & name )
{
    try
    {
        basic_objects::validator::validate( name, o );
        std::cout << name << " : valid" << std::endl;
    }
    catch( std::exception & e )
    {
        std::cout << name << " : invalid : " << e.what() << std::endl;
    }
}

int main( int argc, char ** argv )
{
    if( argc > 1 )
    {
        srand( std::stoi( std::string( argv[1] ) ) );
    }

    basic_objects::Email o;

    validate( o, "EMAIL" );

    std::cout << ::basic_objects::str_helper::to_string( ::basic_objects::dummy::create__TimePoint24() ) << std::endl;
    std::cout << ::basic_objects::str_helper::to_string( ::basic_objects::dummy::create__TimeWindow() ) << std::endl;
    std::cout << ::basic_objects::str_helper::to_string( ::basic_objects::dummy::create__LocalTime() ) << std::endl;
    std::cout << ::basic_objects::str_helper::to_string( ::basic_objects::dummy::create__Weekdays() ) << std::endl;
    std::cout << ::basic_objects::str_helper::to_string( ::basic_objects::dummy::create__TimeRange() ) << std::endl;
    std::cout << ::basic_objects::str_helper::to_string( ::basic_objects::dummy::create__LocalTimeRange() ) << std::endl;
    std::cout << ::basic_objects::str_helper::to_string( ::basic_objects::dummy::create__Date() ) << std::endl;
    std::cout << ::basic_objects::str_helper::to_string( ::basic_objects::dummy::create__Email() ) << std::endl;


    return 0;
}
