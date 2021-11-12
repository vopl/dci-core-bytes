/* This file is part of the the dci project. Copyright (C) 2013-2021 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include <dci/mm/heap/allocable.hpp>
#include <dci/primitives.hpp>

namespace dci::bytes
{
    struct Chunk
        : mm::heap::Allocable<Chunk>
    {
        Chunk(const Chunk&) = delete;
        Chunk(Chunk&&) = delete;

        void operator=(const Chunk&) = delete;
        void operator=(Chunk&&) = delete;

    public:
        Chunk(Chunk* next=nullptr, Chunk* prev=nullptr, uint16 begin=0, uint16 end=0);
        Chunk(uint16 begin, uint16 end);
        ~Chunk();

        static constexpr uint32 bufferSize() {return sizeof(_buffer);}
        uint16 size() const;

        const byte* buffer() const;
        const byte* data() const;
        const Chunk* next() const;
        const Chunk* prev() const;

        byte* buffer();
        byte* data();
        Chunk* next();
        Chunk* prev();

        uint16 begin() const;
        uint16 end() const;

    public:
        void setNext(Chunk* next);
        void setPrev(Chunk* prev);
        void setBegin(uint16 begin);
        void setEnd(uint16 end);
        void setBeginEnd(uint16 begin, uint16 end);

    public:
        bool consistent() const;

    private:
        byte    _buffer[1024];
        Chunk*  _next = nullptr;
        Chunk*  _prev = nullptr;
        uint16  _begin = 0;
        uint16  _end = 0;
    };//1024 + 8 + 8 + (2 + 2 + alignTo8=4) == 1048

    static_assert(1048 == sizeof(Chunk));


    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    inline Chunk::Chunk(Chunk* next, Chunk* prev, uint16 begin, uint16 end)
        : _next(next)
        , _prev(prev)
        , _begin(begin)
        , _end(end)
    {
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    inline Chunk::Chunk(uint16 begin, uint16 end)
        : _next(nullptr)
        , _prev(nullptr)
        , _begin(begin)
        , _end(end)
    {
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    inline Chunk::~Chunk()
    {
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    inline uint16 Chunk::size() const
    {
        dbgAssert(_begin <= bufferSize());
        dbgAssert(_end <= bufferSize());
        dbgAssert(_begin <= _end);

        return _end - _begin;
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    inline const byte* Chunk::buffer() const
    {
        return _buffer;
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    inline const byte* Chunk::data() const
    {
        dbgAssert(_begin <= bufferSize());
        dbgAssert(_begin <= _end);

        return &_buffer[_begin];
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    inline const Chunk* Chunk::next() const
    {
        return _next;
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    inline const Chunk* Chunk::prev() const
    {
        return _prev;
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    inline byte* Chunk::buffer()
    {
        return _buffer;
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    inline byte* Chunk::data()
    {
        dbgAssert(_begin <= bufferSize());
        dbgAssert(_begin <= _end);

        return &_buffer[_begin];
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    inline Chunk* Chunk::next()
    {
        return _next;
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    inline Chunk* Chunk::prev()
    {
        return _prev;
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    inline uint16 Chunk::begin() const
    {
        return _begin;
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    inline uint16 Chunk::end() const
    {
        return _end;
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    inline void Chunk::setNext(Chunk* next)
    {
        _next = next;
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    inline void Chunk::setPrev(Chunk* prev)
    {
        _prev = prev;
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    inline void Chunk::setBegin(uint16 begin)
    {
        dbgAssert(_begin <= bufferSize());
        dbgAssert(_end <= bufferSize());
        dbgAssert(_begin <= _end);

        dbgAssert(begin <= bufferSize());
        dbgAssert(begin <= _end);
        _begin = begin;
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    inline void Chunk::setEnd(uint16 end)
    {
        dbgAssert(_begin <= bufferSize());
        dbgAssert(_end <= bufferSize());
        dbgAssert(_begin <= _end);

        dbgAssert(end <= bufferSize());
        dbgAssert(_begin <= end);
        _end = end;
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    inline void Chunk::setBeginEnd(uint16 begin, uint16 end)
    {
        dbgAssert(_begin <= bufferSize());
        dbgAssert(_end <= bufferSize());
        dbgAssert(_begin <= _end);

        dbgAssert(begin <= bufferSize());
        dbgAssert(end <= bufferSize());
        dbgAssert(begin <= end);
        _begin = begin;
        _end = end;
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    inline bool Chunk::consistent() const
    {
        if(_begin > bufferSize())
        {
            dbgAssert(false);
            return false;
        }

        if(_end > bufferSize())
        {
            dbgAssert(false);
            return false;
        }

        if(_begin >= _end)
        {
            dbgAssert(false);
            return false;
        }

        if(_prev)
        {
            if(this != _prev->next())
            {
                dbgAssert(false);
                return false;
            }
        }

        if(_next)
        {
            if(this != _next->prev())
            {
                dbgAssert(false);
                return false;
            }
        }

        return true;
    }

}
