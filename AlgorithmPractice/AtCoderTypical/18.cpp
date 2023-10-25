#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    long double T;
    long double L,X,Y;
    cin >> T >> L >> X >> Y;
    ll Q;
    cin >> Q;
    ll E[Q];
    rep(i,Q){
        cin>>E[i];
        E[i]%=(ll)T;
        long double cur = T-E[i];
        long double num=(cur/T)*2*M_PI;
        long double x = sin(num)*L/2;
        long double y = L/2-cos(num)*L/2;
        long double ans = 0;
        ans = atan2(y,sqrt(X*X+(x-Y)*(x-Y)));
        ans = ans*180.0L/M_PI;
        cout<<fixed<< setprecision(10)  <<ans << endl;
    }
}