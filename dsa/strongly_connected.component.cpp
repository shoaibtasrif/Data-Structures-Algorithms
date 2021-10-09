#include<bits/stdc++.h>
using namespace std;
vector< vector<int> > adm,radm;
vector<int> sorted;
set<int> visited;

void dfs1(int node)
{
    visited.insert(node);
    for(auto x: adm[node])
    {
        if(!visited.count(x))
        {
            dfs1(x);
        }
    }
    sorted.push_back(node);
}

void dfs2(int node)
{
    cout<<node<<" ";
    visited.insert(node);
    for(auto x: radm[node])
    {
        if(!visited.count(x))
        {
            dfs2(x);
        }
    }
}

int main()
{

    freopen("input.txt", "r", stdin);
    int n,m;
    cin>>n>>m;
    adm.resize(n+1);
    radm.resize(n+1);

    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adm[x].push_back(y);
        radm[y].push_back(x);
    }

    for(int i=1;i<=n;i++)
    {
        if(!visited.count(i))
        {
            dfs1(i);
        }
    }

    visited.clear();

    reverse(sorted.begin(), sorted.end());

    for(auto node: sorted)
    {
        if(!visited.count(node))
        {
            dfs2(node);
            cout<<endl;
        }

    }


}

/*
5 5
1 2
1 3
2 4
3 5
5 1
*/
