#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string S;
    cin >> S;
    ll ans = 0;
    ll JOI[3];
    JOI[0] = 0;
    JOI[1] = 0;
    JOI[2] = 0;
    rep(i,S.size()){
        if(S[i] == 'J'){
            if(JOI[1]!=0||JOI[2]!=0){
                JOI[0] = 0;
                JOI[1] = 0;
                JOI[2] = 0;
            }
            JOI[0]++;
        }
        if(S[i] == 'O'){
            if(JOI[0]==0||JOI[2]!=0){
                JOI[0] = 0;
                JOI[1] = 0;
                JOI[2] = 0;
            }
            if(JOI[0]!=0&&JOI[2]==0){
                JOI[1]++;
            }
        }
        if(S[i] == 'I'){
            JOI[2]++;
        }
        if(JOI[0] != 0 && JOI[1] != 0 && JOI[2] != 0){
            if(JOI[1] <= JOI[0] && JOI[1] <= JOI[2]){
                ans = max(ans,JOI[1]);
            }
        }
    }
    cout << ans << endl;
}