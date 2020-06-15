/*

Dummy Creator.

Copyright (C) 2020 Sergey Kolevatov

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

// $Revision: 13266 $ $Date:: 2020-06-15 #$ $Author: serge $

#ifndef LIB_DUMMY_CREATOR__DUMMY_CREATOR_H
#define LIB_DUMMY_CREATOR__DUMMY_CREATOR_H

#include "protocol.h"              // Date

namespace basic_objects
{

namespace dummy
{

TimeRange create__TimeRange();
LocalTimeRange create__LocalTimeRange();
LocalTime create__LocalTime();
TimePoint24 create__TimePoint24();
TimeWindow create__TimeWindow();
Weekdays create__Weekdays();
Date create__Date();
Email create__Email();

} // namespace dummy

} // namespace basic_objects

#endif // LIB_DUMMY_CREATOR__DUMMY_CREATOR_H
