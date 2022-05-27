from queue import PriorityQueue

EMPTY = 0
WALL = 1
SELECTED = 2
INITIAL = (3, 0)
GOAL = (2, 5)

class Node:
    def __init__(self, x, y, manhattanDist, distTravelled, parent):
        self.x = x
        self.y = y
        self.parent = parent
        self.manhattanDist = manhattanDist
        self.distTravelled = distTravelled
        self.cost = manhattanDist + distTravelled
    
    def __gt__(self, other):
        return self.cost > other.cost

    def __eq__(self, other):
        return self.cost == other.cost

def manhattan_dist(x, y) -> int:
    return abs(x - GOAL[0]) + abs(y - GOAL[1])

def display_board(board):
    print('', '-' * len(board[0] * 3))
    for i, row in enumerate(board):
        print(end='|')
        for j, col in enumerate(row):
            if (i, j) == INITIAL:
                ch='S'
            elif (i, j) == GOAL:
                ch='E'
            elif col == EMPTY:
                ch=' '
            elif col == WALL:
                ch='#'
            elif col == SELECTED:
                ch='.'
            print("{:>3}".format(ch), end='')
        print(end='|\n')
    print('', '-' * len(board[0]) * 3)

def get_successors(node, board):
    neighbours = [
    (node.x, node.y - 1), # Left
    (node.x - 1, node.y), # Top
    (node.x + 1, node.y), # Right
    (node.x, node.y + 1), # Bottom
    ]

    for coordinate in neighbours:
        x,y = coordinate
        if x < 0 or y < 0:
            neighbours = list(filter(lambda a: a != (x,y), neighbours))
        elif x >= len(board) or y >= len(board[0]):
            neighbours = list(filter(lambda a: a != (x,y), neighbours))
        elif board[x][y] == WALL:
            neighbours = list(filter(lambda a: a != (x,y), neighbours))
    return neighbours

def search(initial:  Node, bfs):
    global board
    frontier = PriorityQueue()
    frontier.put(initial)
    closed = []

    d_board = []
    for row in board:
        d_board.append([])
        for col in row:
            d_board[-1].append(col)

    while frontier.not_empty:
        print('=' * 40)
        print("Open List:", [[(node.x,node.y), node.distTravelled, node.manhattanDist] for node in frontier.queue])
        print("Closed List:", closed)

        node = frontier.get()
        if (node.x, node.y) == GOAL:
            return node
        closed.append((node.x, node.y))

        print("\n\nCurrently selected ({}, {})".format(node.x,node.y))
        d_board[node.x][node.y] = SELECTED
        display_board(d_board)

        for child in get_successors(node, board):
            #passing 0 for bfs for distance already travelled so it is not considered in cost
            childNode = Node(child[0], child[1], manhattan_dist(child[0], child[1]), 0 if bfs else node.distTravelled + 1, node)

            if (childNode.x, childNode.y) in [(node.x,node.y) for node in frontier.queue]:   #if new node in open list
                for node1 in frontier.queue:
                    if (node1.x,node1.y) == (childNode.x, childNode.y):
                        if node1.cost > childNode.cost:
                            frontier.queue.remove(node1)
                            frontier.put(childNode)
            elif (childNode.x, childNode.y) in closed:
                pass
            else:
                frontier.put(childNode)
        
        # print('OPEN LIST :', [(node.city, node.distTravelled, node.manhattanDist) for node in frontier.queue])
        # print('CLOSED LIST :', closed)
    return None



if __name__ == '__main__':
    board = [
    [0, 0, 0, 0, 0, 0, 0, 0, 0,],
    [0, 1, 0, 0, 1, 1, 1, 1, 0,],
    [0, 1, 1, 0, 0, 0, 0, 1, 0,],
    [0, 0, 1, 1, 1, 1, 1, 1, 0,],
    [0, 0, 0, 0, 0, 0, 0, 0, 0,],
    ]
    initial = Node(INITIAL[0], INITIAL[1], manhattan_dist(INITIAL[0], INITIAL[1]), 0, None)
    print('BOARD CONFIGURATION :')
    display_board(board)

    print('FORMAT OF OPEN LIST ITEMS: [(coordinate), g(n), h(n)]\n\n')

    print('USING BEST FIRST SEARCH:')
    end = search(initial, bfs=True)
    print("\nThe best path is ")
    path = []
    while end:
        path.append((end.x, end.y))
        end = end.parent
    
    # Create a copy of board
    d_board = []
    for row in board:
        d_board.append([])
        for col in row:
            d_board[-1].append(col)
    
    # mutate it with path found
    for (x, y) in path:
        d_board[x][y] = SELECTED
    
    display_board(d_board)

    print('\n\nUSING A* SEARCH:')
    end = search(initial, bfs=False)
    print("\nThe best path is ")
    path = []
    while end:
        path.append((end.x, end.y))
        end = end.parent
    
    # Create a copy of board
    d_board = []
    for row in board:
        d_board.append([])
        for col in row:
            d_board[-1].append(col)
    
    # mutate it with path found
    for (x, y) in path:
        d_board[x][y] = SELECTED
    
    display_board(d_board)