#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll Q;
    cin >> Q;
    vector<P> R;
    rep(i,Q){
        int t = 0;
        cin >> t;
        if(t == 1){
            ll o,p;
            cin >> o >> p;
            R.push_back(make_pair(o,p));
        }else if(t == 2){
            ll w;
            ll ans = 0;
            cin >> w;
            while(w > 0){
                if(w > R[0].second){
                    ans += R[0].first*R[0].second;
                    w -= R[0].second;
                    R.erase(R.begin());
                }else{
                    ans += R[0].first*w;
                    R[0].second = R[0].second-w;
                    w=0;
                }
            }
            cout << ans << endl;
        }
    }
}