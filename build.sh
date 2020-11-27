#!/bin/sh
[ ! -f "./CMakeLists.txt" ] && echo "[CMakeLists.txt] missing!" >&2 && exit 1

set -e

mkdir -p ./build/
cd ./build/
cmake ../
make
cd ..
mv ./build/pipestatus .
