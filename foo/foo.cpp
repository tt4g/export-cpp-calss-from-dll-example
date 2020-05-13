#include "foo.hpp"

#include <iostream>
#include <string>
#include <utility>

namespace foo
{

class FooImpl : public foo::Foo
{
public:

    explicit FooImpl(std::string name)
            : name_(name)
    {

    }

    virtual ~FooImpl() override
    {

    }

    virtual void doIt() override
    {
        std::cout << std::string{"My name is "}.append(this->name_) << std::endl;
    }

private:

    std::string name_;

};

Foo* __stdcall CreateFoo(void)
{
    std::cout << "create FooImpl" << std::endl;

    return new FooImpl{"FooImpl"};
}

void __stdcall ReleaseFoo(Foo* foo)
{
    std::cout << "delete FooImpl" << std::endl;

    delete foo;
}

void __stdcall Foo_doIt(Foo* foo)
{
    foo->doIt();
}

} // namespace foo
