class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int noDelete = arr[0];
        int oneDelete = INT_MIN;
        int result = arr[0];

        for (int i = 1; i < n; i++) {
            int prevNoDelete = noDelete;
            int prevOneDelete = oneDelete;


            noDelete = max(noDelete + arr[i], arr[i]);

            
            if (prevOneDelete == INT_MIN)
                oneDelete = prevNoDelete;          
            else
                oneDelete = max(prevNoDelete, prevOneDelete + arr[i]);

            result = max(result, max(noDelete, oneDelete));
        }
        return result;
    }
};