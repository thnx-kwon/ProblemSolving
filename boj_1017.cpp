#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;
vector<int> p;

int main(){
    p = vector<int>(2001,1);
    for(int i = 2; i <= 2000;i++) {
        if(!p[i]) continue;
        for(int j = 2 * i; j <= 2000; j += i) p[j] = 0;
    }

    

    printf("hello\n");
    return 0;
}