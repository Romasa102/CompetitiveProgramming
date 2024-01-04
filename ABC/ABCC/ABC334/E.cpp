#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
map<P,P> parents;
P find(P a){
    if(parents[{a}]==a){
        return a;
    }
    return parents[a]=find(parents[a]);
}
void Union(P a,P b){
    parents[find(a)] = find(b);
}
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
int main(){
    ll H,W;
    cin >> H >> W;
    string S[H];
    rep(i,H)cin >> S[i];
    rep(i,H){
        rep(j,W){
            if(S[i][j] == '#'){
                parents[{i,j}]={i,j};
            }else{
                parents[{i,j}]={-1,-1};
            }
        }
    }
    ll dx[4] = {0,0,-1,1};
    ll dy[4] = {1,-1,0,0};
    rep(i,H){
        rep(j,W){
            if(S[i][j] == '#'){
                rep(k,4){
                    if(i+dx[k] >= H || i+dx[k] < 0)continue;
                    if(j+dy[k] >= W || j+dy[k] < 0)continue;
                    if(S[i+dx[k]][j+dy[k]]=='#'){
                        Union({i,j},{i+dx[k],j+dy[k]});
                    }
                }
            }
        }
    }
    set<P> plc;
    rep(i,H){
        rep(j,W){
            plc.insert(find({i,j}));
        }
    }
    ll totalR = 0;
    ll ans =0;
    rep(i,H)rep(j,W)if(S[i][j] == '.')totalR++;
    rep(i,H){
        rep(j,W){
            if(S[i][j]=='.'){
                set<P> plcs;
                rep(k,4){
                    if(i+dx[k] >= H || i+dx[k] < 0)continue;
                    if(j+dy[k] >= W || j+dy[k] < 0)continue;
                    if(S[i+dx[k]][j+dy[k]]=='#'){
                        plcs.insert(find({i+dx[k],j+dy[k]}));
                    }
                }
                ans += plc.size()-plcs.size()+1;
            }
        }
    }
    cout << modinv(totalR,998244353)*ans << endl;
}