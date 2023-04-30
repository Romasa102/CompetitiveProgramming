#include <bits/stdc++.h>
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
int main(){
    ll N,Q;
    cin >> N >> Q;
    ll a[N];
    ll x[Q];
    rep(i,N)cin >> a[i];
    rep(i,Q)cin >> x[i];
    vector<P> B(Q);
    rep(i,Q){
        B[i].first = x[i];
        B[i].second = i;
    }
    sort(a,a+N,greater<ll>());
    sort(B.begin(),B.end(),greater<P>());
    ll ans[Q] = {0};
    ll count = 0;
    rep(i,N){
        while(a[i] < B[count].first){
            ans[B[count].second] = i;
            count ++;
            
        }
        if(count >= Q){
            break;
        }
    }
    
    if(count < Q){
        for (int i = count; i < Q; i ++)
        {
            ans[B[count].second] = N;
            count ++;
        }        
    }
    rep(i,Q){
        cout << ans[i] << endl;
    }
}