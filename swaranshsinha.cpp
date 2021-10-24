//program to find the minimum number of painters required to paint a given number of boards in a given time

#include<bits/stdc++.h>
using namespace std;
bool isVALID(int *arr,int n,int k,int mid)
{
    int painter=1;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
        if(sum>mid)
        {
            painter++;
            sum=arr[i];
        }
        if(painter>k)
        return false;
    }
    return true;
}
int maxinarray(int *arr,int n)
{
    int max=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>=max)
        max=arr[i];
    }
    return max;
}
int sumofallarrayelements(int *arr,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
    }
    return sum;
}
int main()
{
    int n,k,ans;
    cout<<"ENTER NUMBER OF BOARDS: ";
    cin>>n;
    cout<<"ENTER NUMBER OF PAINTERS: ";
    cin>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"ENTER LENGTH OF BOARD "<<i+1<<" : ";
        cin>>arr[i];
    }
    if(k>n)
    printf("PAINTING NOT POSSIBLE");
    else
    {
        int start=maxinarray(arr,n),end=sumofallarrayelements(arr,n);
        while(start<=end)
        {
            int mid=start+((end-start)/2);
            if(isVALID(arr,n,k,mid))
            {
                ans=mid;
                end=mid-1;
            }
            else
            start=mid+1;
        }
        cout<<"THE MINIMUM TIME REQUIRED WILL BE: "<<ans<<"units";
    } 
}
