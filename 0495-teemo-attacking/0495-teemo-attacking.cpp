class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {

        int n = timeSeries.size();
        if (n==0){
            return 0 ;
        }
        int res = 0;

        int currentStart = timeSeries[0];
        int currentEnd = currentStart + duration - 1 ;

        for (int i=1; i<n; i++){
            int nextStart = timeSeries[i];
            int nextEnd = nextStart + duration - 1 ;

            if (currentEnd >= nextStart){
                currentEnd = max(currentEnd , nextEnd);
            }
            else {
                res = res + currentEnd - currentStart + 1;
                currentEnd = nextEnd ;
                currentStart = nextStart;
            }
        }
        res = res + currentEnd - currentStart + 1 ;

        return res ;
        
    }
};