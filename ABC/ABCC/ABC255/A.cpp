#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll R,C;
    cin >> R >> C;
    ll A[2][2];
    cin >> A[0][0] >> A[0][1] >> A[1][0] >> A[1][1];
    cout << A[R-1][C-1] << endl;
}