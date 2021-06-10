#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
ll d, p, q;

int main() {
    scanf("%lld%lld%lld", &d, &p, &q);
    ll ret = d / (p * q) * (p * q);
    if(ret > 0) ret -= p * q;
    d -= ret;
    if (p < q) swap(p, q);
    ll minNum = 2e9;
    for (ll i = 0; i * p <= d + p; i++)
        minNum = min(minNum, i * p + ((d - p * i + q - 1) / q) * q);

    ret += minNum;    

    printf("%lld\n", ret);

    return 0;
}