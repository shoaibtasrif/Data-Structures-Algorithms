#include<bits/stdc++.h>
using namespace std;

/*
    trie is from the idea of bst of string
    bst of string works in O( m*log(n) ) where m is pattern length
    n is the number of words in which to be searched for
    when trie works in O(m)
*/

struct TrieNode
{
    TrieNode* child[26];
    bool isEndofWord=false;
    static vector<int> car;
    TrieNode()
    {
        for(int i=0;i<26;i++)child[i]=0;
    }

    void insert_(string s)
    {
        TrieNode* now=this;

        for(int i=0;i<s.length();i++)
        {
            int key=s[i]-'a';

            if(!now->child[key])
            {
                now->child[key]=new TrieNode;
            }
            now= now->child[key];
        }
        now->isEndofWord=true;
    }

    void print(string x)
    {
        if(isEndofWord)
        {
            cout<<x<<endl;
        }
        for(int i=0;i<26;i++)
        {
            if(child[i])
            {
                string y=x+(char)('a'+i);
                child[i]->print(y);
            }
        }

    }

    void delet(string x)
    {
        TrieNode* now=this;
        for(int i=0;i<x.length();i++)
        {
            int key=x[i]-'a';
            if(now->child[key])
            {
                now=now->child[key];
            }
            else
            {
                return;
            }
        }
        now->isEndofWord=false;
    }

    bool search_(string x)
    {
        TrieNode* now=this;
        for(int i=0;i<x.length();i++)
        {
            int key=x[i]-'a';
            if(now->child[key])
            {
                now=now->child[key];
            }
            else
            {
                return false;
            }
        }
        return now->isEndofWord;
    }
};

int main()
{
    TrieNode x;
    TrieNode y;
    x.insert_("aha");
    x.insert_("ban");
    x.insert_("banana");
    x.print("");
    x.delet("ban");
    x.print("");
    cout<<x.search_("anana");

}
