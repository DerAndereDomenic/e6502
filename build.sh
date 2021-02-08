BUILD_DIR="build"

if [ ! -d "$BUILD_DIR" ]; then
    echo "Creating Build directory!";
    mkdir "$BUILD_DIR";
    cd "$BUILD_DIR"
    cmake .. -G "MinGW Makefiles"
else
    cd "$BUILD_DIR"
    cmake --build .
fi