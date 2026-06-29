#include <bits/stdc++.h>
using namespace std;
class matrix{
    public:
    int * ptr=NULL;
    int row =0;
    int col=0;
     matrix(int row , int col){
        ptr=new int [row*col];
        this->row=row;
        this->col=col;
    }
    matrix(matrix & s){
        ptr=new int[s.row*s.col];
        this->row=s.row;
        this->col=s.col;
        for(int i=1;i<=s.row;i++){
            for(int j=1;j<=s.col;j++){
                ptr[(i-1)*s.col+(j-1)]=s.ptr[(i-1)*s.col+(j-1)];
            }
        }
    }
    void inp(){
            for(int i =1;i<=row;i++){
                for(int j=1;j<=col;j++){
                    cin>>this->ptr[(i-1)*col+(j-1)];
                }
            }
    }
    void show(){
        for(int i =1;i<=row;i++){
            for(int j=1;j<=col;j++){
                cout<<ptr[(i-1)*col+(j-1)]<<" ";
            }
            cout<<endl;
        }
    }
    void transpose(){
        int oldrow=row;
        int oldcol=col;
        swap(this->row, this->col);
        int *p=new int [row*col];

        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                p[(i-1)*oldrow+(j-1)]=ptr[(j-1)*oldcol+(i-1)];
            }
        }
        delete []ptr;
        ptr=p;
    }
    matrix  & operator=(matrix&m){
        for(int i =1;i<=row;i++){
            for(int j=1;j<=col;j++){
                this->ptr[(i-1)*col+(j-1)]=m.ptr[(i-1)*col+(j-1)];
            }
        }
        return *this;
    }
    matrix operator*(matrix &b){
        matrix ans(this->row,b.col);
        for(int i=1;i<=this->row;i++){
            for(int j=1;j<=b.col;j++){
                ans.ptr[(i-1)*b.col+j-1]=0;
                for(int k=1;k<=col;k++){
                    ans.ptr[(i-1)*b.col+j-1]+=(this->ptr[(i-1)*col+k-1])*(b.ptr[(k-1)*b.col+j-1]);
                }
            }
        }
        return ans;
    }
    ~matrix(){
        delete []ptr;
    }
};

int main(){
   


}
