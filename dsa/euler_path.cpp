#include<bits/stdc++.h>
using namespace std;

// euler path - can traverse all the edge not visiting any edge more than once
// euler cycle - euler path starts and ends at the same node
// undirected graph
//

int main()
{
    freopen("input.txt", "r", stdin);
    int n,m;
    cin>>n>>m;
    vector<int> deg(n+1,0);
    vector<int> evod(2,0);

    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        evod[ deg[x]%2 ]--;
        evod[ deg[y]%2 ]--;
        deg[x]++;
        deg[y]++;
        evod[ deg[x]%2 ]++;
        evod[ deg[y]%2 ]++;
    }


    if(evod[1]==0)
    {
        cout<<"euler cycle\n";
    }
    else if(evod[1]<=2)
    {
        cout<<"euler path\n";
    }
    else
    {
        cout<<"not eulerian\m";
    }
}

/*
4 5
1 2
1 3
2 3
3 4
2 4
1 4
*/

