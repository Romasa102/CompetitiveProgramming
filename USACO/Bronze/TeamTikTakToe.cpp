#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    freopen("tttt.in", "r", stdin);
    string s[3];
    rep(i,3){
        cin >> s[i];
    }
    set<char> indivisual;
    set<pair<char,char>> team;//consist of 2 cows
    rep(i,3){
        set<char> used;
        rep(j,3){
            used.insert(s[i][j]);
        }
        if(used.size() == 1){
            indivisual.insert(*used.begin());
        }else if(used.size()==2){
            team.insert({*used.begin(),*used.rbegin()});
            team.insert({*used.rbegin(),*used.begin()});
        }
    }
    rep(j,3){
        set<char> used;
        rep(i,3){
            used.insert(s[i][j]);
        }
        if(used.size() == 1){
            indivisual.insert(*used.begin());
        }else if(used.size()==2){
            team.insert({*used.begin(),*used.rbegin()});
            team.insert({*used.rbegin(),*used.begin()});
        }
    }
    set<char> used;
    rep(i,3){
        used.insert(s[i][i]);
    }
    if(used.size() == 1){
        indivisual.insert(*used.begin());
    }else if(used.size()==2){
        team.insert({*used.begin(),*used.rbegin()});
        team.insert({*used.rbegin(),*used.begin()});
    }

    set<char> used2;
    rep(i,3){
        used2.insert(s[i][2-i]);
    }
    if(used2.size() == 1){
        indivisual.insert(*used2.begin());
    }else if(used2.size()==2){
        team.insert({*used2.begin(),*used2.rbegin()});
        team.insert({*used2.rbegin(),*used2.begin()});
    }
    freopen("tttt.out", "w", stdout);
    cout << indivisual.size() << endl;
    cout << team.size()/2 << endl;
}