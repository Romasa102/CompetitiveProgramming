#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll Q;
    cin >> Q;
    deque<ll> que;
    rep(i,Q){
        ll a;
        cin >> a;
        if(a == 1){
            que.push_back(0);
        }else if(a == 2){
            ll b;
            cin >> b;
            if(que.empty())continue;
            ll before = que.back();
            que.pop_back();
            que.push_back(before+b);
        }else{
            ll b;cin >> b;
            ll cur = 0;
            ll num = 0;
            for (int j = que.size()-1; j >= 0; --j) {
                cur += que[j];
                if(cur >= b){
                    num=j+1;
                    break;
                }
            }
            cout << num << endl;
            rep(j,num){
                que.pop_front();
            }
        }
    }
}