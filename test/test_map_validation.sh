#!/bin/bash

BIN="../so_long"
MAP_DIR="../maps/errors"


# Test cases for map validation
# Test case 1: Map with no player
echo "Running test case 1: Map with no player"
output=$($BIN $MAP_DIR/no_player.ber 2>&1)
if echo "$output" | grep -q "Map must contain a single player."; then
    echo "Test case 1 passed"
else
    echo "Test case 1 failed: Expected error for map with no player"
    echo "Output was: $output"
fi
# Test case 2: Map with no exit
echo "Running test case 2: Map with no exit"
output=$($BIN $MAP_DIR/no_exit.ber 2>&1)
if echo "$output" | grep -q "Map must contain a single exit."; then
    echo "Test case 2 passed"
else
    echo "Test case 2 failed: Expected error for map with no exit"
    echo "Output was: $output"
fi
# Test case 3: Map with no collectible
echo "Running test case 3: Map with no collectible"
output=$($BIN $MAP_DIR/no_collectible.ber 2>&1)
if echo "$output" | grep -q "Map must contain at least one collectible."; then
    echo "Test case 3 passed"
else
    echo "Test case 3 failed: Expected error for map with no collectible"
    echo "Output was: $output"
fi
# Test case 4: Map with multiple players
echo "Running test case 4: Map with multiple players"
output=$($BIN $MAP_DIR/dup_player.ber 2>&1)
if echo "$output" | grep -q "Map must contain a single player."; then
    echo "Test case 4 passed"
else
    echo "Test case 4 failed: Expected error for map with multiple players"
    echo "Output was: $output"
fi
# Test case 5: Map with multiple exits
echo "Running test case 5: Map with multiple exits"
output=$($BIN $MAP_DIR/dup_exit.ber 2>&1)
if echo "$output" | grep -q "Map must contain a single exit."; then
    echo "Test case 5 passed"
else
    echo "Test case 5 failed: Expected error for map with multiple exits"
    echo "Output was: $output"
fi

# Test case 7: Map with invalid characters
echo "Running test case 7: Map with invalid characters"
output=$($BIN $MAP_DIR/invalid_chars.ber 2>&1)
if echo "$output" | grep -q "Map contains invalid characters."; then
    echo "Test case 7 passed"
else
    echo "Test case 7 failed: Expected error for map with invalid characters"
    echo "Output was: $output"
fi
# Test case 8: Map with invalid dimensions
echo "Running test case 8: Map with invalid dimensions"
output=$($BIN $MAP_DIR/not_rectangular.ber 2>&1)
if echo "$output" | grep -q "Map must be rectangular."; then
    echo "Test case 8 passed"
else
    echo "Test case 8 failed: Expected error for map with invalid dimensions"
    echo "Output was: $output"
fi
# Test case 9: Map with invalid wall structure
echo "Running test case 9: Map with invalid wall structure"
output=$($BIN $MAP_DIR/no_walls.ber 2>&1)
if echo "$output" | grep -q "Map is not surrounded by walls."; then
    echo "Test case 9 passed"
else
    echo "Test case 9 failed: Expected error for map with invalid wall structure"
    echo "Output was: $output"
fi
# Test case 10: Map with unreachable exit
echo "Running test case 10: Map with unreachable exit"
output=$($BIN $MAP_DIR/unreachable_exit1.ber 2>&1)
if echo "$output" | grep -q "Exit not reachable from start position."; then
    echo "Test case 10 passed"
else
    echo "Test case 10 failed: Expected error for map with unreachable exit"
    echo "Output was: $output"
fi
# Test case 11: Map with unreachable exit
echo "Running test case 11: Map with unreachable exit"
output=$($BIN $MAP_DIR/unreachable_exit2.ber 2>&1)
if echo "$output" | grep -q "Exit not reachable from start position."; then
    echo "Test case 11 passed"
else
    echo "Test case 11 failed: Expected error for map with unreachable exit"
    echo "Output was: $output"
fi
# Test case 12: Map with unreachable collectible
echo "Running test case 12: Map with unreachable collectible"
output=$($BIN $MAP_DIR/unreachable_colls1.ber 2>&1)
if echo "$output" | grep -q "Not all collectibles reachable."; then
    echo "Test case 12 passed"
else
    echo "Test case 12 failed: Expected error for map with unreachable collectible"
    echo "Output was: $output"
fi
# Test case 13: Map with no top wall
echo "Running test case 13: Map with no top wall"
output=$($BIN $MAP_DIR/no_top.ber 2>&1)
if echo "$output" | grep -q "Map is not surrounded by walls."; then
    echo "Test case 13 passed"
else
    echo "Test case 13 failed: Expected error for map with no top wall"
    echo "Output was: $output"
fi
# Test case 14: Map with no bottom wall
echo "Running test case 14: Map with no bottom wall"
output=$($BIN $MAP_DIR/no_bottom.ber 2>&1)
if echo "$output" | grep -q "Map is not surrounded by walls."; then
    echo "Test case 14 passed"
else
    echo "Test case 14 failed: Expected error for map with no bottom wall"
    echo "Output was: $output"
fi
# Test case 15: Map with no left wall
echo "Running test case 15: Map with no left wall"
output=$($BIN $MAP_DIR/no_left.ber 2>&1)
if echo "$output" | grep -q "Map is not surrounded by walls."; then
    echo "Test case 15 passed"
else
    echo "Test case 15 failed: Expected error for map with no left wall"
    echo "Output was: $output"
fi
# Test case 16: Map with no right wall
echo "Running test case 16: Map with no right wall"
output=$($BIN $MAP_DIR/no_right.ber 2>&1)
if echo "$output" | grep -q "Map is not surrounded by walls."; then
    echo "Test case 16 passed"
else
    echo "Test case 16 failed: Expected error for map with no right wall"
    echo "Output was: $output"
fi
# Test case 17: Map with broken walls
echo "Running test case 17: Map with broken walls"
output=$($BIN $MAP_DIR/broken_walls.ber 2>&1)
if echo "$output" | grep -q "Map is not surrounded by walls."; then
    echo "Test case 17 passed"
else
    echo "Test case 17 failed: Expected error for map with broken walls"
    echo "Output was: $output"
fi
# Test case 18: Map with invalid extension
echo "Running test case 18: Map with invalid extension"
output=$($BIN $MAP_DIR/invalid_extension.txt 2>&1)
if echo "$output" | grep -q "Invalid file extension"; then
    echo "Test case 18 passed"
else
    echo "Test case 18 failed: Expected error for map with invalid extension"
    echo "Output was: $output"
fi
# Test case 19: Map file does not exist
echo "Running test case 19: Map file does not exist"
output=$($BIN $MAP_DIR/non_existent_map.ber 2>&1)
if echo "$output" | grep -q "Error opening file"; then
    echo "Test case 19 passed"
else
    echo "Test case 19 failed: Expected error for non-existent map file"
    echo "Output was: $output"
fi

