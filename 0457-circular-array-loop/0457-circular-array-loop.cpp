class Solution {
public:
    int n;

    int getNextIndex(int i, vector<int>& nums) {
        return ((i + nums[i]) % n + n) % n;
    }


    bool circularArrayLoop(vector<int>& nums) {
        n = nums.size();
 
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;
 
            int slow = i, fast = i;
            bool isForward = nums[i] > 0; 
 
            while (true) {
                slow = getNextIndex(slow, nums);
 
                if ((nums[fast] > 0) != isForward) break; 
                fast = getNextIndex(fast, nums);
 
        
                if ((nums[fast] > 0) != isForward) break;
                fast = getNextIndex(fast, nums);
 
                if (slow == fast) {
        
                    if (slow == getNextIndex(slow, nums)) break;
                    return true;
                }
            }
 

            int j = i;
            while ((nums[j] > 0) == isForward) {
                int next = getNextIndex(j, nums);
                nums[j] = 0;
                j = next;
                if (j >= n || nums[j] == 0) break; 
            }
        }
        return false;
    }
};