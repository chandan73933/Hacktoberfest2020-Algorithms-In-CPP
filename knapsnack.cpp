#include<bits/stdc++.h>
using namespace std;
int max(int a, int b)
{
    return (a > b) ? a : b;
}


int knap(int wt[],int pro[],int n,int w)
{
	int k[n+1][w+1];
	for(int j=0;j<=w;j++)
	{
		k[0][j]=0;
	}

	for(int i=0;i<=n;i++)
	{
		k[i][0]=0;
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=w;j++)
		{
			if(wt[i-1]>j)
			{
				k[i][j]=k[i-1][j];
			}
			else
			{
				k[i][j]= max(pro[i - 1] + k[i - 1][j - wt[i - 1]], k[i - 1][j]);
			}
		}
	}

	int inc[n];
	int i=n;int s=w;
	int j=0;
	while(i>0 || s>0)
	{
		if(s>0 && k[i][s]!=k[i-1][s])
		{
			inc[j]=i;
			j++;
			i--;
			s=s-wt[i];
		}
		else
		{
			i=i-1;
		}
	}

	cout<<"The elements which are included in Knapsnack are : "<<endl;
	for(int i=0;i<j;i++)
	{
		cout<<inc[i]<<" ";
	}
	cout<<"\n"<<"Total value of Knapsnack: ";
	return k[n][w];
} 


int main()
{
	int n,w;
	cout<<"enter the number of items in knapsnack:"<<endl;
	cin>>n;
	cout<<"enter the maximum weight of knapsnack:"<<endl;
	cin>>w;
	int wt[n],pro[n];
	for(int i=0;i<n;i++)
	{
		cout<<"enter the weight and profit for item "<<i+1<<":"<<endl;
		cin>>wt[i]>>pro[i];
	}
	cout<<knap(wt,pro,n,w)<<endl;

	
	return 0;
}
