GOAL = {
    1: 1, 2: 2, 3: 3,
    4: 8, 5: None, 6: 4,
    7: 7, 8: 6, 9: 5,
}

def start(puzzle):
    if heuristic(puzzle) == heuristic(GOAL):
        return puzzle
    
    best_score = heuristic(puzzle)

    for operation in moves(puzzle):
        board = operation(puzzle)
        score = heuristic(board)

        if score >= best_score:
            print(f"\n\nWe {operation.__name__} the empty slot\n")
            display_board(puzzle)
            print(f"\nObjective function value is {heuristic(puzzle)}")
            best_score = score
            return start(board)
        else:
            board = revert(board, operation)
    
    print("\n\nWe have hit a plateau!!!")
    return puzzle

def display_board(puzzle: dict[int, int]):
    print(
        str(safe_get(puzzle, 1)).center(3, ' ') + 
        str(safe_get(puzzle, 2)).center(3, ' ') +
        str(safe_get(puzzle, 3)).center(3, ' ')
    )
    print('-' * 10)
    print(
        str(safe_get(puzzle, 4)).center(3, ' ') + 
        str(safe_get(puzzle, 5)).center(3, ' ') +
        str(safe_get(puzzle, 6)).center(3, ' ')
    )
    print('-' * 10)
    print(
        str(safe_get(puzzle, 7)).center(3, ' ') + 
        str(safe_get(puzzle, 8)).center(3, ' ') +
        str(safe_get(puzzle, 9)).center(3, ' ')
    )

def emtpos(puzzle) -> int:
    for key in puzzle:
        if puzzle[key] is None:
            return key

def up(puzzle):
    pos = emtpos(puzzle)
    puzzle[pos], puzzle[pos - 3] = puzzle[pos - 3], puzzle[pos]
    return puzzle


def down(puzzle):
    pos = emtpos(puzzle)
    puzzle[pos], puzzle[pos + 3] = puzzle[pos + 3], puzzle[pos]
    return puzzle


def right(puzzle):
    pos = emtpos(puzzle)
    puzzle[pos], puzzle[pos + 1] = puzzle[pos + 1], puzzle[pos]
    return puzzle


def left(puzzle):
    pos = emtpos(puzzle)
    puzzle[pos], puzzle[pos - 1] = puzzle[pos - 1], puzzle[pos]
    return puzzle


def revert(puzzle, operation):
    return {
        up: down,
        down: up,
        left: right,
        right: left,
    }[operation](puzzle)

def moves(puzzle):
    operations = {
        up,
        left, right,
        down,
    }
    empty_pos = emtpos(puzzle)

    if empty_pos in {1, 2, 3}:
        operations.remove(up)
    if empty_pos in {7, 8, 9}:
        operations.remove(down)
    if empty_pos in {3, 6, 9}:
        operations.remove(right)
    if empty_pos in {1, 4, 7}:
        operations.remove(left)

    return operations

def heuristic(puzzle: dict) -> int:
    score = 0

    for key in puzzle:
        if puzzle[key] == GOAL[key]:
            score += 1

    return score

def safe_get(puzzle, key):
    if puzzle[key]:
        return puzzle[key]
    return '@'

def main():
    STATE_GLOBAL = {
            1: 1, 2: 2, 3: 3,
            4: 8, 5: 6, 6: None,
            7: 7, 8: 5, 9: 4,
    }
    STATE_LOCAL = {
            1: 4, 2: None, 3: 7,
            4: 2, 5: 8, 6: 1,
            7: 3, 8: 6, 9: 5,
    }
    print("\n\t\t\t\t8-PUZZLE USING HILL CLIMB ALGORITHM!!!")
    print("\n1. State which can reach global maxima")
    print("\n2. State which cannot reach global maxima")
    choice = int(input("\n\nChoose Initial State : \n"))

    if choice == 1:
        puzzle = STATE_GLOBAL
    elif choice == 2:
        puzzle = STATE_LOCAL
    else:
        print("\nPlease enter a valid number!")
        main()
        exit()

    print("\nThe initial board state is : \n")
    display_board(puzzle)
    print("\nThe goal is : \n")
    display_board(GOAL)

    puzzle = start(puzzle)
    print("\nFinal Board state achieved by Hill Climbing is : ")
    display_board(puzzle)
    print(f"\nThe Objective Function Value of this Board is :  {heuristic(puzzle)}")

    if puzzle != GOAL:
        print("\n\nGoal State not Achieved")
    else:
        print("\n\nGoal State Achieved")


if __name__ == '__main__':
    main()
