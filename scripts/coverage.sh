#!/bin/bash

# Exit immediately if any command fails
set -e

# Navigate to the project root directory (assuming the script is run from scripts/ or root)
cd "$(dirname "$0")/.."

echo "========================================="
echo "Cleaning old build files..."
echo "========================================="
rm -rf build
mkdir build
cd build

echo "========================================="
echo "Configuring CMake with coverage..."
echo "========================================="
cmake -DENABLE_COVERAGE=ON ..

echo "========================================="
echo "Building project and tests..."
echo "========================================="
cmake --build .

echo "========================================="
echo "Running tests via CTest..."
echo "========================================="
ctest --output-on-failure

echo "========================================="
echo "Capturing coverage data..."
echo "========================================="
# 1. Capture baseline
lcov --capture --initial --directory . --output-file coverage_base.info --ignore-errors mismatch

lcov --remove coverage_base.info \
     '/usr/*' \
     '*/_deps/*' \
     '*/tests/*' \
     '*googletest*' \
     '*googlemock*' \
     --output-file filtered_coverage_base.info \
     --ignore-errors unused

# 2. Capture test execution data
lcov --capture --directory . --output-file coverage_test.info --ignore-errors mismatch

lcov --remove coverage_test.info \
     '/usr/*' \
     '*/_deps/*' \
     '*/tests/*' \
     '*googletest*' \
     '*googlemock*' \
     --output-file filtered_coverage_test.info \
     --ignore-errors unused

# 3. Combine trace files
lcov --add-tracefile filtered_coverage_base.info \
     --add-tracefile filtered_coverage_test.info \
     --output-file coverage_total.info

# 4. Filter out system libraries, dependencies, and test files
lcov --remove coverage_total.info \
     '/usr/*' \
     '*/_deps/*' \
     '*/tests/*' \
     '*googletest*' \
     '*googlemock*' \
     --output-file coverage_final.info

echo "========================================="
echo "Generating HTML Report..."
echo "========================================="
genhtml coverage_final.info --output-directory coverage_html

echo "========================================="
echo "Success! Report generated at:"
echo "build/coverage_html/index.html"
echo "========================================="