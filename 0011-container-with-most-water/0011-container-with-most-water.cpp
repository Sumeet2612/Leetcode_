class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int water = 0; 
        int maxwater = INT_MIN ;

        // for (int i=0; i<n; i++){
        //     for (int j=i+1; j<n; j++)

        //     if(height[i] >= height[j]){
        //         water =  (height[j] * (j-i));
        //         maxwater = max(water , maxwater);
        //     }
        //     else {
        //         water = (height[i] * (j-i));
        //         maxwater = max(water , maxwater);
        //     }
        // }
        // return maxwater ;  Brute force TC: O(n^2) will not work for data size 10^5 

        int left = 0; int right = n-1;

        while(left < right){
            if (height[left] > height[right]){
                water = (height[right] * (right-left));
                maxwater = max(water , maxwater);
                right --;
            }
            else if (height[left] < height[right]){
                water = (height[left] * (right-left));
                maxwater = max(water , maxwater);
                left++;
            }
            else {
                water = (height[left] * (right-left));
                maxwater = max(water , maxwater);
                left++;
            }
        }
        return maxwater ;
    }
};