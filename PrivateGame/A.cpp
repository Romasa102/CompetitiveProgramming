#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string w;
    cin >> w;
    map<char,int> cool;
    rep(i,w.size()){
        cool[w[i]]++;
    }
    for(auto i = cool.begin();i != cool.end(); i++){
        if(i->second % 2 == 1){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}