#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    string S;
    cin >> N >> S;
    vector<ll> B;
    vector<ll> posA;
    vector<ll> posB;
    rep(i,S.size()){
        if(S[i] == 'B'){
            B.push_back(i);
        }
        if(i%2==0){
            posA.push_back(i);
        }else{
            posB.push_back(i);
        }
    }
    ll ansA = 0;
    ll ansB = 0;
    rep(i,B.size()){
        ansA+=abs(posA[i]-B[i]);

        ansB+=abs(posB[i]-B[i]);
    }
    cout << min(ansA,ansB) << endl;
}