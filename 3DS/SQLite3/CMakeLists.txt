cmake_minimum_required(VERSION 3.20)
project(sqlite3)

file(DOWNLOAD "https://sqlite.org/2025/sqlite-amalgamation-3510100.zip" "sqlite3.zip")

message(STATUS "unzipping file")
execute_process( COMMAND unzip -jo "sqlite3.zip" -d "${CMAKE_CURRENT_SOURCE_DIR}")


add_library(sqlite3 sqlite3.c )

# 3DS: no sys/mman.h, so disable mmap
target_compile_definitions(sqlite3 PRIVATE
    # Make that sys/mman.h guard false:
    SQLITE_OMIT_WAL           # <- this is the key one
    SQLITE_MAX_MMAP_SIZE=0    # must be numeric 0
    SQLITE_OMIT_LOAD_EXTENSION
)

INSTALL(TARGETS sqlite3 LIBRARY DESTINATION lib )