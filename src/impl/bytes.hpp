/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include "pch.hpp"
#include "../bytes/impl/alter.hpp"
#include "../bytes/container.hpp"

namespace dci::impl
{
    using Cursor = bytes::impl::Cursor;
    using Alter = bytes::impl::Alter;

    class Bytes final
        : public bytes::Container
    {
    public:
        Bytes();
        Bytes(const Bytes& from);
        Bytes(Bytes&& from);
        Bytes(bytes::Chunk* first, bytes::Chunk* last, uint32 size);
        Bytes(const void* data, uint32 size);
        Bytes(const char* csz);

        ~Bytes();

        Bytes& operator=(const Bytes& from);
        Bytes& operator=(Bytes&& from);

        bool operator==(const Bytes& with) const;
        bool operator!=(const Bytes& with) const;
        bool operator<(const Bytes& with) const;
        bool operator>(const Bytes& with) const;
        bool operator<=(const Bytes& with) const;
        bool operator>=(const Bytes& with) const;
        std::strong_ordering operator<=>(const Bytes& with) const;

        bool empty() const;
        uint32 size() const;

        String toString() const;
        String toHex() const;

        void clear();

        Alter begin();
        Cursor begin() const;
        Cursor cbegin() const;

        Alter end();
        Cursor end() const;
        Cursor cend() const;

    private:
        std::strong_ordering compare(const Bytes& with) const;
    };
}
