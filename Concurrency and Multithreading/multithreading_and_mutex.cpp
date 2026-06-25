#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
using namespace std;
int m=0;
void hello(){
    m++;
}
mutex k ;
void inc(int * s ){
    k.lock();
    //protected code
    //code inside lock and unlock remains accesiible to only one thread at a time and others must wait
    (*s)++;
    k.unlock();
}
int main(){
    vector<thread>v;
//without mutex
    for(int i=0;i<1000;i++){
        v.push_back(thread(&hello));
    }
     for(int i=0;i<1000;i++){
        v[i].join();
    }
    cout<<"m: "<<m<<endl;
//with mutex 
    vector<thread>v1;
    int s =0;
    for(int i=0;i<1000;i++){
        v1.push_back(thread(&inc,&s));
    }
     for(int i=0;i<1000;i++){
        v1[i].join();
    }
    cout<<"s: "<<s<<endl;
    return 0;
}
