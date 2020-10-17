#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n;
    cin>>n; //Nunmber of rolls
    long long int dp[n+1]={1};
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=min(6,i);j++)
            dp[i]=(dp[i]+dp[i-j]); // Caluculate the sum of previous 6 or less combinations
    }
    cout<<dp[n];
}