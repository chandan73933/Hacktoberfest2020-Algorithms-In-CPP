#include <bits/stdc++.h>

using namespace std;

void SeiveOfEratosthenes ( int n){
	int arr[n+1] = {0};
	
	for( int i = 2; i*i <= n; i++){
		if( arr[i] == 0){
			for( int j = i*i; j <= n; j += i )
				arr[j] = 1;
		}
	}
	
	for (int i = 2; i<=n; i++){
		if(arr[i] == 0)
		cout << i << " ";
	}
	
}


int main(){
	int n = 100;
	cout << "The prime numbers smaller than or equal to " << n << " are : "<<endl;
	SeiveOfEratosthenes(n);
	return 0;
}
