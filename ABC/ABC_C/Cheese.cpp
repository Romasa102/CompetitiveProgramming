
#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
int main(){
    ll N,W;
    cin >> N >> W;
    vector<P> M(N);
    rep(i,N) cin >> M[i].first >> M[i].second;
    sort(M.begin(),M.end(),greater<P>());
    ll ans = 0;
    rep(i,N)
    {
        if(W >= M[i].second){
            ans += M[i].first * M[i].second;
            W -= M[i].second;
        }else{
            ans += M[i].first * W;
            break;
        }
    }
    cout << ans << endl;
}