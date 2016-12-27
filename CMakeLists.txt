cmake_minimum_required(VERSION 3.5)
project(get_next_line)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

set(SOURCE_FILES main.c get_next_line.h get_next_line.c)
add_executable(get_next_line ${SOURCE_FILES} main.c get_next_line.h get_next_line.c)
TARGET_LINK_LIBRARIES(get_next_line /nfs/2016/a/alushenk/ClionProjects/get_next_line/libft.a)