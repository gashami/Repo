#include <iostream>
#include <cstring>
using namespace std;

class Solution{
    public:
       int myAtoi(string s){
            while(s[0] == ' '){
                 s.erase(0, 1);
            }
            int sign = 1;
            if(s[0] == '+' || s[0] == '-'){
                if(s[0] == '-'){
                    sign = -1;
                }
                s.erase(0, 1);             
            }
            int result = 0;
            for(int i = 0; i < s.length(), i++){
                if(!isdigit(s[i]))
                    break;
                int v = s[i] - '0';
                if(result > INT32_MAX/10){
                    

                }
            }          
       }
};


int main(){
    Solution sol;
    cout<<sol.myAtoi("123460");

    return 0;
}