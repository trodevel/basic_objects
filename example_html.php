<?php

namespace basic_objects;


// includes
require_once 'protocol.php';
require_once 'dummy_creator.php';
require_once 'html_helper.php';

# objects

function example_TimePoint24()
{
    $obj = \basic_objects\create_dummy__TimePoint24();

    echo "TimePoint24 : HTML : " . \basic_objects\to_html( $obj ) . "<br>\n";
}

function example_TimeWindow()
{
    $obj = \basic_objects\create_dummy__TimeWindow();

    echo "TimeWindow : HTML : " . \basic_objects\to_html( $obj ) . "<br>\n";
}

function example_LocalTime()
{
    $obj = \basic_objects\create_dummy__LocalTime();

    echo "LocalTime : HTML : " . \basic_objects\to_html( $obj ) . "<br>\n";
}

function example_Weekdays()
{
    $obj = \basic_objects\create_dummy__Weekdays();

    echo "Weekdays : HTML : " . \basic_objects\to_html( $obj ) . "<br>\n";
}

function example_TimeRange()
{
    $obj = \basic_objects\create_dummy__TimeRange();

    echo "TimeRange : HTML : " . \basic_objects\to_html( $obj ) . "<br>\n";
}

function example_LocalTimeRange()
{
    $obj = \basic_objects\create_dummy__LocalTimeRange();

    echo "LocalTimeRange : HTML : " . \basic_objects\to_html( $obj ) . "<br>\n";
}

function example_Date()
{
    $obj = \basic_objects\create_dummy__Date();

    echo "Date : HTML : " . \basic_objects\to_html( $obj ) . "<br>\n";
}

function example_Email()
{
    $obj = \basic_objects\create_dummy__Email();

    echo "Email : HTML : " . \basic_objects\to_html( $obj ) . "<br>\n";
}


# messages


{
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


}

# namespace_end basic_objects


?>
