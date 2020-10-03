#include <iostream>

using namespace std;

long gcd(long a, long b){
    if (a==0) return b;
    else if(b==0) return a;
    else if (a>b) return gcd(a%b,b);
    else return gcd(b%a,a);
}
int main()
{
    long a,b;
    cin>>a;
    cin>>b;
    cout<<gcd(a,b);

    return 0;
}
