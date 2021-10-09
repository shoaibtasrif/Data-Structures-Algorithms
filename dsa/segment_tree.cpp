#include<bits/stdc++.h>
using namespace std;

const int inf=1e9;

struct st
{
    vector<int> car,tree;
    int n;
    st(vector<int> v)
    {
        n=v.size();
        car=v;
        tree.resize(n*2+10);
        build(0, 0, n-1);
        for(int i=0;i<n*2;i++)cout<<tree[i]<<" ";
        cout<<endl;
    }

    int build(int node, int lb, int ub)
    {

        if(lb==ub)
        {
            tree[node]=car[lb];
            return tree[node];
        }
        int mid=(lb+ub)/2;
        int mn1=build(node*2+1, lb, mid);
        int mn2=build(node*2+2, mid+1, ub);
        tree[node]=min(mn1,mn2);
        return tree[node];

    }

    int search_(int lq, int uq)
    {
        return search__(0, 0, n-1, lq, uq);
    }

    int search__(int node, int lb, int ub, int lq, int uq)
    {
        if(lq<=lb && ub<=uq)
        {
            return tree[node];
        }
        if(uq<lb || ub<lq)return inf;
        int mid=(lb+ub)/2;
        int mn1=search__(node*2+1, lb, mid, lq, uq );
        int mn2=search__(node*2+2, mid+1, ub, lq, uq);
        return min(mn1, mn2);
    }

};

int main()
{
    int n;
    cin>>n;

    vector<int> v(n);

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>v[i];
    }

    st st1(v);

    while(1)
    {
        int n,m,o;
        cin>>n;
        if(!n)break;
        cin>>m>>o;
        cout<<st1.search_(m,o)<<endl;
    }

}
