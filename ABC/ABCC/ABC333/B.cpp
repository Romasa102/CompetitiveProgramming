#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string S,T;
    char S1,S2,T1,T2;
    cin >> S >> T;
    S1=S[0];S2=S[1];T1=T[0];T2=T[1];
    map<pair<char,char>,ll> mp;
    mp[{'A','B'}]=1;
    mp[{'B','C'}]=1;
    mp[{'C','D'}]=1;
    mp[{'D','E'}]=1;
    mp[{'E','A'}]=1;
    mp[{'A','C'}]=2;
    mp[{'B','D'}]=2;
    mp[{'C','E'}]=2;
    mp[{'D','A'}]=2;
    mp[{'E','B'}]=2;
    mp[{'B','A'}]=1;
    mp[{'C','B'}]=1;
    mp[{'D','C'}]=1;
    mp[{'E','D'}]=1;
    mp[{'A','E'}]=1;
    mp[{'C','A'}]=2;
    mp[{'D','B'}]=2;
    mp[{'E','C'}]=2;
    mp[{'A','D'}]=2;
    mp[{'B','E'}]=2;
    if(mp[{S1,S2}]==mp[{T1,T2}]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}