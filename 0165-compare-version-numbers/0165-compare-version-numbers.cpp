class Solution {
public:
  int compareVersion(string version1, string version2) {
        int version1Length = version1.size();
        int version2Length = version2.size();
      
        int index1 = 0;
        int index2 = 0;
      
        // Process both version strings until we reach the end of both
        while (index1 < version1Length || index2 < version2Length) {
            // Parse the next revision number from version1
            int revision1 = 0;
            while (index1 < version1Length && version1[index1] != '.') {
                revision1 = revision1 * 10 + (version1[index1] - '0');
                index1++;
            }
          
            // Parse the next revision number from version2
            int revision2 = 0;
            while (index2 < version2Length && version2[index2] != '.') {
                revision2 = revision2 * 10 + (version2[index2] - '0');
                index2++;
            }
          
            // Compare the current revision numbers
            if (revision1 < revision2) {
                return -1;
            }
            if (revision1 > revision2) {
                return 1;
            }
          
            // Skip the dot separator if present
            if (index1 < version1Length) {
                index1++;  // Skip '.'
            }
            if (index2 < version2Length) {
                index2++;  // Skip '.'
            }
        }
      
        // All revisions are equal
        return 0;   
    }
};