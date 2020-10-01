#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)  {  
    for (int i = 0; i < n-1; i++)      
         for (int j = 0; j < n-i-1; j++){  
            if (arr[j] > arr[j+1]){ 
                int temp = arr[j];  
                arr[j] = arr[j + 1];  
                arr[j + 1] = temp; 
            }
        }
    }  
  
void print(int array[], int n)  
{  
    for (int i = 0; i < n; i++){
        cout<<array[i]<<" ";
    } 
}  


int main()  {  
    int arr[] = {77, 45, 22, 6, 89, 54, 23, 50};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    bubbleSort(arr, n);  
    print(arr, n);  
    return 0;  
} 
