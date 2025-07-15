class MyFunctor
{
public:
    MyFunctor(){}

    int operator()(int n)
    {
       printf("Functor: %d\n", n);
    }

private:

};
