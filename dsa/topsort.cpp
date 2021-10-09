#include<bits/stdc++.h>
using namespace std;

// works on directed acyclic graph DAG

vector<int> visited;
vector<int> ans;
vector< vector<int> > adm;

void dfs(int node)
{
    visited[node]=1;
    for(auto x: adm[node])
    {
        if(!visited[x])
        {
            dfs(x);
        }
    }
    ans.push_back( node );
}

int main()
{

    freopen("input.txt", "r", stdin);
    int n,m;
    cin>>n>>m;
    adm.resize(n+1);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adm[x].push_back(y);
    }

    visited.resize(n+1,0);


    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }

    reverse(ans.begin(), ans.end());

    for(auto x: ans)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}

/*
7 8
2 7
2 3
7 5
3 5
5 4
5 1
4 6
1 6
*/


