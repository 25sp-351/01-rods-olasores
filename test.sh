#!/bin/bash

# Color codes for output
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Compile the program
echo "Compiling main.c..."
gcc main.c -o main
if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

# Function to run a test case
run_test() {
    local test_num=$1
    local input=$2
    local length=$3
    local expected=$4
    
    echo "Running Test Case ${test_num}..."
    echo "Input:"
    echo "$input"
    echo "Expected Output:"
    echo "$expected"
    echo "Actual Output:"
    
    # Run the test and capture output
    actual=$(echo -e "$input" | ./main $length)
    echo "$actual"
    
    # Compare output (ignoring whitespace)
    if [ "$(echo "$actual" | tr -d '[:space:]')" = "$(echo "$expected" | tr -d '[:space:]')" ]; then
        echo -e "${GREEN}Test $test_num Passed!${NC}"
    else
        echo -e "${RED}Test $test_num Failed!${NC}"
    fi
    echo "----------------------------------------"
}

# Test Case 1
input1="10, 5
15, 7
20, 10"
expected1="2 @ 20 = 20
Remainder: 5
Value: 20"
run_test 1 "$input1" 45 "$expected1"

# Test Case 2
input2="5, 2
10, 4
25, 10"
expected2="1 @ 25 = 10
1 @ 5 = 2
Remainder: 0
Value: 12"
run_test 2 "$input2" 30 "$expected2"

echo "All tests completed."