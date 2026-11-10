#include <stdio.h>

int fatorial(int n);

int main(){
    fatorial(3);

    return 0;
}


int fatorial(int n){
    
    if(n == 1)
        return 1;
    else if(n == 0)
        return 1;
    return n * fatorial(n-1);

}