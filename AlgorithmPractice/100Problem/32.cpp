#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll w,h;
    while(true){
        cin >> w >> h;
        if(w == 0 && h == 0)break;
        ll wall[2 * h - 1][2 * w - 1];
        rep(i,2*h-1){
            rep(j,2 * w -1){
                wall[i][j] = -1;
            }
        }
        rep(i,2 * h - 1){
            if(i%2 == 0){
                rep(j,w-1){
                    cin >> wall[i][j*2+1];
                }
            }else{
                rep(j,w){
                    cin >> wall[i][2 * j];
                }
            }
        }
        rep(i,2*h-1){
            rep(j,2 * w -1){
                cout << wall[i][j] << " ";
            }cout << endl;
        }
    }
    queue<P> Q;
    Q.push({0,0});
    while(Q.size()){
        ll x = Q.front().first;
        ll y = Q.front().second;
        if(2 * x)
    }
}



