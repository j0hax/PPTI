/**
 * Main file for the test exam
 * @file main.cpp
 */

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cassert>

/**
 * Helper function
 * @returns Zero value of Container element type
 */
template<typename Container> typename Container::value_type zeroValue() 
{ return typename Container::value_type{}; }

/**
 * @brief The Number class
 */
class Number
{
private:
    const unsigned data;
public:
    Number(const unsigned d);
    unsigned getNumber() const { return data; }
};

// TODO: Implement constructor for class Number

// TODO: Implement function calcSqrSum

/**
 * Sort by partitioning
 */
void sort(std::vector<unsigned>::iterator begin, std::vector<unsigned>::iterator end)
{
    // TODO: Implement sort using stable_partition
}

template<typename T>
std::ostream& print(std::ostream& os, const std::vector<T>& v)
{
    for(auto& elem: v)
        os<<elem<<" ";
    return os;
}

/**
 * Main function.
 */
int main()
{
    Number test(3);
    
    std::vector<unsigned> v { 7, 9, 4, 0, 5, 8, 1, 3, 6, 2, 10, 14, 12, 11};
    std::cout<<"SqrSum(v): " << calcSqrSum(v) << " (expected: 846)" << std::endl;
    assert(typeid(calcSqrSum(v)) == typeid(v[0]));
    std::vector<double> w { 0.5, 3.5, 0.5, 3.5, 0.5, 3.5};
    std::cout<<"SqrSum(w): " << calcSqrSum(w) << " (expected: 37.5)" << std::endl;
    assert(typeid(calcSqrSum(w)) == typeid(w[0]));
    
    sort(v.begin(), v.end());
    print(std::cout, v);
    std::cout << std::endl;

    return 0;
}
