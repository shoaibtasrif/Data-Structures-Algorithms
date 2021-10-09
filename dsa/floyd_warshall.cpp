#include<bits/stdc++.h>
using namespace std;

// all pair shortest path
// O(v^3)
// dont work on negative cycle but on negative weight
// can detect negative cycle by negative self distance

vector< vector < int > > adm;
const int inf=1e9;

int main()
{
    freopen("input.txt", "r", stdin);
    int n,m;
    cin>>n>>m;
    adm.resize(n+1, vector<int> (n+1,inf) );
    for(int i=1;i<=n;i++)adm[i][i]=0;
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        adm[x][y]=z;
    }

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(adm[i][k]!=inf && adm[k][j]!=inf)
                {
                    adm[i][j]=min(adm[i][j], adm[i][k]+adm[k][j] );
                }
            }
        }
    }



    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<adm[i][j]<<" ";
        }
        cout<<endl;
    }
}
