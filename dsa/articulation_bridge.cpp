#include<bits/stdc++.h>
using namespace std;
vector< vector < int > > adm;
vector< int > visited, tim, low;
int timer;
vector< pair<int,int> > ans;

// undirected graph
// O(n+m)

void dfs(int node, int parent)
{
    visited[node]=1;
    tim[node]=timer++;
    low[node]=tim[node];
    for(int x: adm[node])
    {
        if(x==parent)continue;
        else if(visited[x])
        {
            low[node]=min(low[node], tim[x]);
        }
        else
        {
            dfs(x, node);
            low[node]=min(low[node], low[x]);
            if(low[x]>tim[node])
            {
                ans.push_back({node, x});
            }
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    adm.resize(n+1);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adm[x].push_back(y);
        adm[y].push_back(x);
    }
    const int inf=1e9;
    visited.resize(n+1,0);
    tim.resize(n+1);
    low.resize(n+1,inf );
    timer=1;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(i,0);
        }
    }

    for(auto [x,y]: ans)
    {
        cout<<x<<"-"<<y<<endl;
    }
}
