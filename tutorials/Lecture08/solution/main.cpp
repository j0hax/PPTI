#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <forward_list>
#include <vector>

#define SOLUTION

/* Teilaufgabe 1 */
void removeFromVector(std::vector<int>& vi, int val)
{
    vi.erase(std::remove(vi.begin(), vi.end(), val), vi.end());
}

/* Teilaufgabe 2 */
size_t countSmaller(std::vector<int>& vd, int val)
{
    return static_cast<size_t>(std::count_if(vd.begin(), vd.end(), [val](int elem) { return elem < val; }));
}

/* Teilaufgabe 3 */
void printAll(const std::vector<int>& vi, std::ostream& os)
{
    bool first = true;
    std::for_each(vi.begin(), vi.end(), [&first, &os](int elem) 
    {
        if(!first)
            os<<", ";
        os<<elem;
        first = false;
    });
    os << "\n";
}

/* Teilaufgabe 4 */
double avg_abs_difference(const std::vector<double>::iterator begin, 
                          const std::vector<double>::iterator end)
{
    if(begin == end)
        return 0;
    double last = *begin;
    double result = std::accumulate(std::next(begin), end, 0.0, [&last](const double& accum, const double& elem)
        {
            double diff = (elem < last) ? last-elem : elem-last;
            last = elem;
            return accum + diff;
        });
    return result / static_cast<double>(std::distance(begin, end)-1);
}

/* Teilaufgabe 5 */
template<typename Iterator>
typename std::iterator_traits<Iterator>::value_type avg_abs_difference(Iterator begin, Iterator end)
{
    if(begin == end)
        return 0;
    using Type = typename std::iterator_traits<Iterator>::value_type;
    Type last = *begin;
    Type result = std::accumulate(std::next(begin), end, static_cast<Type>(0), [&last](const Type& accum, const Type& elem)
        {
            Type diff = (elem < last) ? last-elem : elem-last;
            last = elem;
            return accum + diff;
        });
    return result / static_cast<Type>(std::distance(begin, end)-1);
}

int main()
{
    std::vector<int> vi = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // TODO: Use the following code when removeFromVector has been implemented
    std::vector<int> rvi{1,2,0,4,0,0,7,0,9};
    removeFromVector(rvi, 0);
    for (auto& elem: rvi)
        std::cout << elem << " ";
    std::cout << std::endl;
    int x = 0;
    ([](auto i) { i += 5; })(x);
    std::cout<<x<<"\n";
    // TODO: use the following code when countSmaller has been Implemented
    std::cout<<"Smaller 5: "<<countSmaller(vi, 5)<<"\n";
    
    // TODO: use the following code when printAll has been Implemented
    printAll(vi, std::cout);    
    
    
    // TODO: Use the following code when avg_abs_difference has been implemented
    std::vector<double> vd{1,2,3,4,5,6,7,8,9,10};
    std::cout<<avg_abs_difference(vd.begin(), vd.end())<<std::endl;

    // TODO: Use the following code when template avg_abs_difference has been implemented
    std::cout<<avg_abs_difference(&vd.front(), &vd.back() + 1)<<std::endl;
    std::forward_list<int> fi{10, 5, 20, -10, 30, 50};
    std::cout<<avg_abs_difference(fi.begin(), fi.end())<<std::endl;
}
