class Solution {
public:
    int maxNumberOfBalloons(string text) {

        unordered_map<char , int> have ; 

        for (int i=0; i<text.size(); i++){
            have[text[i]]++;
        }

        string bal = "balloon";

        unordered_map<char , int> need;

        for (int j=0; j<bal.size(); j++){
            need[bal[j]]++;
        }

        int res = INT_MAX;

        for (auto i : need){
            char c = i.first;
            int fneed = i.second;
            int fhave = have[c];

            int times = fhave / fneed ;

            res = min(res , times);
        }

        return res ;
        
        
    }
};