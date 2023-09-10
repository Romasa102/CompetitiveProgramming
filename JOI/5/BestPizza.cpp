#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,A,B,C;
    cin >> N >> A >> B >> C;
    ll Topping[N];
    rep(i,N){
        cin >> Topping[i];
    }
    sort(Topping,Topping+N,greater<ll>());
    ll CaloryN = C;
    ll PriceN = A;
    ll ans = 0;
    ans = CaloryN/PriceN;
    rep(i,N){
        CaloryN += Topping[i];
        PriceN += B;
        ans = max(ans,CaloryN/PriceN);
    }
    cout << ans << endl;
}