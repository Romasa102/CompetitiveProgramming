#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main(){
    ll n,k;
    cin >> n >> k;
    ll a[n];
    ll all = 0;
    all = k/n;
    k %= n;
    rep(i,n)cin >> a[i];
    vector<ll> ans(n);
    vector<P> M(n);
    rep(i,n) M[i] = P(a[i],i);
    sort(M.begin() ,M.end());
    rep(i,k) ans[M[i].second]++;
    rep(i,n)cout << ans[i] + all << endl;
}