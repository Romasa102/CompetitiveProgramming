#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll M,N;
    cin >> N >> M;
    string S;
    cin >> S;  // length M
    ll color[N]; //color for each char
    map<ll,vector<pair<ll,char>>> mp; //key color, pair of index and char
    rep(i,N){
        cin >> color[i];
        mp[color[i]-1].push_back({i,S[i]});
    }
    char ans[M];
    rep(i,M){
        rep(j,mp[i].size()){
            if(j == mp[i].size()-1){
                ans[mp[i][0].first] = mp[i][j].second;
                continue;
            }
            ans[mp[i][j+1].first] = mp[i][j].second;
        }
    }
    rep(i,N){
        cout << ans[i];
    }cout << endl;
}