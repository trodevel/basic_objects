#include "protocol.h"
#include "str_helper.h"
#include "csv_helper.h"
#include "dummy_creator.h"
#include "validator.h"

#include <iostream>       // std::cout

template <class T>
void validate( const T & o, const std::string & name )
{
    try
    {
        basic_objects::validator::validate( o );
        std::cout << name << " : valid" << std::endl;
    }
    catch( std::exception & e )
    {
        std::cout << name << " : invalid : " << e.what() << std::endl;
    }
}

// enums

void example_weekdays_e()
{
    auto obj = basic_objects::dummy::create__weekdays_e();

    std::cout << "weekdays_e : STR : " << basic_objects::str_helper::to_string( obj ) << std::endl;
}

void example_gender_e()
{
    auto obj = basic_objects::dummy::create__gender_e();

    std::cout << "gender_e : STR : " << basic_objects::str_helper::to_string( obj ) << std::endl;
}


// objects

void example_TimePoint24()
{
    auto obj = basic_objects::dummy::create__TimePoint24();

    std::cout << "TimePoint24 : STR : " << basic_objects::str_helper::to_string( obj ) << std::endl;
}

void example_TimeWindow()
{
    auto obj = basic_objects::dummy::create__TimeWindow();

    std::cout << "TimeWindow : STR : " << basic_objects::str_helper::to_string( obj ) << std::endl;
}

void example_LocalTime()
{
    auto obj = basic_objects::dummy::create__LocalTime();

    std::cout << "LocalTime : STR : " << basic_objects::str_helper::to_string( obj ) << std::endl;
}

void example_Weekdays()
{
    auto obj = basic_objects::dummy::create__Weekdays();

    std::cout << "Weekdays : STR : " << basic_objects::str_helper::to_string( obj ) << std::endl;
}

void example_TimeRange()
{
    auto obj = basic_objects::dummy::create__TimeRange();

    std::cout << "TimeRange : STR : " << basic_objects::str_helper::to_string( obj ) << std::endl;
}

void example_LocalTimeRange()
{
    auto obj = basic_objects::dummy::create__LocalTimeRange();

    std::cout << "LocalTimeRange : STR : " << basic_objects::str_helper::to_string( obj ) << std::endl;
}

void example_Date()
{
    auto obj = basic_objects::dummy::create__Date();

    std::cout << "Date : STR : " << basic_objects::str_helper::to_string( obj ) << std::endl;
}

void example_Email()
{
    auto obj = basic_objects::dummy::create__Email();

    std::cout << "Email : STR : " << basic_objects::str_helper::to_string( obj ) << std::endl;
}


// messages


int main( int argc, char ** argv )
{
    if( argc > 1 )
    {
        std::srand( std::stoi( std::string( argv[1] ) ) );
    }

    // enums

    example_weekdays_e();
    example_gender_e();

    // objects

    example_TimePoint24();
    example_TimeWindow();
    example_LocalTime();
    example_Weekdays();
    example_TimeRange();
    example_LocalTimeRange();
    example_Date();
    example_Email();

    // messages


    return 0;
}

