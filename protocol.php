<?php

/*

Basic Objects.

Copyright (C) 2018 Sergey Kolevatov

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

*/

// $Revision: 12692 $ $Date:: 2020-02-03 #$ $Author: serge $

namespace basic_objects;

require_once __DIR__.'/../generic_protocol/request_assembler.php';

class TimePoint24
{
    public             $hh;
    public             $mm;

    function __construct()
    {
        $this->hh   = 0;
        $this->mm   = 0;
    }

    public function to_generic_request( $prefix )
    {
        $res = array(
            $prefix => ( $this->hh * 100 + $this->mm ) );

        return \generic_protocol\assemble_request( $res );
    }
}

class TimeWindow
{
    public             $from;
    public             $to;

    function __construct()
    {
        $this->from = new TimePoint24;
        $this->to   = new TimePoint24;

        $this->to->hh = 23;
        $this->to->mm = 59;
    }

    public function to_generic_request( $prefix )
    {
        return
            $this->from->to_generic_request( $prefix . "_FROM" ) .
            $this->to->to_generic_request(   $prefix . "_TO" );
    }
}

class LocalTime
{
    public          $year;  // year
    public          $month; // month
    public          $day;   // day
    public          $hh;    // hour
    public          $mm;    // minute
    public          $ss;    // second

    function __construct( $year, $month, $day, $hh, $mm, $ss )
    {
        $this->year     = $year;
        $this->month    = $month;
        $this->day      = $day;
        $this->hh       = $hh;
        $this->mm       = $mm;
        $this->ss       = $ss;
    }

    public function get_encoded()
    {
        return $this->year * 10000000000 + $this->month * 100000000 + $this->day * 1000000
            + $this->hh * 10000 + $this->mm * 100 + $this->ss;
    }

    public function to_generic_request( $key_name )
    {
        $res = array(
            $key_name  => $this->get_encoded() );
        
        return \generic_protocol\assemble_request( $res );
    }
};

class Weekdays
{
    // enum weekdays_e
    const MO = 1;
    const TU = 2;
    const WE = 4;
    const TH = 8;
    const FR = 16;
    const SA = 32;
    const SU = 64;

    public              $mask;

    function __construct()
    {
        $this->mask    =
        self::MO + self::TU + self::WE + self::TH + self::FR + self::SA + self::SU;
    }

    public function to_generic_request()
    {
        $res = array(
                "WEEKDAYS_MASK" => $this->mask
            );

        return \generic_protocol\assemble_request( $res );
    }
}

class TimeRange
{
    public             $from;   // epoch (seconds)
    public             $to;     // epoch (seconds)

    function __construct( $from, $to )
    {
        $this->from     = $from;
        $this->to       = $to;
    }

    public function to_generic_request( $prefix )
    {
        $res = array(
            $prefix . "_TR_FROM" => $this->from,
            $prefix . "_TR_TO"   => $this->to );

        return \generic_protocol\assemble_request( $res );
    }
}

class LocalTimeRange
{
    public             $from;   // LocalTime
    public             $to;     // LocalTime

    function __construct( $from, $to )
    {
        $this->from     = $from;
        $this->to       = $to;
    }

    public function to_generic_request( $prefix )
    {
        return $this->from->to_generic_request( $prefix . "_TR_FROM" ) .
            $this->to->to_generic_request( $prefix . "_TR_TO" );
    }
}

class Date
{
    public          $year;  // year
    public          $month; // month
    public          $day;   // day

    function __construct( $year, $month, $day )
    {
        $this->year     = $year;
        $this->month    = $month;
        $this->day      = $day;
    }

    public function get_encoded()
    {
        return $this->year * 10000 + $this->month * 100 + $this->day;
    }

    public function to_generic_request( $key_name )
    {
        $res = array(
                $key_name  => $this->get_encoded() );

        return \generic_protocol\assemble_request( $res );
    }
};

class Email
{
    public          $email;  // email
    
    function __construct( $email )
    {
        $this->email    = $email;
    }
    
    public function to_generic_request( $key_name )
    {
        $res = array(
            $key_name . ":X"  => str2hex( $this->email ) );
        
        return \generic_protocol\assemble_request( $res );
    }
};

?>
