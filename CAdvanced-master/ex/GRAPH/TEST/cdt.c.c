#include <stdio.h>
#include <ctype.h>
#include "queue.h"
#include "mygraph.h"

typedef struct Egdes{
    int id1;
    int id2;
    int sentencesArr[20];
    int count;
} Egdes ;
int xoaKhoangTrang(FILE *f){
    int c = fgetc(f);
    while(c == (int)(' ')){
        if(feof(f)) return -1;
        c = fgetc(f);

    }
    return c;
}
int readFile(char *fileName, Graph *graph){
    FILE *f = fopen(fileName, "r");
    int cau = 1;
    int c;
    c = xoaKhoangTrang(f);
    char xau[100][100];
    int i = 0;
    int j = 0;
    int id = 1;

    while(!feof(f)) {
        if ((!isalpha(c)) && (!isdigit(c))) {
            xau[i][j] = '\0';
            if(getID(graph, xau[i]) == -1){
                addVertex(graph, id++, xau[i]);
            }
            addEdge(graph,getID(graph,xau[i]),cau, NULL);
            if ( c != ' ') cau++;
            if((c = xoaKhoangTrang(f)) == -1) break;
            j = 0;
            ++i;
            continue;
        }
        xau[i][j] = (char)c;
        c = fgetc(f);
        ++j;
     }
    fclose(f);
}
int check(int *arr, int arr1[], int arr2[], int c, int d){
    int count = 0;
    for(int i = 0; i < c; i++){
        for(int j = 0; j < d; j++){
            if(arr1[i] == arr2[j]){
                arr[count] = arr1[j];
                ++count;
            }
        }
    }
    return count;
}
int sapXep(Egdes *egdes, int total){
    for(int i = 0;i < total; i++){
        for(int j = i + 1; j < total; j++){
            if(egdes[i].count < egdes[j].count){
                Egdes eg = egdes[i];
                egdes[i] = egdes[j];
                egdes[j] = eg;
            }
        }
    }
}
int search(Graph *graph){
    printf("Cac tu xuat hien cung nhau theo thu tu giam dan : \n");
    int arr[20];
    int arr1[20];
    Egdes edges[100];
    int m = 0;
    for(int i = 0 ; i < getVertexCount(graph); i++){
        for(int j = i + 1; j < getVertexCount(graph); j++){
            int c = getConnected(graph, i, arr);
            int d = getConnected(graph, j , arr1);
            edges[m].count = check(edges[m].sentencesArr, arr, arr1, c ,d);
            if(edges[m].count != 0){
                edges[m].id1 = i;
                edges[m].id2 = j;
                ++m;
            }

        }

    }
    sapXep(edges,m);
    for(int i = 0; i < m; i++){
        printf("%-10s - %-10s : ", getName(graph, edges[i].id1), getName(graph, edges[i].id2));
        for(int j = 0; j < edges[i].count  ; j++){
            printf("%d\t", edges[i].sentencesArr[j]);
        }
        printf("\n");
    }

}

int main(){
    Graph graph;
    //Egdes egdes[100];
    createGraph(&graph);
    readFile("input1.txt",&graph);
    printGraph(&graph,0);
    search(&graph);
    return 0;
}