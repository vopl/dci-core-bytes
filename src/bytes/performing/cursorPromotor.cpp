/* This file is part of the the dci project. Copyright (C) 2013-2022 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#include "pch.hpp"
#include "cursorPromotor.hpp"
#include "../impl/cursor.hpp"

namespace dci::bytes::performing
{
    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    CursorPromotor::CursorPromotor(impl::Cursor& cursor)
        : _cursor(cursor)
    {
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    CursorPromotor::~CursorPromotor()
    {
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    uint32 CursorPromotor::possibleContinuousSize()
    {
        return _cursor.continuousDataSize();
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    void CursorPromotor::promotePrepare(uint32 size)
    {
        (void)size;
        dbgAssert(size <= _cursor.continuousDataSize());
        dbgAssert(!_cursor.continuousDataSize() == !_cursor.continuousData());
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    const void* CursorPromotor::continuousData()
    {
        dbgAssert(!_cursor.continuousDataSize() == !_cursor.continuousData());
        return _cursor.continuousData();
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    void CursorPromotor::promoteFix(uint32 size)
    {
        int32 isize = static_cast<int32>(size);
        int32 res = _cursor.advance(isize);
        (void)res;
        dbgAssert(res == isize);
    }

}
