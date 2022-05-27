#include<bits/stdc++.h>

using namespace std;

struct Move
{
	int row, col;
};

char player = 'x', opponent = 'o';

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

int main()
{
    char board[5][5] =
	{
		{'x','|','o','|','x'},
		{'-','|','-','|','-'},
		{'o','|',' ','|','o'},
		{'-','|','-','|','-'},
		{' ','|','x','|',' '}
	};
	printf("\nCurrent Board Position :\n\n");
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            printf("\t%c",board[i][j]);
        }
        printf("\n");
    }
	Move bestMove = findBestMove(board);
    if(bestMove.row == 0)
        bestMove.row++;
    if(bestMove.row == 4)
        bestMove.row--;
    if(bestMove.col == 0)
        bestMove.col++;
    if(bestMove.col == 4)
        bestMove.col--;
	printf("\nOptimal Move :\n");
	printf("Row: %d \nCol: %d\n\n", bestMove.row,bestMove.col);
	return 0;
}
