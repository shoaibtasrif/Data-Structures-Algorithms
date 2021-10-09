#include<bits/stdc++.h>
using namespace std;

// single source shortest path
// works on non-negative edge
// O(VlogV)

#define PII  pair<int,int>

struct edge
{
    int src=0, des=0, wet=0;
    edge(int x, int y, int z)
    {
        src=x;
        des=y;
        wet=z;
    }
};

struct comp
{
    bool operator()(edge a, edge b)
    {
        return a.wet>b.wet;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);

    int n,m,src;
    cin>>n>>m>>src;
    vector< vector< PII> > adm(n+1);
    for(int i=0; i<m; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        adm[x].push_back({y,z});
        adm[y].push_back({x,z});
    }

    priority_queue<edge, vector<edge>, comp> pq;
    set<int> taken;
    vector<int> parent(n+1,-1);
    const int inf=1e9;
    pq.push(edge(0,src,0));
    vector<int> ans(n+1);
    while(pq.size())
    {
        edge x=pq.top();
        pq.pop();
        int node=x.des;
        if(taken.count(node))continue;
        parent[node]=x.src;
        ans[node]=x.wet;
        taken.insert(node);
        int covered=x.wet;
        for(int i=0; i<adm[node].size(); i++)
        {
            int nxt=adm[node][i].first;
            int dur=adm[node][i].second;
            pq.push( edge(node,nxt,covered+dur) );
        }
    }

    for(int i=1; i<=n; i++)
    {
        if(i==src)continue;
        stack<int> st;
        for(int j=i; j>0; j=parent[j])
        {
            st.push(j);
        }
        cout<<ans[i]<<endl;
        while(st.size())
        {
            cout<<st.top()<<" ";
            st.pop();
        }
        cout<<endl;
    }
}

/*
4 4 1
1 2 1
1 3 2
2 4 2
3 4 0
*/
