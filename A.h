#include <functional>

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
