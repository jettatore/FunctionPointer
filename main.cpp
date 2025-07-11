#include <iostream>

// #include "A.h"
#include "B.h"

void foo(int number)
{
    printf("foo: %i\n", number);
}

template<typename Func>
void display(const int *a, size_t n, Func func)
{
    for(size_t indx = 0; indx < n; ++indx)
    {
        printf("%i ", func(a[indx]));
    }
    printf("\n");
}

int main()
{
    // std::function<void(int)>fun;
    // fun = &foo;    

    // auto test = std::bind(fun, std::placeholders::_3);
    // test(1, 2, 3, 4, 5, 6, 7);

    // B b;

    const size_t n = 5;
    int a[5] = {1, 2, 3, 4, 5};
    const size_t factor = 2;

    auto square = std::bind(std::multiplies<int>(), std::placeholders::_1, std::placeholders::_1);

    display(a, n, square);

    return 0;
}
