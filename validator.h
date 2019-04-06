/*

Validator.

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

// $Revision: 9895 $ $Date:: 2018-10-19 #$ $Author: serge $

#include "basic_objects.h"      // Date...

namespace basic_objects
{

class Validator
{
public:
    static bool validate( const Weekdays & r );
    static bool validate( const TimeRange & r );
    static bool validate( const LocalTimeRange & r );
    static bool validate( const Date & r );
    static bool validate( const LocalTime & r );
    static bool validate( const TimePoint24 & r );
    static bool validate( const TimeWindow & r );
    static bool validate( const Email & r );
};

} // namespace basic_objects
