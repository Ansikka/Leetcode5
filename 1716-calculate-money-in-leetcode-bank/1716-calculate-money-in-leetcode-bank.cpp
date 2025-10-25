class Solution {
public:
    int totalMoney(int n) {
      
        // Calculate number of complete weeks and remaining days
        int completeWeeks = n / 7;
        int remainingDays = n % 7;
      
        // Calculate total money from complete weeks
        // Each week starts with 1 more dollar than the previous week
        // Week 1: 1+2+3+4+5+6+7 = 28
        // Week 2: 2+3+4+5+6+7+8 = 35 (28 + 7)
        // Week 3: 3+4+5+6+7+8+9 = 42 (28 + 14)
        // This forms an arithmetic sequence: 28, 35, 42, ...
        // Sum = (first term + last term) * number of terms / 2
        int firstWeekSum = 28;
        int lastWeekSum = 28 + 7 * (completeWeeks - 1);
        int totalFromCompleteWeeks = (firstWeekSum + lastWeekSum) * completeWeeks / 2;
      
        // Calculate total money from remaining days
        // Remaining days start from (completeWeeks + 1) on Monday
        // Forms an arithmetic sequence starting from (completeWeeks + 1)
        // Sum = (first term + last term) * number of terms / 2
        int firstDayAmount = completeWeeks + 1;
        int lastDayAmount = completeWeeks + remainingDays;
        int totalFromRemainingDays = (firstDayAmount + lastDayAmount) * remainingDays / 2;
      
        // Return the total sum
        return totalFromCompleteWeeks + totalFromRemainingDays;
    }
};