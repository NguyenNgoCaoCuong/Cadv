#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "mygraph.h"
#include "jval.h"
#include "fields.h"
#include "jrb.h"


void readFile(Graph *graph);
void inDanhSach(const Graph *graph);
void banThanThietNhat(const Graph *graph);
void kiemTraQuanHeBacCau(const Graph *graph);
void banChung(const Graph *graph);


void MENU(Graph *graph){
    char c;
    while (1){
        printf("\n--------- MENU --------\n");
        printf("1.In danh sach.\n");
        printf("2.Ban than thiet nhat.\n");
        printf("3.Kiem tra quan he bac cau.\n");
        printf("4.Tim banchung.\n");
        printf("5.Thoat.\n");
        __fpurge(stdin);
        scanf("%c",&c);
        switch (c) {
            case '1' :
                inDanhSach(graph);
                break;
            case '2' :
                banThanThietNhat(graph);
                break;
            case '3' :
                kiemTraQuanHeBacCau(graph);
                break;
            case '4' :
                banChung(graph);
                break;
            case '5' :
                break;
            default:
                printf("Lua chon khong phu hop.!");
        }
        if(c == '5') break;
    }
}

int main(){
    Graph  graph;
    createGraph(&graph);
    readFile(&graph);
    MENU(&graph);
    dropGraph(&graph);
    return 0;
}
void readFile(Graph *graph){
    IS is = new_inputstruct("data.txt");
    int m;
    int n;
    get_line(is);
    m = atoi(is->fields[0]);
    n = atoi(is->fields[1]);
    for (int i = 0; i < m; ++i){
        get_line(is);
        addVertex(graph,atoi(is->fields[0]),is->fields[1]);
    }
    for (int j = 0; j < n; ++j) {
        get_line(is);
        int weight = (int)(atof(is->fields[2])*100);
        addEdge(graph,atoi(is->fields[0]),atoi(is->fields[1]),&weight);
        addEdge(graph,atoi(is->fields[1]),atoi(is->fields[0]),&weight);
    }
    jettison_inputstruct(is);
}
void inDanhSach(const Graph *graph){
    printGraph(graph,0);
}
void banThanThietNhat(const Graph *graph){
    int id;
    printf("Nhap vao id cua nguoi can kiem tra : ");
    __fpurge(stdin);
    scanf("%d",&id);
    int max = 0;
    JRB p;
    jrb_traverse(p,graph->vertex)
        if(getweight(graph,id,jval_i(p->key)) > max) max = getweight(graph,id,jval_i(p->key));
    if(max > 0){
        printf("%.3f\n",(float )max/100);
        jrb_traverse(p,graph->vertex)
            if(getweight(graph,id,jval_i(p->key)) == max)
                printf("%d %s\n",jval_i(p->key),getName(graph,jval_i(p->key)));
    }else printf("%d\n",-1);
}
void kiemTraQuanHeBacCau(const Graph *graph){
    int total;
    int link[100];
    int id1,id2;
    printf("Nhap vao id cua nguoi thu nhat : ");
    __fpurge(stdin);
    scanf("%d",&id1);
    printf("Nhap vao id cua nguoi thu hai : ");
    __fpurge(stdin);
    scanf("%d",&id2);

    total = getConnected(graph,id1,link);
    for (int i = 0; i < total; ++i)
        if(link[i] == id2){
            printf("%d",-1);
            return ;
        }


    total = DFS(graph,id1,id2,NULL,link,NULL,NULL,0);
    if(total < 1 ) printf("%d\n",-1);
    else printf("%d\n",1);
}
void banChung(const Graph *graph){
    int total1;
    int link1[100];
    int total2;
    int link2[100];
    int id1,id2;
    printf("Nhap vao id cua nguoi thu nhat : ");
    __fpurge(stdin);
    scanf("%d",&id1);
    printf("Nhap vao id cua nguoi thu hai : ");
    __fpurge(stdin);
    scanf("%d",&id2);
    total1 = getConnected(graph,id1,link1);
    total2 = getConnected(graph,id2,link2);
    int t = 0;
    for (int i = 0; i < total1; ++i)
        for (int j = 0; j < total2; ++j)
            if(link1[i] == link2[j]) ++t;
    printf("%d\n",t);
    if(t > 0)
        for (int i = 0; i < total1; ++i)
            for (int j = 0; j < total2; ++j)
                if(link1[i] == link2[j]) printf("%d %s\n",link1[i],getName(graph,link1[i]));
}
