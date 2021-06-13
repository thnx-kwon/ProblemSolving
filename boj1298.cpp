#include <iostream>
#include <cstring>

using namespace std;

int n, m, t1, t2;
int a[101][101];
int b[101];
bool visit[101];

int f(int arg){
    if(visit[arg]) return 0;
    visit[arg] = 1;
    for(int i = 1; i <= n; i++){
        if(!a[arg][i]) continue;
        if(!b[i] || f(b[i])){
            b[i] = arg;
            return 1;
        }
    }
    return 0;
}

int main() {
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d",&t1,&t2);
        a[t1][t2] = 1;
    }
    int ret = 0;
    for(int i = 1; i <= 100; i++){
        memset(visit,0,n+1);
        ret += f(i);
    }
    printf("%d\n",ret);
    return 0;
}