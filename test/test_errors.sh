#!/bin/bash

BIN="../so_long"
MAP_DIR="../maps/errors"
USE_VALGRIND=false

# Check for optional --valgrind flag
if [[ "$1" == "--valgrind" ]]; then
    USE_VALGRIND=true
    VALGRIND_CMD="valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes"
    echo "Valgrind testing enabled."
else
    VALGRIND_CMD=""
fi

# Function to run a test case
run_test() {
    local test_name="$1"
    local map_file="$2"
    local expected_output="$3"

    echo "Running $test_name"
    if $USE_VALGRIND; then
        output=$($VALGRIND_CMD $BIN $map_file 2>&1)
    else
        output=$($BIN $map_file 2>&1)
    fi

    if echo "$output" | grep -q "$expected_output"; then
        echo "$test_name passed"
    else
        echo "$test_name failed: Expected error '$expected_output'"
        echo "Output was: $output"
    fi
}

# Test cases for map validation
run_test "Test case 1: Map with no player" "$MAP_DIR/no_player.ber" "Map must contain a single player."
run_test "Test case 2: Map with no exit" "$MAP_DIR/no_exit.ber" "Map must contain a single exit."
run_test "Test case 3: Map with no collectible" "$MAP_DIR/no_collectible.ber" "Map must contain at least one collectible."
run_test "Test case 4: Map with multiple players" "$MAP_DIR/dup_player.ber" "Map must contain a single player."
run_test "Test case 5: Map with multiple exits" "$MAP_DIR/dup_exit.ber" "Map must contain a single exit."
run_test "Test case 7: Map with invalid characters" "$MAP_DIR/invalid_chars.ber" "Map contains invalid characters."
run_test "Test case 8: Map with invalid dimensions" "$MAP_DIR/not_rectangular.ber" "Map must be rectangular."
run_test "Test case 9: Map with invalid wall structure" "$MAP_DIR/no_walls.ber" "Map is not surrounded by walls."
run_test "Test case 10: Map with unreachable exit" "$MAP_DIR/unreachable_exit1.ber" "Exit not reachable from start position."
run_test "Test case 11: Map with unreachable exit" "$MAP_DIR/unreachable_exit2.ber" "Exit not reachable from start position."
run_test "Test case 12: Map with unreachable collectible" "$MAP_DIR/unreachable_colls1.ber" "Not all collectibles reachable."
run_test "Test case 13: Map with no top wall" "$MAP_DIR/no_top.ber" "Map is not surrounded by walls."
run_test "Test case 14: Map with no bottom wall" "$MAP_DIR/no_bottom.ber" "Map is not surrounded by walls."
run_test "Test case 15: Map with no left wall" "$MAP_DIR/no_left.ber" "Map is not surrounded by walls."
run_test "Test case 16: Map with no right wall" "$MAP_DIR/no_right.ber" "Map is not surrounded by walls."
run_test "Test case 17: Map with broken walls" "$MAP_DIR/broken_walls.ber" "Map is not surrounded by walls."
run_test "Test case 18: Map with invalid extension" "$MAP_DIR/invalid_extension.txt" "Invalid file extension"
run_test "Test case 19: Map file does not exist" "$MAP_DIR/non_existent_map.ber" "Error opening file"
