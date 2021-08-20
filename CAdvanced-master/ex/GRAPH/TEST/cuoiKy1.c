#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mygraph.h"
#include "fields.h"
#include "jrb.h"


int readFile(Graph *graph,char *nameFile){
    IS is = new_inputstruct(nameFile);
    if(is->f == NULL){
        printf("Không thể mở file!!\n");
        return 0;
    }
    int m,n;
    fscanf(is->f,"%d%d",&m,&n);
    get_line(is);
    for (int i = 0; i < m; ++i){
        get_line(is);
        addVertex(graph,atoi(is->fields[1]),is->fields[0]);
    }
    for (int j = 0; j < n; ++j) {
        get_line(is);
        addEdge(graph,atoi(is->fields[1]),atoi(is->fields[0]),NULL);
    }
    jettison_inputstruct(is);
    return 1;
}
void goiY(char *string){
    if(strcmp(string,"help") == 0) {
        printf("Supported commanf: help,about,i2n,n2i,cc,cr,odg,rel.\n");
        return;
    }
    if(strcmp(string,"about") == 0){
        printf("C advanced 20142 final exam.\n");
        return;
    }
    printf("Tham số đầu vào không hợp lệ!!\n");

}

void check4(const Graph *graph,char *string1,char *string2){
    if(strcmp(string1,"i2n") == 0  && isdigit(string2[0])){
        int id = atoi(string2);
        if(getName(graph,id) != NULL) printf("%s\n",getName(graph,id));
        else printf("Không tìm thấy tên cần tìm!\n");
    }else if(strcmp(string1,"n2i") == 0){
        int id = getID(graph,string2);
        if(id == -1) printf("Không tồn tại tên cần tìm!!\n");
        else printf("%d\n",id);
    }else if(strcmp(string1,"odg") == 0){
        int degree = atoi(string2);
        JRB g;
        jrb_traverse(g,graph->vertex){
            if(g != NULL && outDegree(graph,jval_i(g->key)) > degree)
                printf("%s\n",getName(graph,jval_i(g->key)));
        }
    } else if(strcmp(string1,"rel") == 0){
        int id = atoi(string2);
        int link[100];
        int total = DFS(graph,id,-1,NULL,link,NULL,NULL,0);
        for (int i = 0; i < total; ++i)
            printf("%s\n",getName(graph,link[i]));
    } else printf("Tham số đầu vào không phù hợp!");
}
void check5(Graph *graph,char * string,int id1,int id2){
    if(strcmp(string,"cc") == 0){
        JRB g;
        jrb_traverse(g,graph->edges){
            JRB tree = (JRB)jval_v(g->val);
            if(tree != NULL && jrb_find_int(tree,id1) != NULL && jrb_find_int(tree,id2) != NULL)
                printf("%s\n",getName(graph,jval_i(g->key)));
        }
    }
    else if(strcmp(string,"cr") == 0){
        int link1[100];
        int link2[100];
        int total1 = getConnected(graph,id1,link1);
        int total2 = getConnected(graph,id2,link2);
        for (int i = 0; i < total1; ++i)
            for (int j = 0; j < total2; ++j)
                if(link1[i] == link2[j]) printf("%s\n",getName(graph,link2[j]));
    }
}
int main(int argc,char *argv[]){
    if(argc == 2 || argc == 4 || argc == 5);
    else{
        printf("Thiếu tham số đầu vào!!\n");
        return -1;
    }
    if(argc == 2){
        goiY(argv[1]);
        return 0;
    }
    Graph graph;
    createGraph(&graph);
    if(!readFile(&graph,argv[2])) return -1;
    if(argc == 4)
        check4(&graph,argv[1],argv[3]);
    else if(argc == 5)
        check5(&graph,argv[1],atoi(argv[3]),atoi(argv[4]));
    dropGraph(&graph);
    return 0;
}
