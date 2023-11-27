#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;cin >> N;
    string S[N];
    rep(i,N)cin >> S[i];
    vector<ll> HS(N,0);//Horizontal Sum
    vector<ll> VS(N,0);//Vertical Sum
    rep(i,N)rep(j,N)if(S[i][j]=='o')HS[i]++;//i = row     j = column
    rep(i,N)rep(j,N)if(S[j][i]=='o')VS[i]++;//i = column  j = row
    ll ans = 0;
    rep(i,N)rep(j,N)if(S[i][j]=='o')ans += (HS[i]-1)*(VS[j]-1);
    cout << ans << endl;
}