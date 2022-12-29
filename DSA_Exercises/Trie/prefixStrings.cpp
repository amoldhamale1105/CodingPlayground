#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <ComplexObjectStream.hpp>

struct Node
{
    char ch;
    std::unordered_map<char, Node*> children;
    bool endOfWord;
    Node(const char& ch) : ch(ch), endOfWord(false) {}
};

class Trie
{
    Node* root;
    void recursiveSearch(Node* node, std::string str, std::vector<std::string>& prefixStrs)
    {
        for(auto itr = node->children.begin(); itr != node->children.end(); ++itr)
        {
            if (itr->second->endOfWord)
                prefixStrs.emplace_back(str+itr->first);
            recursiveSearch(itr->second, str+itr->first, prefixStrs);
        }
    }
public:
    Trie() : root(new Node('\0')) {}
    void insert(const std::string& data)
    {
        Node* node = root;
        for(char ch : data)
        {
            if (node->children.count(ch) == 0)
                node->children.insert({ch, new Node(ch)});
            node = node->children[ch];
        }
        node->endOfWord = true;
    }

    std::vector<std::string> prefixStrings(const std::string& prefix)
    {
        std::vector<std::string> prefixStrs;
        Node* node = root;

        for(char ch : prefix)
        {
            if (node->children.count(ch) == 0)
                return {};
            node = node->children[ch];
        }
        recursiveSearch(node, prefix, prefixStrs);

        return prefixStrs;
    }
};

std::vector<std::string> findPrefixStrings(const std::vector<std::string>& words, const std::string& prefix)
{
    Trie tr;
    std::vector<std::string> prefixStrs;
    
    for(const std::string& word : words)
    {
        tr.insert(word);
    }
    prefixStrs = tr.prefixStrings(prefix);
    std::sort(prefixStrs.begin(), prefixStrs.end());
    
    return prefixStrs;
}

int main(int argc, char** argv)
{
    if (argc < 2){
        std::cerr<<"Please enter prefix string as program arg."<<std::endl;
        return -1;
    }

    std::string prefix = argv[1];
    std::vector<std::string> words={"abc","abd","acde","abe","aeb","abba"};
    std::cout<<"words containing prefix \'"<<prefix<<"\' are: "<<findPrefixStrings(words, prefix)<<std::endl;
    return 0;
}