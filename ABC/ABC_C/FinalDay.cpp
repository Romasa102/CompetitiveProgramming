#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,K;
    cin >> N >> K;
    vector<P> M(N);
    rep(i,N){
        ll a[4] = {0};
        cin >> a[0] >> a[1] >> a[2];
        M[i] = P((a[0] + a[1] + a[2]),i);
    }
    bool ans[N] = {false};
    sort(M.begin(),M.end(),greater<P>());
    rep(i,N){
        if(300 >= M[K - 1].first - M[i].first){
            ans[M[i].second] = true;
        }else{
            ans[M[i].second] = false;
        }
    }
    rep(i,N){
        if(ans[i] == true){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}