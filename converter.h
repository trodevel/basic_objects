/*

Converter.

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

// $Revision: 13339 $ $Date:: 2020-07-02 #$ $Author: serge $

#ifndef LIB_BASIC_OBJECTS__CONVERTER_H
#define LIB_BASIC_OBJECTS__CONVERTER_H

#include "protocol.h"      // LocalTime...

namespace basic_objects
{

uint64_t to_val( const LocalTime & r );

Date        to_Date( const LocalTime & r );
TimePoint24 to_TimePoint24( const LocalTime & r );

} // namespace basic_objects

#endif // LIB_BASIC_OBJECTS__CONVERTER_H
