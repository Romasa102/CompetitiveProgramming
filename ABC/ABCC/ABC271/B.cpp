#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,Q;
    cin >> N >> Q;
    vector <vector<int>> L(N);
    rep(i,N){
        ll count;
        cin >> count;
        rep(j,count){
            ll P;
            cin >>P;
            L[i].push_back(P); 
        }
    }
    ll s,t;
    rep(i,Q){
        cin >> s >> t;
        cout << L[s - 1][t - 1] << endl;
    }
}