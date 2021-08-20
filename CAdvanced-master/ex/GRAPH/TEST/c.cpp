#include <iostream>
#include <string>

using namespace std;

template<class T> class  Node{
public:
    T value;
    Node *next;
    Node(T v) : value(v),next(0){}
};
template<class T> class  List{
    Node<T> *head,*tail;
    int count;
public:
    List() : count(0){}
    ~List(){
        delete [] this->ToArray();
    };
    void RemoveAll(){
        while(count){
            --count;
            Node<T> *p = head;
            head = p->next;
            delete  p;
        }
    }
    void Add(T v){
        Node<T> *p = new Node<T>(v);
        if(count++ == 0){
            head = p;
        }else{
            tail->next = p;
        }
        tail = p;
    }
    Node<T> * First() const { return head;}
    int Count() const { return count;}
    T *ToArray(){
        T *arr = new T[count];
        Node<T> *p = head;
        for(int i = 0;i <count;i++,p = p->next)
            arr[i] = p->value;
        return arr;
    }

};

class Date{
public:
    int day,month,year;
    Date(){ day = month = year = 0;}
    Date(int a,int b,int c){
        this->year = a;
        this->month = b;
        this->day = c;
    };// ham khoi tao
    friend  ostream & operator << (ostream& os,const Date& date){
        os << date.day << "." << date.month << "." << date.year ;//them vao
        return os;//them vao
    }
};


class ThiSinh{
public:
    Date ngaySinh;
    string hoTen;
    double  toan,ly,anh;//Diem ca nhan
public:
    ThiSinh(){}
    ThiSinh(const char *hoTen,const Date ns,double  toan,double ly,double anh){
        this->hoTen = hoTen;//them vao
        this->ngaySinh.year = ns.year;//them vao
        this->ngaySinh.month = ns.month;//them vao
        this->ngaySinh.day = ns.day;//them vao
        this->toan = toan;//them vao
        this->ly = ly;//them vao
        this->anh = anh;//them vao
    };
    double Tong() const {
        return this->toan + this->ly + this->anh;// them vao
    };
    double TB()const {
        return (this->toan + this->ly + this->anh)/3;// them vao
    };
    friend  ostream& operator << (ostream& os,const ThiSinh& thiSinh){
        os << thiSinh.hoTen << " " <<thiSinh.ngaySinh <<" " << thiSinh.toan <<" " <<thiSinh.ly << "  " <<thiSinh.anh <<"  " << thiSinh.Tong() << "  " <<thiSinh.TB();//them dong
        return os;//them vao
    }
};
class ListThiSinh : public List<ThiSinh *> {
public:
    ListThiSinh(ThiSinh **arr){
        int i = 0;
        while (arr[i]){
            this->Add(arr[i++]);
        }
    }
    ~ListThiSinh(){
        delete [] this->ToArray();//them vao
    };

};

void sort(ThiSinh *arr[]){
    ListThiSinh cacTHiSinh(arr);
    int soLuong = cacTHiSinh.Count();
    for (int i = 0; i < soLuong; ++i)
        for (int j = 0; j < soLuong; ++j)
            if(arr[i]->Tong() > arr[j]->Tong()){
                ThiSinh a = *arr[i];
                *arr[i] =  *arr[j];
                *arr[j] = a;
            }
}
void thongKe(ThiSinh **arr){
    ListThiSinh cacTHiSinh(arr);
    int soLuong = cacTHiSinh.Count();
    int kha = 0;
    int gioi = 0;
    for (int i = 0; i < soLuong; ++i) {
        if(arr[i]->TB() >=8) ++gioi;
        if(arr[i]->TB() < 8 && arr[i]->TB() >=6.5) ++kha;
    }
    cout <<"\n So hoc sinh gioi : " << gioi <<endl;
    cout <<"\n So hoc sinh kha : " << kha <<endl;
}
int main(){
    ThiSinh *arr[] = {
            new ThiSinh("Nguyen Thanh Son",Date(2020,1,15),8,7,8),
            new ThiSinh("Tran Hai Nam",Date(2020,10,6),9,8,8),
            new ThiSinh("Vu Duy Anh",Date(2020,7,31),7,10,9),
            new ThiSinh("Hoang Anh Tuan",Date(2020,12,22),3,5,7),
            new ThiSinh("Pham Thanh Huyen",Date(2020,8,10),8,8,8),
            new ThiSinh("Phung Ngoc Linh",Date(2020,4,5),9,9,9)
    };
    ListThiSinh cacTHiSinh(arr);
    auto   Node<ThiSinh* > *p = cacTHiSinh.First();//them vao
    int soLuong = cacTHiSinh.Count();
    for (int i = 0; i < soLuong; ++i,p = p->next) {
        cout << *p->value << endl;
    }
    cout << "\n\nDanh sach cac thi sinh co diem tong tang dan :"<<endl;
    sort(arr);
    p = cacTHiSinh.First();//them vao
    soLuong = cacTHiSinh.Count();
    for (int i = 0; i < soLuong; ++i,p = p->next) {
        cout << *p->value << endl;
    }
    thongKe(arr);
    return 0;
}