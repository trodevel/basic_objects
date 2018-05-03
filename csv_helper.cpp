/*

CSV helper.

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

// $Revision: 9032 $ $Date:: 2018-05-03 #$ $Author: serge $

#include "csv_helper.h"         // self

#include "../utils/csv_helper.h"        // CsvHelper

namespace basic_objects
{

std::ostream & CsvHelper::write( std::ostream & os, const TimePoint24 & r )
{
    return utils::CsvHelper::write( os, r.hh * 100 + r.mm );
}

std::ostream & CsvHelper::write( std::ostream & os, const TimeWindow & r )
{
    write( os, r.from );
    write( os, r.to );
    return os;
}

std::ostream & CsvHelper::write( std::ostream & os, const LocalTime & r )
{
    auto val = r.year * 10000000000 + r.month * 100000000 + r.day * 1000000 + r.hh * 10000 + r.mm * 100 + r.ss;

    return utils::CsvHelper::write( os, val );
}

std::ostream & CsvHelper::write( std::ostream & os, const Weekdays & r )
{
    return utils::CsvHelper::write( os, r.mask );
}

std::ostream & CsvHelper::write( std::ostream & os, const Date & r )
{
    return utils::CsvHelper::write( os, r.year * 10000 + r.month * 100 + r.day );
}

} // namespace basic_objects
