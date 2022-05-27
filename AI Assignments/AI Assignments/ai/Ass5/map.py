Graph = dict[str, list[str]]
COLORS = ["red", "blue", "green", "yellow"]

def generate_graph() -> dict:
    graph = {}

    def put_neighbours(n1: str, n2: str):
        if n1 in graph:
            graph[n1].append(n2)
        else:
            graph[n1] = [n2]
        if n2 in graph:
            graph[n2].append(n1)
        else:
            graph[n2] = [n1]

    put_neighbours('a', 'b')
    put_neighbours('a', 'c')
    put_neighbours('a', 'd')
    put_neighbours('b', 'c')
    put_neighbours('b', 'e')
    put_neighbours('c', 'd')
    put_neighbours('c', 'e')
    put_neighbours('c', 'f')
    put_neighbours('d', 'f')
    put_neighbours('d', 'g')
    put_neighbours('e', 'f')
    put_neighbours('e', 'g')
    put_neighbours('f', 'g')

    return graph

def neighbour_colors(node: str, graph: Graph, node_colors: dict[str, str])-> list[str]:
    neighbours = graph[node]
    return { n:node_colors[n] for n in neighbours if n in node_colors }

def start(graph: Graph, node_colors: dict[str, str] = {}):
    for key in graph:
        if key in node_colors:
            continue
        nc = neighbour_colors(key, graph, node_colors)
        available_colours = [color for color in COLORS if color not in nc.values()]
        print(f"\nColours available for {key} : ", available_colours)
        for c in available_colours:
            node_colors[key] = c
            print(f"\nApplying colour : {c} to node {key}")
            if color_list := start(graph, node_colors):
                if len(color_list) == len(graph):
                    return color_list
    return node_colors

def main() -> None:
    graph = generate_graph()
    print("\nMap Structure : ")
    for node, neighbours in graph.items():
        print(f"Node {node} has neighbours : ", neighbours)
    colors = start(graph) 
    print('\n', "After colouring ", sep='')
    for node, color in colors.items():
        print(f"Node {node} : {color:<6}")

if __name__ == '__main__':
    main()
