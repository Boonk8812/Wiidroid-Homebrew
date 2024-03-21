cmake_minimum_required(VERSION 2.8 FATAL_ERROR) # Minimal supported CMake version
project(WiidroidHomebrew)

# Set include directories
file(GLOB HEADERS RELATIVE_PATH "." "*.h")
file(GLOB SOURCES RELATIVE_PATH "." "*.c" "*".cpp)

# Add sources
add_executable(WiidroidHomebrew ${SOURCES} ${HEADERS})

# Install the executable
install(TARGETS WiidroidHomebrew DESTINATION bin)
