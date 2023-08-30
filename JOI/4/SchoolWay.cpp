#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll a,b;
    ll n;
    cin >>a >> b >> n;
    map<P,bool> fix;
    rep(i,n){
        ll f,s;
        cin >> f >>s;
        fix[{f-1,s-1}] = true;
    }
    queue<P> Q;
    ll pattern[a][b];
    bool visit[a][b];
    rep(i,a){
        rep(j,b){
            pattern[i][j] = 0;
            visit[i][j] = false;
        }
    }
    pattern[0][0] = 1;
    Q.push({0,0});
    while(Q.size()){
        P now = Q.front();
        Q.pop();
        if(visit[now.first][now.second])continue;
        visit[now.first][now.second] = true;
        if(fix.find({now.first+1,now.second}) == fix.end()){
            if(now.first + 1 < a){
                Q.push({now.first+1,now.second});
                pattern[now.first + 1][now.second]+=pattern[now.first][now.second];
            }
        }
        if(fix.find({now.first-1,now.second}) == fix.end()){
            if(now.first - 1 >= 0){
                Q.push({now.first-1,now.second});
                pattern[now.first - 1][now.second] += pattern[now.first][now.second];
            }
        }
        if(fix.find({now.first,now.second + 1}) == fix.end()){
            if(now.second + 1 < b){
                Q.push({now.first,now.second+1});
                pattern[now.first][now.second + 1]+= pattern[now.first][now.second];
            }
        }
        if(fix.find({now.first,now.second-1}) == fix.end()){
            if(now.second - 1 >= 0){
                Q.push({now.first,now.second-1});
                pattern[now.first][now.second - 1] += pattern[now.first][now.second];
            }
        }
    }
    cout << pattern[a-1][b-1] << endl;
}