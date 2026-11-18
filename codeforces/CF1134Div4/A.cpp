#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll n;
    cin >> n;
    rep(_,n){
        double a,b,c;
        cin >> a >> b >> c;
        if(max(max(abs(a-b),abs(a-c)),abs(b-c)) == 2 && ((a+b+c)/3 == a || (a+b+c)/3 == b || (a+b+c)/3 == c)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}