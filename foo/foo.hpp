#pragma once

#include "foo_export.hpp"

namespace foo
{

#ifdef __cplusplus
extern "C" {
#endif

class FOO_API Foo
{
public:

    virtual ~Foo()
    {

    }

    virtual void doIt() = 0;

};

// If you want to use CreateFoo() in C language, change Foo* to void*,
// or change the definition of Foo to struct so that Foo has no member functions.
FOO_API Foo* __stdcall CreateFoo(void);

FOO_API void __stdcall ReleaseFoo(Foo* foo);

// Execute Foo::doIt().
// This function exists to avoid the possibility of losing ABI compatibility
// and not being able to call virtual functions due to different compiler versions.
FOO_API void __stdcall Foo_doIt(Foo* foo);

#ifdef __cplusplus
} // extern "C"
#endif

} // namespace foo
