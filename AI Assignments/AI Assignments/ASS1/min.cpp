#include<bits/stdc++.h>

using namespace std;

int arr[]={1,2,3,4,5,6,7,8,9};
int arr2[9]={-1};
int m;

struct Move
{
	int row, col;
};

char player = 'x', opponent = 'o';

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

bool isMovesLeft(char board[5][5])
{
	for (int i = 0; i<5; i++)
		for (int j = 0; j<5; j++)
			if (board[i][j]==' ')
				return true;
	return false;
}

int evaluate(char b[5][5])
{
	for (int row = 0; row<5; row++)
	{
		if (b[row][0]==b[row][2] && b[row][2]==b[row][4])
		{
			if (b[row][0]==player)
				return +10;
			else if (b[row][0]==opponent)
				return -10;
		}
	}

	for (int col = 0; col<5; col++)
	{
		if (b[0][col]==b[2][col] && b[2][col]==b[4][col])
		{
			if (b[0][col]==player)
				return +10;

			else if (b[0][col]==opponent)
				return -10;
		}
	}

	if (b[0][0]==b[2][2] && b[2][2]==b[4][4])
	{
		if (b[0][0]==player)
			return +10;
		else if (b[0][0]==opponent)
			return -10;
	}

	if (b[0][4]==b[2][2] && b[2][2]==b[4][0])
	{
		if (b[0][4]==player)
			return +10;
		else if (b[0][4]==opponent)
			return -10;
	}
	return 0;
}

int minimax(char board[5][5], int depth, bool isMax)
{
	int score = evaluate(board);
	if (score == 10)
		return score;
	if (score == -10)
		return score;
	if (isMovesLeft(board)==false)
		return 0;
	if (isMax)
	{
		int best = -1000;
		for (int i = 0; i<5; i++)
		{
			for (int j = 0; j<5; j++)
			{
				if (board[i][j]==' ')
				{
					board[i][j] = player;
					best = max( best,minimax(board, depth+1, !isMax) );
					board[i][j] = ' ';
				}
			}
		}
		return best;
	}
	else
	{
		int best = 1000;
		for (int i = 0; i<5; i++)
		{
			for (int j = 0; j<5; j++)
			{
				if (board[i][j]==' ')
				{
					board[i][j] = opponent;
					best = min(best,minimax(board, depth+1, !isMax));
					board[i][j] = ' ';
				}
			}
		}
		return best;
	}
}

Move findBestMove(char board[5][5])
{
	int bestVal = -1000;
	Move bestMove;
	bestMove.row = -1;
	bestMove.col = -1;

	for (int i = 0; i<5; i++)
	{
		for (int j = 0; j<5; j++)
		{
            if (board[i][j]==' ')
			{
				board[i][j] = player;
				int moveVal = minimax(board, 0, false);
				board[i][j] = ' ';
				if (moveVal > bestVal)
				{
					bestMove.row = i;
					bestMove.col = j;
					bestVal = moveVal;
				}
			}
		}
	}
	//printf("\n\nThe value of the best Move is : %d\n",bestVal);
	return bestMove;
}

void dis_board(char board[5][5])
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
	char board[5][5] =
	{
		{' ','|',' ','|',' '},
		{'-','|','-','|','-'},
		{' ','|',' ','|',' '},
		{'-','|','-','|','-'},
		{' ','|',' ','|',' '}
	};
	printf("\t\t\t\t\t\t\tTIC TAC TOE!!\n\n\n\n");
    int i,j,p,c=0;
    int mover=1;
    printf("\n\n1. Player plays first\n2. Computer plays first\nYour Choice : ");
    scanf("%d",&i);
    if(i==1)
        p=1;
    else
        p=2;
    dis_board(board);
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
            printf("\n\t\t\tPlayer 1(o) : \n\nChoose your move index : ");
            scanf("%d",&mover);
            printf("\n\n");
            arr[mover-1] = -3;
            arr2[mover-1] = 1;
            switch(mover)
            {
                case 1:
                    board[0][0] = 'o';
                    break;
                case 2:
                    board[0][2] = 'o';
                    break;
                case 3:
                    board[0][4] = 'o';
                    break;
                case 4:
                    board[2][0] = 'o';
                    break;
                case 5:
                    board[2][2] = 'o';
                    break;
                case 6:
                    board[2][4] = 'o';
                    break;
                case 7:
                    board[4][0] = 'o';
                    break;
                case 8:
                    board[4][2] = 'o';
                    break;
                case 9:
                    board[4][4] = 'o';
                    break;
            }
            dis_board(board);
            c = check();
            if(c==1)
                return 0;
            p++;
            m++;
        }
        else
        {
            printf("\n\t\t\tPlayer COMP(x) : \n\nChoose your move index : ");
            Move bestMove = findBestMove(board);
            board[bestMove.row][bestMove.col] = 'x';
            if(bestMove.row == 0)
            {
                if(bestMove.col == 0)
                    mover = 1;
                if(bestMove.col == 2)
                    mover = 2;
                if(bestMove.col == 4)
                    mover = 3;
            }
            if(bestMove.row == 2)
            {
                if(bestMove.col == 0)
                    mover = 4;
                if(bestMove.col == 2)
                    mover = 5;
                if(bestMove.col == 4)
                    mover = 6;
            }
            if(bestMove.row == 4)
            {
                if(bestMove.col == 0)
                    mover = 7;
                if(bestMove.col == 2)
                    mover = 8;
                if(bestMove.col == 4)
                    mover = 9;
            }
            printf("%d\n\n\n",mover);
            arr[mover-1] = -3;
            arr2[mover-1] = 2;
            dis_board(board);
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
