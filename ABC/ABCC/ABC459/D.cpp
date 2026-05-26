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
    rep(_,T){
        string S;
        cin >> S;
        ll Ssize = (ll)S.size();
        vector<ll> count(27);
        rep(i,Ssize){
            count[S[i]-'a']++;
        }
        vector<pair<ll,char>> charOcc(27);
        rep(i,27){
            charOcc[i] = {count[i],i+'a'};
        }
        sort(charOcc.begin(),charOcc.end(),greater<pair<ll,char>>());
        if(charOcc[0].first > (Ssize+1)/2){
            cout << "No" << endl;
            continue;
        }else{
            cout << "Yes" << endl;
            while(charOcc[0].first !=0){
                cout << charOcc[0].second;
                charOcc[0].first--;
                if(charOcc[1].first>0){
                    cout << charOcc[1].second;
                    charOcc[1].first--;
                }
                sort(charOcc.begin(), charOcc.end(), greater<pair<ll,char>>());
            }
            cout << endl;
        }
    }

}