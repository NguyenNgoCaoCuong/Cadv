#include <stdio.h>
#include <stdarg.h>

int _max(int count,...){
    va_list arr;
    va_start(arr,count);
    int max = va_arg(arr,int);
    for (int i = 1; i < count; ++i) {
        int val = va_arg(arr,int);
        max = max > val ? max : val;
    }
    va_end(arr);
    return max;
}
void PrintLines(char* _firstStr, ...)
{
    char* str;
    va_list ap;
    va_start(ap, _firstStr);
    str = _firstStr;
    while(str != NULL)
    {
        printf("%s\n", str);
        str = va_arg(ap, char*);
    }
    va_end(ap);
}


int main(){
    PrintLines("Nguyen Ngo Cao Cuong", "Nguyen Dinh Canh", "Ha Huy Cuong", NULL);
    int max = _max(12,1,3,4,5,6,7,5,34,23,5,45,32);
    printf("%d",max);
    return 0;
}
