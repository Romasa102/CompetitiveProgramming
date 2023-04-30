#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll sz = 0;
    P counter = {0,0};
    vector<ll> v;
    bool deled = false;
    rep(i,N){
        ll k;
        cin >> k;
        v.push_back(k);
        if(k == counter.first){
            counter.second++;
        }else{
            counter.first = k;
            counter.second = 1;
        }
        if(counter.first > 1 && counter.first == counter.second){
            v.erase(v.end() - counter.first,v.end());
            deled = true;
        }
        while(deled == true){
            deled = true;
            rep(j,v[v.size() - 1]){
                if(v[v.size() - 1 - j] != v[v.size() - 1]){
                    deled = false;
                    counter.first = v[v.size()];
                    counter.second = j + 1;
                    break;
                }
            }
            if(deled == true){
                v.erase(v.end() - v[v.size() - 1],v.end());
            }
        }
        rep(i,v.size()){
            cout << v[i];
        }cout << endl;
        cout << v.size() << endl;
    }
}