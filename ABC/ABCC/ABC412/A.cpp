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
    ll T;
    cin >> T;
    rep(i,T){
        ll N;
        cin >> N;
        deque<ll> S(N);
        rep(j,N){
            cin >> S[j];
        }
        ll base = S[N-1];
        ll goal = S[0];
        S.pop_back();
        S.pop_front();
        sort(S.begin(),S.end());
        ll current = base;
        bool work = true;
        ll counter = 2;
        while((current+1)/2 > goal){
            if(S.size()==0){
                work = false;
                break;
            }
            if(lower_bound(S.begin(),S.end(),(current+1)/2)!=S.end()){
                if(current == *lower_bound(S.begin(),S.end(),(current+1)/2)){
                    work = false;
                    break;
                }
                current = *lower_bound(S.begin(),S.end(),(current+1)/2);
                counter++;
            }else{
                work = false;
                break;
            }
        }
        if(work){
            cout << counter << endl;
        }else{
            cout << "-1" << endl;
        }
    }
}