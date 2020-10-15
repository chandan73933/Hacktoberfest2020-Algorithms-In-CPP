//SELECTION SORT
#include<stdio.h>

int main()
{
    int n,p[30],index;
    printf("enter length of array::");
    scanf("%d",&n);  //take length of an array
    printf("\n enter array elements here::");
    for(int i=0;i<n;i++) // taking elements of an array
    {
        scanf("%d",&p[i]);
    }
    for(int pass=0;pass<n-1;pass++) //sorting elements according to selection sort
    {
        index=pass;
        for(int i=pass+1;i<n;i++)
        {
            if(p[i]<p[index])
            {
                index=i;
            }
        }
        int temp = p[pass];
        p[pass] = p[index];
        p[index] = temp;
    }
    printf("\n================================\n");
    for(int i=0;i<n;i++)  // print sorted elements
    {
        printf("%d, ",p[i]);
    }
    return 0;
}
