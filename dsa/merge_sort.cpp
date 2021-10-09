#include<bits/stdc++.h>
using namespace std;

// nlog2(n)

void print(vector<int> a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void sort__(vector<int>& a, int low, int high)
{
    if(low>=high)return ;
    int mid= (low+high)/2;
    sort__(a,low,mid);
    sort__(a,mid+1,high);
    vector<int> tmp(high-low+1);
    for(int i=0,j=low,k=mid+1;i<tmp.size();)
    {
        if(j<=mid)
        {
            if(k<=high)
            {
                if(a[j]<=a[k])tmp[i++]=a[j++];
                else tmp[i++]=a[k++];
            }
            else
            {
                tmp[i++]=a[j++];
            }
        }
        else
        {
            tmp[i++]=a[k++];
        }
    }
    for(int i=0,j=low;j<=high;i++,j++)a[j]=tmp[i];

}

void merge_sort(vector<int>& a)
{
    int n=a.size();
    sort__(a,0,n-1);
    return ;

}

int main()
{

    vector<int> arra={3,1,2,5,1,0,4,2,7,4,6};
    merge_sort(arra);

    for(int i=0;i<arra.size();i++)cout<<arra[i]<<" ";

}
