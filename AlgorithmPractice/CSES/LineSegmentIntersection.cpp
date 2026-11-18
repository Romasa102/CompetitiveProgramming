#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;

ll check(ll x1,ll y1, ll x2, ll y2,ll a,ll b){
    return (b-y1)*(x2-x1) - (a-x1)*(y2-y1);
}
int sign(ll x){
    if(x>0){
        return 1;
    }else if(x<0){
        return -1;
    }else{
        return 0;
    }
}
int main(){
    ll N;
    cin >> N;
    rep(_,N){
        ll x1,y1,x2,y2,x3,y3,x4,y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        if(sign(check(x1,y1,x2,y2,x3,y3)) * sign(check(x1,y1,x2,y2,x4,y4))<=0 &&
            sign(check(x3,y3,x4,y4,x1,y1)) * sign(check(x3,y3,x4,y4,x2,y2))<=0
        ){
            if(min(x1,x2) <= max(x3,x4) &&
            max(x1,x2) >= min(x3,x4) &&
            min(y1,y2) <= max(y3,y4) &&
            max(y1,y2) >= min(y3,y4) 
            ){
                cout <<"YES" << endl;
                continue;
            }
        }
        cout << "NO" << endl;
    }
}