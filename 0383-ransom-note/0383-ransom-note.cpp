class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map<char , int> have ;
        unordered_map<char , int> reqd ;

        for (int i=0; i<magazine.size(); i++){
            have[magazine[i]]++;
        }
        for (int j=0; j<ransomNote.size(); j++){
            reqd[ransomNote[j]]++;
        }

        return func(have , reqd);
    }


    bool func (unordered_map<char , int> have , unordered_map<char , int> reqd){

        for (auto i : reqd){
            char c = i.first ;
            int fneed = i.second ;
            int fhave = have[c];
            if (fhave < fneed) return false ;
        }

        return true ;

    }
};