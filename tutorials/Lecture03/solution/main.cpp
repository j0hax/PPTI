#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

#define A1
#define A2
#define A3

class RNG
{
private:
    unsigned x;

public:
    RNG(unsigned x):x(x){}

    unsigned generateNumber()
    {
        this->x ^= this->x >> 13;
        this->x ^= this->x <<  7;
        this->x ^= this->x >> 17;
        return this->x;
    }

    unsigned generateUpTo(unsigned max)
    {
        unsigned long long maxRand = 0x100000000ull;
        unsigned long long defect  = maxRand % max;
        unsigned result = 0;
        do
        {
            result = this->generateNumber();
        } while(result >= maxRand - defect);
        return static_cast<unsigned>(result / (maxRand / max));
    }
};

unsigned modPow(unsigned a, unsigned b, unsigned n)
{
    unsigned x = 1;
    for(; b; b/=2)
    {
        if(b & 1)
            x = (x*a)%n;
        a = (a*a)%n;
    }
    return x;
}

bool fermatTest(unsigned p, unsigned a)
{
    if(a<2)
        return true;
    const unsigned x = modPow(a, p-1, p);
    return x == 1;
}

bool isPrime(unsigned p, unsigned iterations)
{
    RNG rng(78265893u);
    if(p<2)
        return false;
    for(unsigned i=0; i<iterations; ++i)
    {
        if(!fermatTest(p, rng.generateUpTo(p)))
            return false;
    }
    return true;
}

std::tuple<int, int, int> advancedEuclid(unsigned x, unsigned y)
{
    int s = 1;
    int t = 0;
    int u = 0;
    int v = 1;
    while(y != 0)
    {
        int q = static_cast<int>(x / y);
        std::tie(s, t, u, v) = std::make_tuple(u, v, s - q*u, t - q*v);
        std::tie(x, y)       = std::make_tuple(y, x % y);
    }
    return {x, s, t};
}

unsigned findPrime(RNG& rng, unsigned n)
{
    unsigned candidate = 1;
    while(!(isPrime(candidate, 400)))
        candidate = rng.generateUpTo(n);
    return candidate;
}

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
    
class RSA
{
private:    
    unsigned decryptexp;
public:
    unsigned encryptexp;
    unsigned rsamodul;
    RSA(RNG& rng): decryptexp(0), encryptexp(0), rsamodul(0)
    {
        unsigned p1 = findPrime(rng, 255);
        unsigned p2 = p1;
        while(p1 == p2 || p1*p2 < 256)
            p2 = findPrime(rng, 255);
        this->rsamodul   = p1 * p2;        
        unsigned phi = (p1-1)*(p2-1);
        std::tie(this->encryptexp, this->decryptexp) = calcExponents(rng, phi);
    }

    unsigned encrypt(unsigned m) const
    {
        return modPow(m, this->encryptexp, this->rsamodul);
    }

    unsigned decrypt(unsigned c) const
    {
        return static_cast<unsigned>(modPow(c, this->decryptexp, this->rsamodul));
    }
};

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
