#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL fact[1009], infact[1009];
const LL mod=1e9+7;

LL powm(LL a, LL b,LL mod)
{
    // (a^b) %mod
    LL res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) %mod;
        a = (a * a) %mod;
        b >>= 1;
    }
    return res;
}

void cal_fact()
{
    infact[0]=fact[0]=1LL;
    for(LL i=1; i<=1000; i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
        infact[i]=powm(fact[i], mod-2, mod);
    }
}

LL nCr(LL n, LL r)
{
    if(r>n)return 0;
    LL res= (fact[n]*infact[r])%mod;
    res = (res *  infact[n-r] )%mod;
    return res;
}


LL nPr(LL n, LL r)
{
    return (fact[n]*infact[n-r])%mod;
}

int main()
{

}
