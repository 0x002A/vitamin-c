#!/bin/bash

set -e
set -o pipefail

mkdir -p build && cd build

# Configure
cmake -DCMAKE_BUILD_TYPE=Debug ..
# Build
cmake --build . --config Debug -- -j $(nproc)
# Test
ctest -j $(nproc) --output-on-failure
