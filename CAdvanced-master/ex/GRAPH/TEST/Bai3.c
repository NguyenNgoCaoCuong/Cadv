#include <stdio.h>
#include <math.h>
void hinhTron(){
    float n;
    printf("Nhap ban kinh hinh tron : ");
    scanf("%f",&n);
    printf("Dien tich hinh tron la  : %f\n",M_PI*n*n);
}
void hinhThang(){
    float h,d1,d2;
    printf("Nhap chieu cao cua hinh thang : ");
    scanf("%f",&h);
    printf("Nhap do dai hai day cua hinh thang : ");
    scanf("%f%f",&d1,&d2);
    if(h >= 0 && d1 >= 0 && d2 >=0 )printf("Dien tich cua hinh thang la : %f\n",h*(d1+d2)/2);
    else printf("Do dai nhap vao khong hop le.\n");
}
void hinhChuNhat(){
    float a,b;
    printf("Nhap chieu dai hinh chu nhat : ");
    scanf("%f",&a);
    printf("Nhap chieu rong hinh chua nhat : ");
    scanf("%f",&b);
    if( a >=0 && b >= 0) printf("Dien tich hinh chu nhat la : %f",a*b);
    else printf("Do dai nhap vao khong hop le.\n");
}
void MENU(){
    char c;
    while (1){
        printf("\n--------- MENU --------\n ");
        printf("1.Dien tich hinh tron.\n");
        printf("2.Dien tich hnh thang.\n");
        printf("3.Dien tich hinh chu nhat.\n");
        printf("4.Thoat.\n");
        scanf("%c",&c);
        switch (c) {
            case '1' :
                hinhTron();
                break;
            case '2' :
                hinhThang();
                break;
            case '3' :
                hinhChuNhat();
                break;
            case '4' :
                break;
            default:
                printf("Lua chon khong phu hop.!");
        }
        if(c == '4') break;
    }
}
int main(){
    MENU();
    return 0;
}
