class Solution {
public:
    string reorganizeString(string s) {

        unordered_map<char , int> freq;
        for (char c : s){
            freq[c]++;
        }

        priority_queue<pair<int,char>> pq;

        for (auto it : freq){
            pq.push({it.second , it.first});
        }

        string result = "";
        pair<int , char> prev = {0 , '#'};

        while(!pq.empty()){

            auto current = pq.top();
            pq.pop();
            result += current.second;
            current.first--;

            if (prev.first > 0){
                pq.push(prev);
            }

            prev = current ;
        }

        if (result.length() == s.length()){
            return result ;
        }
        
        return "";
    }
};