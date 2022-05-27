#implement code for the n-queens problem
#key - maintaining track of columns using hashset
#key - positive and negative diagonals using hashset

#for n queens negative diagonal(row - column)
'''
0 -1 -2  _
1  0 -1 -2
2  1  0 -1
_  2  1  0
'''

#for n queens positive diagonal(row+column)
'''
_  1  2  3
1  2  3  4
2  3  4  1
3  4  1  _
'''

col = set()
positivediag = set()
negativediag = set()

N=4
board = [[" _ "] * N for i in range(N)]

def backtrack(row):

    if row == N:
        for row in board:
            print(row)

        print("\n")

    for c in range(N):
        if c in col or (row+c) in positivediag or (row-c) in negativediag:
            continue

        positivediag.add(row+c)
        negativediag.add(row-c)
        col.add(c)

        board[row][c] = 'Q'

        backtrack(row+1)

        positivediag.remove(row+c)
        negativediag.remove(row-c)
        col.remove(c)
        board[row][c] = '_'

backtrack(0)