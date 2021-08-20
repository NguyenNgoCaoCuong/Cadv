project(DEMO C)

add_executable(demo1 demo1.c)

target_link_libraries(demo1 fdr)

if(USE_IGRAPH)
    add_executable(demo2 demo2.c)
    target_link_libraries(demo2 ${IGRAPH_LIBS} fdr)
endif(USE_IGRAPH)