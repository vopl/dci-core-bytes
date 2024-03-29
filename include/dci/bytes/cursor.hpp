/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include "../api.hpp"
#include <compare>
#include <dci/bytes/implMetaInfo.hpp>
#include <dci/himpl.hpp>
#include <dci/primitives.hpp>

namespace dci
{
    class Bytes;
}

namespace dci::bytes
{
    class Alter;

    class API_DCI_BYTES Cursor
        : public himpl::FaceLayout<Cursor, impl::Cursor>
    {
    public:
        Cursor(himpl::FakeConstructionArg);
        Cursor();
        Cursor(const Cursor& from);
        Cursor(Cursor&& from);
        ~Cursor();

        Cursor& operator=(const Cursor& from);
        Cursor& operator=(Cursor&& from);

    public:
        bool atBegin() const;
        bool atEnd() const;

        uint32 pos() const;

        uint32 size() const;
        uint32 sizeBack() const;

        int32 advance(int32 offset);

        int32 advanceChunks(int32 amount);
        const byte* continuousData() const; //инвалидируется при cow, модификациях контейнера
        uint32 continuousDataSize() const;  //инвалидируется при cow, модификациях контейнера
        uint32 continuousDataOffset() const;  //инвалидируется при cow, модификациях контейнера

        uint32 read(void* dst, uint32 maxSize);
        uint32 read(Bytes& dst, uint32 maxSize);
        uint32 read(Alter& dst, uint32 maxSize);

        std::strong_ordering compare(const void* with, uint32 size);
        std::strong_ordering compare(const Bytes& with);
        std::strong_ordering compare(Cursor& with);

        String toString(uint32 maxSize = ~uint32(0));
        String toHex(uint32 maxSize = ~uint32(0));
    };

}
