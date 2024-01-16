#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;N--;
    vector<ll> ans;
    if(N==0){
        cout << 0 << endl;
        return 0;
    }
    while(N>0){
        ans.push_back(N%5);
        N/=5;
    }
    rep(i,ans.size()){
        ll ind = ans[ans.size()-1-i];
        if(ind==0){
            cout << "0";
        }else if(ind == 1){
            cout << "2";
        }else if(ind == 2){
            cout << "4";
        }else if(ind == 3){
            cout << "6";
        }else if(ind == 4){
            cout << "8";
        }
    }cout << endl;
}