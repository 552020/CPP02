#!/bin/bash

# Define ANSI color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Test cases with expected results
declare -a tests=(
    "0.5 0.5 0 0 0 1 1 0 1"
    "-0.1 -0.1 0 0 0 1 1 0 0"
    "1 1 0 0 0 1 1 0 0"
    "0 0 0 0 0 1 1 0 0"
    "0.1 0.9 0 0 0 1 1 0 1"
    "0.5 0.1 0 0 0 1 1 0 1"
    "1 0 0 0 0 1 1 0 0"
    "0 1 0 0 0 1 1 0 0"
)

# Loop through each test case
for i in "${tests[@]}"; do
    # Split the test case into an array
    IFS=' ' read -r -a params <<< "$i"

    # Run the program with the test case parameters
    ./fixed "${params[@]:0:8}" > /dev/null
    result=$?

    # Check if the result matches the expected outcome
    if [ "$result" -eq "${params[8]}" ]; then
        echo -e "${GREEN}Test passed: Point (${params[0]}, ${params[1]}) with triangle ((${params[2]}, ${params[3]}), (${params[4]}, ${params[5]}), (${params[6]}, ${params[7]})) - Expected: ${params[8]}${NC}"
    else
        echo -e "${RED}Test FAILED: Point (${params[0]}, ${params[1]}) with triangle ((${params[2]}, ${params[3]}), (${params[4]}, ${params[5]}), (${params[6]}, ${params[7]})) - Expected: ${params[8]}, Got: $result${NC}"
    fi
done
