#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    freopen("herding.in","r",stdin);
    ll num[3];
    rep(i,3)cin >> num[i];
    sort(num,num+3);
    ll maxAns = max(num[2]-num[1]-1,num[1]-num[0]-1);
    while(true){

    }
    freopen("herding.out","w",stdout);
    cout << minAns << endl << maxAns << endl;
}