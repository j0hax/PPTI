#include <iostream>
#include <algorithm>
#include <numeric>
#include <array>
#include <iterator>
#include <memory>
#include <forward_list>
#include <deque>
#include <list>
#include <vector>
#define SOLUTION
#define TEST

/* Exercise 1 */
void exploreVector(int n)
{
#ifdef SOLUTION
    std::vector<int> vec;
    size_t oldCapacity = 0;
    for (int i = 1; i <= n; ++i)
    {
        vec.push_back(i);
        if (vec.capacity() != oldCapacity)
        {
            std::cout << "number of elements: " << i<<" "
                  << "size: " << vec.size()<<" "
                      << "capacity: " << vec.capacity()
                  << std::endl;
            oldCapacity = vec.capacity();
        }
    }
#endif
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

#ifdef SOLUTION
template<typename Container>
void loopContainer(Container& c)
{
    auto iter = c.begin();
    while (iter != c.end())
    {
        if (*iter % 2)
        {
            iter = c.insert(iter, *iter);
            std::advance(iter, 2);
        }
        else
            iter = c.erase(iter);
    }
#ifdef TEST
    for (auto& elem: c)
        std::cout << elem << " ";
    std::cout << std::endl;
#endif
}
#else
// TODO: Write template function loopContainer!
#endif

/* Exercise 3 */
#ifdef SOLUTION
void removeFromVector(std::vector<int>& vi, int val)
{
    size_t n = 0;
    for(int& elem: vi)
    {
        if(elem != val)
            vi[n++] = elem;
    }
    vi.resize(n);
}
#else
// TODO: Write function removeFromVector!
#endif

#ifdef SOLUTION
class Leaderboard
{
private:
    using Entry     = double;
    using Container = std::vector<Entry>;
    Container Data;
    size_t      MaxLength;
public:
    Leaderboard(size_t maxLength):  Data(), MaxLength(maxLength) {}
    
    void add(Entry value)
    {
        auto position = std::lower_bound(this->Data.rbegin(), this->Data.rend(), value).base();
        if(this->Data.size() >= MaxLength)
        {
            if(position != this->Data.end())
            {
                #if false
                this->Data.back() = value;
                std::rotate(position, this->Data.end() - 1, this->Data.end());
                #else
                this->Data.pop_back();
                this->Data.insert(position, value);
                #endif
            }
            else
            {}//Do nothing since value is after end of queue

        }
        else
            this->Data.insert(position, value);
    }
    Container::const_iterator begin() const { return this->Data.begin(); }
    Container::const_iterator end()   const { return this->Data.end(); }
};
#endif

int main()
{
    exploreVector(10000);

    std::vector<int> vi = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    loopVector(vi);

    // TODO: Use the following code when template loopContainer has been implemented
    std::vector<int> cv{1,2,3,4,5,6,7,8,9};
    loopContainer<std::vector<int>>(cv);
    std::deque<int> cd{1,2,3,4,5,6,7,8,9};
    loopContainer<std::deque<int>>(cd);
    std::list<int> cl{1,2,3,4,5,6,7,8,9};
    loopContainer<std::list<int>>(cl);

    // TODO: Use the following code when removeFromVector has been implemented
    std::vector<int> rvi{1,2,0,4,0,0,7,0,9};
    removeFromVector(rvi, 0);
    for (auto& elem: rvi)
        std::cout << elem << " ";
    std::cout << std::endl;
    
    // TODO: Use the following code when Leaderboard has been implemented
    Leaderboard ld(5);
    std::vector<double> lv{7.0, 2.0, 4.0, 9.0, 1.0, 3.0, 4.0, 10.0};
    for(auto& elem: lv)
        ld.add(elem);
    size_t idx = 0;
    for(auto& elem: ld)
        std::cout<<"Place "<<++idx<<": "<<elem<<"\n";
}
