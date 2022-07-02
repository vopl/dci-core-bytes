/* This file is part of the the dci project. Copyright (C) 2013-2022 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include <dci/bytes.hpp>

using namespace dci;
using namespace dci::bytes;

namespace
{
    Bytes mkBig()
    {
        Chunk* first = new Chunk;
        Chunk* last = first;
        uint32 size = 0;

        const uint16 sbegins[] = {0,1,2,3,0,9,8,7,6,0,0,1,7,3,356,23,0,1,97,0,1,0,1};
        const uint16 ssizes[]  = {1,1,2,3,3,1,5,6,7,7,1,1,7,9,123,43,1,2,45,2,2,1,1};

        for(uint32 si(0); si < sizeof(sbegins)/sizeof(sbegins[0]); ++si)
        {
            uint16 sb = sbegins[si];
            uint16 ss = ssizes[si];

            last->setBeginEnd(sb, sb+ss);

            for(uint32 i(0); i<ss; ++i)
            {
                last->data()[i] = byte(size+i);
            }

            size += ss;
            last->setNext(new Chunk{nullptr, last});
            last = last->next();
        }

        uint16 ss = 10;
        last->setEnd(ss);

        for(uint32 i(0); i<ss; ++i)
        {
            last->data()[i] = byte(size+i);
        }
        size += ss;

        return Bytes(first, last, size);
    }
}
