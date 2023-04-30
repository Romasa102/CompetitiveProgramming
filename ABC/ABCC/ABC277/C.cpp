#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int move(int P,map<int,vector<int>> M){
    bool nothing  = true;
    int maxNow = 0;
    rep(i,M[P].size()){
        cout << P << M[P].size() << endl;
        if(M[P][i]){
            if(move(i,M) > maxNow){
                maxNow = move(i,M);
            }
            nothing = false;
        }
    }
    if(nothing == true){
        return P;
    }
    return maxNow;
}
int main(){
    ll N;
    cin >> N;
    map<int,vector<int>>mp;
    ll A,B;
    rep(i,N){ 
        cin >> A >> B;
        mp[A-1].push_back(B-1);
        mp[B-1].push_back(A-1);
    }
    cout << move(0,mp) << endl;
    
}