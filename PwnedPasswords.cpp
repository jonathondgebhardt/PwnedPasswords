#include "Trie.h"
#include <iostream>
#include <string>

int main()
{
    Trie t = Trie();

    std::string s1 = "MooGoo";
    std::string s2 = "JooGoo";

    t.insert(s1);
    // t.insert(s2);

    return 0;
}