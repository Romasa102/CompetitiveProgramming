#include <iostream>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
int main(){
    ll A,B,C,D;
    cin >> A >> B >> C >> D;
    ll ans = 0;
    ans = min((max(A,C)+B+D)*2,(max(B,D)+A+C)*2);
    cout << ans << endl;
}