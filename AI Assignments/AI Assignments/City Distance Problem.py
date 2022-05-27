from queue import PriorityQueue

MAP = {}
def add_edge(city1: str, city2: str, weight: int) -> None:
    global MAP
    if city1 in MAP:
        MAP[city1].append((city2, weight))
    else:
        MAP[city1] = [(city2, weight)]

    if city2 in MAP:
        MAP[city2].append((city1, weight))
    else:
        MAP[city2] = [(city1, weight)]

def create_map():
    add_edge("Pune", "Navi Mumbai", 106)
    add_edge("Pune", "Satara", 112)
    add_edge("Pune", "Solapur", 434)
    add_edge("Solapur", "Satara", 203)
    add_edge("Solapur", "Latur", 104)
    add_edge("Nanded", "Latur", 113)
    add_edge("Nanded", "Aurangabad", 221)
    add_edge("Nashik", "Aurangabad", 159)
    add_edge("Nanded", "Ahmednagar", 267)
    add_edge("Pune", "Ahmednagar", 120)
    add_edge("Nashik", "Pune", 165)
    add_edge("Nashik", "Navi Mumbai", 136)

SOURCE = "Latur"
DESTINATION = "Navi Mumbai"
HEURISTIC_VALUE = {
"Solapur": 340,
"Satara": 177,
"Navi Mumbai": 0,
"Nashik": 133,
"Ahmednagar": 180,
"Aurangabad": 265,
"Nanded": 451,
"Latur": 373,
"Pune": 10
}

class Node:
    def __init__(self, city, euclideanDist, distTravelled, parent):
        self.city = city
        self.euclideanDist = euclideanDist
        self.distTravelled = distTravelled
        self.parent = parent
        self.cost = distTravelled + euclideanDist   #f(n) = g(n) + h(n)

    def __gt__(self, other):
        return self.cost > other.cost

    def __eq__(self, other):
        return self.cost == other.cost

def get_successors(city):
    return MAP[city]

def search(initial:  Node, bfs): 
    frontier = PriorityQueue()
    frontier.put(initial)
    closed = []

    while frontier.not_empty:
        node = frontier.get()
        if node.city == DESTINATION:
            return node
        closed.append((node.city, node.distTravelled, node.euclideanDist))

        for city,distance in get_successors(node.city):
            childNode = Node(city, HEURISTIC_VALUE[city], 0 if bfs else node.distTravelled + distance, node)

            if city in [node.city for node in frontier.queue]:   #if new node in open list
                for node1 in frontier.queue:
                    if node1.city == city:
                        if node1.cost > childNode.cost:
                            frontier.queue.remove(node1)
                            frontier.put(childNode)
            elif city in [city[0] for city in closed]:
                pass
            else:
                frontier.put(childNode)
        
        print('OPEN LIST :', [(node.city, node.distTravelled, node.euclideanDist) for node in frontier.queue])
        print('CLOSED LIST :', closed)
    return None

if __name__ == '__main__':
    create_map()
    initial = Node(SOURCE, HEURISTIC_VALUE[SOURCE], 0, None)
    
    print('Using Best First Search :')
    temp = solution = search(initial, bfs = True)
    steps = dist = 0
    path = []
    while solution:
        steps += 1
        if solution.parent:
            dist += [x[1] for x in MAP[solution.city] if x[0] == solution.parent.city][0] 
        path.append(solution.city)
        solution = solution.parent
    
    path.reverse()
    print('PATH TAKEN :')
    for city in path[:-1]:
        print(city,end=' ->')
    print(path[-1])
    print('STEPS : ', steps)
    print('DISTANCE TRAVELLED : ', dist)
    
    print('\n\nUsing A* Search :')
    temp = solution = search(initial, bfs = False)
    steps = 0
    path = []
    while solution:
        steps += 1
        path.append(solution.city)
        solution = solution.parent
    
    path.reverse()
    print('PATH TAKEN :')
    for city in path[:-1]:
        print(city,end=' ->')
    print(path[-1])
    print('STEPS : ', steps)
    print('DISTANCE TRAVELLED : ', temp.distTravelled)