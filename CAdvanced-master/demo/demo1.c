#include <stdio.h>
#include "jrb.h"
int main(){
    JRB tree = make_jrb();
    jrb_free_tree(tree);
    printf("NGUYEN NGO CAO CUONG");
    return 0;
}