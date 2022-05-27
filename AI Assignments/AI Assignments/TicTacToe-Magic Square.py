from random import randint

def draw_board(board):
    print("\n")
    print(f"{board[0]}|{board[1]}|{board[2]}")
    print("-----")
    print(f"{board[3]}|{board[4]}|{board[5]}")
    print("-----")
    print(f"{board[6]}|{board[7]}|{board[8]}")

def free_space(move, board):
    if board[move] == " ":
        return True
    
    return False

def playermove(board, playerChoice):
    move = int(input("\nEnter your move between 0-8 :"))
    move_success = True
    while(move_success):
        if move in [0,1,2,3,4,5,6,7,8] and free_space(move, board):
            move_success=False
            return move
        else:
            print("\nInvalid Move")

def checkwin(board, choice):
    magic = [2, 7, 6, 9, 5, 1, 4, 3, 8]
    for i in range(0,8):
        if board[i] == choice:
            for j in range(0,8):
                if board[j] == choice and i!=j:
                    for k in range(0,8):
                        if board[k] == choice and j!=k and k!=i and (magic[i]+magic[j]+magic[k] == 15):
                            return True
    return False

def get_random_move(board):
    move_success = True
    while(move_success):
        move = randint(0,8)
        if free_space(move, board):
            return move
            
def board_full(board):
    if " " not in board:
        return False
    return True

def computermove(board, computermove):
    move = get_random_move(board)
    return move

def main():
    print("Tic Tac Toe - Magic Square\n")
    board = [0,1,2,3,4,5,6,7,8]
    print("Consider for reference moves\n")
    draw_board(board)

    board = [" " for i in range(0,9)]
    draw_board(board)

    cont = True
    while(cont):
        playerChoice = input("Select your character \"X\" or \"O\" : ")
        if playerChoice in ['X','x','O','o']:
            cont = False
            playerChoice = playerChoice.upper()
            computerChoice = 'X' if playerChoice == 'O' else 'O'
        else: 
            print("Select valid character")


    print(f"\nYou have chosen {playerChoice}")
    print(f"Computer is {computerChoice}")

    chance = randint(0,1)
    if chance:
        print("\nPlayer goes first")
        firstmove = playerChoice
    else:
        print("\nComputer goes first")
        firstmove = computerChoice
    nextmove = firstmove

    while (not checkwin(board, playerChoice) or not checkwin(board,computerChoice) or board_full(board)):
        if nextmove == playerChoice:
            print("\nPlayer's Move")
            move = playermove(board, playerChoice)
            board[move] = playerChoice
            draw_board(board)
            if checkwin(board, playerChoice):
                print("\nPlayer Wins!")
                break
            else:
                nextmove = computerChoice

        elif nextmove == computerChoice:
            print("\nComputer's Move")
            move = computermove(board, computerChoice)
            board[move] = computerChoice
            draw_board(board)
            if checkwin(board,computerChoice):
                print("\nComputer Wins!")
                break
            else:
                nextmove = playerChoice

if __name__=="__main__":
    main()