#include<bits/stdc++.h>
using namespace std;

//average nlog2(n)
// worst n^2

void print(vector<int> a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void quicksort(vector<int>& a, int low, int high)
{
    if(low>=high)return;
    int pivot=low;
    int lm=low+1, rm=high;
    for(;lm<rm;)
    {
        while(lm<=high &&  a[lm] <= a[pivot] )lm++;
        while(rm>pivot && a[pivot] < a[rm] )rm--;
        if(lm<rm)
        {
            int tmp=a[lm];
            a[lm]=a[rm];
            a[rm]=tmp;
        }
    }
    int tmp=a[rm];
    a[rm]=a[pivot];
    a[pivot]=tmp;
    quicksort(a,low,rm-1);
    quicksort(a,rm+1,high);
}

int main()
{
    vector<int> ara={1,3,2,6,2,4,8,4,1,6,80,9};
    quicksort(ara ,0,ara.size()-1);
    print(ara);
}
