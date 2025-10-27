class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int prevDevices =0;
        int totalBeams =0;

        for(string &row : bank){
            int currDevices= count(row.begin(), row.end(), '1');

            if(currDevices > 0){
                totalBeams += prevDevices * currDevices;

                prevDevices = currDevices;
            }
        }
        return totalBeams;
    }
};