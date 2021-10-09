#include <bits/stdc++.h>
using namespace std;

vector<int> build_lps(string s)
{

    int n=s.length();
    vector<int> lps(n+1,0);

    for(int i=1;i<n;i++)
    {
        int j= lps[i-1];
        while( j>0 && s[j]!=s[i])
        {
            j=lps[j-1];
        }

        if(s[j]==s[i])
        {
            lps[i]=j+1;
        }
        else
        {
            lps[i]=0;
        }
    }

    return lps;

}

int kmp_search(string text, string pat)
{
    vector<int> lps = build_lps(pat);
    int n=text.length(), m=pat.length();
    for(int i=0,j=0;i<n;i++)
    {
        while(j>0 && text[i]!=pat[j])
        {
            j=lps[j-1];
        }

        if(text[i]==pat[j])
        {
            j++;
        }

        if(j==m)
        {
            cout<<"found at "<<i-m+1<<endl;
            j=lps[m-1];
        }

    }
}


int main()
{
    string text= "ahahahahaha";
    string pat="haha";
    kmp_search(text, pat);

}
