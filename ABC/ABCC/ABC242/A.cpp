#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    double A,B,C,X;
    cin >> A >> B >> C >> X;
    double ans = 0;
    if(X <= A){
        ans = 1;
    }else if(A < X && X <= B){
        double o = B - A;
        ans = C/o;
    }
    cout << fixed << setprecision(7) << ans << endl;
}