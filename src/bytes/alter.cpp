/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#include "pch.hpp"
#include "impl/alter.hpp"
#include <dci/bytes/alter.hpp>
#include <dci/bytes.hpp>

namespace dci::bytes
{
    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    Alter::Alter()
        : himpl::FaceLayout<Alter, impl::Alter, Cursor>()
    {
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    Alter::Alter(const Alter& from)
        : himpl::FaceLayout<Alter, impl::Alter, Cursor>(himpl::face2Impl(from))
    {
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    Alter::Alter(Alter&& from)
        : himpl::FaceLayout<Alter, impl::Alter, Cursor>(himpl::face2Impl(std::move(from)))
    {
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    Alter::~Alter()
    {
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    Alter& Alter::operator=(const Alter& from)
    {
        return himpl::impl2Face<Alter>(impl()=himpl::face2Impl(from));
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    Alter& Alter::operator=(Alter&& from)
    {
        return himpl::impl2Face<Alter>(impl()=himpl::face2Impl(std::move(from)));
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    void Alter::advance(int32 offset)
    {
        return impl().advance(offset);
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    void* Alter::continuousData4Write()
    {
        return impl().continuousData4Write();
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    byte* Alter::prepareWriteBuffer(uint32& size)
    {
        return impl().prepareWriteBuffer(size);
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    void Alter::commitWriteBuffer(uint32 size)
    {
        return impl().commitWriteBuffer(size);
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    void Alter::write(const void* src, uint32 size)
    {
        return impl().write(src, size);
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    uint32 Alter::write(const char* srcz)
    {
        return impl().write(srcz);
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    uint32 Alter::write(const Bytes& src, uint32 maxSize)
    {
        return impl().write(himpl::face2Impl(src), maxSize);
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    uint32 Alter::write(Bytes&& src, uint32 maxSize)
    {
        return impl().write(himpl::face2Impl(std::move(src)), maxSize);
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    uint32 Alter::write(Cursor& src, uint32 maxSize)
    {
        return impl().write(himpl::face2Impl(src), maxSize);
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    void Alter::write(Chunk* srcFirst, Chunk* srcLast, uint32 size)
    {
        return impl().write(srcFirst, srcLast, size);
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    uint32 Alter::remove(uint32 maxSize)
    {
        return impl().remove(maxSize);
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    uint32 Alter::removeTo(void* dst, uint32 maxSize)
    {
        return impl().removeTo(dst, maxSize);
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    uint32 Alter::removeTo(Bytes& dst, uint32 maxSize)
    {
        return impl().removeTo(himpl::face2Impl(dst), maxSize);
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    uint32 Alter::removeTo(Alter& dst, uint32 maxSize)
    {
        return impl().removeTo(himpl::face2Impl(dst), maxSize);
    }
}
