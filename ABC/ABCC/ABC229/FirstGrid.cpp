#include <bits/stdc++.h>
using namespace std;
int main(){
    char a[5];
    string M,N;
    cin >> M;
    cin >> N;
    a[0] = M[0];
    a[1] = M[1];
    a[2] = N[0];
    a[3] = N[1];
    int counter = 0;
    vector<int> I;
    for (int i = 0; i < 4; i++)
    {
        if(a[i] == '#'){
            counter++;
            I.push_back(i);
        }
    }
    if(counter == 4){
        cout << "Yes" << endl;
    }else if(counter == 3){
        cout << "Yes" << endl;
    }else if(counter == 2){
        if(I[0] == 0 && I[1] == 1){
            cout << "Yes" << endl;
        }
        else if(I[0] == 0 && I[1] == 2){
            cout << "Yes" << endl;
        }
        else if(I[0] == 1 && I[1] == 3){
            cout << "Yes" << endl;
        }
        else if(I[0] == 2 && I[1] == 3){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }else{
        cout << "No" << endl;
    }
}