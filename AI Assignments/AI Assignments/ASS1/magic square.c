#include<stdio.h>

int main()
{
    printf("\t\t\t\t\t\t\tMAGIC SQUARE!!\n\n\n\n");
    int n;
    printf("\nEnter an Odd Number : ");
    scanf("%d",&n);
    int arr[n][n];
    memset(arr, 0, sizeof(arr[n][n]) * n * n);
    int i=0,j,val=1;
    int temp1,temp2;
    j = (n-1)/2;
    arr[i][j] = val;
    val++;
    while(val<=(n*n))
    {
        temp1 = i;
        temp2 = j;
        i--;
        if(i == -1)
            i = n-1;
        j++;
        if(j == n)
            j = 0;
        if(arr[i][j] == 0)
            arr[i][j] = val;
        else
        {
            i = temp1+1;
            j = temp2;
            arr[i][j] = val;
        }
        val++;
    }
    printf("\n\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("\t%d",arr[i][j]);
        printf("\n");
    }
    return 0;
}
