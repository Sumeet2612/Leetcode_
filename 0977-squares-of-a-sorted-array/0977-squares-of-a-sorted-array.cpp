class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        vector<int> res;
        vector<int> pos ;
        vector<int> neg ;

        for (int i=0; i<n; i++){
            if (nums[i] < 0) {
                neg.push_back(nums[i]*nums[i]);
            }
            else {
                pos.push_back(nums[i] * nums[i]);
            }
        }
        sort(neg.begin(), neg.end());
        
        int l = neg.size(); int k = 0;
        int m = pos.size(); int p = 0;

        while (k<l && m>p){
            if (neg[k] > pos[p]){
                res.push_back(pos[p]);
                p++;
            }
            else if(neg[k] < pos[p]){
                res.push_back(neg[k]);
                k++;
            }
            else {
                res.push_back(pos[p]); p++;
                res.push_back(neg[k]); k++;
            }
        }
        while (k<l){
            res.push_back(neg[k]);
            k++;
        }
        while(p<m){
            res.push_back(pos[p]);
            p++;
        }

        return res;
    }
};