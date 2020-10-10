
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
#include<iostream>
 
using namespace std;
 
int main(){
	int i,j,k,n,a[10][10],indeg[10],flag[10],count=0;
 
	cout<<"Enter the no of vertices:\n";
	cin>>n;
 
	cout<<"Enter the adjacency matrix:\n";
	for(i=0;i<n;i++){
		cout<<"Enter row "<<i+1<<"\n";
		for(j=0;j<n;j++)
			cin>>a[i][j];
	}
 
	for(i=0;i<n;i++){
        indeg[i]=0;
        flag[i]=0;
    }
 
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            indeg[i]=indeg[i]+a[j][i];
 
    cout<<"\nThe topological order is:";
 
    while(count<n){
        for(k=0;k<n;k++){
            if((indeg[k]==0) && (flag[k]==0)){
                cout<<k+1<<" ";
                flag[k]=1;
            }
 
            for(i=0;i<n;i++){
                if(a[i][k]==1)
                    indeg[k]--;
            }
        }
 
        count++;
    }
 
    return 0;
}