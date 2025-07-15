#include <string>

class SimpleFunctor
{
public:
    SimpleFunctor(const std::string &name) :
        _name(name)
    {}

    void operator()()
    {
        printf("Name: %s\n", _name.c_str());
    }

private:
    std::string _name;

};
