#include <iostream>

using namespace std;

int main()
{ int n=0,i=0,max=0;
    cout<<"\t\tProgram on Bubble sort";
    cout<<"\nEnter the size of array : ";cin>>n;
    int a[n];
    cout<<"Enter the array elements :\n";
    for(i=0;i<n;i++)
    {cin>>a[i];}
    int j=0;
    max=0;
    for(i=0;i<n;i++)
    {
        {
            for(j=0;j<n-i-1;j++)
            {if(a[j]>a[j+1])
            {
                max=a[j];
                a[j]=a[j+1];
                a[j+1]=max;
            }}
        }
        
    }
    cout<<"Sorted Element are :";
   for(i=0;i<n;i++)
   {cout<<a[i];}
    
        return 0;
    }

  
