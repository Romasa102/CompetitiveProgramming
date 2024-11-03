#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll H,W,N;cin >> H >> W >> N;
    string smp = "";rep(i,W)smp+='.';
    string S[H];rep(i,H)S[i] = smp;
    ll dir = 0;
    ll dx[4] = {-1,0,1,0};
    ll dy[4] = {0,1,0,-1};
    P cur = {0,0};
    rep(_,N){
        if(S[cur.first][cur.second]=='.'){
            S[cur.first][cur.second] = '#';
            dir++;dir%=4;
        }else if(S[cur.first][cur.second] == '#'){
            S[cur.first][cur.second] = '.';
            dir+=3;dir%=4;
        }
        cur.first+=dx[dir];cur.second+=dy[dir];
        if(cur.first<0)cur.first=H-1;
        if(cur.first>=H)cur.first=0;
        if(cur.second<0)cur.second=W-1;
        if(cur.second>=W)cur.second=0;
    }
    rep(i,H)cout << S[i] << endl;
}