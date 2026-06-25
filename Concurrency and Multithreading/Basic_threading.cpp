#include <iostream>
#include <thread>
using namespace std;
void hello(){
    cout<<"HELLO"<<endl;
}
int main(){
    thread t1(&hello);
      t1.join();
    cout<<"OK"<<endl;
    return 0;
}
