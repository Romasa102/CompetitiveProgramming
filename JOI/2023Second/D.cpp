#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    string S[N];
    rep(i,N)cin >> S[i];
    ll fAns = 0;
    ll dx[4]={0,0,1,-1};
    ll dy[4]={1,-1,0,0};
    rep(i,N){
        rep(j,N){//{i,j}=center;
            queue<pair<ll,P>> Q;//depth pos
            vector<string>depth(N+1000);
            vector<vector<bool>> visited(N,vector<bool>(N,false));
            Q.push({0,{i,j}});
            ll ans = 0;
            while(!Q.empty()){
                auto cur = Q.front();Q.pop();
                ll dep = cur.first;
                P pos =  cur.second;
                if(visited[pos.first][pos.second])continue;
                visited[pos.first][pos.second]=true;
                if(pos.first>=N||pos.second>=N)continue;
                char in = S[pos.first][pos.second];
                depth[dep].push_back(in);
                rep(o,4){
                    if(pos.first+dx[o]>=N||pos.second+dy[o]>=N || pos.second+dy[o]<0 || pos.first+dx[o]<0){
                        continue;
                    }
                    if(visited[pos.first+dx[o]][pos.second+dy[o]])continue;
                    Q.push({dep+1,{pos.first+dx[o],pos.second+dy[o]}});
                }
            }
            rep(k,10){
                cout << depth[k] << endl;
            }
            rep(k,N){
                if(depth[k].size()!=k*k*2+2*k+1){
                    break;
                }
                char al = depth[k][0];
                bool work = true;
                rep(l,k*k*2+2*k+1){
                    if(depth[k][l]!=al){
                        work = false;
                    }
                }
                if(work)ans+=(k*k*2+2*k+1);
            }
            fAns = max(fAns,ans);
        }
    }
    cout << fAns << endl;
}