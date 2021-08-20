#include <stdio.h>
#include "fields.h"
#include <string.h>
void replac(){
    IS is = new_inputstruct("cuong.txt");
    FILE *file = fopen("ouput.txt","w");
    if(is == NULL || file == NULL){
        printf("Khong the mo file\n");
    }else{
        int total;
        while((total = get_line(is)) > 0){
            char str[200] = "";
            for (int i = 1; i < total-4; ++i)
                strcat(strcat(str," "),is->fields[i]);
            for (int i = 0; i < total; ++i) {
                printf("%s ",is->fields[i]);
            }

            fprintf(file,"('%s','%s',%s,%s,%s,%s),\n",is->fields[0],str,is->fields[total-4],is->fields[total-3],is->fields[total-2],is->fields[total-1]);
         //   fprintf(file,"('%s','%s'),\n",str,is->fields[total-1]);
            printf("\n");
        }
    }
    jettison_inputstruct(is);
}

int main(){
    replac();
    return 0;
}