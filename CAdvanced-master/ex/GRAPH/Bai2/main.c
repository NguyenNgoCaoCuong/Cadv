#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "fields.h"
#include "jval.h"
#include "jrb.h"


typedef struct Graph{
    JRB vertex;
    JRB edges;
}Graph;


typedef struct Data_q{
    int id;
    int weight;
    struct Data_q *pNext;
}Data_q;
typedef struct Queue{
    Data_q *pHead;
    Data_q *pTail;
}Queue;




Data_q* newData_q(int id,int weight);
void createQueue(Queue *);
int isEmpty(const Queue *);
Data_q* deQueue(Queue *);
void inQueue(Queue *,int id,int weight,int tag);
void freeQueue(Queue *);
int compare(int,int);
int compare_(int,int);
void printQueue(const Queue);



void  createGraph(Graph *);
void addEdge(Graph *,int edge_1,int edge_2,int *weight);
void addVertex(Graph *,int key,char *mark);
void printGraph(const Graph *,int tag);
int inDegree(const Graph *,int key);
int outDegree(const Graph *,int key);
int getVertexCount(const Graph *);
int getID(const Graph *,char *);
int getEdgesCount(const Graph *);
int dijkstra(const Graph *,int start,int end,int *money,int *arr,int tag_1);
void printArr(const Graph *,int *arr,int total);
int getweight(const Graph *,int edge_1,int edge_2);
char* getName(const Graph *,int id);
int getConnected(const Graph *graph,int v1,int *arr);
void dropGraph(Graph *graph);


Data_q* newData_q(int id,int weight){
    Data_q *data = (Data_q*)calloc(1,sizeof(Data_q));
    data->weight = weight;
    data->id = id;
    data->pNext = NULL;
    return data;
}
void createQueue(Queue *queue){
    queue->pTail = NULL;
    queue->pHead = NULL;
}
int isEmpty(const Queue *queue){
    if(queue == NULL) return 2;
    if(queue->pHead == NULL) return 2;
    return 0;
}
Data_q* deQueue(Queue *queue){
    if(isEmpty(queue)) return -1;
    Data_q *data = queue->pHead;
    queue->pHead = data->pNext;
    return data;
}
void insert1(Queue *queue,Data_q *data,int tag){
    Data_q *s = NULL;
    Data_q *p = queue->pHead;
    if(tag == 0)
        while(compare(data->weight,p->weight) >= 0){
            s = p;
            p = p->pNext;
            if(p == NULL) break;
        }
    else
        while(compare(data->weight,p->weight) <= 0){
            s = p;
            p = p->pNext;
            if(p == NULL) break;
        }
    if(s == NULL){
        data->pNext = p;
        queue->pHead = data;
    }else if(p == NULL){
        queue->pTail->pNext = data;
        queue->pTail = data;
    }else{
        s->pNext = data;
        data->pNext = p;
    }
}
void inQueue(Queue *queue,int id,int weight,int tag){
    Data_q *data =newData_q(id,weight);
    if(isEmpty(queue)) queue->pHead = queue->pTail = data;
    else insert1(queue,data,tag);
}
void freeQueue(Queue *queue){
    while(!isEmpty(queue)) free(deQueue(queue));
}
int compare(int a,int b){
    return a - b;
}

void printQueue(const Queue queue){
    Data_q *p;
    for (p = queue.pHead; p != NULL ; p = p->pNext)
        printf("| %-2d : %-2d | ",p->id,p->weight);
}



/*
 * Khởi tạo đồ thị
 */
void createGraph(Graph *graph){
    graph->vertex = make_jrb();
    graph->edges = make_jrb();
    return ;
}
/*
 * Hàm này có chức năng thêm một cạnh vào đồ thị
 * edge_1 là id đỉnh đầu ,edge_2 là id đỉnh thứ hai ( một liên kết từ đỉnh 1 đến đỉnh 1)
 * weight là một con trỏ trỏ chứa giá trị là trọng số của cạnh nối hai đỉnh không có thì truyền null
 * tag = 0 là trông có trọng số (weight == null) ,tag = 1 là có trọng số (weigth != null)
 */
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
/*
 * In dò thị đã đọc được
 * graph là con trỏ đến đồ thị đã tạo
 * tag == 1 nếu đồ thị có trọng số
 * tag = 0 nếu đồ thị không có trọng số
 */
void printGraph(const Graph *graph,int tag){
    JRB p;
    printf("Danh sach : \n");
    JRB s,tree;
    jrb_traverse(s,graph->edges){
        int id = jval_i(s->key);
        printf("\t%-20s : ",getName(graph,id));
        tree = (JRB)jval_v(s->val);
        if(tree != NULL) jrb_traverse(p,tree)
                if(p != NULL && tag == 0) printf("%d   ",jval_i(p->key));
                else printf("%-5s (%d)  ",getName(graph,jval_i(p->key)),getweight(graph,id,jval_i(p->key)));
        printf("\n");
    }
}
/*
 * sau khi thực hiện xong không còn sử dụng đồ thị nữa thì goi hàm này để xóa đồ thị
 */
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
/*
 * lấy tên của đỉnh theo id tương ứng của đỉnh
 */
