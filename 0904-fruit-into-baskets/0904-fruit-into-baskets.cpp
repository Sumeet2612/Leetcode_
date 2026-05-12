class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low = 0;
        int n = fruits.size();
        int res = -1 ;
        unordered_map <int , int> count;

        for (int high = 0; high<n; high++){
            count[fruits[high]]++;
            while (count.size() > 2){
                count[fruits[low]]--;
                if(count[fruits[low]]==0){
                    count.erase(fruits[low]);
                }
                low++;
            }
            int len = high-low+1;
            res = max(len , res);   
        }
        return res; 
    }
};