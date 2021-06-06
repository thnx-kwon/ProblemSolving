#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<vector<int> > dp(50,vector<int>(250001,-1));
int a[51];
int n;

int f(int idx, int diff){
    if(idx == -1 && diff == 0) return 0;
    diff = abs(diff);
    if(idx == -1 || diff > 250000) return -987654321;
    int& ret = dp[idx][diff];
    if(ret != -1) return ret;

    ret = f(idx - 1, diff);
    ret = max(ret, f(idx - 1, diff + a[idx]) + a[idx]);
    ret = max(ret, f(idx - 1, diff - a[idx]) + abs(min(diff - a[idx], 0)));

    if(ret < -1) ret = -987654321;

    return ret;

}

int main(){
    scanf("%d",&n);

    for(int i = 0; i < n; i++) scanf("%d",&a[i]);
    int ret = f(n-1,0);
    if(ret <= 0) ret = -1;
    printf("%d\n",ret);

    return 0;
}