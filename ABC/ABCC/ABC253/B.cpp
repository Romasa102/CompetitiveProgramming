#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll H,W;
    cin >> H >> W;
    string S[H];
    rep(i,H){
        cin >> S[i];
    }
    P one;
    bool oneE = false;
    P two;
    rep(i,H){
        rep(j,W){
            if(S[i][j] == 'o'){
                if(oneE == false){
                    one.first = i;
                    one.second = j;
                    oneE = true;
                }else{
                    two.first = i;
                    two.second = j;
                    break;
                }
            }
        }
    }
    cout << one.first << " " << two.first << endl;
    cout << one.second << " " << two.second << endl;
    cout << abs(one.first - two.first) + abs(one.second - two.second) << endl;
}