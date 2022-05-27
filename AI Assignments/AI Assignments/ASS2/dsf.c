#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int close1[100];
int open1[100];
int close2[100];
int open2[100];
int c1=0,c2=0;

struct node
{
    int x, y;
    struct node *next;
}*root, *left, *right;

int fin_node(struct node *next, int J1, int J2, int S1, int S2)
{
    struct node *temp;
    if((next->x == S1) && (next->y == S2))
    {
        return(0);
    }
    if((next->x == J1) && (next->y == J2))
    {
        return(1);
    }
    if((next->x == 0) && (next->y == 0))
    {
        return(1);
    }
    temp = left;
    while(1)
    {
        if((temp->x == next->x) && (temp->y == next->y))
        {
            return(1);
        }
        else if(temp->next == NULL)
        {
            break;
        }
        else
        {
            temp = temp->next;
        }
    }
    temp = right;
    while(1)
    {
        if((temp->x == next->x) && (temp->y == next->y))
        {
            return(1);
        }
        else if(temp->next == NULL)
        {
            break;
        }
        temp = temp->next;
    }
    return(0);
}

struct node* nxt_node(struct node *current, int J1, int J2, int S1, int S2)
{
    int d;
    struct node *next;
    next = (struct node*)malloc(sizeof(struct node));
    next->x = J1;
    next->y = current->y;
    if(fin_node(next, J1, J2, S1, S2) != 1)
    {
        return(next);
    }
    next->x = current->x;
    next->y = J2;
    if(fin_node(next, J1, J2, S1, S2) != 1)
    {
        return(next);
    }
    next->x = 0;
    next->y = current->y;
    if(fin_node(next, J1, J2, S1, S2) != 1)
    {
        return(next);
    }
    next->y = 0;
    next->x = current->x;
    if(fin_node(next, J1, J2, S1, S2) != 1)
    {
        return(next);
    }
    if((current->y < J2) && (current->x != 0))
    {
        d = J2 - current->y;
        if(d >= current->x)
        {
            next->x = 0;
            next->y = current->y + current->x;
        }
        else
        {
            next->x = current->x - d;
            next->y = current->y + d;
        }
        if(fin_node(next, J1, J2, S1, S2) != 1)
        {
            return(next);
        }
    }
    if((current->x < J1) && (current->y != 0))
    {
        d = J1 - current->x;
        if(d >= current->y)
        {
            next->y = 0;
            next->x = current->x + current->y;
        }
        else
        {
            next->y = current->y - d;
            next->x = current->x + d;
        }
        if(fin_node(next, J1, J2, S1, S2) != 1)
        {
            return(next);
        }
    }
    return(NULL);
}

void add_node(int J1, int J2, int S1, int S2)
{
    int flag1, flag2;
    struct node *tempLeft, *tempRight;

    root  = (struct node*)malloc(sizeof(struct node));
    root->x = 0;
    root->y = 0;
    root->next = NULL;

    left = (struct node*)malloc(sizeof(struct node));
    left->x = 0;
    left->y = J2;
    left->next = NULL;

    right = (struct node*)malloc(sizeof(struct node));
    right->x = J1;
    right->y = 0;
    right->next = NULL;

    tempLeft = left;
    tempRight = right;
    while(1)
    {
        flag1 = 0;
        flag2 = 0;
        if((tempLeft->x != S1) || (tempLeft->y != S2))
        {
            tempLeft->next = nxt_node(tempLeft, J1, J2, S1, S2);
            tempLeft = tempLeft->next;
            tempLeft->next = NULL;
            flag1 = 1;
        }
        if((tempRight->x != S1) || (tempRight->y != S2))
        {
            tempRight->next = nxt_node(tempRight, J1, J2, S1, S2);
            tempRight = tempRight->next;
            tempRight->next = NULL;
            flag2 = 1;
        }
        if((flag1 == 0) && (flag2 == 0))
            break;
    }
}

void dis_sol()
{
    struct node *temp;
    temp = left;
    printf("\n\nStart State : (%d,%d)\n", root->x, root->y);
    printf("\nSolution : \n");
    while(1)
    {
        printf("(%d,%d)\n", temp->x, temp->y);
        if(temp->next == NULL)
        {
            break;
        }
        temp = temp->next;
    }
    temp = right;
}

int main()
{
    printf("\n\t\t\t\tWATER JUG PROBLEM USING DFS!!\n");
    int J1, J2, S1, S2;
    printf("\nCapacity of Jug 1 : ");
    scanf("%d", &J1);
    printf("\nCapacity of Jug 2 : ");
    scanf("%d", &J2);
    printf("\nRequired water in Jug 1 : ");
    scanf("%d", &S1);
    printf("\nRequired water in Jug 2 : ");
    scanf("%d", &S2);
    add_node(J1, J2, S1, S2);
    dis_sol();
    return 0;
}
