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

// $Revision: 12795 $ $Date:: 2020-02-26 #$ $Author: serge $

#include "protocol.h"      // Date...

namespace basic_parser
{

namespace validator
{

bool validate( const basic_objects::Weekdays & r );
bool validate( const basic_objects::TimeRange & r );
bool validate( const basic_objects::LocalTimeRange & r );
bool validate( const basic_objects::Date & r );
bool validate( const basic_objects::LocalTime & r );
bool validate( const basic_objects::TimePoint24 & r );
bool validate( const basic_objects::TimeWindow & r );
bool validate( const basic_objects::Email & r );

} // namespace validator

} // namespace basic_parser
