#include <iostream>
#include <functional>

//class B;

class A
{
public:
    // A(void(*f)(int a))
    // {
    //     fa = f;
    // };
    // ~A(){};

    // void(*fa)(int a);   
    
    // A(void(B::*f)(int i) const, const B & b)
    // {
    //     std::cout << "f ";
    //     fa = f;
    //     faa(b);
    // }

    A(std::function<void(int i)>f)
    {
        std::cout << "ctor: A\n";
        faf = f;
        faf(789);
    }
    
    ~A() {
        std::cout << "dctor: A\n";
    }

    // void(B::*fa)(int i) const;
    std::function<void(int i)>faf;

    // void faa(const B & obj)
    // {
    //     (obj.*fa)(123);
    // }

    void faaf()
    {
        faf(456);
    }

};

class B
{
public:
    // B(void(*f)(int a)) : a(f)
    // {};
    // B() : a(&B::boo, *this)
    // {
        
    // };

    B()// : a(std::bind(&B::boo, *this, std::placeholders::_1))
    {
        std::cout << "+++" << std::endl;
        a = new A(std::bind(&B::boo, *this, std::placeholders::_1));
        std::cout << "---" << std::endl;
    };

    ~B() { delete a; };

    A* a = nullptr;

    static void foo(int i);

private:
    void boo(int i) const;    
};

void B::boo(int i) const
{
     std::cout << "B::boo: " << i << std::endl;
}

void B::foo(int i)
{
    std::cout << "B::foo, " << i << std::endl;
}

int main()
{
    B b;
    A a(b.foo);
    
    return 0;
}
