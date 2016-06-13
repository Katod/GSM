cmake_minimum_required(VERSION 2.6)
project(hello)

link_directories(/usr/lib/x86_64-linux-gnu)


# link the libraries to the executable
link_libraries (libsqlite3.so)


add_executable(hello src/Column.cpp src/Database.cpp src/Statement.cpp src/Transaction.cpp src/client.cpp  src/main.cpp)
include_directories(include)

install(TARGETS hello RUNTIME DESTINATION bin)
add_subdirectory(src)