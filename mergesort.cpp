#include<bits/stdc++.h>
using namespace std;
// int count=0;
void merge(int *arr,int l,int mid,int r)
{
    int i=l;
    int j=mid+1;
    int k=l;
    int b[r-l+1];
    
    while(i<=mid and j<=r)
    {
        if(arr[i]<arr[j])
        {
            b[k]=arr[i];
            i++;
        }
        else{
            b[k]=arr[j];
            j++;
        }
        k++;
        // count++;
    }
    if(j>r)
    {
        while(i<=mid)
        {
            b[k]=arr[i];
            i++;
            k++;
            // count++;
        }
    }
    else{
        while(j<=r)
        {
            b[k]=arr[j];
            j++;
            k++;
            // count++;
        }
    }
    for(int i=l;i<=r;i++)
    {
        arr[i]=b[i];
    }
}

void merge_sort(int *arr,int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

int main(){
    int n;
    cout<<"enter number of elements"<<"\n";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    merge_sort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}