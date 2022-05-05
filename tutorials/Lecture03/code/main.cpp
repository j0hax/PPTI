#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

//#define A1
//#define A2
//#define A3

class RNG
{
private:
// ToDo: Add code here

public:
// ToDo: Add code here

    unsigned generateNumber()
    {
        // ToDo: Add code here
        return 0;  // ToDo: Change code here
    }

    unsigned generateUpTo(unsigned max)
    {
        unsigned long long maxRand = 0x100000000ull;
        unsigned long long defect  = maxRand % max;
        unsigned result = 0;
        do {
            result = this->generateNumber();
        } while(result >= maxRand - defect);
        return static_cast<unsigned>(result / (maxRand / max));
    }
};

// ToDo: Add Code here

#ifdef A3
std::tuple<unsigned, unsigned> calcExponents(RNG& rng, unsigned phi)
{
    unsigned encrypt = 0;
    do
    {
        encrypt = findPrime(rng, phi);
    } while((phi % encrypt) == 0);
        
    auto triple = advancedEuclid(encrypt, phi);
    unsigned decrypt = (static_cast<unsigned>(std::get<1>(triple))+phi)%phi;
    return std::make_tuple(encrypt, decrypt);
}
#endif

int main()
{
    #ifdef A1
    RNG rng(25234);
    std::cout << "Number               :" << rng.generateNumber()     << ", expected: " << 3222025 << "\n";
    std::cout << "Number up to 1337    :" << rng.generateUpTo(1337)   << ", expected: " << 128 << "\n\n";
    #endif
    
    #ifdef A2
    std::cout << std::boolalpha;
    std::cout << "4329⁶⁷⁸ mod 2376     :" << modPow(4329,678,2376)    << ", expected: " << 81 << "\n\n";
    std::cout << "523 is prim          :" << isPrime(523,400)         << ", expected: " << "true"<< "\n";
    std::cout << "65521 is prime       :" << isPrime(65521,400)       << ", expected: " << "true"<< "\n";
    std::cout << "8888 is prime        :" << isPrime(8888, 400)       << ", expected: " << "false"<< "\n\n";
    #endif 
    
    #ifdef A3
    RNG rng2(123462);
    RSA rsa(rng2);
    int a,b,c;
    std::tie(a,b,c) = advancedEuclid(412,36);
    std::cout << "encrypt 42           :" << rsa.encrypt(42)          << ", expected: " << 280 << "\n";
    std::cout << "decrypt 280          :" << rsa.decrypt(280)         << ", expected: " << 42 << "\n\n";
    std::cout << "extEuclid of 412 36  :" << a <<", "<<b<<", "<<c     << ", expected: " << 4 <<", "<<-2<<", "<<23<< "\n\n";
    #endif
    return 0;
}
