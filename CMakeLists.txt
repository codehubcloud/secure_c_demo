cmake_minimum_required(VERSION 3.10)

project(SecureCDemo C)

# Set C standard
set(CMAKE_C_STANDARD 99)

# Create securelib as a static library
add_library(securelib STATIC)

# Include directories for securelib
target_include_directories(securelib PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/securelib/include
)

# Add all .c files from securelib/src to the securelib target
file(GLOB SECURELIB_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/securelib/src/*.c
)

# Exclude input.inl and output.inl as they seem to be include files, not source files
list(FILTER SECURELIB_SOURCES EXCLUDE REGEX ".*input\.inl$")
list(FILTER SECURELIB_SOURCES EXCLUDE REGEX ".*output\.inl$")

target_sources(securelib PRIVATE ${SECURELIB_SOURCES})

# Create the main executable
add_executable(demo_project
    project_src/main.c
    project_src/demo_project.c
)

# Link securelib to the main executable
target_link_libraries(demo_project securelib)

# Include directories for the main executable
target_include_directories(demo_project PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/securelib/include
    ${CMAKE_CURRENT_SOURCE_DIR}/project_src
)