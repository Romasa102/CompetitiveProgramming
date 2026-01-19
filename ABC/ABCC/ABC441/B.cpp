#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    string S,T;
    cin >> S >> T;
    bool takahashi[27];
    bool aoki[27];
    rep(i,27){
        takahashi[i] = false;
        aoki[i] = false;
    }
    rep(i,S.size())takahashi[S[i]-'a']=true;
    rep(i,T.size())aoki[T[i]-'a']=true;
    ll Q;
    cin >> Q;
    rep(_,Q){
        string w;
        cin >> w;
        bool Taka = true;
        bool Ao = true;
        rep(i,w.size()){
            if(takahashi[w[i]-'a']==false)Taka = false;
            if(aoki[w[i]-'a']==false)Ao = false;
        }
        if(Taka && Ao){
            cout << "Unknown" << endl;
        }else if(Taka){
            cout << "Takahashi" << endl;
        }else if(Ao){
            cout << "Aoki" << endl;
        }else{
            cout << "Unknown" << endl;
        }
    }
}