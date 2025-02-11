class Solution {
public:
    std::vector<int> singleNumber(std::vector<int>& nums) {
        int xorAll = 0;
        
        // Step 1: XOR all numbers to get xorAll = x ^ y
        for (int num : nums) {
            xorAll ^= num;
        }

        // Step 2: Find the rightmost set bit safely using unsigned int
        unsigned int diffBit = xorAll & -(unsigned int)xorAll;

        int x = 0, y = 0;

        // Step 3: Separate numbers into two groups based on diffBit
        for (int num : nums) {
            if (num & diffBit) {
                x ^= num;  // XOR group with set bit
            } else {
                y ^= num;  // XOR group without set bit
            }
        }

        return {x, y};
    }
};
