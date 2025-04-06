|   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 |
|---|---|---|---|---|---|---|---|---|---|---|----|----|
| 0 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |  1 |  1 |
| 1 | 1 | E | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |  0 |  1 |
| 2 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |  0 |  1 |
| 3 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |  0 |  1 |
| 4 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |  0 |  1 |
| 5 | 1 | 0 | 0 | C | 0 | 0 | 0 | 0 | 0 | 0 |  0 |  1 |
| 6 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |  0 |  1 |
| 7 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | C |  0 |  1 |
| 8 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |  0 |  1 |
| 9 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |  0 |  1 |
| 10| 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |  P |  1 |
| 11| 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |  1 |  1 |

Get init Positions
P	map[10][10]
C	map[3][5], map[9][7]
E	map[1][1]

Path Calculation:
Find a valid path from P to E:
1. Check if the path is valid
2. Check if the path is blocked by walls
3. Check if collectibles are reachable


Flood-Fill Algorithm for Path Validation
Use Breadth-First Search (BFS) or Depth-First Search (DFS) to check reachability.
Key Steps:
- Locate P (player) and E (exit) positions.
- Flood-fill from P, marking reachable cells.
- Verify E and all C are reachable.

Flood-Fill Algorithm:
1. Initialize a queue, `q`, with the starting position P.
2. While the queue is not empty:
   a. Dequeue a position.
   b. Check if it is E or C.
   c. If it is E, return success.
   d. If it is C, mark as collected.
   e. For each adjacent cell (up, down, left, right):
	  i. If the cell is valid and not blocked:
		 - Mark as visited.
		 - Enqueue the cell.
3. If the queue is empty and E is not reached, return failure.
