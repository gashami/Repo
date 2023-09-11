#include <iostream>
using namespace std;

class Solution{
    public:
        int reverse(int num){
            int rem, revNum = 0;
            while(num != 0){
                rem = num % 10;
                num = num / 10;                
                if((revNum >= INT64_MAX / 10) && (rem > 7) ) return 0;
                if((revNum <= INT64_MIN / 10) && (rem == -9) ) return 0;
                revNum = (revNum * 10) + rem;

            }
            return revNum;
        }
    
};



int main(){

    Solution sol;
    cout<<INT64_MAX <<endl;
    cout<<INT64_MIN <<endl;
    cout<<INT16_MAX <<endl;
    cout<<INT16_MIN <<endl;
    cout<<INT32_MAX <<endl;
    cout<<INT32_MIN <<endl;
    
    cout<<sol.reverse(INT64_MAX) <<endl;
    cout<<sol.reverse(INT64_MIN) <<endl;

    cout<<sol.reverse(32768) <<endl;
    return 0;
}
