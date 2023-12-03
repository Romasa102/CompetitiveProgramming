#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll M,D;
    cin >> M >> D;
    ll y,m,d;
    cin >> y >> m >> d;
    if(m==M && d==D){
        cout << y+1 << " " << 1 << " " << 1;
        return 0;
    }
    if(d==D){
        cout << y << " " << m+1 << " " << 1;
        return 0;
    }
    cout << y << " " << m << " " << d+1;
}