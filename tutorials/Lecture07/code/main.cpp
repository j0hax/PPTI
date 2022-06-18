#include <iostream>
#include <algorithm>
#include <numeric>
#include <array>
#include <iterator>
#include <memory>
#include <forward_list>
#include <deque>
#include <list>

/* Exercise 1 */
void exploreVector(int n)
{
    // TODO: Implement exploreVector
}

/* Exercise 2 */
void loopVector(std::vector<int>& vi)
{
    auto iter = vi.begin();
    while (iter != vi.end())
    {
        if (*iter % 2)
        {
            iter = vi.insert(iter, *iter);
            iter += 2;
        }
        else
            iter = vi.erase(iter);
    }
#ifdef TEST
    for (auto& elem: vi)
        std::cout << elem << " ";
    std::cout << std::endl;
#endif
}

// TODO: Write template function loopContainer!

/* Exercise 3 */
// TODO: Write function removeFromVector!

int main()
{
    exploreVector(10000);
    
    std::vector<int> vi = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    loopVector(vi);

    // TODO: Use the following code when template loopContainer has been implemented
#if false
    std::vector<int> cv{1,2,3,4,5,6,7,8,9};
    loopContainer<std::vector<int>>(cv);
    std::deque<int> cd{1,2,3,4,5,6,7,8,9};
    loopContainer<std::deque<int>>(cd);
    std::list<int> cl{1,2,3,4,5,6,7,8,9};
    loopContainer<std::list<int>>(cl);
#endif

    // TODO: Use the following code when removeFromVector has been implemented
#if false
    std::vector<int> rvi{1,2,0,4,0,0,7,0,9};
    removeFromVector(rvi, 0);
    for (auto& elem: rvi)
        std::cout << elem << " ";
    std::cout << std::endl;
#endif 
    
    // TODO: Use the following code when Leaderboard has been implemented
#if false
    Leaderboard ld(5);
    std::vector<double> lv{7.0, 2.0, 4.0, 9.0, 1.0, 3.0, 4.0, 9.0};
    for(auto& elem: lv)
        ld.add(elem);
    size_t idx = 0;
    for(auto& elem: ld)
        std::cout<<"Place "<<++idx<<": "<<elem<<"\n";
#endif
}
