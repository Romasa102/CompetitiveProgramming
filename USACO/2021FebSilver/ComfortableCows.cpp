#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
vector<vector<ll>> distribution(3000,vector<ll>(3000,0));
map<P,bool> filled;
map<P,bool>cow;
ll cur = 0;
ll dx[4] = {-1,1,0,0};
ll dy[4] = {0,0,-1,1};
void checkEmp(ll x,ll y){
    if(distribution[x][y]!=3)return;
    distribution[x][y]++;
    rep(i,4){
        if(cow.find({x+dx[i],y+dy[i]})==cow.end()){
            filled[{x+dx[i],y+dy[i]}]=true;//place that u must fill
            cow[{x+dx[i],y+dy[i]}]=true;//place a cow at the position
            distribution[x+dx[i]][y+dy[i]]++;//set the counter
            cur++;
            rep(j,4){
                if(x+dx[i]+dx[j] == x || y+dy[i]+dy[j] == y){
                    continue;
                }
                if(cow.find({x+dx[i] + dx[j], y+dy[i]+ dy[j]}) != cow.end()){
                    distribution[x+dx[i] + dx[j]][y+dy[i]+ dy[j]]++;//place from the new cow
                    distribution[x+dx[i]][y+dy[i]]++;
                }
                if(distribution[x+dx[i]+dx[j]][y+dy[i]+dy[j]]==3){
                    checkEmp(x+dx[i]+dx[j],y+dy[i]+dy[j]);
                }
            }
            if(distribution[x+dx[i]][y+dy[i]]==3){
                checkEmp(x+dx[i],y+dy[i]);
            }
            return;
        }
    }
}
int main(){
    ll N;cin >>N;
    vector<P> cows(N);
    rep(i,N){
        cin >> cows[i].first >> cows[i].second;
        cow[{cows[i].first+1000,cows[i].second+1000}] = true;
        if(filled.find({cows[i].first+1000,cows[i].second+1000}) != filled.end()){
            cur--;
            cout << cur << endl;
            continue;
        }
        rep(j,4){
            if(cow.find({cows[i].first+1000 + dx[j], cows[i].second+1000 + dy[j]}) != cow.end()){
                distribution[cows[i].first+1000 + dx[j]][cows[i].second+1000 + dy[j]]++;
                distribution[cows[i].first+1000][cows[i].second+1000]++;
            }
            if(distribution[cows[i].first+1000 + dx[j]][cows[i].second+1000 + dy[j]]==3){
                checkEmp(cows[i].first+1000 + dx[j],cows[i].second+1000 + dy[j]);
            }
        }
        if(distribution[cows[i].first+1000][cows[i].second+1000]==3){
            checkEmp(cows[i].first+1000,cows[i].second+1000);
        }
        cout << cur << endl;
    }
}