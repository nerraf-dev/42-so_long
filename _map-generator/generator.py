import random
from collections import deque

def generate_map(rows, cols):
    # Initialize the map with walls
    map_data = [['1' for _ in range(cols)] for _ in range(rows)]

    # Fill the map with empty spaces (0), leaving walls on the borders
    for i in range(1, rows-1):
        for j in range(1, cols-1):
            map_data[i][j] = '0'

    # Randomly place internal walls
    def place_internal_walls():
        for i in range(1, rows-1):
            for j in range(1, cols-1):
                if random.random() < 0.2:  # 20% chance to place a wall
                    map_data[i][j] = '1'

    place_internal_walls()

    # Randomly place the player (P), exit (E), and collectibles (C)
    def place_entity(entity, count=1):
        for _ in range(count):
            while True:
                x, y = random.randint(1, rows-2), random.randint(1, cols-2)
                if map_data[x][y] == '0':
                    map_data[x][y] = entity
                    break

    # Place the player (P)
    place_entity('P')

    # Place the exit (E)
    place_entity('E')

    # Place at least one collectible (C)
    place_entity('C', random.randint(1, 5))

    # Ensure the map is closed/surrounded by walls
    for i in range(rows):
        map_data[i][0] = '1'
        map_data[i][-1] = '1'
    for j in range(cols):
        map_data[0][j] = '1'
        map_data[-1][j] = '1'

    # Convert the map to a string representation
    map_str = '\n'.join(''.join(row) for row in map_data)

    return map_str

def is_map_valid(map_str):
    map_data = [list(row) for row in map_str.split('\n')]
    rows = len(map_data)
    cols = len(map_data[0]) if rows > 0 else 0

    # Check if the map is rectangular
    if not all(len(row) == cols for row in map_data):
        return False, "Map is not rectangular."

    # Check if the map is closed/surrounded by walls
    for i in range(rows):
        if map_data[i][0] != '1' or map_data[i][-1] != '1':
            return False, "Map is not closed by walls."
    for j in range(cols):
        if map_data[0][j] != '1' or map_data[-1][j] != '1':
            return False, "Map is not closed by walls."

    # Check for exactly one exit (E), at least one collectible (C), and exactly one starting position (P)
    entities = {'E': 0, 'C': 0, 'P': 0}
    for row in map_data:
        for cell in row:
            if cell in entities:
                entities[cell] += 1

    if entities['E'] != 1:
        return False, "Map must contain exactly one exit."
    if entities['C'] < 1:
        return False, "Map must contain at least one collectible."
    if entities['P'] != 1:
        return False, "Map must contain exactly one starting position."

    return True, "Map is valid."

def has_valid_path(map_str):
    map_data = [list(row) for row in map_str.split('\n')]
    rows = len(map_data)
    cols = len(map_data[0]) if rows > 0 else 0

    # Find the positions of P, E, and all C's
    start = None
    end = None
    collectibles = []
    for i in range(rows):
        for j in range(cols):
            if map_data[i][j] == 'P':
                start = (i, j)
            elif map_data[i][j] == 'E':
                end = (i, j)
            elif map_data[i][j] == 'C':
                collectibles.append((i, j))

    if not start or not end:
        return False

    # Breadth-First Search (BFS) to check if there's a path from P to E that collects all C's
    def bfs(start, end, collectibles):
        queue = deque([(start, set())])
        visited = set()

        while queue:
            (x, y), collected = queue.popleft()
            if (x, y) == end and collected.issuperset(collectibles):
                return True
            if (x, y) in visited:
                continue
            visited.add((x, y))

            for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                nx, ny = x + dx, y + dy
                if 0 <= nx < rows and 0 <= ny < cols and map_data[nx][ny] != '1':
                    new_collected = set(collected)
                    if (nx, ny) in collectibles:
                        new_collected.add((nx, ny))
                    queue.append(((nx, ny), new_collected))
        return False

    return bfs(start, end, collectibles)

def generate_valid_map(rows, cols, max_attempts=1000):
    attempts = 0
    while attempts < max_attempts:
        map_str = generate_map(rows, cols)
        is_valid, message = is_map_valid(map_str)
        if is_valid and has_valid_path(map_str):
            return map_str
        attempts += 1
    raise Exception("Failed to generate a valid map within the maximum number of attempts.")

# Generate a map with at least 20 lines
rows = 12
cols = 18  # Adjust the number of columns as needed
try:
    valid_map = generate_valid_map(rows, cols)
    print(valid_map)
except Exception as e:
    print(e)
