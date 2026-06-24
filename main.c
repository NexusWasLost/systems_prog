#include <unistd.h>

int main(){
    // char buf[] = "Roger";
    // int size = sizeof(buf);
    // write(1, buf, size - 1);

    // char buf[100];
    // int size = sizeof(buf);

    // ssize_t bytes_read = read(0, buf, size - 1);

    int x = 3826464;

    int temp = x;
    int bufSize = 0;
    while(temp > 0){
        ++bufSize;
        temp /= 10;
    }
    ++bufSize; //extra padding for null terminator

    char buf[bufSize]; //buf[8]
    temp = x;

    int counter = bufSize - 1;
    buf[counter] = '\0';
    counter--;

    while(temp > 0){
        int rem = temp % 10;
        buf[counter] = rem + '0';
        temp /= 10;
        counter--;
    }

    write(1, buf, bufSize);

    return 0;
}
