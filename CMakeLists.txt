cmake_minimum_required(VERSION 3.27)
project(6502emulator C)

set(SOURCE_FILES src/main.c src/cpu.c src/instructions.c)

add_compile_options(-fsanitize=undefined,address -Wall -Wextra -Werror -pedantic)
add_link_options(-fsanitize=undefined,address)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
include_directories(include/)

set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 23)