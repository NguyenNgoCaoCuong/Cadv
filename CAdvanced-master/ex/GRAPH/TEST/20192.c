#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "mygraph.h"
#include "jval.h"
#include "fields.h"
#include "jrb.h"
int t = 0;
float pageRank[100];
int idwed[100];
void readFile1(Graph *graph){
    IS is = new_inputstruct("webpages.txt");
    int n;
    int total = 0;
    get_line(is);
    n = atoi(is->fields[0]);
    printf("Danh sach cac webpage va url :\n");
    for(int i = 0; i < n; i++){
        get_line(is);
        printf("%-6d : %s\n",atoi(is->fields[1]),is->fields[0]);
        addVertex(graph, atoi(is->fields[1]), is->fields[0]);
        pageRank[total] = 1;
        idwed[total++]  =atoi(is->fields[1]);
    }

}
void readFile2(Graph *graph){
    IS is = new_inputstruct("pageConnections.txt");
    int m;
    get_line(is);
    m = atoi(is->fields[0]);
    for (int i = 0; i < m; ++i) {
        get_line(is);
        int weight = 1;
        for (int j = 1; j < is->NF; ++j)
            addEdge(graph,atoi(is->fields[0]),atoi(is->fields[j]),&weight);
    }
    int max = 0;
    int min = 0;
    JRB p;
    jrb_traverse(p,graph->vertex)
        if(p != NULL) {
            if(inDegree(graph,jval_i(p->key)) > max) max = inDegree(graph,jval_i(p->key));
            if(inDegree(graph,jval_i(p->key)) < min) min = inDegree(graph,jval_i(p->key));
        }
    printf("Wedpage co nhieu lien ket toi nhat la : ");
    jrb_traverse(p,graph->vertex)
        if(p != NULL && inDegree(graph,jval_i(p->key)) ==  max) printf("%5d",jval_i(p->key));
    printf("\nWedpage co it lien ket toi nhat la : ");
    jrb_traverse(p,graph->vertex)
        if(p != NULL && inDegree(graph,jval_i(p->key)) ==  min) printf("%5d",jval_i(p->key));
    jettison_inputstruct(is);
}
float getPR(const Graph  *graph,int id){
    for (int i = 0; i < getVertexCount(graph); ++i)
        if(idwed[i] == id) return pageRank[i];
}
int gid(Graph  *graph,int id){
    for (int i = 0; i <  getVertexCount(graph); ++i) {
        if(idwed[i] == id) return i;
    }
}
float PR(const Graph *graph){
    int connect[100];
    int total = 0;
    JRB p;
    jrb_traverse(p,graph->vertex){
        float pr = 0;
        total = getPreConnect(graph,jval_i(p->key),connect);
        for (int i = 0; i < total; ++i)
            pr = getPR(graph,connect[i])*1.0/outDegree(graph,connect[i]);
        pageRank[gid(graph,jval_i(p->key))] = pr;
    }
    ++t;
    if(t == 1){
        float min = 0;
        float max = 0;
        for (int j = 0; j < getVertexCount(graph); ++j){
            if(min > pageRank[j]) min = pageRank[j];
            if(max < pageRank[j]) max = pageRank[j];
        }
        printf("Cac url co pageRank lon nhat la : \n");
        for (int k = 0; k < getVertexCount(graph); ++k)
            if(max ==  pageRank[k]) printf("%s\n",getName(graph,idwed[k]));
        printf("Cac url co pageRank nho nhat la : \n");
        for (int k = 0; k < getVertexCount(graph); ++k)
            if(min ==  pageRank[k]) printf("%s\n",getName(graph,idwed[k]));
    }
}
void MENU1(Graph *graph){
    char c;
    while (1){
        printf("\n--------- MENU --------\n ");
        printf("1.In webpage va url.\n");
        printf("2.Wedpage co nhieu lie ket toi va it lien ket toi nhat.\n");
        printf("3.Exit.\n");
        __fpurge(stdin);
        scanf("%c",&c);
        switch (c) {
            case '1' :
                readFile1(graph);
                break;
            case '2' :
                readFile2(graph);
                break;
            case '3' :
                break;
            default:
                printf("Lua chon khong phu hop.!");
        }
        if(c == '3') break;
    }
}
void wedQuanTrong(const Graph *graph){
    int m;
    printf("Nhap vao so nguyen m : ");
    __fpurge(stdin);
    scanf("%d",&m);
    while(m <10 || m > 50){
        printf("Nhap lai so nguyen m : ");
        __fpurge(stdin);
        scanf("%d",&m);
    }
    while (t < m) PR(graph);
    float wrs[100];
    int ids[100];
    for (int i = 0; i < getVertexCount(graph); ++i) {
        wrs[i] = pageRank[i];
        ids[i] = idwed[i];
    }
    for (int j = 0; j < getVertexCount(graph) - 1; ++j)
        for (int k = j+1; k < getVertexCount(graph); ++k)
            if(wrs[j] < wrs[k]){
                float c = wrs[j];
                wrs[j] = wrs[k];
                wrs[k] = c;
                int d = ids[j];
                ids[j] = ids[k];
                ids[k] = d;
            }
    printf("Ba trang wed co muc do quan trong nhat la : \n");
    for (int l = 0; l < 3; ++l)
        printf("%s\n",getName(graph,ids[l]));
}
void wedin(const Graph *graph){
    int t = 0;
    JRB p;
    jrb_traverse(p,graph->vertex)
        if(p != NULL && inDegree(graph,jval_i(p->key)) > 0 && outDegree(graph,jval_i(p->key)) == 0)
            ++t;
    if(t == 0) printf("Khong ton tai trang wed\n");
    else printf("So luong trang wed la :%d\n",t);
}
void wedout(const Graph *graph){
    int t = 0;
    int id ;
    JRB p;
    jrb_traverse(p,graph->vertex){
        if(p != NULL && inDegree(graph,jval_i(p->key)) == 0 && outDegree(graph,jval_i(p->key)) > 0)
            ++t;
        id = jval_i(p->key);
    }
    if(t == 0) {
        printf("Khong ton tai trang wed : ");

    }
    else {
        printf("So luong trang wed la :%d\n",t);
        printf("dia chi url : %s \n",getName(graph,id));
    }
}
void MENU2(const Graph *graph){
    char c;
    while (1){
        printf("\n--------- MENU --------\n ");
        printf("1.So luong wed chi co lien ket den.\n");
        printf("2.So luong spam bot.\n");
        printf("3.Exit.\n");
        __fpurge(stdin);
        scanf("%c",&c);
        switch (c) {
            case '1' :
                wedin(graph);
                break;
            case '2' :
                wedout(graph);
                break;
            case '3' :
                break;
            default:
                printf("Lua chon khong phu hop.!");
        }
        if(c == '3') break;
    }
}
void khoangCachNhoNhat(const Graph *graph){
    int id1;
    int id2;
    printf("Nhap vao id thu 1 : ");
    __fpurge(stdin);
    scanf("%d",&id1);
    printf("Nhap vao id thu 2 : ");
    __fpurge(stdin);
    scanf("%d",&id2);
    if(getName(graph,id1) != NULL && getName(graph,id2) != NULL){
        int total;
        int weight;
        int link[100];
        total = dijkstra(graph,id1,id2,NULL,&weight,link,0);
        if(total > 0) printf("Khoang cach nho nhat la : %d\n",weight);
        else printf("Khong ton tai duong di can tim.\n");
    }else printf("Khong ton tai duong di can tim.\n");
}
void MENU(Graph *graph){
    char c;
    while (1){
        printf("\n--------- MENU --------\n ");
        printf("1.Doc file.\n");
        printf("2.Thuat toan PageRank.\n");
        printf("3.Thuat toan PageRank sau m lan lap.\n");
        printf("4.So luong wepage.\n");
        printf("5.Khoang cach giua hai id.\n");
        printf("6.Thoat.\n");
        __fpurge(stdin);
        scanf("%c",&c);
        switch (c) {
            case '1' :
                MENU1(graph);
                break;
            case '2' :
                PR(graph);
                break;
            case '3' :
                wedQuanTrong(graph);
                break;
            case '4' :
                MENU2(graph);
                break;
            case '5' :
                khoangCachNhoNhat(graph);
                break;
            case '6' :
                break;
            default:
                printf("Lua chon khong phu hop.!");
        }
        if(c == '6') break;
    }
}

int main(){
    Graph  graph;
    createGraph(&graph);
    MENU(&graph);
    dropGraph(&graph);
    return 0;
}
