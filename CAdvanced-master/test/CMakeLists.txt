project(login C)

add_executable(login login.c)
include_directories(gtk-)
target_link_libraries(login fdr)