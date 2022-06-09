#include <iostream>
#include <random>

//#define A1
//#define A2
//#define A3
//#define A4

std::random_device rd{};

// TODO (A1, A2): Dice

// TODO (A3, A4): AccumulatedDice

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
