<?php

namespace basic_objects;


// includes
require_once 'protocol.php';
require_once 'dummy_creator.php';
require_once 'str_helper.php';
require_once 'request_encoder.php';

# objects

function example_TimePoint24()
{
    $obj = \basic_objects\create_dummy__TimePoint24();

    echo "TimePoint24 : STR : " . \basic_objects\to_string( $obj ) . "\n";
}


# messages

function example_TimeWindow()
{
    $obj = \basic_objects\create_dummy__TimeWindow();

    echo "TimeWindow : STR : " . \basic_objects\to_string( $obj ) . "\n";
}

function example_LocalTime()
{
    $obj = \basic_objects\create_dummy__LocalTime();

    echo "LocalTime : STR : " . \basic_objects\to_string( $obj ) . "\n";
}

function example_Weekdays()
{
    $obj = \basic_objects\create_dummy__Weekdays();

    echo "Weekdays : STR : " . \basic_objects\to_string( $obj ) . "\n";
}

function example_TimeRange()
{
    $obj = \basic_objects\create_dummy__TimeRange();

    echo "TimeRange : STR : " . \basic_objects\to_string( $obj ) . "\n";
}

function example_LocalTimeRange()
{
    $obj = \basic_objects\create_dummy__LocalTimeRange();

    echo "LocalTimeRange : STR : " . \basic_objects\to_string( $obj ) . "\n";
}

function example_Date()
{
    $obj = \basic_objects\create_dummy__Date();

    echo "Date : STR : " . \basic_objects\to_string( $obj ) . "\n";
}

function example_Email()
{
    $obj = \basic_objects\create_dummy__Email();

    echo "Email : STR : " . \basic_objects\to_string( $obj ) . "\n";
}

{
    example_TimePoint24();
    example_TimeWindow();
    example_LocalTime();
    example_Weekdays();
    example_TimeRange();
    example_LocalTimeRange();
    example_Date();
    example_Email();

}

# namespace_end basic_objects

?>
