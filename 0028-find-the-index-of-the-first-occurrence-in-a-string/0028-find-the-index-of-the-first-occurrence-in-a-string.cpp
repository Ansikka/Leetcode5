class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()){
            return 0;
        }
        size_t found_pos = haystack.find(needle);
        if(found_pos != std::string::npos){
            return static_cast<int>(found_pos);
        }
        else{
            return -1;
        }
    }
};