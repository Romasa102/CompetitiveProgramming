#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    freopen("traffic.in", "r", stdin);
    ll N;
    cin >> N;
    string s[N];
    ll a[N],b[N];
    rep(i,N){
        cin >> s[i];
        cin >> a[i] >> b[i];
    }
    ll minn = 0;
    ll maxx = 1LL<<60;
    for(ll i = N-1; i>=0; i--){
        if(s[i]=="none"){
            minn = max(minn,a[i]);
            maxx = min(maxx,b[i]);
        }else if(s[i]=="on"){
            minn -= b[i];
            maxx -= a[i];
        }else if(s[i]=="off"){
            minn += a[i];
            maxx += b[i];
        }
    }
    freopen("traffic.out", "w", stdout);
    cout << max(0LL,minn) << " " << maxx << endl;
    minn = 0;
    maxx = 1LL<<60;
    rep(i,N){
        if(s[i]=="none"){
            minn = max(minn,a[i]);
            maxx = min(maxx,b[i]);
        }else if(s[i]=="on"){
            minn += a[i];
            maxx += b[i];
        }else if(s[i]=="off"){
            minn -= b[i];
            maxx -= a[i];
        }
    }
    cout << max(0LL,minn) << " " << maxx << endl;
}