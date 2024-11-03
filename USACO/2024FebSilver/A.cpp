#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    if(done)continue;
    LazySegmentTree seg(currentState);
    ll remain = N-baseC;
    if(remain <= 0){
        cout << -1 << endl;
        continue;
    }
    rep(j,M){
        if(InitialChoice[j] == 0){
            cout << "Even ";
        }else{
            if(seg.getmin(j,N) > evenM[j] - oddM[j]){
                cout << "Even ";
                seg.add(j,N,-(evenM[j] - oddM[j]));
            }else{
                cout << "Odd ";
            }
        }
    }
}