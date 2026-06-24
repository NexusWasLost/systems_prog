#include <stdio.h>
#include <stdarg.h>
int sum(int cnt , ...){
    int ans =0;
    va_list args;
    va_start(args,cnt);
    for(int i=0;i<cnt;i++){
        ans+=va_arg(args,int);
    }
    va_end(args);
    return ans;
}
int main(){
    printf("%d\n", sum(3,10,50,60));
    printf("%d", sum(4,10,50,60,70));
}
