#include<stdio.h>

int arr[10][10] = {0};
int q = 1,n;

void place()
{
    int i,j,k,l,temp;
    i=0;
    j = 0;
    while(q != n+1)
    {
        if(arr[i][j] == 0)
        {
            arr[i][j] = q;
            k = j + 1;
            if(k == n)
                k = 0;
            while(k != j)
            {
                if(arr[i][k] == 0)
                    arr[i][k] = -q;
                k++;
                if(k == n)
                    k = 0;
            }
            k = i + 1;
            if(k == n)
                k = 0;
            while(k != i)
            {
                if(arr[k][j] == 0)
                    arr[k][j] = -q;
                k++;
                if(k == n)
                    k = 0;
            }
            k = i + 1;
            l = j + 1;
            if(k == n && k>=j)
            {
                k=k-l;
                l=0;
            }
            else
            {
                if(l == n && l>k)
                {
                    l=l-k;
                    k=0;
                }
            }
            while(k != i)
            {
                if(arr[k][l] == 0)
                    arr[k][l] = -q;
                k++;
                l++;
                if(k == n && k>=j)
                {
                    k=k-l;
                    l=0;
                }
                else
                {
                    if(l == n && l>k)
                    {
                        l=l-k;
                        k=0;
                    }
                }
            }
            k = i + 1;
            l = j - 1;
            if(l == -1)
            {
                l=l+k;
                k=0;
            }
            else
            {
                if(k == n)
                {
                    temp = l;
                    l=k-1;
                    k=k-l+temp;
                }
            }
            while(k != i)
            {
                if(arr[k][l] == 0)
                    arr[k][l] = -q;
                k++;
                l--;
                if(l == -1)
                {
                    l=l+k;
                    k=0;
                }
                else
                {
                    if(k == n)
                    {
                        temp = l;
                        l=k-1;
                        k=k-l+temp;
                    }
                }
            }
            j = q;
            i = 0;
            q++;
        }
        else
        {
            i++;
            if(i == n && j == q-1)
            {
                for(k=0;k<n;k++)
                {
                    for(l=0;l<n;l++)
                    {
                        if(arr[k][l] == -j)
                            arr[k][l] = 0;
                        if(arr[k][l] == j)
                            arr[k][l] = -1;
                    }
                }
                q--;
                i=0;
                j=q-1;
            }
        }
    }
}

int main()
{
    printf("\t\t\t\t\t\t\tN QUEENS PROBLEM!!\n\n\n\n");
    int i,j;
    printf("\nEnter the Number of Queens : ");
    scanf("%d",&n);
    printf("\n\n");
    char dis[n][n];
    place();
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[i][j]>0)
                dis[i][j] = 'Q';
            else
                dis[i][j] = '-';
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("\t\t%c",dis[i][j]);
        }
        printf("\n");
    }
    return 0;
}
