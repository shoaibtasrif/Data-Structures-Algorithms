#include<bits/stdc++.h>
using namespace std;
// single source shortest path on directed graph
// works on negative edge
// can detect negative cycle, but doesnt work on negative cycle
// O(VE)
struct edge
{
    int src,des,weight;
    edge(int x,int y,int z)
    {
        src=x;
        des=y;
        weight=z;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    vector<edge> edges;
    int n,m,src;
    cin>>n>>m>>src;
    for(int i=0; i<m; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        edges.emplace_back(x,y,z);
    }

    const int inf=1e9;
    vector<int>dis(n+1, inf);
    dis[src]=0;

    for(int j=1; j<n ; j++)
    {
        for(int i=0; i<edges.size(); i++)
        {
            int src=edges[i].src;
            int des=edges[i].des;
            int weight=edges[i].weight;

            if(dis[src]!=inf && dis[des]>dis[src]+weight)
            {
                dis[des]=dis[src]+weight;
            }
        }
    }

    for(int i=1; i<=n; i++)cout<<dis[i]<<" ";
    cout<<endl;

    for(int i=0; i<edges.size(); i++)
    {
        int src=edges[i].src;
        int des=edges[i].des;
        int weight=edges[i].weight;

        if(dis[src]!=inf && dis[des]>dis[src]+weight)
        {
            cout<<"negative cycle\n";
        }
    }
}





/*
5 8 1
1 2 -1
1 3 4
2 3 3
2 4 2
2 5 2
4 2 1
4 3 5
5 4 -5
*/
