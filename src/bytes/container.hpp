/* This file is part of the the dci project. Copyright (C) 2013-2021 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include "pch.hpp"
#include "user.hpp"
#include "buffer.hpp"

namespace dci::bytes
{
    class Container
    {
    protected:
        Container();
        Container(const Container& from);
        Container(Container&& from);

        ~Container();

        Container& operator=(const Container& from);
        Container& operator=(Container&& from);

    public:
        void resetUsers();

        bytes::Buffer* buffer();
        const bytes::Buffer* buffer() const;
        void setBuffer(bytes::Buffer* buffer);
        void resetBuffer();

    private:
        friend class User;

        void track(User* user);
        void untrack(User* user);

    private:
        bytes::BufferPtr    _buffer;
        User*               _firstUser = nullptr;
    };
}
