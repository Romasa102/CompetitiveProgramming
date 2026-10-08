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
    ll t;
    cin >> t;
    rep(_,t){
        ll n;string s;cin >> n >> s;
        stack<ll> printq;
        set<ll> printed;
        rep(i,n){
            if(s[i] == '1'){ // add to q
                printq.push(i);
            }else if(s[i] == '2'){ // print topq
                if(printq.empty()){
                    printed.insert(i);
                    continue;
                }
                printed.insert(printq.top());
                printq.pop();
            }else if(s[i] == '3'){ //instant print;
                printed.insert(i);
            }
        }
        cout << n - printed.size() << endl;;
        rep(i,n){
            if(printed.find(i)==printed.end()){
                cout << i + 1<< " ";
            }
        }cout << endl;
    }
}