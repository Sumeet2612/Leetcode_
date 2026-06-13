class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int ns = nums.size() ;
        vector<int> a;
        vector<int> b;
        vector<int> res(ns);

        for(int i=0; i < ns; i++){
            if(nums[i] < 0){
                a.push_back(nums[i]*nums[i]);
            }
        }
        reverse(a.begin() , a.end());
        for (int j=0; j<ns; j++){
            if(nums[j] >= 0){
                b.push_back(nums[j]*nums[j]);
            }
        }

        int k = a.size();
        int l = b.size();
        int id = 0;

        int m=0; int n=0;

        while (k>m && l>n){
            if(a[m] < b[n]){
                res[id] = a[m];
                id++;
                m++;
            }
            else if(a[m] > b[n]){
                res[id] = b[n];
                id++;
                n++;
            }
            else{
                res[id] = a[m] ;
                id++ ; m++;
                res[id] = b[n];
                id++; n++;
            }

        }

        while(k>m){
            res[id] = a[m];
            id++;
            m++;
        }
        while(l>n){
            res[id] = b[n];
            id++;
            n++;
        }

        return res;


    }
};