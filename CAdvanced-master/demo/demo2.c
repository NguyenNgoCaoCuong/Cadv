#include <stdio.h>
#include <stdlib.h>
#include "igraph.h"
#include "fields.h"

void readFile(igraph_vector_t *vector){
    IS is = new_inputstruct("graph.txt");
    igraph_vector_init(vector,0);
    while(get_line(is) != EOF){
        igraph_vector_insert(vector,igraph_vector_size(vector),atoi(is->fields[0]));
        igraph_vector_insert(vector,igraph_vector_size(vector),atoi(is->fields[1]));
    }
}

void edgeList(const igraph_t igraph){
    igraph_es_t es;
    igraph_eit_t eit;

    igraph_es_all(&es,IGRAPH_EDGEORDER_FROM);
    igraph_eit_create(&igraph,es,&eit);
    printf("Danh sach cac canh cua do thi la : ");
    while(!IGRAPH_EIT_END(eit)){
        printf("%5d",IGRAPH_EIT_GET(eit));
        IGRAPH_EIT_NEXT(eit);
    }
    igraph_es_destroy(&es);
    igraph_eit_destroy(&eit);
}
void addAttribute(igraph_t *igraph){
    char type[20];
    char string[50];
    int area;
    FILE *f = fopen("graph_name.txt","r");
    if(f == NULL){
        printf("Khong the mo file!");
        return;
    }
    fgets(type,29,f);
    for (int k = 0; k < igraph_vcount(igraph); ++k) {
        fgets(string,49,f);
        SETVAS(igraph,type,k,string);
    }
    fgets(type,29,f);
    printf("%s",type);
    for (int k = 0; k < igraph_vcount(igraph); ++k) {
        fscanf(f,"%d",&area);
        SETEAN(igraph,type,k,area);
    }
    fclose(f);
}
void getNameV(const igraph_t *graph){
    int id;
    printf("Nhap vao id cua dinh can tim : ");
    scanf("%d",&id);
    if(id < 0 || id >= igraph_vcount(graph)) printf("ID khong ton tai\n");
     printf("Name : %s \n",VAS(graph,"name\n",id));

    if(igraph_i_attribute_has_attr(graph,IGRAPH_ATTRIBUTE_EDGE,"dien tich\n"))
        printf("%f",EAN(graph,"dien tich\n",id));
    else printf("Khong ton tai thuoc tinh dien tich!");
}
int checkConnected(const igraph_t *graph){
    int id1,id2;
    printf("\nNhap vao id cua hai dinh can xem : ");
    scanf("%d%d",&id1,&id2);
    igraph_bool_t boolean;
    igraph_are_connected(graph,id1,id2,&boolean);
    return boolean;
}
int main(int argc,char *argv[]){
    igraph_vector_t edge;
    igraph_t graph;

    igraph_i_set_attribute_table(&igraph_cattribute_table);
    readFile(&edge);
    igraph_create(&graph,&edge,0,IGRAPH_DIRECTED);
    addAttribute(&graph);
    getNameV(&graph);
    printf("Booleab : %d",checkConnected(&graph));
    DELALL(&graph);
    igraph_vector_destroy(&edge);
    igraph_destroy(&graph);
    return 0;
}