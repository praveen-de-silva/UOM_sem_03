# =================
#     A* Search
# =================

import heapq

class Node:
    def __init__(self, position, g=0, h=0, parent=None):
        self.position = position
        self.g = g
        self.h = h
        self.f = g + h
        self.parent = parent

    def __lt__(self, other):
        return self.f < other.f

def heuristic(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

def a_star_search(grid, start, goal):
    rows, cols = len(grid), len(grid[0])
    open_list = [] # heap ordered by f() = g() + h()
    closed_set = set()

    start_node = Node(start, 0, heuristic(start, goal))
    heapq.heappush(open_list, start_node)

    while open_list:
        crnt_node = heapq.heappop(open_list)

        if crnt_node.position == goal:
            path = []

            while crnt_node:
                path.append(crnt_node.position)
                crnt_node = crnt_node.parent

            return path[::-1]

        closed_set.add(crnt_node.position)

        for dx, dy in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
            neighbor_pos = (crnt_node.position[0] + dx, crnt_node.position[1] + dy)
            
            if (0 <= neighbor_pos[0] < rows and 0 <= neighbor_pos[1] < cols and grid[neighbor_pos[0]][neighbor_pos[1]] == 0 and neighbor_pos not in closed_set): # check va;idity of the neighbor node
                g_cost = crnt_node.g + 1
                h_cost = heuristic(neighbor_pos, goal)
                neighbor_node = Node(neighbor_pos, g_cost, h_cost, crnt_node)

                if any(n.position == neighbor_pos and n.f <= neighbor_node.f for n in open_list): # check if there are some better node in openlist than the neighbor node
                    continue
                  
                heapq.heappush(open_list, neighbor_node)
    return None

if __name__=='__main__':
    grid = [
        [0, 0, 0, 0, 0],
        [0, 1, 1, 1, 0],
        [0, 0, 0, 1, 0],
        [1, 1, 0, 0, 0],
        [0, 0, 0, 1, 0]
    ]

    start = (0, 0)
    goal = (4, 4)

    path = a_star_search(grid, start, goal)
    print("Path found: ", path)


            
