/*

Flattener.

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

// $Revision: 9185 $ $Date:: 2018-05-14 #$ $Author: serge $


#include "flattener.h"          // self

namespace basic_objects
{

uint64_t to_val( const LocalTime & r )
{
    auto res = r.year * 10000000000 + r.month * 100000000 + r.day * 1000000 + r.hh * 10000 + r.mm * 100 + r.ss;

    return res;
}

} // namespace basic_objects
