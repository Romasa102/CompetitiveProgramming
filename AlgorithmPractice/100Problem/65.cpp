#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
ll parents[1000000];
ll find(int child){
    if(parents[child] == child)return child;
    return parents[child] = find(parents[child]);
}
void Union(int a,int b){
    parents[find(a)] = find(b);
}
int main(){
    ll N,M,K;
    cin >> N >> M >> K;
    ll a[M];
    ll b[M];
    ll c[M];
    P connection[M];
    ll size = N;
    rep(i,N){
        parents[i] = i;
    }
    rep(i,M){
        cin >> a[i] >> b[i] >> c[i];
        connection[i].first = c[i];
        connection[i].second = i;
    }
    sort(connection,connection + M);
    ll ans = 0;
    rep(i,M){
        if(size == K-1)break;
        if(find(a[connection[i].second]) != find(b[connection[i].second])){
            Union(a[connection[i].second],b[connection[i].second]);
            ans += connection[i].first;
            size--;
        }
    }
    cout << ans << endl;
}