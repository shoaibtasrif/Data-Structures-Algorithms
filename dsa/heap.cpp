#include<bits/stdc++.h>
using namespace std;

struct heap
{
    int car[100];
    int n=0;
    bool (*comp)(int,int);

    heap( bool (*func)(int,int) )
    {
        comp=func;
    }

    void push_(int x)
    {
        car[n++]=x;
        for(int i=n-1,par;i>0 ; i=par )
        {
            par=(i-1)/2;
            if( comp(car[par], car[i]) )
            {
                int tmp=car[par];
                car[par]=car[i];
                car[i]=tmp;
            }
            else
                break;
        }

        //for(int i=0;i<n;i++)cout<<car[i]<<" ";
        //cout<<endl;
    }

    int pop_()
    {
        int ret=car[0];
        car[0]=car[n-1];
        n--;
        for(int i=0,lc,rc,oc;i<n/2;)
        {
            lc=i*2+1;
            rc=i*2+2;

            if(rc<n)
            {
                if(comp(car[rc],car[lc]))
                {
                    oc=lc;
                }
                else
                {
                    oc=rc;
                }
            }
            else
                oc=lc;

            if( comp(car[i],car[oc]) )
            {
                int aha=car[oc];
                car[oc]=car[i];
                car[i]=aha;
                i=oc;
            }
            else
                break;
        }
        //for(int i=0;i<n;i++)cout<<car[i]<<" ";
        //cout<<endl;
        return ret;
    }

    int top_()
    {
        return car[0];
    }

    int size_()
    {
        return n;
    }

};

bool comp(int a,int b)
{
    return a>b;
}

int main()
{
    heap x(comp);
    x.push_(2);
    x.push_(1);
    x.push_(3);
    x.push_(9);
    x.push_(6);
    x.push_(8);

    while(x.size_())
    {
        cout<<x.pop_()<<endl;
    }


}
