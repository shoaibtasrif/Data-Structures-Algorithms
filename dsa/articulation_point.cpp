#include<bits/stdc++.h>
using namespace std;
vector< vector< int> > adm;
vector<int> visited, low, tim;
int timer;
set<int> ans;




void dfs(int node, int parent)
{
    //cout<<node<<"a\n";
    visited[node]=1;
    tim[node]=timer++;
    low[node]=tim[node];
    int child=0;
    for(int x: adm[node])
    {
        if(x==parent)continue;
        else if(visited[x])
        {
            low[node]=min(low[node],tim[x]);
        }
        else
        {
            child++;
            dfs(x,node);
            low[node]= min(low[node], low[x]);
            if(low[x]>=tim[node] && parent)
            {
                ans.insert(node);
            }

        }
    }

    if(!parent && child>1)
    {
        ans.insert(node);
    }
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
        adm[y].push_back(x);
    }
    visited.resize(n+1,0);
    const int inf = 1e9;
    low.resize(n+1, inf);
    tim.resize(n+1);
    timer=1;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(i,0);
        }
    }

    for(int x: ans)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}


/*
7 8
1 2
1 3
2 4
3 4
4 5
6 4
7 6
7 5
answer 4
*/
