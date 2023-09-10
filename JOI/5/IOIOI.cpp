#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll n;
    ll m;
    string s;
    cin >> n >> m >> s;
    ll currentCon = 0;
    char currentN = 'I';
    vector<ll> continuousC;
    rep(i,s.size()){
        if(s[i] == currentN){
            if(currentN == 'I'){
                currentN = 'O';
            }else{
                currentN = 'I';
            }
            currentCon++;
        }else{
            if(currentCon >= 3+2*(n-1)) {
                continuousC.push_back(currentCon);
            }
            if(s[i] == 'I'){
                currentN = 'O';
                currentCon = 1;
            }else{
                currentN = 'I';
                currentCon = 0;
            }
        }
    }
    ll ans = 0;
    rep(i,continuousC.size()){
        ans += (continuousC[i] - (3+2*(n-1)))/2 + 1;
    }
    cout << ans << endl;
}