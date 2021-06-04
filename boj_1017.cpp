#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> p;
vector<int> a;
vector<int> b;
vector<bool> visit;
vector<int> result;
int n;

int f(int arg){
    if(visit[arg]) return 0;
    visit[arg] = 1;
    for(int i = 1; i < n; i++){
        if(b[i] == 0 || !p[a[arg] + a[i]]) continue;
        if(b[i] == -1 || f(b[i])){
            b[i] = arg;
            return 1;
        }
    }
    return 0; 
}

int main(){
    p = vector<int>(2001,1);
    for(int i = 2; i <= 2000;i++) {
        if(!p[i]) continue;
        for(int j = 2 * i; j <= 2000; j += i) p[j] = 0;
    }

    scanf("%d",&n);
    a = vector<int>(n);
    for(int i = 0; i < n; i++) scanf("%d",&a[i]);

    for(int i = 1; i < n; i++) {
        if(!p[a[0] + a[i]]) continue;
        int match = 1;
        b = vector<int>(n,-1);
        b[0] = i; b[i] = 0;
        for(int j = 1; j < n; j++) {
            if(a[j]&1 || i == j) continue;
            visit = vector<bool>(n,0);
            match += f(j);
            
        }
        if(match * 2 == n) result.push_back(a[i]);
    }
    sort(result.begin(),result.end());
    if(result.size() == 0) printf("-1");
    else for(int i = 0; i < result.size(); i++) printf("%d ",result[i]);
    printf("\n");

    return 0;
}