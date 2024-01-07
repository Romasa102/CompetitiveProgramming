#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,Q;
    cin >> N >> Q;
    deque<P> pos;
    rep(i,N)pos.push_back({i+1,0});
    rep(i,Q){
        ll cmd = 0;
        cin >> cmd;
        if(cmd == 1){
            //move head;
            P curT = pos.front();
            pos.pop_back();
            char dir;
            cin >> dir;
            if(dir == 'R'){
                pos.push_front({curT.first+1,curT.second});
            }else if(dir == 'L'){
                pos.push_front({curT.first-1,curT.second});
            }else if(dir == 'U'){
                pos.push_front({curT.first,curT.second+1});
            }else if(dir == 'D'){
                pos.push_front({curT.first,curT.second-1});
            }
        }else{
            //get the pos;
            ll id;
            cin >> id;
            cout << pos[id-1].first << " " << pos[id-1].second << endl;
        }
    }
}