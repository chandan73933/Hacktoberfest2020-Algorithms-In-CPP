#include<bits/stdc++.h>
using namespace std;

// Function for Sorting ( takes input an array and its size )
void selection_sort(int arr[],int size)
{
    for(int i=0;i<size;i++)
        {
            int min_element=arr[i];
            int min_index=0;
            for(int j=i+1;j<size;j++)if(min_element>arr[j])
            {
                min_element=arr[j];
                min_index=j;
            }
            if(min_index>i)
            {
                int temp=arr[i];
                arr[i]=arr[min_index];
                arr[min_index]=temp;
            }

        }
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	// Array Size Input
    int n;
    printf("Enter number of elements : ");
    cin>>n;
	
	// Array element Input
    int arr[n];
    printf("Enter the elements separated by space : \n");
    for(int i=0;i<n;i++)cin>>arr[i];
	
	// sort function call
    selection_sort(arr,n);
	
	//Printing Sorted array
    for(int i: arr)cout<<i<<" ";
    return 0;

}
