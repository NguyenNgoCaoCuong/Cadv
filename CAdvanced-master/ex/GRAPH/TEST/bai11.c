#include <stdio.h>
#include <string.h>


int main(int agrc,char *argv[]){
    if(agrc == 2){
        if(strcmp(argv[1],"help") == 0) printf("Supported command: help ,i2n,n2i,cc,cr,odg,rel\n");
        if(strcmp(argv[1],"about") == 0) printf("C advaned 20142 final exam\n");
    }

}