using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        // Allocate extra space to avoid boundary issues
        int maxDays = (n << 1) + 10;
      
        // deltaKnowers[i]: net change in number of people who know the secret on day i
        vector<ll> deltaKnowers(maxDays);
      
        // newSpreaders[i]: number of new people who start spreading the secret on day i
        vector<ll> newSpreaders(maxDays);
      
        // Initially, one person knows the secret on day 1
        newSpreaders[1] = 1;
      
        // Process each day from 1 to n
        for (int day = 1; day <= n; ++day) {
            // Skip if no new spreaders on this day
            if (!newSpreaders[day]) continue;
          
            // People who start spreading on this day also start knowing the secret
            deltaKnowers[day] = (deltaKnowers[day] + newSpreaders[day]) % MOD;
          
            // These people will forget the secret after 'forget' days
            deltaKnowers[day + forget] = (deltaKnowers[day + forget] - newSpreaders[day] + MOD) % MOD;
          
            // Calculate when these people can start spreading
            // They can spread from day + delay until day + forget - 1
            int startSpreadingDay = day + delay;
            while (startSpreadingDay < day + forget) {
                // Each person who starts spreading on 'day' will cause one new person
                // to start spreading on each day in their spreading window
                newSpreaders[startSpreadingDay] = (newSpreaders[startSpreadingDay] + newSpreaders[day]) % MOD;
                ++startSpreadingDay;
            }
        }
      
        // Calculate total number of people who know the secret on day n
        // This is the cumulative sum of all delta changes up to day n
        int totalPeopleKnowing = 0;
        for (int day = 1; day <= n; ++day) {
            totalPeopleKnowing = (totalPeopleKnowing + deltaKnowers[day]) % MOD;
        }
      
        return totalPeopleKnowing;
    }
};
