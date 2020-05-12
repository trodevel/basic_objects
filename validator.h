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

// $Revision: 13028 $ $Date:: 2020-05-13 #$ $Author: serge $

#include "protocol.h"      // Date...

namespace basic_objects
{

namespace validator
{

bool validate( const Weekdays & r );
bool validate( const TimeRange & r );
bool validate( const LocalTimeRange & r );
bool validate( const Date & r );
bool validate( const LocalTime & r );
bool validate( const TimePoint24 & r );
bool validate( const TimeWindow & r );
bool validate( const Email & r );

} // namespace validator

} // namespace basic_objects
