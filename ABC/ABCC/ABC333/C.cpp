#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    vector<vector<string>> s(12);
    vector<ll>final;
    s[0].push_back("3");
    rep(i,11){
        for(string o:s[i]){
            if(o[0]=='1'){
                s[i+1].push_back("1"+o);
            }else if(o[0]=='2'){
                s[i+1].push_back("1"+o);
                s[i+1].push_back("2"+o);
            }else{
                s[i+1].push_back("1"+o);
                s[i+1].push_back("2"+o);
                s[i+1].push_back("3"+o);
            }
        }
    }
    rep(i,12){
        rep(j,s[i].size()){
            final.push_back(stoll(s[i][j]));
        }
    }
    sort(final.begin(),final.end());
    cout << final[N-1] << endl;
}