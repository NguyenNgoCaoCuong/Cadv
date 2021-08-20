#include <stdio.h>

void UCLN_BCNN(){
    int a,b;
    printf("Nhap vao so nguyen a : ");
    scanf("%d",&a);
    printf("Nhap vao so nguyen b : ");
    scanf("%d",&b);
    int c = a,d = b;
    while(a != b){
        if(a > b) a-=b;
        else b-=a;
    }
    printf("UCLN(%d,%d) = %d\n",c,d,a);
    printf("BCNN(%d,%d0 = %d\n",c,d,c*d/a);
}
int main(){
    UCLN_BCNN();
    return 0;
}