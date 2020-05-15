#include <iostream>

#include "parser.h"
#include "csv_helper.h"     // CsvHelper::to_csv()
#include "validator.h"

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

int main()
{
    basic_objects::Email o;

    validate( o, "EMAIL" );

    return 0;
}
