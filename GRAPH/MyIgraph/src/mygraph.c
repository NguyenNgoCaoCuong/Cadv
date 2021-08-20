#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "mygraph.h"
#include "queue.h"
#include "jval.h"
#include "jrb.h"
#include "dllist.h"

void createGraph(Graph *graph){
    graph->vertex = make_jrb();
    graph->edges = make_jrb();
    return ;
}

void addEdge(Graph *graph,int edge_1,int edge_2,int *weight){
    JRB p = jrb_find_int(graph->edges,edge_1);
    JRB tree = (JRB)jval_v(p->val);
    if(tree == NULL) {
        tree = make_jrb();
        if(weight == NULL) jrb_insert_int(tree,edge_2,new_jval_i(1));
        else jrb_insert_int(tree,edge_2,new_jval_i(*weight));
        p->val = new_jval_v(tree);
    }else{
        JRB s = jrb_find_int(tree,edge_2);
        if(s != NULL) return ;
        if(weight == NULL) jrb_insert_int(tree,edge_2,new_jval_i(1));
        else jrb_insert_int(tree,edge_2,new_jval_i(*weight));
    }
}
/*
 * Thêm một đỉnh vào đồ thị
 * id là id của đỉnh cần thêm
 * mark là tên của đỉnh cần thêm
 */
void addVertex(Graph *graph,int id,char *name){
    JRB p = jrb_find_int(graph->vertex,id);
    if(p != NULL) return ;
    jrb_insert_int(graph->vertex,id,new_jval_s(strdup(name)));
    jrb_insert_int(graph->edges,id,new_jval_v(NULL));
}

void printGraph(const Graph *graph,int tag){
    printf("\nDanh sach cac id va ten dinh : \n");
     JRB p;
    jrb_traverse(p,graph->vertex)
        if(p != NULL) printf("%-5d : %s\n",jval_i(p->key),jval_s(p->val));
        printf("\t\tTong hop danh sach : \n");
    JRB s,tree;
    jrb_traverse(s,graph->edges){
        int id = jval_i(s->key);
        printf("\t-Cates  %-5d : ",id);
        tree = (JRB)jval_v(s->val);
        if(tree != NULL) jrb_traverse(p,tree)
            if(p != NULL && tag == 0) printf("%-5d",jval_i(p->key));
            else printf("%-5s (%-5d)  ",getName(graph,jval_i(p->key)),getweight(graph,id,jval_i(p->key)));
        printf("\n");
    }
}

void dropGraph(Graph *graph){
    JRB p,tree;
    if(graph->vertex != NULL) {
        jrb_traverse(p, graph->vertex) if (p != NULL){
            char *s = jval_s(p->val);
            if(s != NULL) free(s);
        }
        jrb_free_tree(graph->vertex);
    }
    if(graph->edges != NULL){
        JRB s;
        jrb_traverse(s,graph->edges)
            if(s != NULL){
                JRB g = jval_v(s->val);
                if(g != NULL) jrb_free_tree(g);
            }
        jrb_free_tree(graph->edges);
    }
}

char* getName(const Graph *graph,int id){
    JRB s = jrb_find_int(graph->vertex,id);
    if(s == NULL) return NULL;
    return jval_s(s->val);
}

int  outDegree(const Graph *graph,int id){
    int t = 0;
    JRB p = jrb_find_int(graph->edges,id);
    JRB tree = (JRB)jval_v(p->val);
    JRB s;
    if(tree != NULL) jrb_traverse(s,tree)
            ++t;
    return t;

}

int inDegree(const Graph *graph,int id){
    int t = 0;
    JRB p,tree,s;
    jrb_traverse(p,graph->edges){
        tree = (JRB)jval_v(p->val);
        if(tree != NULL)
                if(jrb_find_int(tree,id) != NULL){
                    ++t;
                }
    }
    return t;
}

int getVertexCount(const Graph *graph){
    int t = 0;
    JRB p;
    jrb_traverse(p,graph->vertex)
        if(p != NULL) ++t;
    return t;
}

int getEdgesCount(const Graph *graph){
    int t = 0;
    JRB s,p,tree;
    jrb_traverse(s,graph->edges){
        int id = jval_i(s->key);
        tree = (JRB)jval_v(s->val);
        if(tree != NULL) jrb_traverse(p,tree)
                if(p != NULL) ++t;
    }
    return t;
}

void printArr(const Graph *graph,int *arr,int total){
    JRB p;
    for (int i = 0; i < total; ++i) {
        p = jrb_find_int(graph->vertex,arr[i]);
        if(p != NULL) printf("%s   ",jval_s(p->val));
    }
}

