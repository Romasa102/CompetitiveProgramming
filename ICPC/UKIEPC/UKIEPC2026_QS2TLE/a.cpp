#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define repp(i,x,n) for(int i = x; i < n; i++)
typedef long long ll;
int main(){
    int n,k;
    cin>>n>>k;
    vector<string> s(n);
    rep(i,n){
        cin >> s[i];
    }

    map<char,ll> mp;
    rep(i,n){
        rep(j,(int)s[i].size()){
            mp[s[i][j]]++;
        }
    }
    vector<pair<ll,char>> vec;
    for(auto i : mp){
        vec.push_back({i.second,i.first});
    }
    sort(vec.begin(),vec.end());
    // how do you cin an entire line
    map<char,char> sub;
    rep(i,max(0,(int)vec.size()-k)){
        sub[vec[i].second] = vec[vec.size()-1].second;
    }
    repp(i,max(0,(int)(vec.size()-k)),(int)vec.size()){
        sub[vec[i].second] = vec[i].second;
    }
    rep(i,(int)s.size()){
        rep(j,s[i].size()){
            s[i][j]=sub[s[i][j]];
        }
    }
    rep(i,(int)s.size()){
        cout << s[i] << " ";
    }cout << endl;
}