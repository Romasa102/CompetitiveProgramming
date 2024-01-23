#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll T;cin >> T;
    rep(i,T){
        ll N,C,M;cin >> N >> C >> M;
        ll a[N],b[N],c[N];
        rep(j,N)cin >> a[i] >> b[i] >> c[i];
        ll left=0,right=C;
        ll ans = 0;
        while(right-left>1){
            ll mid = (left+right)/2;//mid is the current C time value;
            ll mMax = 1LL<<30;//possible maximum value for m
            rep(j,N){
                mMax = min(mMax,(c[i] - a[i] * mid)/b[i]);
            }
            if(mMax > 0){//if it worked
                left = mid;//increase the value to search
                ans = max(ans,mid + mMax);
            }else{
                right = mid;
            }
        }
        cout << C+M-ans << endl;
    }
}