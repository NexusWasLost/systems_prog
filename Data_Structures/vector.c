#include <stdio.h>
#include <stdlib.h>
typedef struct{
int * addr;
int cap;
int size;
}vector;
void init(vector*v){
    v->addr=(int *)malloc(sizeof(int)*1);
    v->cap=1;
    v->size=0;
}
void push_back(vector * v, int a ){
    if(v->cap==v->size){
        v->cap*=2;
        v->addr=realloc(v->addr,sizeof(int)*(v->cap));
    }
    v->addr[v->size]=a;
    v->size+=1;
}
void pop_back(vector * v ){
    if(v->size==0)return;
    v->size=v->size-1;
}
//init(address of the vector):initializes an uninitialized vector;
//push_back(address of the vector,number to push);
//pop_back(address of the vector);
int main(){
    vector a ;
    init(&a);
    for(int i =0;i<12;i++){
        push_back(&a,i);
    }
    pop_back(&a);
    for(int i=0;i<a.size;i++){
        printf("%d\n",a.addr[i]);
    }
    free(a.addr);
}
