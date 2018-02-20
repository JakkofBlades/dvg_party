//******************************************************************************
// File:   noncopyable.hpp
// Author: Samuel Dahlberg
// Desc:   A noncopyable base class which can be inherited from.
//******************************************************************************
#ifndef _NONCOPYABLE_H_
#define _NONCOPYABLE_H_

struct NonCopyable
{
   NonCopyable() = default;
   NonCopyable& operator = (const NonCopyable&) = delete;
   NonCopyable(const NonCopyable&) = delete;
}

#endif
