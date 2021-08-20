#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "mygraph.h"
#include "fields.h"
#include "jrb.h"
#include "jval.h"

int t = 0;
int s = 0;


void inSanPham(Graph *);// in ra file products.txt
void inDanhSachGiaoDich(Graph *);// in ra file orderhistory.txt
void mucDoLienQuan(const Graph *);
void danhSachCacSanPhamLienQuan(const Graph *);
void kiemTraLienHe(const Graph *);
void MENU(Graph *);


int main(int argc,char *argv[]){
    Graph graph;
    createGraph(&graph);
    MENU(&graph);
    dropGraph(&graph);
    return 0;
}


void addEdge1(Graph *graph,int edge_1,int edge_2){
    JRB p = jrb_find_int(graph->edges,edge_1);
    JRB tree = (JRB)jval_v(p->val);
    if(tree == NULL) {
        tree = make_jrb();
        jrb_insert_int(tree,edge_2,new_jval_i(1));
        p->val = new_jval_v(tree);
    }else{
        JRB s = jrb_find_int(tree,edge_2);
        if(s != NULL){
            s->val = new_jval_i(jval_i(s->val) + 1);
            return;
        }
        jrb_insert_int(tree,edge_2,new_jval_i(1));
    }
}

void inSanPham(Graph *graph){
    if(t !=0) return;
    IS is_pro = new_inputstruct("products.txt");
    while(get_line(is_pro) != -1){
        printf("Ma san pham : %s\n",is_pro->fields[0]);
        printf("Ten san pham : %s\n",is_pro->fields[1]);
        addVertex(graph,atoi(is_pro->fields[0]),is_pro->fields[1]);
    }
    jettison_inputstruct(is_pro);
    ++t;
}
void inDanhSachGiaoDich(Graph *graph){
    if(s != 0) return;
    IS is_order = new_inputstruct("orderhistory.txt");
    while (get_line(is_order) != -1){
        for (int i = 0; i < is_order->NF; ++i){
            printf("%-15s",getName(graph,atoi(is_order->fields[i])));
            for (int j = i+1; j < is_order->NF; ++j) {
                addEdge1(graph,atoi(is_order->fields[i]),atoi(is_order->fields[j]));
                addEdge1(graph,atoi(is_order->fields[j]),atoi(is_order->fields[i]));
            }
        }
        printf("%s",getName(graph,atoi(is_order->fields[is_order->NF -1])));
        printf("\n");
    }
    jettison_inputstruct(is_order);
    ++s;
}
void mucDoLienQuan(const Graph *graph){
    int id1,id2;
    printf("Nhap vao id san pham thu nhat : ");
    __fpurge(stdin);
    scanf("%d",&id1);
    printf("Nhap vap id san pham thu hai : ");
    __fpurge(stdin);
    scanf("%d",&id2);
    int weight = getweight(graph,id1,id2);
    if(weight != -1) printf("Do lien quan giua hai san phan : %d\n",weight);
    else printf("Hai san phan khong lien quan voi nhau.\n");
}
void danhSachCacSanPhamLienQuan(const Graph *graph){
    int id;
    printf("Nhap vao id cua san pham can kiem tra : ");
    __fpurge(stdin);
    scanf("%d",&id);
    int list[100];
    int total = getConnected(graph,id,list);
    if(total == 0) printf("Id nhap vap khong ton tai!!\n");
    for (int i = 0; i < total; ++i)
        printf("%-15s",getName(graph,list[i]));
}
void kiemTraLienHe(const Graph *graph){
    int id1,id2;
    printf("Nhap vao id san pham thu nhat : ");
    __fpurge(stdin);
    scanf("%d",&id1);
    printf("Nhap vap id sn pham thu hai : ");
    __fpurge(stdin);
    scanf("%d",&id2);
    int link[100];
    int total = DFS(graph,id1,id2,NULL,link,NULL,NULL,0);\
    if(total == -1) printf("\"Hai san pham nay khong lien quan.\"\n");
    else {
        printf("\" ");

        for (int i = 0; i < total ; ++i)
            if(i < total - 1) printf("%s - ",getName(graph,link[i]));
            else printf("%s \"",getName(graph,link[i]));
    }
}
void MENU(Graph *graph){
    char c;
    while (1){
        printf("\n--------- MENU --------\n");
        printf("1.In danh sach cac san pham.\n");
        printf("2.In danh sach cac giao dich.\n");
        printf("3.Kiem tra muc do lien quan.\n");
        printf("4.Danh sach cac san pham lien quan.\n");
        printf("5.Hien thi moi lien he giua hai san pham.\n");
        printf("6.Thoat.\n");
        __fpurge(stdin);
        scanf("%c",&c);
        switch (c) {
            case '1' :
                inSanPham(graph);
                break;
            case '2' :
                inDanhSachGiaoDich(graph);
                break;
            case '3' :
                mucDoLienQuan(graph);
                break;
            case '4' :
                danhSachCacSanPhamLienQuan(graph);
                break;
            case '5' :
                kiemTraLienHe(graph);
                break;
            case '6' :
                break;
            default:
                printf("Lua chon khong phu hop.!");
        }
        if(c == '6') break;
    }
}
