#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    string T;
    cin >> N >> T;
    set<ll> ans;
    rep(i,N){
        string S;
        cin >> S;
        ll diffe = T.size()-S.size();
        if(abs(diffe)>1){
            continue;
        }
        if(T == S){
            ans.insert(i+1);
            continue;
        }
        if(S.size()>T.size()){
            bool diff = false;
            bool cor = true;
            rep(j,S.size()){
                ll o = j;
                if(diff){
                    o--;
                }else{
                    if(j==S.size()-1)continue;
                }
                if(S[j] != T[o]){
                    if(diff){
                        cor = false;
                        continue;
                    }
                    diff=true;
                }
            }
            if(cor)ans.insert(i+1);
            continue;
        }else if(S.size()<T.size()){
            bool diff = false;
            bool cor = true;
            rep(j,T.size()){
                ll o = j;
                if(diff){
                    o--;
                }else{
                    if(j==T.size()-1)continue;
                }
                if(S[o] != T[j]){
                    if(diff){
                        cor = false;
                        continue;
                    }
                    diff=true;
                }
            }
            if(cor)ans.insert(i+1);
            continue;
        }else{
            bool diff = false;
            bool cor = true;
            rep(j,T.size()){
                if(S[j] != T[j]){
                    if(diff){
                        cor = false;
                        continue;
                    }
                    diff=true;
                }
            }
            if(cor)ans.insert(i+1);
            continue;
        }
    }
    cout << ans.size() << endl;
    for(int i:ans){
        cout << i << " ";
    }cout << endl;
}