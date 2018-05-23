<?php

// $Revision: 9250 $ $Date:: 2018-05-24 #$ $Author: serge $

require_once '../basic_objects.php';
require_once '../parser.php';
require_once '../str_helper.php';

{
    $resp  = array( '201805041739' );
    $offset = 0;

    $parsed = \basic_objects\parse_LocalTime( $resp, $offset );

    echo "parsed: " . \basic_objects\to_string_LocalTime( $parsed ) . "\n";

    print_r( $parsed );
}

?>
