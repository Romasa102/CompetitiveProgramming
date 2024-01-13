#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
vector<vector<bool>> visited;
vector<string> S;
ll dx[4] = {-1,1,0,0};
ll dy[4] = {0,0,1,-1};
void dfs(ll a,ll b,ll tx,ll ty,ll bx,ll by){
    if(visited[a][b])return;
    visited[a][b] = true;
    rep(i,4){
        if(a+dx[i]<=bx && a+dx[i] >= tx && b+dy[i]>=ty && b+dy[i]<=by){
            if(S[a+dx[i]][b+dy[i]]==S[a][b]){
                dfs(a+dx[i],b+dy[i],tx,ty,bx,by);
            }
        }
    }
}
int main(){
    freopen("where.in","r",stdin);
    freopen("where.out","w",stdout);

    ll N;cin >> N;
    S.resize(N);
    rep(i,N)cin >> S[i];
    ll ans = 0;
    visited.resize(N,vector<bool>(N,false));
    vector<pair<P,P>> ansPair;
    rep(i,N){
        rep(j,N){
            repp(k,i,N){
                repp(l,j,N){
                    //top left = {i,j}
                    //bottom right = {k,l}
                    fill(visited.begin(),visited.end(),vector<bool>(N,false));
                    //set<char> checker;
                    //ll num = 0;
                    bool getO;
                    map<char,ll> types;
                    while(true){
                        getO = false;
                        repp(m,i,k+1){
                            repp(n,j,l+1){
                                if(!visited[m][n]){
                                    //cout << m << n << endl;
                                    //num++;
                                    //checker.insert(S[m][n]);
                                    types[S[m][n]]++;
                                    dfs(m,n,i,j,k,l);
                                    getO=true;
                                    break;
                                }
                            }
                            if(getO)break;
                        }
                        if(!getO)break;
                        if(types.size()>=3)break;
                    }
                    bool work = true;
                    repp(m,i,k+1)repp(n,j,l+1)if(!visited[m][n])work = false;
                    if(types.size()!=2)work = false;
                    if(types.begin()->second>1&&(types.rbegin())->second>1)work = false;
                    if(types.begin()->second<=1&&(types.rbegin())->second<=1)work = false;
                    //cout << types.begin()->first<< types.begin()->second << (types.rbegin())->first<< (types.rbegin())->second << endl;
                    //if(checker.size()!=2)work = false;
                    //cout<< num<< "number of word appeared is " << checker.size() << "    " << work << " number of count is " << num << "    "<<endl;
                    //if(num<3)work = false;
                    if(work){
                       // cout << i << " " << j << " " << k << " " << l << " "  << endl;
                        ansPair.push_back({{i,j},{k,l}});
                        ans++;
                    }
                }
            }
        }
    }
    vector<bool> workingP(ansPair.size(), true);
    rep(i,ansPair.size()){
        rep(j,ansPair.size()){
            if(!workingP[i]||!workingP[j])continue;
            if(i==j)continue;
            if(ansPair[i].first.first>=ansPair[j].first.first && ansPair[i].first.second >= ansPair[j].first.second &&
            ansPair[i].second.first <= ansPair[j].second.first && ansPair[i].second.second <= ansPair[j].second.second){
                workingP[i]=false;
            }
        }
    }
    ll fans=0;
    rep(i,workingP.size()){
        if(workingP[i]){
            fans++;
        }
    }
    cout << fans << endl;
}