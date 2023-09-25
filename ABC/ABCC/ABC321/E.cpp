#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
ll N,X,K;
ll count_down(ll v,ll d){
    ll maxD = log2(N/v);
    if(d < maxD) {
        ll mAmn = ((ll) 1)<<d;
        return mAmn;
    }
    if(d == maxD) {
        ll tmp = v<<maxD;
        ll mAmn = ((ll) 1)<<d;
        return max((ll) 0,min(mAmn,N-tmp+((ll) 1)));
    }
    return 0;
}
int main(){
    ll T;
    cin >> T;
    rep(i,T){
        cin >> N >> X >> K;
        //X == startPoint
        //N == size of the tree
        //K == length
        //then find the one from the top.
        if(K>120){
            cout << 0 << endl;
            continue;
        }
        ll ans = 0;
        ll x = X;
        ll px = -1;
        ll k = K;
        while(x>0 && k>=0){
            if(x==X){
                ans += count_down(x,k);
            }else{
                if(k==0){
                    ans ++;
                }else{
                    ll y = 2*x;
                    if(px == 2*x+1){
                        ans += count_down(y,k-1);
                    }else{
                        ans += count_down(y+1,k-1);
                    }
                }
            }
            px = x;
            x=x/2;
            k--;
        }
        cout << ans << endl;
    }
}