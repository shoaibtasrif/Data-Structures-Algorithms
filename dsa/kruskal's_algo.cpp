#include<bits/stdc++.h>
using namespace std;

// it detects the minimum weighted edge while creating circle or not
// work with negative weight

//faster
#define faster                       \
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);                   \
    cout.tie(NULL);                  \
    cerr.tie(NULL);


vector<int> parent;

int get_parent(int x)
{
    if(x==parent[x])return x;
    parent[x]=get_parent(parent[x]);
    return parent[x];
}

void set_parent(int x, int par)
{
    if(x==parent[x])
    {
        parent[x]=par;
        return;
    }
    set_parent(parent[x], par);
    parent[x]=par;
}

struct edge
{
    int src,des,wet;
    edge(int x, int y, int z)
    {
        src=x;
        des=y;
        wet=z;
    }
};

bool comp(edge a, edge b)
{
    return a.wet<b.wet;
}

int main()
{
    faster;
    freopen("input.txt", "r", stdin);
    int n,m;
    cin>>n>>m;
    vector< edge > eges;

    for(int i=0; i<m; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        eges.emplace_back(x,y,z);
    }

    sort(eges.begin(), eges.end(), comp);

    parent.resize(n+1);
    for(int i=1; i<=n; i++)parent[i]=i;

    vector<edge> tree;
    int ans=0;

    for(auto [x,y,z]: eges )
    {
        int xp=get_parent(x), yp=get_parent(y);
        if(xp==yp)continue;
        ans+=z;
        tree.emplace_back(x,y,z);
        set_parent(y,xp);
    }

    cout<<ans<<endl;
    for(auto [x,y,z]: tree)
    {
        cout<<x<<" "<<y<<" "<<z<<endl;
    }

}

//c++ stl uses balanced binary search tree for set and map
// heap for priority queue

