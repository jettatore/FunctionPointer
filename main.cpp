#include <iostream>
#include <functional>

void foo(int number)
{
    printf("foo: %i\n", number);
}

void boo()
{
    printf("boo!!!\n");
}

class A
{
    public:
    A(std::function<void(int)> fun)
    {
        funA = fun;        
    }

    void setFun(void(*fun)(int))
    {
        funA = fun;
    }

    void a()
    {
        funA(555);
    }

    private:
    std::function<void(int)> funA;

};

int main()
{
    std::function<void(int)>fun;
    fun = &foo;

    

    auto test = std::bind(fun, std::placeholders::_2);
    test(2, 666);

    return 0;   
}
