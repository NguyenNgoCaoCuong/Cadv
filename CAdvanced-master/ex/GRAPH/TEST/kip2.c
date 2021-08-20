#include <stdio.h>

#include "mygraph.h"
int main(){
    Graph graph;
    createGraph(&graph);


    addVertex(&graph,1,"hanoi");
    addVertex(&graph,2,"hanoi");
    addVertex(&graph,4,"hanoi");
    addVertex(&graph,3,"hanoi");
    addVertex(&graph,6,"hanoi");
    addVertex(&graph,8,"hanoi");

    addEdge(&graph,1,6,NULL);
    addEdge(&graph,1,8,NULL);
    addEdge(&graph,2,6,NULL);
    addEdge(&graph,4,1,NULL);

    printGraph(&graph,0);

    dropGraph(&graph);
    return 0;
}