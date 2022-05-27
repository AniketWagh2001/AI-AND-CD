from typing import *

ALPHABETS: list[str] = []
State = dict[str, int]
RESULT_STATES: list[State] = []

def tokenise(eq: str) -> list[str]:
    i, prev = 0, 0
    tokens = []
    while i < len(eq):
        if not eq[i].isalpha():
            tokens.append(eq[prev:i])
            tokens.append(eq[i])
            prev = i + 1
        i += 1
    tokens.append(eq[prev:])
    return tokens

def operation(operator: str, operand1: int, operand2: int) -> int:
    return {
            '+': lambda a, b: a+b,
            '-': lambda a, b: a-b,
            '*': lambda a, b: a*b,
            '/': lambda a, b: a/b,
                }[operator](operand1, operand2)

def transform(operand: str, state: State) -> Optional[int]:
    result = 0
    for alphabet in operand:
        if alphabet not in state:
            return None
        result *= 10
        result += state[alphabet]
    return result
    
def display_transform(operand: str, state: State) -> str:
    result = operand
    for op in operand:
        result = result.replace(op, str(state[op]))
    return result

def fact_estimate(operation: str, op1: str, op2: str, result: str) -> State:
    facts = {}
    if len(op1) == len(op2) and len(op1) < len(result) and operation == '+':
        difference = len(result) - len(op1)
        for i in range(difference):
            facts[result[i]] = 1
    return facts

def fact_check(state: State, fact: State) -> bool:
    if len(state) < len(fact):
        return False
    for key in fact:
        if state.get(key, None) != fact[key]:
            return False
    return True

def is_valid(tokens: list[str], state: State) -> bool:
    op1 = transform(tokens[0], state)
    op2 = transform(tokens[2], state)
    result = transform(tokens[4], state)
    if not all([op1, op2, result]):
        return False
    return operation(tokens[1], op1, op2) == result

def start(tokens: list[str], facts: State, alphabet_pos: int = 0, state: State = {}) -> State:
    if alphabet_pos == len(ALPHABETS):
        if is_valid(tokens, state) and fact_check(state, facts):
            return state
        else:
            return None
    counter = 0
    while counter < 10:
        if counter in state.values():
            counter += 1
            continue
        state[ALPHABETS[alphabet_pos]] = counter
        if start(tokens, facts, alphabet_pos + 1, state):
            RESULT_STATES.append(state.copy())
        else:
            state.pop(ALPHABETS[alphabet_pos])
        counter += 1
    return None

def main() -> None:
    eq = input("Enter the equation : ").replace(" ", "")
    tokens = tokenise(eq)
    op1, operation, op2, _, result = tokens
    padding_len = max([len(op1), len(op2), len(result)])
    print("\n\nThe Equation is : ")
    print(op1.rjust(padding_len))
    print(op2.rjust(padding_len), tokens[1])
    print('-' * padding_len)
    print(result.rjust(padding_len))
    global ALPHABETS
    ALPHABETS = list(set(op1) | set(op2) | set(result))
    if len(ALPHABETS) > 10:
        print("\nInvalid Input!!!")
        print("\nThere are more than 10 distinct letters : ",
        sorted(ALPHABETS), f"({len(ALPHABETS)} letters)")
        print("\nWe can't have distinct values for each letter")
        exit()
    facts = fact_estimate(operation, op1, op2, result)
    if facts:
        print("\n\nThe facts are : ")
        for key, value in facts.items():
            print(f"{key} = {value}")
    start(tokens, facts)
    if len(RESULT_STATES) == 0:
        print("\n\nSuitable mapping not found!")
    for i, state in enumerate(RESULT_STATES):
        print(f"\nMapping [{i + 1}] : ")
        print(str(display_transform(op1, state)).rjust(padding_len))
        print(str(display_transform(op2, state)).rjust(padding_len),tokens[1])
        print('-' * padding_len)
        print(str(display_transform(result, state)).rjust(padding_len))

if __name__ == '__main__':
    main()
