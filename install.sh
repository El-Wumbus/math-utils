#!/usr.bin/env bash

cmake -DCMAKE_INSTALL_PREFIX="" -DCMAKE_CXX_COMPILER="clang++" -DCMAKE_C_COMPILER "clang" .
cmake --build . --config Release --target all