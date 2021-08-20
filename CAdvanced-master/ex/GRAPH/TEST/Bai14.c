#include <stdio.h>

void daoNguoc(int n){
    if(n <= 0) return ;
    printf("%d",n%10);
    n /= 10;
    daoNguoc(n);
}
int main(){
    int n;
    printf("Nhap vao mot so nguyen duong  n : ");
    scanf("%d",&n);
    printf("So dao nguoc cua n la : ");
    daoNguoc(n);
    return 0;
}