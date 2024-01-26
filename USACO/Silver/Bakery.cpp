#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
ll N,C,M;
vector<ll> a,b,c;
bool check(ll mid){
    ll mins = max(1LL,C-mid);//case when u use all the money to the cookie
    ll maxs = min(C+M-mid,C);
    rep(i,N){
        if(a[i]-b[i] > 0){
            maxs = min(maxs,(c[i]-b[i]*(C+M-mid))/(a[i]-b[i]));
        }else if(a[i]-b[i] < 0){
            mins =
        }else{
            if(mid * a[i] > c[i]){
                return false;
            }
        }
    }
    return mins<=maxs;
}
int main(){
    ll T;cin >> T;
    rep(i,T){
        cin >> N >> C >> M;
        a.resize(N);b.resize(N);c.resize(N);
        rep(j,N)cin >> a[i] >> b[i] >> c[i];
        ll left=0,right=C;
        ll ans = 0;
        while(right-left>1){
            ll mid = (left+right)/2;//mid is the current time taken for C+M;
            if(check(mid)){//if it worked
                left = mid;//increase the value to search
                ans = max(ans,min(C,cMax) + min(M,mMax));
            }else{
                right = mid;
            }
        }
        cout << C+M-ans << endl;
    }
}