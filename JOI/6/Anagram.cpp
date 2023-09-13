#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
#define rrep(i,n) for(ll i = n; i >= 0; --i)
using P = pair<ll,ll>;
int main(){
    string S;
    cin >> S;
    vector<char> sortThis;
    map<char,P> charM;//char {howBig,howMany}
    rep(i,S.size()){
        sortThis.push_back(S[i]);
    }
    sort(sortThis.begin(),sortThis.end());
    ll cont = 1;
    ll num = 1;
    charM[sortThis[0]] = {num,cont};
    repp(i,1,sortThis.size()){
        if(sortThis[i] == sortThis[i-1]){
            cont ++;
            charM[sortThis[i]] = {num,cont};
        }else{
            num++;
            charM[sortThis[i]] = {num,1};
            cont = 1;
        }
    }
    ll ans = 0;
    ll factorialNum[S.size()]; //factor of S,size()-1;
    factorialNum[0] = 1;
    repp(i,1,S.size()){
        factorialNum[i] = factorialNum[i-1]*i;
    }
    rep(i,S.size()-1){
        for(auto itra = charM.begin(); itra != charM.end(); itra++) {
            ll cash = factorialNum[S.size()-1-i];
            if(charM[S[i]].first < itra->second.first){
                continue;
            }else{
                itra->second.second--;
            }
            for (auto itr = charM.begin(); itr != charM.end(); itr++) {
                cash /= factorialNum[(itr->second.second)];
                if (charM[S[i]].first < itr->second.first && charM[S[i]].second == 0) {
                    itr->second.first--;
                }
            }
            ans += cash;
            itra->second.second++;
            cout << cash << endl;
        }
        charM[S[i]].second-=1;
    }
    cout << ans+1 << endl;
}