char* getName(const Graph *graph,int id){
    JRB s = jrb_find_int(graph->vertex,id);
    return jval_s(s->val);
}
/*
 * lấy ra số lượng cạnh ra của một đỉnh
 */
int  outDegree(const Graph *graph,int id){
    int t = 0;
    JRB p = jrb_find_int(graph->edges,id);
    JRB tree = (JRB)jval_v(p->val);
    JRB s;
    if(tree != NULL) jrb_traverse(s,tree)
            ++t;
    return t;

}
/*
 * lấy ra số cạnh vào của một đỉnh
 */
int inDegree(const Graph *graph,int id){
    int t = 0;
    JRB p,tree,s;
    jrb_traverse(p,graph->edges){
        tree = (JRB)jval_v(p->val);
        if(tree != NULL) jrb_traverse(s,tree)
                if(id == jval_i(s->key)){
                    ++t;
                    break;
                }
    }
    return t;
}
/*
 * lấy ra số lượng đỉnh của đò thị
 */
int getVertexCount(const Graph *graph){
    int t = 0;
    JRB p;
    jrb_traverse(p,graph->vertex)
        if(p != NULL) ++t;
    return t;
}
/*
 * Lấy ra số lượng cạnh của đồ thị
 */
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
/*
 * in đường đi
 */
void printArr(const Graph *graph,int *arr,int total){
    JRB p;
    for (int i = 0; i < total; ++i) {
        p = jrb_find_int(graph->vertex,arr[i]);
        if(p != NULL) printf("%s   ",jval_s(p->val));
    }
}

/*
 * lấy ra trọng số giữa hai cạnh
 */
int getweight(const Graph *graph,int edge_1,int edge_2){
    return 1;
    JRB p = jrb_find_int(graph->edges,edge_1);
    JRB tree = (JRB)jval_v(p->val);
    JRB s = jrb_find_int(tree,edge_2);
    return jval_i(s->val);
}
/*
 * lấy tất cả các id của cách đỉnh lân cận của v1 mà có thề đi đến trực tiếp từ v1
 */
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
int dijkstra(const Graph *graph,int start,int end,int *money,int *arr,int tag_1){
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

int getID(const Graph *graph,char *name){
    JRB p;
    jrb_traverse(p,graph->vertex)
        if((p != NULL) && strcmp(name,jval_s(p->val)) == 0) return jval_i(p->key);
    return -1;
}

int check1(char *string1,char *string2,int n){
    int t = 0;
    for (int i = 0; i < n; ++i)
        if (tolower(string1[i]) != tolower(string2[i])) {
            ++t;
            if((i == 0 || i == n -1) && t < 2) continue;
            else return 0;
        }
    return 1;
}
int check2(char *string1,char *string2,int n){
	int t = 0;
    if(tolower(string2[0]) == tolower(string1[0])){
        for (int i = 1; i < n; ++i)
            if (tolower(string1[i]) != tolower(string2[i])){
            ++t;
            break;
            }
        if(t == 0) return 1;
    }
        for (int i = n-1; i >= 0; --i)
            if (tolower(string1[i]) != tolower(string2[i+1]))
                return 0;
        return 1;
}
int check(char *string1,char *string2){
    if(strcmp(string1,string2) == 0) return 0;
    int n = strlen(string1);
    int m = strlen(string2);
    if(m - n == 1 || m - n == -1 || m - n == 0);
    else return 0;
    if(m == n) return check1(string1,string2,n);
    if(m > n) return check2(string1,string2,n);
    return check2(string2,string1,m);
}
void addE(Graph *graph,char *string){
    JRB p;
    jrb_traverse(p,graph->vertex)
        if(p != NULL && check(string,jval_s(p->val))){
            printf("%-15s : %-15s\n",string,jval_s(p->val));
            addEdge(graph,getID(graph,string),jval_i(p->key),NULL);
            addEdge(graph,jval_i(p->key),getID(graph,string),NULL);
        }
}
void readFile(Graph *graph){
    IS is = new_inputstruct("tudien.txt");
    int id = 1;
    while(get_line(is) != -1){
        addVertex(graph,id++,is->fields[0]);
        addE(graph,is->fields[0]);
    }
    jettison_inputstruct(is);
}

int main(int argc,char *argv[]){
    char s1[100];
    char s2[100];
    int arr[2000];
    int total = 0;
    int x;
    Graph graph;
    createGraph(&graph);
    printf("Các từ có quan hệ với nhau : \n");
    readFile(&graph);
    printf("Nhập từ bắt đầu: ");
    __fpurge(stdin);
    scanf("%[^\n]s",s1);
    printf("Nhập kết thúc : ");
    __fpurge(stdin);
    scanf("%[^\n]s",s2);
    int id1 = getID(&graph,s1);
    int id2 = getID(&graph,s2);
    if(id1 != -1 && id2 != -1)total = dijkstra(&graph,id1,id2,&x,arr,0);
    if(total == -1 || total == 0) printf("Không chuyển được\n");
    else{
            printf("Chuyển từ như sau : ");
            printArr(&graph,arr,total);
        }
    dropGraph(&graph);
    return 0;
}
// vào thư mục build mở ter chạy các lệnh sau
// cmake ..
//make
// ./Bai1
