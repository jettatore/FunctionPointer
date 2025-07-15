#include "A.h"

class B
{
public:
    B()
    {
        a = new A(std::bind(&B::_boo, *this, std::placeholders::_1));
        a->a();
    }

private:
    A *a = nullptr;

    void _boo(int value)
    {
        printf("B::boo - %i\n", value);
    }

};
