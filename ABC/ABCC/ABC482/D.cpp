#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    double X[N];
    rep(i,N)cin >> X[i];
    if(N==1){
        cout << 0 << endl;
        return 0;
    }
    rep(i,N){
        //first case when the original go to the left;
        double ans = 1LL<<50;
        double ans2 = 1LL<<50;
        if(i>0){
            ans = (X[i] - X[0]) / 2.0;
            ans = max(ans,(X[N-1] - X[i-1]) / 2.0);
        }
        //second case when the original go to the right;
        if(i<N-1){
            ans2 = (X[N-1] - X[i])/2.0;
            ans2 = max(ans2, (X[i+1] - X[0])/2.0);
        }
        cout << (ll)min(ans,ans2) << endl;
    }
}