int checkTopo(const Graph *graph,int *arr){
    int indegree[100] = {0};
    int id[100] = {0};
    int t = 0;
    int to = 0;
    JRB p;
    jrb_traverse(p,graph->vertex){
        id[t] = jval_i(p->key);
        indegree[t++] = inDegree(graph,jval_i(p->key));
    }
    int tag = 0;
    while(1){
        tag = 0;
        for (int i = 0; i < t; ++i)
            if(indegree[i] == 0){
                int connect[100] = {0};
                int total = 0;
                arr[to++] = id[i];
                total = getConnected(graph,id[i],connect);
                for (int j = 0; j < total; ++j)
                    for (int k = 0; k < t; ++k)
                        if(id[k] == connect[j]){
                            --indegree[k];
                            break;
                        }
                indegree[i] = -1;
                tag = 1;
            }
        if(tag == 0) break;
    }
    if(to == getVertexCount(graph)) return to;
    return -1;
}

int getweight(const Graph *graph,int edge_1,int edge_2){
    JRB p = jrb_find_int(graph->edges,edge_1);
    if(p == NULL) return 0;
    JRB tree = (JRB)jval_v(p->val);
    if(tree == NULL) return  0;
    JRB s = jrb_find_int(tree,edge_2);
    if(s == NULL) return 0;
    return jval_i(s->val);
}

int getConnected(const Graph *graph,int v1,int *arr){
    JRB node = jrb_find_int(graph->edges,v1);
    if(node == NULL) return -1;
    int total = 0;
    JRB tree = (JRB)jval_v(node->val);
    JRB p;
    if(tree != NULL) jrb_traverse(p,tree)
            if(p!= NULL) arr[total++] = jval_i(p->key);
    return total;
}

int DFS(const Graph *graph,int start,int end,int *weight,int *arr,int *time_s,int *time_e,int tag){
    int time = 1;
    int to = 0;
    int x;
    unsigned int w = 3000000000;
    if(weight != NULL) w = *weight;
    int vertex[1000];
    int ck[1000] = {0};
    int c[1000] = {0};
    int total,t;
    Dllist stack = new_dllist();
    Dllist node;
    dll_append(stack,new_jval_i(start));
    ck[start] = 2;
    if(time_s != NULL) time_s[start] = time++;
    while(!dll_empty(stack)) {
        node = dll_last(stack);
        t = jval_i(node->val);
        dll_delete_node(node);
        if (ck[t] != 1) {
            if (c[t] <= w) {
                if(time_e != NULL) time_e[t] = time++;
                arr[to++] = t;
            }
            ck[t] = 1;
            if (t == end){
                printf("Da den cuoi\n");
                break;
            }

            total = getConnected(graph, t, vertex);
            for (int i = 0; i < total; ++i) {
                x = 1;
                if (tag != 0) x = getweight(graph, t, vertex[i]);
                if (ck[vertex[i]] == 0) {
                    ck[vertex[i]] = 2;
                    if(time_s != NULL) time_s[vertex[i]] = time++;
                    dll_append(stack, new_jval_i(vertex[i]));
                    c[vertex[i]] = x + c[t];
                }
                if(c[vertex[i]] > c[t] + x) c[vertex[i]] = x + c[t];
            }
        }
    }
    if(weight != NULL){
        JRB s;
        int i;
        jrb_traverse(s,graph->vertex){
            if(c[jval_i(s->key)] <= *weight) {
                for (i = 0; i < to; ++i)
                    if (arr[i] == jval_i(s->key)) break;
                if (i == to) arr[to++] = jval_i(s->key);
            }
        }
    }
    free_dllist(stack);
    if(end != -1 && arr[to-1] != end) return -1;
    return to;
}
/*
 * tương tự DFS
 */
