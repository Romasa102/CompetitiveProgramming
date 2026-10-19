#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.size();
    vector<vector<pair<int,int>>>v(n);
    vector<pair<int,int>>st;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            st.push_back({i,cnt});
        }else if(s[i]==')'){
            v[cnt-st.back().second].push_back({st.back().first,i});
            st.pop_back();
        }else{
            cnt++;
        }
    }
    if(cnt%3){
        cout<<"impossible\n";
        return 0;
    }
    vector<pair<int,int>>ans;
    if(!v[cnt/3*2].empty()){
        ans.push_back(v[cnt/3*2][0]);
        for(pair<int,int>p:v[cnt/3]){
            if(p.first>ans[0].first&&p.second<ans[0].second){
                ans.push_back(p);
                break;
            }
        }
        if(ans.size()==1){
            cout<<"impossible\n";
            return 0;
        }
        vector<string>w(3);
        w[1]="[1] ";
        w[2]="[2] ";
        for(int i=0;i<ans[0].first;i++){
            w[0]+=s[i];
        }
        w[0]=w[0]+"[1]";
        for(int i=ans[0].second+1;i<n;i++){
            w[0]+=s[i];
        }
        for(int i=ans[0].first+1;i<ans[1].first;i++){
            w[1]+=s[i];
        }
        w[1]=w[1]+"[2]";
        for(int i=ans[1].second+1;i<ans[0].second;i++){
            w[1]+=s[i];
        }
        for(int i=ans[1].first+1;i<ans[1].second;i++){
            w[2]+=s[i];
        }
        for(string i:w)cout<<i<<'\n';
    }else{
        for(auto p:v[cnt/3]){
            if(ans.empty()){
                ans.push_back(p);
            }else if(!(p.first>ans[0].first&&p.second<ans[0].second)&&!(p.first<ans[0].first&&p.second>ans[0].second)){
                ans.push_back(p);
                break;
            }
        }
        if(ans.size()<2){
            cout<<"impossible\n";
            return 0;
        }
        if(ans[1].second<ans[0].first)swap(ans[0],ans[1]);
        vector<string>w(3);
        w[1]="[1] ";
        w[2]="[2] ";
        for(int i=0;i<ans[0].first;i++){
            w[0]+=s[i];
        }
        w[0]+="[1]";
        for(int i=ans[0].second+1;i<ans[1].first;i++){
            w[0]+=s[i];
        }
        w[0]+="[2]";
        for(int i=ans[1].second+1;i<n;i++){
            w[0]+=s[i];
        }
        for(int i=ans[0].first+1;i<ans[0].second;i++){
            w[1]+=s[i];
        }
        for(int i=ans[1].first+1;i<ans[1].second;i++){
            w[2]+=s[i];
        }
        for(string i:w)cout<<i<<'\n';
    }
}