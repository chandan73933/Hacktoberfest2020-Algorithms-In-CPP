#include<iostream>
using namespace std;
void merge(int *a,int low,int high)
{
	int mid = (low+high)/2;
	vector<int> left,right;
	for(int i=low,i<=mid;i++)
		left.push_back(a[i]);
	for(int i=mid+1,i<=high;i++)
		right.push_back(a[i]);
	int i=0; int j=0;
	for(int k=low;k<=high;k++){
		if(i == left.size()){
			a[k] = left[i++];
			continue;				
		}
		else if(j == right.size()){
			a[k] = right[j++];
			continue;				
		}
		if(left[i] < right[j])
			a[k] = left[i++];
		else
			a[k] = right[j++];
	}
	
}


void merge_sort(int a[],int low,int high)
{ 

			if(low<high)
			{

		int mid = (low+high)/2;

		
				merge_sort(a,low,mid);

				merge_sort(a,mid+1,high);

				merge(a,low,high);
			}
}
int main()
{
	int n;
cin>>n;

			int a[n];

			for(int i=0;i<n;i++)
			{
				cin>>a[i];
			}
			int low = 0,high = n-1;

			merge_sort(a,low,high);

			for(int i=0;i<n;i++)
				cout<<a[i]<<" ";


			return 0;
		}
