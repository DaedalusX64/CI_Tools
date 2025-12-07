cmake_minimum_required(VERSION 3.20)
project(sqlite3)

file(DOWNLOAD "https://sqlite.org/2025/sqlite-amalgamation-3510100.zip" "sqlite3.zip")

message(STATUS "unzipping file")
execute_process( COMMAND unzip -jo "sqlite3.zip" -d "${CMAKE_CURRENT_SOURCE_DIR}")

if(CTR)
add_library(sqlite3 sqlite3.c sqlite3_stubs.c)
else()
add_library(sqlite3 sqlite3.c)
endif()

# CTR Toolchain lacks all the below. yay
if(CTR)
target_compile_definitions(sqlite3 PRIVATE
    SQLITE_OMIT_WAL
    SQLITE_MAX_MMAP_SIZE=0
    SQLITE_DISABLE_MMAP
    SQLITE_OMIT_LOAD_EXTENSION
    SQLITE_OMIT_DYNAMIC_EXTENSION
    SQLITE_THREADSAFE=0

)
endif()

INSTALL(TARGETS sqlite3 ARCHIVE DESTINATION lib )
INSTALL(FILES sqlite3.h DESTINATION include)