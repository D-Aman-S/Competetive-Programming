//link:https://leetcode.com/contest/biweekly-contest-80/problems/successful-pairs-of-spells-and-potions/

class Solution {
public:
    vector<int> successfulPairs(vector<int>& sp, vector<int>& po, long long su) {
        vector<int> v;
        sort(po.begin(),po.end());
        for(int i=0;i<sp.size();i++){
            long long div=ceil((double)su/sp[i]);
            auto pos=lower_bound(po.begin(),po.end(),div);
            int realpos=pos-po.begin();
            if(div<po[0]){
                v.push_back(po.size());}
            else if(div>po[po.size()-1]){
                v.push_back(0);
            }
            else{
                if(realpos==-1){
                    v.push_back(0);
                }
                else{
                    v.push_back((po.size()-realpos));
                }
            }


        }
        return v;
    }
};
