#include <bits/stdc++.h>
using namespace std;

struct DFA
{


    vector<int> build_lps(string s)
    {
        int n=s.length();
        vector<int> lps(n,0);

        for(int i=1;i<n;i++)
        {
            int j = lps[i-1];
            while(j>0 && s[i]!=s[j])
            {
                j=lps[j-1];
            }
            if(s[i]==s[j])j++;
            lps[i]=j;
        }
        return lps;
    }

    int get_index(vector<int> lps, int state, int letter, string s)
    {
        if(state==0)return 0;
        int j=lps[state-1];
        while(j>0 && s[j]-'a'!=letter)
        {
            j=lps[j-1];
        }
        if(s[j]-'a'==letter)j++;
        return j;
    }

    vector< vector<int> > get_table(string s)
    {
        int n=s.length();
        auto lps=build_lps(s);
        vector< vector<int> > table(n+1, vector<int> (30,0) );


        for(int i=0;i<=n;i++)
        {
            int now=s[i]-'a';
            for(int j=0;j<26;j++)
            {
                if(j==now)
                {
                    table[i][j]=i+1;
                }
                else
                {
                    table[i][j]= get_index(lps, i, j, s);
                }
            }
        }

        return table;

    }

    string pattern="";
    int patter_length;
    vector< vector<int> > table = {};

    DFA(string s)
    {
        pattern=s;
        patter_length=s.length();
        table=get_table(pattern);
    }



    void get_matches(string text)
    {
        int n=text.length();
        int state=0;
        for(int i=0;i<n;i++)
        {
            state=table[state][text[i]-'a'];
            if(state==patter_length)
            {
                cout<<i-patter_length+1<<endl;
            }
        }
    }


};

int main()
{
    DFA dfa("aha");

    dfa.get_matches("ahahahahahahahaaaaaaahaha");


}









