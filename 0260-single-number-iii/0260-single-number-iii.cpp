class Solution {
public:
    std::vector<int> singleNumber(std::vector<int>& nums) {
        int xorAll = 0;
        
       
        for (int num : nums) {
            xorAll ^= num;
        }
        unsigned int diffBit = xorAll & -(unsigned int)xorAll;

        int x = 0, y = 0;
        for (int num : nums) {
            if (num & diffBit) {
                x ^= num;
            } else {
                y ^= num; 
            }
        }

        return {x, y};
    }
};
