#include <iostream>
#include <set>
#include <stdexcept>
#include <vector>
#include <cassert>
#include <memory>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>

//#define A1
//#define A2
//#define A3
//#define A4

struct Node 
{
public:
    Node():Node(' ', nullptr) {}
    Node(char cont, Node* p):children(), content(cont), endMarker(false), parent(p) {}
    Node* findChild(char c);
    void  findPossibleWords(std::string s, std::vector<std::string>& result) const;
    
    std::map<char,std::unique_ptr<Node>> children;
    char content;
    bool endMarker;
    Node* parent;
};

class Trie 
{
public:
    Trie();
    void addWord(const std::string& s);
    bool searchWord(const std::string& s) const;
    void deleteWord(const std::string& s);    
    std::vector<std::string> autoComplete(const std::string& s) const;
private:
    std::unique_ptr<Node> root;
    std::pair<Node*, size_t> lastPossibleNode(const std::string& s) const;
};

Trie::Trie(): root(std::make_unique<Node>())
{}

// ToDo: Add code here.

std::vector<std::string> filterAll(std::istream& is)
{
    std::vector<std::string> result;
    std::string str(std::istreambuf_iterator<char>{is}, {});    
    std::regex r("[a-zA-Z'\\-]+");
    auto begin = std::sregex_iterator(str.begin(), str.end(), r);
    auto end   = std::sregex_iterator();
    for(;begin != end; ++begin)
        result.push_back(begin->str());
    return result;
}

#ifdef A2
void testTrie(const Trie& trie, std::vector<std::string> words, std::vector<std::string> expected)
{
    for(const auto& a : words) 
    {
        std::string expect = std::find(expected.begin(), expected.end(), a) != expected.end() ? "found" : "not found";
        std::string status = trie.searchWord(a) ? "found" : "not found";
        std::cout<<a<<" "<<status<<", expected "<<expect<<std::endl;       
    }
}
#endif

#ifdef A4
void importFile(Trie& t, const std::string& s)
{
    std::string word;
    std::ifstream file (s);
    if(file.is_open())
    {
        std::vector<std::string> words = filterAll(file);
        file.close();
        for(auto& word : words )
            t.addWord(word);
        return;
    }
    std::cout<<"File not found."<<std::endl;
}

void testAutoComplete(const Trie& trie, std::string word, std::vector<std::string> expected)
{
    std::vector<std::string> found = trie.autoComplete(word);
    std::set<std::string> match;
    for(const auto& a : expected)
    {
        std::string status;
        auto iter = std::find(found.begin(), found.end(), a);
        if(iter != found.end())
        {
            status = "found";
            match.emplace(*iter);
        }else{
            status = "not found";
        }
        std::cout<<a<<" was "<<status<<std::endl;
        
    }
    for(const auto& x : found)
    {
        if(match.find(x)==match.end())
            std::cout<<x<<" was found but not expected."<<std::endl;
    }
}
#endif

int main(int argc, char **argv)
{
    std::vector<std::string> args(argv+1, argv+argc);
    std::vector<std::string> test   = {"Hallo","Baum","Ball","Haus","Maus","Ballon","Glas","Regenschirm","Stift"};
    std::vector<std::string> search = {"Hallo","Maus","Glas","Ball","Zoo","Haus","Regen"};
    std::vector<std::string> remove = {"Maus", "Glas","Ballon"};
    std::unique_ptr<Trie> trie  = std::make_unique<Trie>();
   
#ifdef A1    
    for(const auto & a : test)
        trie->addWord(a);
#endif

#ifdef A2
    std::cout<<"\n\nsearchWord:\n"<<std::endl;
    testTrie(*trie, search, {"Hallo", "Maus", "Glas", "Ball", "Haus"});
#endif

#ifdef A3    
    for(const auto& a  : remove)
        trie->deleteWord(a);
    std::cout<<"\n\ndeleteWord:\n"<<std::endl;
    testTrie(*trie, search, {"Hallo", "Ball", "Haus"});
#endif    
    
#ifdef A4
    std::cout<<"\n\n";
    std::unique_ptr<Trie> hamlet = std::make_unique<Trie>();
    if(args.size() < 1)
    {
        std::cout<<"\nPlease give a commandline argument\n";
        return -1;
    }
    importFile(*hamlet, args[0]);
    testAutoComplete(*hamlet,"you",{"you'l","young","yours","your","youth","you"});
#endif

    return 0;
}
