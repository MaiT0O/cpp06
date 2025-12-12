# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base *generate(void)
{
    int random = rand() % 3;

    std::cout << random << std::endl;
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch (...) {}

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch (...) {}

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch (...) {}
}

int main() {
    srand(time(NULL));

    Base* ptr = generate();

    identify(ptr);
    identify(*ptr);

    delete ptr;
}
