#!/bin/sh

BUILD_DIR="./build"
PROJECT_NAME="Vulgine"

if [ -d "$BUILD_DIR" ] && [ -f "$BUILD_DIR/${PROJECT_NAME}" ]; then
    echo "Running program ($PROJECT_NAME)..."
    $BUILD_DIR/$PROJECT_NAME
else
    echo "Build does not exist, please run ./build.sh first!"
fi