int BFS(const Graph *graph,int start,int end,int *weight,int *arr,int *time_s,int *time_e,int tag){
    int time = 1;
    int to = 0;
    int x;
    unsigned int w = 3000000000;
    if(weight != NULL) w = *weight;
    int vertex[1000];
    int ck[1000] = {0};
    int ck2[1000] = {0};
    int c[1000] = {0};
    int total,t;
    Dllist queue = new_dllist();
    Dllist node;
    dll_prepend(queue,new_jval_i(start));
    ck2[start] = 2;
    if(time_s != NULL) time_s[start] = time++;
    while(!dll_empty(queue)) {
        node = dll_last(queue);
        t = jval_i(node->val);
        dll_delete_node(node);
        if (ck[t] != 1) {
            if (c[t] <= w) {
                if(time_e != NULL) time_e[t] = time++;
                arr[to++] = t;
            }
            ck[t] = 1;
            if (t == end) break;
            total = getConnected(graph, t, vertex);
            for (int i = 0; i < total; ++i) {
                x = 1;
                if (tag != 0) x = getweight(graph, t, vertex[i]);
                if (ck[vertex[i]] == 0) {
                    ck[vertex[i]] = 2;
                    if(time_s != NULL ) time_s[vertex[i]] = time++;
                    dll_prepend(queue, new_jval_i(vertex[i]));
                    c[vertex[i]] = x + c[t];
                }
                if (c[vertex[i]] > c[t] + x) c[vertex[i]] = x + c[t];
            }
        }
    }
    if(weight != NULL){
        JRB s;
        int i;
        jrb_traverse(s,graph->vertex){
            if(c[jval_i(s->key)] <= *weight) {
                for (i = 0; i < to; ++i)
                    if (arr[i] == jval_i(s->key)) break;
                if (i == to) arr[to++] = jval_i(s->key);
            }
        }
    }
    free_dllist(queue);
    if(arr[to-1] != end) return -1;
    return to;
}
int checkID(int *idDuong,int id,int total){
    for (int i = 0; i < total; ++i) if(idDuong[i] == id) return i;
    return -1;
}
int timDuong(int *ghiDuong,int end,int *arr){
    int to = 0;
    int a[100];
    while(1){
        if(end == -1) break;
        a[to++] = end;
        end = ghiDuong[end];
    }
    for (int i = 0; i < to; ++i)
        arr[i] = a[to-1-i];
    return to;
}
int dijkstra1(const Graph *graph,int start,int end,int *money,int *arr,int tag_1){
    int ck[1000] = {0};
    int weight[1000] = {0};
    int ghiDuong[1000] = {-1};
    int connect[1000] = {0};
    int total_c = 0;
    Queue queue;
    createQueue(&queue);
    inQueue(&queue,start,0,tag_1);
    weight[start] = 0;
    ck[start] = 2;
    ghiDuong[start] = -1;
    while(!isEmpty(&queue)){
        Data_q *data = deQueue(&queue);
        if(ck[data->id] != 1){
            ck[data->id] = 1;
            if(data->id == end) break;
            total_c = getConnected(graph,data->id,connect);
            for (int i = 0; i < total_c; ++i) {
                if(ck[connect[i]] == 1) continue;
                else if(ck[connect[i]] == 2){
                    if(tag_1 == 0 && compare(weight[connect[i]],weight[data->id] + getweight(graph,data->id,connect[i])) > 0){
                        weight[connect[i]] =  weight[data->id] + getweight(graph,data->id,connect[i]);
                        ghiDuong[connect[i]] = data->id;
                    }
                    if(tag_1 != 0 && compare(weight[connect[i]],weight[data->id] + getweight(graph,data->id,connect[i])) < 0){
                        weight[connect[i]] =  weight[data->id] + getweight(graph,data->id,connect[i]);
                        ghiDuong[connect[i]] = data->id;
                    }
                }
                else if(ck[connect[i]] == 0){
                    inQueue(&queue,connect[i],getweight(graph,data->id,connect[i]) + weight[data->id],tag_1);
                    ck[connect[i]] = 2;
                    ghiDuong[connect[i]] = data->id;
                    weight[connect[i]] = getweight(graph,data->id,connect[i]) + weight[data->id];
                }
            }
            free(data);
        }
    }
    *money = weight[end];
    if(*money == 0) return -1;
    int t = -1;
    if(arr != NULL) t = timDuong(ghiDuong,end,arr);
    freeQueue(&queue);
    return t;
}
int dijkstra2(const Graph *graph,int start,int end,int edge,int *money,int *arr,int tag_1){
    int array[100] = {-1};
    int total = dijkstra1(graph,start,end,money,array,tag_1);
    for (int i = 0; i < total; ++i) if(array[i] == edge){
            for (int j = 0; j < total; ++j) arr[j] = array[j];
            return total;
    }
    int t = 0;
    int ax[100];
    for (int k = 0; k < total; ++k)
        ax[k] = arr[k];
    int a_12[100] = {-1};
    int a_23[100] = {-1};
    int t_12 = -1;
    int t_23 = -1;
    int m_12 = 0;
    int m_23 = 0;
    t_12 = dijkstra1(graph,start,edge,&m_12,a_12,tag_1);
    t_23 = dijkstra1(graph,edge,end,&m_23,a_23,tag_1);
    if(m_12 == 0 || m_23 == 0) return -1;
    *money = m_12 + m_23;
    for (int j = 0; j < t_23; ++j)
        arr[t++] = a_23[j];
    for (int i = 1; i < t_12; ++i)
        arr[t++] = a_12[i];
    return t;
}

void cayKhungNhoNhatPrim(Graph *graph,int *arr){

}

int checkLinked(const Graph *graph,int id1,int id2){
    JRB p = jrb_find_int(graph->edges,id1);
    if(p == NULL) return 0;
    JRB tree = (JRB)jval_v(p->val);
    if(tree == NULL) return 0;
    if(jrb_find_int(tree,id2) == NULL) return 0;
    return 1;
}

int dijkstra(const Graph *graph,int start,int end,int *edge,int *money,int *arr,int tag_1){
    int total ;
    if(edge == NULL)    total = dijkstra1(graph,start,end,money,arr,tag_1);
    else if(edge != NULL) total = dijkstra2(graph,start,end,*edge,money,arr,tag_1);
    return total;
}
int getID(const Graph *graph,char *name){
    JRB p;
    jrb_traverse(p,graph->vertex)
        if((p != NULL) && strcmp(name,jval_s(p->val)) == 0) return jval_i(p->key);
    return -1;
}
int getPreConnect(const Graph *graph,int id,int  *arr){
    int total  =0;
    JRB p;
    jrb_traverse(p,graph->edges)
        if(p != NULL &&  checkLinked(graph,jval_i(p->key),id) == 1)
            arr[total++] = jval_i(p->key);
    return total;
}