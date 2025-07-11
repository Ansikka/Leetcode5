class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> rooms(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        for(int i =0; i < n; i++){
            pq.push({0, i});
        }
        for(auto& meeting : meetings){
            int start = meeting[0], end = meeting[1];
            while(!pq.empty() && pq.top().first < start){
                auto [time, room] =pq.top();
                pq.pop();
                pq.push({start, room});
            }
            auto [time, room] = pq.top();
            pq.pop();
            rooms[room]++;
            pq.push({time + end - start, room});
        }
        return max_element(rooms.begin(), rooms.end()) - rooms.begin();
    }
};