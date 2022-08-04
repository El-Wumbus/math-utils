#!/usr.bin/env bash

cmake -DCMAKE_INSTALL_PREFIX="./build" .
cmake --build . --config Release --target all