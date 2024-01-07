#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    set<string> ans;
    rep(i,N+1){
        rep(j,N+1){
            rep(k,N+1){
                if(i+j+k<=N){
                    string l;
                    l+=(char)i+'a';
                    l+=(char)j+'a';
                    l+=(char)k+'a';
                    ans.insert(l);
                }
            }
        }
    }
    for(string i : ans){
        if(i.size() == 3){
            rep(j,i.size()){
                cout << i[j]-'a' << " ";
            }cout << endl;
        }else{
            rep(j,i.size()){
                cout << i[j]-'a';
                if(j%2 == 1){
                    cout << " ";
                }
            }cout << endl;
        }
    }
}