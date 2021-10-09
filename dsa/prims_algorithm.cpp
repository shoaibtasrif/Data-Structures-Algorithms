#include<bits/stdc++.h>
using namespace std;

// The idea of using key values is to pick the minimum weight edge from cut.
// works with negative weight

struct edge
{
    int src,des,wet;
    edge(int x,int y,int z)
    {
        src=x;
        des=y;
        wet=z;
    }
};

struct com
{
    bool operator()(edge a, edge b )
    {
        return a.wet>b.wet;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);

    int n,m;
    cin>>n>>m;

    vector<  vector< pair<int,int> > > adm(n+1)  ;

    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        adm[x].push_back( make_pair(y,w) );
        adm[y].push_back( make_pair(x,w) );
    }

    priority_queue< edge, vector<edge> , com>  pq;
    vector< edge > tree;
    set<int> taken;

    pq.push(edge(0,1,0));
    int ans=0;

    while(pq.size())
    {
        edge x=pq.top();
        pq.pop();

        int wt=x.wet, node=x.des, from=x.src;

        if(taken.count(node))continue;

        ans+=wt;
        if(from) tree.push_back(x);
        taken.insert(node);

        for(int i=0;i<adm[node].size();i++)
        {
            int nxt=adm[node][i].first;
            int w=adm[node][i].second;
            pq.push(edge(node,nxt,w));
        }

    }

    cout<<ans<<endl;

    for(auto [x,y,z]: tree)
    {
        cout<<x<<" "<<y<<" "<<z<<endl;
    }

}

/*
input

7 8
1 2 1
1 3 2
2 4 3
3 4 1
4 5 2
4 6 2
5 7 3
6 7 4

answer
11
*/
