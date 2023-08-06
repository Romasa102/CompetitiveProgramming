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
    ll k;
    cin >> k;
    vector<P> rc(k);
    vector<ll> yaxis;
    rep(i,k){
        ll a,b;
        cin >> a >> b;
        rc[i].first = a;
        rc[i].second = b;
    }
    rep(i,8){
        yaxis.push_back(i);
    }
    do{
        ll counter = 0;
        vector<P> queen(8);
        bool Ans[8][8];
        rep(i,8){
            rep(j,8){
                Ans[i][j] = false;
            }
        }
        rep(i,8){
            queen[i].first = i;
            queen[i].second = yaxis[i];
            Ans[i][yaxis[i]] = true;
        }
        rep(j,k){
            if(yaxis[rc[j].first] == rc[j].second){ 
                counter++;
            }
        }
        
        if(counter < k)continue;
        bool Satisfy = true;
        rep(i,8){
            rep(j,8){
                if(i==j)continue;
                if(queen[i].first == queen[j].first)Satisfy = false;
                if(queen[i].second == queen[j].second)Satisfy = false;
                if(abs(queen[i].first - queen[j].first) == abs(queen[i].second - queen[j].second)){
                    Satisfy = false;
                }
            }
        }
        if(Satisfy){
            rep(i,8){
                rep(j,8){
                    if(Ans[i][j]){
                        cout << "Q";
                    }else{
                        cout << ".";
                    }
                }
                cout << endl;
            }
        }
    }while(next_permutation(yaxis.begin(),yaxis.end()));
}