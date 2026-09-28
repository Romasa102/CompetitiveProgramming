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
                    if(dist[j] == MAX){
                        dist[j] = dist[cur]+1;
                        q.push(j);
                    }
                }
            }
            vector<P> distP;
            rep(j,n){
                distP.push_back({dist[j],j});
            }
            sort(distP.begin(),distP.end());
            dists.push_back(distP);
        }

        sort(vec.begin(),vec.end());
        ll cur = 0;
        ll time = 0;
        set<ll> visited;
        visited.insert(0);
        vector<ll> ans;
        bool work = true;
        rep(i,vec.size()){
            ll timeLimit = vec[i].first - time;
            ll nodeo = vec[i].second.first;
            ll nodet = vec[i].second.second;
            ll minimumTimeTake = 1LL<<50;
            ll beg;
            ll dest = nodeo;
            if(visited.find(nodeo) != visited.end() && visited.find(nodet) != visited.end())continue;;
            for(auto j:dists[nodeo]){
                if(visited.find(j.second) != visited.end()){
                    if(j.first < minimumTimeTake){
                        beg = j.second;
                        dest = nodet;
                    }
                    minimumTimeTake = min(j.first,minimumTimeTake);
                    break;
                }
            }

            for(auto j:dists[nodet]){
                if(visited.find(j.second) != visited.end()){
                    if(j.first < minimumTimeTake){
                        beg = j.second;
                        dest = nodeo;
                    }
                    minimumTimeTake = min(j.first,minimumTimeTake);
                    break;
                }
            }
            queue<ll> q;
            vector<ll> dist(n,MAX);
            dist[beg] = 0;
            q.push(beg);
            vector<ll> par(n);
            par[beg] = -1;
            while(!q.empty()){
                ll cur = q.front();
                q.pop();
                for(auto j : mp[cur]){
                    if(dist[j] == MAX){
                        par[j] = cur;
                        dist[j] = dist[cur]+1;
                        q.push(j);
                    }
                }
            }
            vector<ll> path;
            for(ll v = dest; v != -1; v = par[v]) path.push_back(v);
            reverse(path.begin(),path.end());
            for(auto k : path){
                if(visited.find(k) == visited.end()){
                    visited.insert(k);
                    ans.push_back(k);
                }
            }
            if(minimumTimeTake > timeLimit){
                work = false;
            }
            time += dist[dest];
        }
        if(work){
            cout << "yes" << endl;
            rep(i,vec.size()){
                cout << ans[i]+1 << " ";
            }cout << endl;
        }else{
            cout << "no" << endl;
        }
    }
}