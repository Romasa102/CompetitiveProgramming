#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
ll LOG = 30;
vector<vector<ll>> jmp; //how left
int main(){
    ll N;
    cin >> N;
    vector<ll> x(N);
    rep(i,N)cin >> x[i];
    ll L;
    cin >> L;
    jmp.resize(N,vector<ll>(LOG));
    rep(i,N){
        jmp[i][0] = lower_bound(x.begin(),x.end(),x[i]-L)-x.begin();
    }
    repp(i,1,LOG){
        rep(j,N){
            jmp[j][i]=jmp[jmp[j][i-1]][i-1];
        }
    }
    /*
    rep(i,LOG){
        rep(j,N){
            cout << x[jmp[j][i]] << " ";
        }cout << endl;
    }
    */


    ll Q;cin >> Q;
    rep(_,Q){
        ll a,b;cin >> a >> b;a--;b--;
        if(a>b)swap(a,b);
        ll ans = 0;
        for(int i = LOG-1; i >= 0;i--){
            if(jmp[b][i] > a){
                b = jmp[b][i];
                ans+=(1<<i);
            }
        }
        cout << ans+1 << endl;
    }
}