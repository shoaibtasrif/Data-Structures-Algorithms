#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> bit;

void update(int lb, int ub, int val)
{
    while(lb<=n)
    {
        bit[lb]+=val;
        lb+= lb & (-lb);
    }
    ub++;
    while(ub<=n)
    {
        bit[ub]-=val;
        ub+= ub & (-ub);
    }
}

int getval(int index)
{
    int sum=0;
    while(index>0)
    {
        sum += bit[index];
        index -= index &(-index);
    }
    return sum;
}

int main()
{
    freopen("input.txt", "r", stdin);

    cin>>n>>m;

    bit.resize(n+10, 0);

    for(int i=0; i<m; i++)
    {
        int x,y;
        cin>>x;
        if(x==1)
        {
            int lb,ub,val;
            cin>>lb>>ub>>val;
            update(lb, ub, val);
        }
        else
        {
            int index;
            cin>>index;
            cout<<"res "<<getval(index)<<endl;
        }
    }
}

/*

10
5
1 1 3 3
1 3 7 2
1 5 10 1
2 6
2 3

*/
