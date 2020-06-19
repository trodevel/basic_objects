<?php

// $Revision: 13300 $ $Date:: 2020-06-19 #$ $Author: serge $

require_once '../protocol.php';
require_once '../parser.php';
require_once '../str_helper.php';

{
    $resp  = array( '2018', '05', '04', '17' , '39', '15' );
    $offset = 0;

    $parsed = \basic_objects\parse__LocalTime( $resp, $offset );

    echo "parsed: " . \basic_objects\to_string__LocalTime( $parsed ) . "\n";

    print_r( $parsed );
}

?>
