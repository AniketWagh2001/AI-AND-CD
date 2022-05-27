#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

char board[5][5] = {0};
int arr[]={1,2,3,4,5,6,7,8,9};
int mag[]={8,3,4,1,5,9,6,7,2};
int arr2[9]={-1};
int pla[5],comp[5];
int m;

int check()
{
    int i=0;
    while(i<9)
    {
        if(arr2[i] == 1 && arr2[i+1] == 1 && arr2[i+2] == 1)
        {
            printf("\n\n\t\t\t\t\tPlayer 1 WINS!!");
            return 1;
        }
        if(arr2[i] == 2 && arr2[i+1] == 2 && arr2[i+2] == 2)
        {
            printf("\n\n\t\t\t\t\tCOMPUTER WINS!!");
            return 1;
        }
        i = i+3;
    }
    i=0;
    while(i<3)
    {
        if(arr2[i] == 1 && arr2[i+3] == 1 && arr2[i+6] == 1)
        {
            printf("\n\n\t\t\t\t\tPlayer 1 WINS!!");
            return 1;
        }
        if(arr2[i] == 2 && arr2[i+3] == 2 && arr2[i+6] == 2)
        {
            printf("\n\n\t\t\t\t\tCOMPUTER WINS!!");
            return 1;
        }
        i++;
    }
    i=0;
    if(arr2[i] == 1 && arr2[i+4] == 1 && arr2[i+8] == 1)
    {
        printf("\n\n\t\t\t\t\tPlayer 1 WINS!!");
        return 1;
    }
    if(arr2[i] == 2 && arr2[i+4] == 2 && arr2[i+8] == 2)
    {
        printf("\n\n\t\t\t\t\tCOMPUTER WINS!!");
        return 1;
    }
    i=2;
    if(arr2[i] == 1 && arr2[i+2] == 1 && arr2[i+4] == 1)
    {
        printf("\n\n\t\t\t\t\tPlayer 1 WINS!!");
        return 1;
    }
    if(arr2[i] == 2 && arr2[i+2] == 2 && arr2[i+4] == 2)
    {
        printf("\n\n\t\t\t\t\tCOMPUTER WINS!!");
        return 1;
    }
    return 0;
}

void dis_board()
{
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("\t%c",board[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    printf("\t\t\t\t\t\t\tTIC TAC TOE!!\n\n\n\n");
    int i,j,p,c=0,mc1=0,mc2=0,a;
    int move=1;
    printf("\n\n1. Player plays first\n2. Computer plays first\nYour Choice : ");
    scanf("%d",&i);
    if(i==1)
        p=1;
    else
        p=2;
    for(i=1;i<5;i++)
    {
        for(j=0;j<5;j++)
            board[i][j] = '-';
        i++;
    }
    for(j=1;j<5;j++)
    {
        for(i=0;i<5;i++)
            board[i][j] = '|';
        j++;
    }
    dis_board();
    m=0;
    while(m<9)
    {
        j=0;
        printf("\n\nAvailable Moves : \n\n");
        for(i=0;i<9;i++)
        {
            printf("\t%c",arr[i] + 48);
            j++;
            if(j==3)
            {
                printf("\n");
                j=0;
            }
        }
        if(p==1)
        {
            printf("\n\t\t\tPlayer 1(X) : \n\nChoose your move index : ");
            scanf("%d",&move);
            printf("\n\n");
            arr[move-1] = -3;
            arr2[move-1] = 1;
            pla[mc2] = mag[move-1];
            mc2++;
            switch(move)
            {
                case 1:
                    board[0][0] = 'X';
                    break;
                case 2:
                    board[0][2] = 'X';
                    break;
                case 3:
                    board[0][4] = 'X';
                    break;
                case 4:
                    board[2][0] = 'X';
                    break;
                case 5:
                    board[2][2] = 'X';
                    break;
                case 6:
                    board[2][4] = 'X';
                    break;
                case 7:
                    board[4][0] = 'X';
                    break;
                case 8:
                    board[4][2] = 'X';
                    break;
                case 9:
                    board[4][4] = 'X';
                    break;
            }
            dis_board();
            c = check();
            if(c==1)
                return 0;
            p++;
            m++;
        }
        else
        {
            printf("\n\t\t\tPlayer COMP(O) : \n\nChoose your move index : ");
            if(mc1==0)
            {
                move = 5;
                if(arr[move-1] == -3)
                    goto jump2;
            }
            if(mc1==1)
            {
                jump2:
                    move = 1;
                    while(arr[move-1] == -3 && move<9)
                        move = (move*2) + 1;
            }
            if(mc1>=2)
            {
                a = 15 - comp[mc1-1] - comp[mc1-2];
                if(a<9)
                {
                    i=0;
                    while(mag[i] != a)
                        i++;
                    move = i+1;
                }
                else
                    goto jump1;
                if(arr[move-1] == -3)
                {
                    a = 15 - pla[mc2-1] - pla[mc2-2];
                    if(a<9)
                    {
                        i=0;
                        while(mag[i] != a)
                            i++;
                        move = i+1;
                    }
                    else
                        goto jump1;
                }
                jump1:
                    if(arr[move-1] == -3 || move>=9)
                    {
                        while(arr[move-1] == -3)
                            move = rand() %9 + 1;
                    }
            }
            printf("%d\n\n",move);
            arr[move-1] = -3;
            arr2[move-1] = 2;
            comp[mc1] = mag[move-1];
            mc1++;
            switch(move)
            {
                case 1:
                    board[0][0] = 'O';
                    break;
                case 2:
                    board[0][2] = 'O';
                    break;
                case 3:
                    board[0][4] = 'O';
                    break;
                case 4:
                    board[2][0] = 'O';
                    break;
                case 5:
                    board[2][2] = 'O';
                    break;
                case 6:
                    board[2][4] = 'O';
                    break;
                case 7:
                    board[4][0] = 'O';
                    break;
                case 8:
                    board[4][2] = 'O';
                    break;
                case 9:
                    board[4][4] = 'O';
                    break;
            }
            dis_board();
            c = check();
            if(c==1)
                return 0;
            p--;
            m++;
        }
    }
    if(m==9)
        printf("\n\n\t\t\t\t\tTHAT'S A DRAW!!");
    return 0;
}
