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
    ll t;cin >> t;
    while(t--){
        ll n,x,y;
        cin >> n >> x >> y;
        ll p[n];
        rep(i,n)cin >> p[i];
        vector<ll> fsten;
        vector<ll> mid;
        bool inM = false;
        rep(i,n){
            if(i==x){
                inM = true;
            }
            if(i==y){
                inM = false;
            }
            if(inM){
                mid.push_back(p[i]);
            }else{
                fsten.push_back(p[i]);
            }
        }
        ll midmin = 1LL<<50;
        ll midminInd = 0;
        rep(i,mid.size()){
            if(midmin>mid[i]){        
                midminInd=i;    
                midmin=min(midmin,mid[i]);
            }
        }
        rotate(mid.begin(), mid.begin() +midminInd, mid.end());
        bool middone = false;
        rep(i,fsten.size()){
            if(!middone && fsten[i] > midmin){
                middone=true;
                rep(j,mid.size()){
                    cout << mid[j] << " ";
                }
            }
            cout << fsten[i] << " ";
        }
        if(!middone){
            rep(j,mid.size()){
                    cout << mid[j] << " ";
                }
        }
        cout << endl;
    }
}