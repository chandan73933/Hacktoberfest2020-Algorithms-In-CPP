// this program is an implementation of addition/subtraction two numbers, assuming that the numbers given are so large that they cannot be stored in a variable..
#include <bits/stdc++.h> 
using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void addition(int a1[], int n1, int a2[], int n2);
void subtraction(int a1[], int n1, int a2[], int n2);


int main() {

	IOS;
    
    //Input Number of digits in a1 and a2
    int n1, n2;
    cin >> n1 >> n2;

    //Input a1 and a2
    int a1[n1], a2[n2];
    int i, j, flag = 0;
    //Here we assume that the input is valid input, where valid input means;- 1)The first digit of the number is not 0
    //If there is Invalid Input the code for subtraction may fail.
    for (i = n1 - 1; i >= 0; i--)
        scanf("%1d", &a1[i]);

    for (j = n2 - 1; j >= 0; j--)
        scanf("%1d", &a2[j]);

    addition(a1, n1, a2, n2);
    cout << endl;
    
    //Checks which number is greater a1 or a2.
    if (n1 > n2)
        //OK
        subtraction(a1, n1, a2, n2);

    else if (n1 < n2)
        //Work on swapped array
        subtraction(a2, n2, a1, n1);
    
    else //if n1==n2
    {
        for (i = n1 - 1, j = n2 - 1; i >= 0, j >= 0; i--, j--)
        {
            if (a1[i] < a2[j])
            {
                flag = 1;
                break;
            }
            else
                flag = 0;
        }
        if (flag == 1)
            subtraction(a2, n2, a1, n1);
        else
            subtraction(a1, n1, a2, n2);
    }
    return 0;




}


void addition(int a1[], int n1, int a2[], int n2)
{
    int carry = 0, i, j, k, n3, min_n, sum;
    if (n1 > n2)
    {
        n3 = n1;
        min_n = n2;
    }
    else if (n1 < n2)
    {
        n3 = n2;
        min_n = n1;
    }
    else
    {
        n3 = n1;
        min_n = n1;
    }

    int ans[n3];

    for (i = 0, j = 0, k = 0; i < min_n, j < min_n, k < min_n; i++, j++, k++)
    {
        sum = a1[i] + a2[j] + carry;
        ans[k] = sum % 10;
        carry = sum / 10;

    }

    if (n3 == n1)
    {
        for (i = min_n, k = min_n; i < n3, k < n3; i++, k++)
        {
            sum = a1[i] + carry;
            ans[k] = sum % 10;
            carry = sum / 10;

        }
    }
    else if (n3 == n2)
    {
        for (i = min_n, k = min_n; i < n3, k < n3; i++, k++)
        {
            sum = a2[i] + carry;
            ans[k] = sum % 10;
            carry = sum / 10;
        }
    }

    if (carry == 0)
    {
        for (k = n3 - 1; k >= 0; k--)
            cout << ans[k];
    }
    else
    {
        cout << carry;
        for (k = n3 - 1; k >= 0; k--)
            cout << ans[k];
    }
}


void subtraction(int a1[], int n1, int a2[], int n2)
{
    int borrow = 0, i, j, k, sub;
    int ans[n1];
    
    for (j = 0; j < n2; j++)
    {
        sub = a1[j] - a2[j] - borrow;
        if (sub < 0)
        {
            sub = sub + 10;
            borrow = 1;
        }
        else
            borrow = 0;

        ans[j] = sub;
    }
    for (j = n2; j < n1; j++)
    {
        sub = a1[j] - borrow;
        if (sub < 0)
        {
            sub = sub + 10;
            borrow = 1;
        }
        else
            borrow = 0;

        ans[j] = sub;
    }

    for (k = n1 - 1; k >= 0; k--)
        cout << ans[k];




}


