#!/bin/bash

PROJECT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
BUILD_DIR="${PROJECT_DIR}/build/"
CONAN_DIR="${PROJECT_DIR}/conan/"

if [ -d "$BUILD_DIR" ]; then
    cd $BUILD_DIR
else
    mkdir $BUILD_DIR
    cd $BUILD_DIR
fi

conan install ${CONAN_DIR}
cmake .. -DCMAKE_BUILD_TYPE=test
cmake --build .