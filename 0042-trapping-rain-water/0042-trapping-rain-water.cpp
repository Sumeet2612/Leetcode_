class Solution {
public:
    int trap(vector<int>& height) {
        // for (int i=0; i<n; i++){
        //     int left_max = 0;
        //     for (int j = 0; j <= i; j++) {
        //         left_max = max(left_max, height[j]);
        //     }
        //     int right_max = 0;
        //     for (int k=i; k<=n-1; k++){
        //         right_max = max(right_max , height[k]);
        //     }
        //     water = min(right_max , left_max) - height[i] + water ;
        // }  Brute Force T.C : O(2n^2)


        int n = height.size() ;
        int water = 0;
        
        if(n==0) return 0;
        
        vector<int> right_max(n) ;
        vector<int> left_max(n);


        left_max[0] = height[0];
        for (int i=1; i<n; i++){
            left_max[i] =  max(left_max[i-1] , height[i]);
        }
        right_max[n-1] = height[n-1];
        for(int j = n-2; j>=0; j--){
            right_max[j] = max(right_max[j+1] , height[j]);
        }
        for (int k=0; k<n; k++){
            water = water + min(left_max[k] , right_max[k]) - height[k];
        }

        return water ;
    }
};