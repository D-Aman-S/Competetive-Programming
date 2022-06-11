//link :https://leetcode.com/contest/biweekly-contest-80/problems/strong-password-checker-ii/
class Solution {
public:
    bool strongPasswordCheckerII(string s) {
        bool res=false,same=true;
        int lo=0,up=0,sp=0,dig=0;
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i])){
                if(isupper(s[i])){
                    up++;
                }
                else{
                    lo++;
                }
            }
            else if(isdigit(s[i])){
                dig++;
            }
            else{
                sp++;
            }
        }
         for(int i=0;i<s.size()-1;i++){
             if(s[i]==s[i+1]){
                 same=false;break;
             }
         }
        if((s.length()>=8) and lo and up and sp and dig and same){
            return true;
        }
        else {
            return false;
        }
    }
};
