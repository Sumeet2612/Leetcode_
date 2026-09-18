class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        int siz = tasks.size();

        unordered_map<char, int> freq;
        unordered_map<char, int> free;

        // Calculate frequency
        for (int i = 0; i < siz; i++) {
            freq[tasks[i]]++;
            free[tasks[i]] = 1;
        }

        // Max heap: {frequency, task}
        priority_queue<pair<int, char>> pq;

        for (auto i : freq) {
            pq.push({i.second, i.first});
        }

        int seat = 1;

        while (!pq.empty()) {

            vector<pair<int, char>> pulled;

            // Find a task which is currently available
            while (!pq.empty()) {

                pair<int, char> p = pq.top();
                pq.pop();

                int fre = p.first;
                char child = p.second;
                if (free[child] <= seat) {
                    if (fre > 1) {
                        free[child] = seat + n + 1;
                        pq.push({fre - 1, child});
                        break;
                    }
                    else {
                        free[child] = INT_MAX;
                        break;
                    }
                }
                else {
                    pulled.push_back(p);
                }
            }
            for (auto p : pulled) {
                pq.push(p);
            }
            seat++;
        }
        return seat - 1;
    }
};