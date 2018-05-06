#include "Trie.h"
#include <iostream>
#include <string>

int main()
{
    Trie t = Trie();

    std::string s1 = "abcd";
    std::string s2 = "wxyz";

    // std::cout << &s1[0] << std::endl;

    t.insert("abcd");
    t.display();

    // t.insert("abce");
    // t.insert("abc");
    // t.insert("wxyz");

    // t.display();

    return 0;
}