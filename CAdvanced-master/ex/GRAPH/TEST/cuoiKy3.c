#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mygraph.h"
#include "jrb.h"
#include "jval.h"
#include "fields.h"

int readFile(Graph *,char *);
void check2(char *);
void check3(const Graph *,char *);
void check4(const Graph *,char *,int );
void check5(const Graph *,char **,int );
int main(int agrc,char *agrv[]){
    if(agrc < 2){
        printf("So luong tham so khong phu hop!");
        return -1;
    }
    if(agrc == 2){
        check2(agrv[1]);
        return 0;
    }
    Graph graph;
    createGraph(&graph);
    if(!readFile(&graph,agrv[2])){
        printf("Khong the mo file!\n");
        return -1;
    }
    if(agrc == 3) check3(&graph,agrv[1]);
    else if(agrc == 4) check4(&graph,agrv[1],atoi(agrv[3]));
    else  check5(&graph,agrv,agrc);
    return 0;
}

int readFile(Graph *graph,char *fileName){
    IS is = new_inputstruct(fileName);
    if(is->f == NULL) return 0;
    int n;
    get_line(is);
    n = atoi(is->fields[0]);
    for (int i = 0; i < n; ++i) {
        get_line(is);
        addVertex(graph,atoi(is->fields[0]),is->fields[1]);
    }
    get_line(is);
    n = atoi(is->fields[0]);
    for (int j = 0; j < n; ++j) {
        get_line(is);
        int weight = atoi(is->fields[2]);
        addEdge(graph,atoi(is->fields[0]),atoi(is->fields[1]),&weight);
        addEdge(graph,atoi(is->fields[1]),atoi(is->fields[0]),&weight);
    }
    jettison_inputstruct(is);
    return 1;
}

void check2(char *string){
    if(strcmp(string,"-h") == 0) printf("C-Advaned ,HK20152\n");
    else printf("Tham so khong hop le.!\n");
}
void check3(const Graph *graph,char *string){
    if(strcmp(string,"-v") == 0){
        JRB p;
        jrb_traverse(p,graph->vertex)
            if(p != NULL) printf("%-5d%s\n",jval_i(p->key),jval_s(p->val));
    }
    else printf("Tham so dong lenh khong hop le!!\n");
}
void check4(const Graph *graph,char *string,int id1){
    int connect[100];
    int total = getConnected(graph,id1,connect);
    if(strcmp(string,"-n") ==  0 && total != 0){
        printf("%d\n",total);
        for (int i = 0; i < total; ++i)
            printf("%-5d%-20s%d\n",connect[i],getName(graph,connect[i]),getweight(graph,id1,connect[i]));
    }
}
void check5(const Graph *graph,char *agrv[],int agrc){
    if(strcmp(agrv[1],"-w") == 0) {
        int weight = getweight(graph,atoi(agrv[3]),atoi(agrv[4]));
        if(weight != -1) printf("%d\n",weight);
    }else if(strcmp(agrv[1],"-p") == 0){
        int link[100];
        int weight;
        int total = dijkstra(graph,atoi(agrv[3]),atoi(agrv[4]),NULL,&weight,link,0);
        if(total > 0) printf("%d\n",weight);
    }else if(strcmp(agrv[1],"-s") == 0){
        Graph graph1;
        createGraph(&graph1);
        for(int i = 3;i < agrc;i++){
            char *name = getName(graph,atoi(agrv[i]));
            if(name == NULL){
                printf("Tham so cac id khong phu hop!\n");
                dropGraph(&graph1);
                return ;
            }
            addVertex(&graph1,atoi(agrv[i]),getName(graph,atoi(agrv[i])));
        }
        JRB p;
        jrb_traverse(p,graph1.vertex){
            int connect[100];
            int total = getConnected(graph,jval_i(p->key),connect);
            for (int i = 0; i < total; ++i)
                if(getName(&graph1,connect[i]) != NULL && checkLinked(&graph1,jval_i(p->key),connect[i]) == 0 && checkLinked(&graph1,connect[i],jval_i(p->key)) == 0){
                    int w = getweight(graph,jval_i(p->key),connect[i]);
                    addEdge(&graph1,jval_i(p->key),connect[i],&w);
                }
        }
        printf("%d\n",getVertexCount(&graph1));
        jrb_traverse(p,graph1.vertex)
            if(p != NULL) printf("%-5d%s\n",jval_i(p->key),jval_s(p->val));
        printf("%d\n",getEdgesCount(&graph1));
        jrb_traverse(p,graph1.edges)
            if(p != NULL){
                JRB tree = (JRB)jval_v(p->val);
                JRB s;
                if(tree != NULL )
                    jrb_traverse(s,tree)
                        if(s != NULL) printf("%-5d%-5d%d\n",jval_i(p->key),jval_i(s->key),jval_i(s->val));
            }
        dropGraph(&graph1);
    }
}
