#include <bits/stdc++.h>
using namespace std;
int main(){
    int S,T,X;
    cin >> S >> T >> X;
    bool Ans = false;
    if(S < T){
        if(S <= X && X < T){
            Ans = true;
        }
    }else if(S <= X || X < T){
        Ans = true;
        
    }
    if(Ans){
        cout << " Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}