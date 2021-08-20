#include <stdio.h>
#include <stdlib.h>
#include "fields.h"

void readFile(){
    IS is = new_inputstruct("webpages.txt");
    int n;
    get_line(is);
    n = atoi(is->fields[0]);
    for (int i = 0; i < n; ++i) {
        get_line(is);
        int id = atoi(is->fields[2]);
        printf("%d : %s\n",id,is->fields[0]);
    }
}
int main(){
    readFile();
    return 0;
}
