/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#include "pch.hpp"
#include "partCursorPromotor.hpp"
#include "../impl/cursor.hpp"

namespace dci::bytes::performing
{
    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    PartCursorPromotor::PartCursorPromotor(impl::Cursor& cursor, uint32 maxSize)
        : _cursor(cursor)
        , _maxSize(maxSize)
    {
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    PartCursorPromotor::~PartCursorPromotor()
    {
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    uint32 PartCursorPromotor::possibleContinuousSize()
    {
        return std::min(_maxSize, _cursor.continuousDataSize());
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    void PartCursorPromotor::promotePrepare(uint32 size)
    {
        (void)size;
        dbgAssert(!size == !possibleContinuousSize());
        dbgAssert(size <= possibleContinuousSize());
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    const void* PartCursorPromotor::continuousData()
    {
        dbgAssert(!_cursor.continuousDataSize() == !_cursor.continuousData());
        return _cursor.continuousData();
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    void PartCursorPromotor::promoteFix(uint32 size)
    {
        int32 isize = static_cast<int32>(size);
        int32 res = _cursor.advance(isize);
        (void)res;
        dbgAssert(res == isize);

        dbgAssert(_maxSize >= size);
        _maxSize -= size;
    }

}
