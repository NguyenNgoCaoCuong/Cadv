#include <stdio.h>
#include <igraph/igraph.h>

int readFile(igraph_matrix_t *matrix){
    FILE *f = fopen("file.txt","r");
    if(f == NULL){
        printf("Loi mo file!!");
        return 0;
    }
    int n;
    fscanf(f,"%d",&n);
    igraph_matrix_init(matrix,(long)n,(long)n);
    for (int k = 0; k < n; ++k)
        for (int l = 0; l < n; ++l)
            fscanf(f,"%lf",igraph_matrix_e_ptr(matrix,k,l));
    fclose(f);
    return 1;
}
int main(int argc,char *argv[]){
    igraph_t graph;
    igraph_matrix_t matrix;
    igraph_vs_t vs;
    igraph_vit_t  vit;


    if(!readFile(&matrix)) return -1;

    igraph_weighted_adjacency(&graph,&matrix,IGRAPH_ADJ_DIRECTED,NULL,0);
    igraph_vs_all(&vs);
    igraph_vit_create(&graph,vs,&vit);

    printf("Danh sach cac dinh cua do thi : ");
    while(!IGRAPH_VIT_END(vit)){
        printf("%5d",(int)IGRAPH_VIT_GET(vit));
        IGRAPH_VIT_NEXT(vit);
    }
    

    igraph_vit_destroy(&vit);
    igraph_vs_destroy(&vs);
    igraph_matrix_destroy(&matrix);
    igraph_destroy(&graph);
    return 0;
}