#include <iostream>
#include <algorithm>
#include <vector>

//#define A1
//#define A2
//#define A3
//#define A4
//#define A5
//#define A6

/* Teilaufgabe 1 */
// TODO: Write function alternateSum!

/* Teilaufgabe 2 */
// TODO: Write function sortIndirect!

/* Teilaufgabe 3 */
// TODO: Write function zip!

/* Teilaufgabe 4 */
// TODO: Write class LinearInterpolator!

/* Teilaufgabe 5 */
//Write function makeInterpolator!

/* Teilaufgabe 6 */
// TODO: Write class MultiInterpolator!

// Helper function for readable printing of pointers and pairs
template<typename T> std::ostream& print(std::ostream& os, const T& elem)  { return os<<elem; }
template<typename T> std::ostream& print(std::ostream& os, T*       elem)  { return (elem ? print(os, *elem) : os<<"null")<<"@"<<elem; }
template<typename T, typename V> 
std::ostream& print(std::ostream& os, const std::pair<T, V>& elem) 
{ return print(print(os << "{", elem.first)<<", ", elem.second)<<"}"; }

// Helper function for readable printing of ranges
template<typename Iter>
std::ostream& printRange(std::ostream& os, Iter begin, Iter end)
{
    if(begin == end)
        return os;
    print(os, *begin);
    while(++begin != end)
        print(os<<", ", *begin);
    return os;
}

int main()
{
    std::vector<int> vi = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    printRange(std::cout<<"vi: ", vi.begin(), vi.end())<<"\n";
    
#ifdef A1
    // TODO: Use the following code when alternateSum has been implemented
    std::cout<<"alternateSum(vi): "<<alternateSum(vi)<<" should be: "<< -5 <<"\n";
#endif

#ifdef A2
    // TODO: Use the following code when sortIndirect has been implemented
    std::vector<int*> pvi;
    for(auto& i: vi)
        pvi.push_back(&i);
    printRange(std::cout<<"pvi: ", pvi.begin(), pvi.end())<<"\n";
    sortIndirect(pvi.begin(), pvi.end(), [](int a, int b) { return a > b; });
    printRange(std::cout<<"pvi(sorted): ", pvi.begin(), pvi.end())<<"\n";
#endif

#ifdef A3
    // TODO: Use the following code when zip has been implemented
    std::vector<double> vd = {0.0, 0.2, 0.4, 0.3, 0.9, 0.7, 0.1, 0.6, 0.0, 0.8 };
    std::vector<std::pair<int, double>> rv(vi.size());
    zip(vi.begin(), vi.end(), vd.begin(), rv.begin());
    printRange(std::cout<<"rv: ", rv.begin(), rv.end())<<"\n";
#endif

#ifdef A4
    // TODO: Use the following code when LinearInterpolator has been implemented
    LinearInterpolator li{2.0, 6.0};
    std::cout<<"Interpolating 2 to 6: \n";
    std::cout<<"\tAt 0.0: "<<li(0)<<"\n";
    std::cout<<"\tAt 0.25: "<<li(0.25)<<"\n";
    std::cout<<"\tAt 0.5: "<<li(0.5)<<"\n";
    std::cout<<"\tAt 0.6: "<<li(0.6)<<"\n";
    std::cout<<"\tAt 1.0: "<<li(1)<<"\n";
#endif

#ifdef A5
    // TODO: Use the following code when makeInterpolator has been implemented
    auto li2 = makeInterpolator(2.0, 6.0);
    std::cout<<"Interpolating 2 to 6: \n";
    std::cout<<"\tAt 0.0: "<<li2(0)<<"\n";
    std::cout<<"\tAt 0.25: "<<li2(0.25)<<"\n";
    std::cout<<"\tAt 0.5: "<<li2(0.5)<<"\n";
    std::cout<<"\tAt 0.6: "<<li2(0.6)<<"\n";
    std::cout<<"\tAt 1.0: "<<li2(1)<<"\n";
#endif

#ifdef A6
    // TODO: Use the following code when MultiInterpolator has been implemented
    MultiInterpolator mi;
    for(size_t x = 0; x < 10; ++x)
        mi.addValue(static_cast<double>(x), static_cast<double>((x * 13) % 11));
    std::cout<<"MI-Interpolation: \n";
    std::cout<<"\tAt -1: "<<mi(-1)<<"\n";
    std::cout<<"\tAt 0: "<<mi(0)<<"\n";
    std::cout<<"\tAt 2: "<<mi(2)<<"\n";
    std::cout<<"\tAt 4.6: "<<mi(4.6)<<"\n";
    std::cout<<"\tAt 10: "<<mi(10)<<"\n";
    std::cout<<"\tAt 9: "<<mi(9)<<"\n";
    std::cout<<"\tAt 7.2: "<<mi(7.2)<<"\n";
#endif
}
