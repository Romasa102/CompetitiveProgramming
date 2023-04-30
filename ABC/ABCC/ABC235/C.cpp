#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
vector<P> a;
vector<P> m;
void find(ll x,ll k){
    int count = 0;
    rep(i,a.size()){
        if(a[i].first == x){
            count++;
        }
        if(count == k){
            cout << a[i].second + 1 << endl;
            return;
        }
        if(a[i].first > x){
            break;
        }
    }
    if(count != k){
        cout  << -1 << endl;
        return;
    }
}
int main(){
    ll N,Q;
    cin >> N >> Q;
    a.resize(N);
    rep(i,N){
        cin >> a[i].first;
        a[i].second = i;
    }
    m.resize(Q);
    rep(i,Q){
        cin >> m[i].first >> m[i].second;
    }   
    ll c[N] = {0};
    sort(a.begin(),a.end());
    rep(j,Q){
        find(m[j].first,m[j].second);
    }
}