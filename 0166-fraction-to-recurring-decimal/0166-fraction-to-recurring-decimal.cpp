
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string result;
        if ((numerator < 0) ^ (denominator < 0)) {
            result += "-";
        }
        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);
        long long integerPart = num / den;
        result += to_string(integerPart);
        long long remainder = num % den;
        if (remainder == 0) return result;
        result += ".";
        unordered_map<long long, int> remainderMap;

        while (remainder != 0) {
            if (remainderMap.find(remainder) != remainderMap.end()) {
                int pos = remainderMap[remainder];
                result.insert(pos, "(");
                result += ")";
                break;
            }
            remainderMap[remainder] = result.size();

            remainder *= 10;
            result += to_string(remainder / den);
            remainder %= den;
        }

        return result;
    }
};