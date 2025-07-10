class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
         int n = startTime.size();  // Total number of meetings
        int maxFreeTime = 0;  // Variable to hold the maximum free time found

        // Calculate the maximum gaps from the left side
        vector<int> leftGaps(n, 0);
        leftGaps[0] = startTime[0];  // Free time before the first meeting starts
        for (int i = 1; i < n; ++i) {
            leftGaps[i] = max(leftGaps[i - 1], startTime[i] - endTime[i - 1]);
        }

        // Calculate the maximum gaps from the right side
        vector<int> rightGaps(n, 0);
        rightGaps[n - 1] = eventTime - endTime[n - 1];  // Free time after the last meeting ends
        for (int i = n - 2; i >= 0; --i) {
            rightGaps[i] = max(rightGaps[i + 1], startTime[i + 1] - endTime[i]);
        }

        // Compute the maximum free time by evaluating each meeting
        for (int i = 0; i < n; ++i) {
            // Calculate the gap before the current meeting
            int leftGap = (i == 0) ? leftGaps[i] : startTime[i] - endTime[i - 1];
            // Calculate the gap after the current meeting
            int rightGap = (i == n - 1) ? rightGaps[i] : startTime[i + 1] - endTime[i];

            // Calculate the total interval of free time
            int interval = 0;
            if ((i != 0 && leftGaps[i - 1] >= (endTime[i] - startTime[i]))
                || (i != n - 1 && rightGaps[i + 1] >= (endTime[i] - startTime[i]))) {
                interval = endTime[i] - startTime[i];
            }

            // Update the maximum free time found
            maxFreeTime = max(maxFreeTime, leftGap + interval + rightGap);
        }

        return maxFreeTime;
    }
};