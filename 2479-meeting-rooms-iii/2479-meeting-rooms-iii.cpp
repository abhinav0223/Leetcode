#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Sort meetings by start time
        sort(meetings.begin(), meetings.end());

        // Min-heap for available rooms (room numbers)
        priority_queue<int, vector<int>, greater<int>> available_rooms;
        for (int i = 0; i < n; ++i)
            available_rooms.push(i);

        // Min-heap for occupied rooms: (end_time, room_number)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> occupied;

        vector<int> room_count(n, 0);

        for (auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];
            long long duration = end - start;

            // Free up rooms whose meetings ended by start time
            while (!occupied.empty() && occupied.top().first <= start) {
                available_rooms.push(occupied.top().second);
                occupied.pop();
            }

            if (!available_rooms.empty()) {
                int room = available_rooms.top(); available_rooms.pop();
                occupied.push({start + duration, room});
                room_count[room]++;
            } else {
                auto [free_time, room] = occupied.top(); occupied.pop();
                occupied.push({free_time + duration, room});
                room_count[room]++;
            }
        }

        // Find the room with max count
        int max_meetings = 0, result = 0;
        for (int i = 0; i < n; ++i) {
            if (room_count[i] > max_meetings) {
                max_meetings = room_count[i];
                result = i;
            }
        }

        return result;
    }
};
