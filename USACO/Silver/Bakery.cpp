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
            ll mid = (left+right)/2;//mid is the current time taken for C+M;
            ll cMax = 1LL<<30;//possible maximum value for c
            rep(j,N){
                cMax = min(cMax,(c[i] - b[i] * mid)/(a[i]-b[i]));//a[i]*C + b[i]*(mid - C) < c[i]
                //(a[i]-b[i])*C+b[i]*mid <= c[i]
            }
            ll mMax = mid - cMax;
            if(cMax >= 0 && mMax >= 0 && mid >= cMax && mid >= mMax){//if it worked
                left = mid;//increase the value to search
                ans = max(ans,min(C,cMax) + min(M,mMax));
            }else{
                right = mid;
            }
        }
        cout << C+M-ans << endl;
    }
}