#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "jrb.h"
#include "jval.h"
#include "fields.h"
#include "gtk-3.0/gtk/gtk.h"
int readFile(JRB tree){
    IS is = new_inputstruct("pass.txt");
    while (get_line(is) != -1){
        char name[30] = "";
        strcat(name,is->fields[0]);
        for (int i = 1; i < is->NF - 1; ++i)
            strcat(strcat(name," "),is->fields[i]);
        jrb_insert_str(tree,strdup(name),new_jval_s(strdup(is->fields[is->NF - 1])));
    }
    jettison_inputstruct(is);
    return 1;
}
JRB checkLogin(const JRB tree,const char *name,const char *pass){
    JRB s = NULL;
    if(tree != NULL) s = jrb_find_str(tree,name);
    char *pass_ = jval_s(s->val);
    if(pass != NULL && strcmp(pass,pass_) == 0) return s;
    return NULL;
}
void dropTree(JRB tree){
    JRB s;
    if(tree != NULL) jrb_traverse(s,tree)
        if(s != NULL){
            char *name = jval_s(s->key);
            char *pass = jval_s(s->val);
            if(pass != NULL) free(pass);
            if(name != NULL) free(name);
        }
}
int main(int argc,char *argv[]){
    JRB tree = make_jrb();
    readFile(tree);
    JRB s;
    if(NULL != checkLogin(tree,"nguyen ngo cao cuong","0123")) printf("ok");
    dropTree(tree);
    jrb_free_tree(tree);
    return 0;
}
