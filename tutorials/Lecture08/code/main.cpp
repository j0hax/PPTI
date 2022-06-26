#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <forward_list>

//#define A1
//#define A2
//#define A3
//#define A4
//#define A5

/* Teilaufgabe 1 */
void removeFromVector(std::vector<int>& vi, int val)
{
    // TODO: Implement functionality!
}

/* Teilaufgabe 2 */
// TODO: Write function countSmaller!

/* Teilaufgabe 3 */
// TODO: Write function printAll!

/* Teilaufgabe 4 */
//TODO: Implement function avg_abs_difference for doubles here

/* Teilaufgabe 5 */
//TODO: Implement function avg_abs_difference as a template here

int main()
{
    std::vector<int> vi = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // TODO: Use the following code when removeFromVector has been implemented
#ifdef A1
    std::vector<int> rvi{1,2,0,4,0,0,7,0,9};
    removeFromVector(rvi, 0);
    for (auto& elem: rvi)
        std::cout << elem << " ";
    std::cout << std::endl;
#endif

    // TODO: use the following code when countSmaller has been Implemented
#ifdef A2
    std::cout<<"Smaller 5: "<<countSmaller(vi, 5)<<"\n";
#endif

    // TODO: use the following code when printAll has been Implemented
#ifdef A3
    printAll(vi, std::cout);    
#endif
    
    // TODO: Use the following code when avg_abs_difference has been implemented
#ifdef A4
    std::vector<double> vd{1,2,3,4,5,6,7,8,9,10};
    std::cout<<avg_abs_difference(vd.begin(), vd.end())<<std::endl;
#endif

    // TODO: Use the following code when template avg_abs_difference has been implemented
#ifdef A5
    std::cout<<avg_abs_difference(&vd.front(), &vd.back() + 1)<<std::endl;
    std::forward_list<int> fi{10, 5, 20, -10, 30, 50};
    std::cout<<avg_abs_difference(fi.begin(), fi.end())<<std::endl;
#endif
}
