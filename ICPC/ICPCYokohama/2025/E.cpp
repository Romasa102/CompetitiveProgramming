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
const ll MAX = 1LL<<50;
int main(){
    while(true){
        ll n;
        cin >> n;
        if(n == 0)return 0;
        ll p[n],c[n];
        repp(i,1,n){
            cin >> p[i] >> c[i];
            p[i]--;
        }
        map<ll,vector<ll>> mp;
        repp(i,1,n){
            mp[i].push_back(p[i]);
            mp[p[i]].push_back(i);
        }
        vector<pair<ll,P>> vec;
        repp(i,1,n){
            vec.push_back({c[i], {i,p[i]}});
        }
        vector<vector<P>> dists;
        rep(i,n){
            queue<ll> q;
            vector<ll> dist(n,MAX);
            dist[i] =0;
            q.push(i);

            while(!q.empty()){
                ll cur = q.front();
                q.pop();
                for(auto j : mp[cur]){
                    if(dist[j] != MAX){
                        dist[j] = dist[i]+1;
                        q.push(j);
                    }
                }
            }
            vector<P> distP;
            rep(j,n){
                distP.push_back({dist[j],j});
            }
            dists.push_back(distP);
        }

        sort(vec.begin(),vec.end());
        ll cur = 0;
        ll time = 0;
        set<ll> visited;
        visited.insert(0);
        bool work = true;
        rep(i,vec.size()){
            ll tiemLimit = vec[i].first - time;
            ll nodeo = vec[i].second.first;
            ll nodet = vec[i].second.second;
            ll minimumTimeTake = 1LL<<50;
            for(auto j:dists[nodeo]){
                if(visited.find(j.second) != visited.end()){
                    minimumTimeTake = min(j.first,minimumTimeTake);
                    break;
                }
            }

            for(auto j:dists[nodet]){
                if(visited.find(j.second) != visited.end()){
                    minimumTimeTake = min(j.first,minimumTimeTake);
                    break;
                }
            }
            if(minimumTimeTake > tiemLimit){
                work = false;
            }
        }
        if(work){
            cout << "yes" << endl;
            repp(i,1,vec.size()){
                cout << vec[i].second.second+1;
            }
        }else{
            cout << "no" << endl;
        }
    }
}