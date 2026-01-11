#!/bin/sh

BUILD_DIR="./build"
EXECUTABLE="vulgine"

if [ ! -d "$BUILD_DIR" ]; then
    echo "Build directory does not exist! Creating $BUILD_DIR..."
    mkdir "$BUILD_DIR"
else
    for i in 3 2 1; do
        echo -ne "Cleaning $BUILD_DIR in $i seconds...\r"
        sleep 1
    done
    echo "Cleaning $BUILD_DIR now..."
    rm -rf "$BUILD_DIR"
    mkdir "$BUILD_DIR"
fi

echo "Generating CMAKE Build..."
cmake -B "$BUILD_DIR" -S .

echo "Building Generated CMAKE Build..."
cmake --build "$BUILD_DIR"

echo -e "\n\n Operation Finished!"