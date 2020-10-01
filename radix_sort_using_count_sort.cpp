#include<iostream>
#include<cmath>
using namespace std;

void csort10(int a[],int n,int d)
{
	int fr[10]={0};
	for(int i=0 ;i<n ;i++)
	{
		fr[(a[i]/d)%10]++;
	}
	for(int i=1 ;i<10 ;i++)
	fr[i]+=fr[i-1];
	
	int b[n];
	for(int i=n-1 ;i>=0 ;i--)
	{
		b[fr[(a[i]/d)%10]-1]=a[i];
		fr[(a[i]/d)%10]--;
	}
	
	for(int i=0 ;i<n;i++)
	a[i]=b[i];
	
//	for(int i=0 ;i<n ;i++)
//	cout<<a[i]<<" ";
	
// 	cout<<endl;
	
}

int getmaxdigits(int a[],int n)
{
	int maxa=a[0];
	for(int i=0 ;i<n ;i++)
	{
		if(a[i]>maxa)
		maxa=a[i];
	}
	int m=0;
	while(maxa>0)
	{
		maxa/=10;m++;
	}
	return m;
}

int main()
{
	int n;
	cin>>n;
  int a[n];
  int fr[10]={0},
	for(int i=0 ;i<n ;i++)
	cin>>a[i];
	
	int m=getmaxdigits(a,10);
	for(int i=0 ;i<m ;i++)
	{
		csort10(a,n,pow(10,i));
	}
	
	for(int i=0 ;i<n ;i++)
	cout<<a[i]<<" ";
	
}
