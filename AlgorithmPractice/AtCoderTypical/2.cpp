#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    if(N%2==1)return 0;
    vector<string> sets;
    for(ll i = 0;i<(1LL<<N); i++){
        string cur="";
        rep(j,N){
            cur+= 'a';
        }
        rep(j,N){
            if(i&1<<j){
                cur[j]='b';
            }
        }
        sets.push_back(cur);
    }
    set<string> ans;
    rep(i,sets.size()){
        queue<int> Lbracket;
        bool ok = true;
        rep(j,sets[i].size()){
            if(sets[i][j] == 'a'){
                Lbracket.push(1);
            }else{
                if(Lbracket.empty()){
                    ok = false;
                    break;
                }
                Lbracket.pop();
            }
        }
        if(Lbracket.empty()&&ok){
            ans.insert(sets[i]);
        }
    }
    for(string i:ans){
        rep(j,i.size()){
            if(i[j]=='a'){
                i[j]='(';
            }else{
                i[j]=')';
            }
        }
        cout << i << endl;
    }
}