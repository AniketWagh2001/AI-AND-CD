def read_quadruples():
    '''returns list of [op,arg1,arg2,res] objects read from file.'''
    with open(r'Assignment 6/quadruples_2.txt') as file:
        lines = [line.strip() for  line in file.readlines()]
        quadruples = [line.split(',') for line in lines]
    return quadruples

def display_table(table):
    print(f"\n{'INDEX':{10}}{'OP':{10}}{'ARG1':{10}}{'ARG2':{10}}{'RES':{10}}")
    for index,line in enumerate(table):
        print(f"{index:<{10}}{line[0]:<{10}}{line[1]:{10}}{line[2]:{10}}{line[3]:{10}}")

def display_code(quadruples):
    print()
    for quadruple in quadruples:
        if ' ' in quadruple:
            print(f'{quadruple[3]} {quadruple[0]} {quadruple[1]}')
        else:
            print(f'{quadruple[3]} = {quadruple[1]} {quadruple[0]} {quadruple[2]}')

def optimize():
    global quadruples
    values = {}

    for index, entry in enumerate(quadruples):
        if entry[0] == '=' and entry[1].isnumeric():
            values[entry[3]] = int(entry[1])
        elif entry[0] == '=' and entry[3] in values:
            del values[entry[3]]
        
        if entry[1] in values:
            entry[1] = str(values[entry[1]])
        if entry[2] in values:
            entry[2] = str(values[entry[2]])
        if entry[2] != ' ':
            if entry[1].isnumeric() and entry[2].isnumeric():
                value = eval(entry[1]+entry[0]+entry[2])
                values[entry[3]] = value
                entry[0] = '='
                entry[1] = str(value)
                entry[2] = ' '
    

if __name__ == '__main__':
    quadruples = read_quadruples()
    print('INPUT:')
    display_code(quadruples)
    display_table(quadruples)
    optimize()
    print('\n\nOUTPUT:')
    display_code(quadruples)
    display_table(quadruples)