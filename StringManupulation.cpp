#include <bits/stdc++.h>

using namespace std;
    int main (){
    string line = "BrookAshami is a must try";
    vector <string> tokens;

    stringstream check1(line);

    string intermediate;

    while(getline(check1, intermediate, ' ')){
        tokens.push_back(intermediate);
    }
    for(int i = 0; i < tokens.size(); i++){
        cout<< tokens[i] << '\n';
    }
}

