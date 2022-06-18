#include <iostream>
#include <random>
#define SOLUTION

#ifdef SOLUTION 
#define A1
#define A2
#define A3
#define A4
#else
//#define A1
//#define A2
//#define A3
//#define A4
#endif

std::random_device rd{};

#ifdef SOLUTION
class Dice
{
private:
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution;
public:
    Dice(int s): generator(rd()), distribution(1, s) {}
    
    int roll()
    {
        return this->distribution(this->generator);
    }
    friend std::ostream& operator<<(std::ostream& os, const Dice& d)
    {
        return os << "d"<<d.distribution.max();
    }
};

template<typename D1, typename D2>
class AccumulatedDice
{
private:
    D1 a;
    D2 b;
public:
    AccumulatedDice(D1 a, D2 b): a(std::move(a)), b(std::move(b)) {}
    int roll() 
    {
        return a.roll() + b.roll();
    }
    friend std::ostream& operator<<(std::ostream& os, const AccumulatedDice& d)
    {
        return os << d.a <<"+" << d.b;
    }
};
#endif

int main()
{
    size_t count = 20;

#ifdef A1
    Dice d6(6);
    std::cout<<"d6 Rolls: ";
    for(size_t i = 0; i < count; ++i)
        std::cout<<d6.roll()<<" ";
    std::cout<<"\n";
    Dice d10(10);
    std::cout<<"d10 Rolls: ";
    for(size_t i = 0; i < count; ++i)
        std::cout<<d10.roll()<<" ";
    std::cout<<"\n";
#endif

#ifdef A2
    std::cout<<d6<<" expected: \'d6\'\n";
    std::cout<<d10<<" expected: \'d10\'\n";
#endif

#ifdef A3
    AccumulatedDice<Dice, Dice> d6d6(Dice(6), Dice(6));
    std::cout<<"d6+d6 Rolls: ";
    for(size_t i = 0; i < count; ++i)
        std::cout<<d6d6.roll()<<" ";
    std::cout<<"\n";
#endif

#ifdef A4
    std::cout<<d6d6<<" expected: \'d6+d6\'\n";
    AccumulatedDice<AccumulatedDice<Dice, Dice>, Dice> complex{{6,8},10};
    std::cout<<complex<<" expected: \'d6+d8+d10\'\n";
#endif
}
