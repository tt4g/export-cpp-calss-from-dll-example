#include "foo/foo.hpp"

#include <memory>

int main(int argc, char** argv)
{
    std::unique_ptr<foo::Foo, decltype(&foo::ReleaseFoo)> fooPtr{foo::CreateFoo(), &foo::ReleaseFoo};

    foo::Foo_doIt(fooPtr.get());

    return 0;
}
