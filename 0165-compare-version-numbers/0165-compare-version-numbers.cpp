class Solution {
public:
  int compareVersion(string version1, string version2) {
    int v1 = version1.size();
    int v2 = version2.size();
    int i = 0;
    int j = 0;
    while (i < v1 || j < v2) {
        long long num1 = 0;
        long long num2 = 0;
        while (i < v1 && version1[i] != '.') {
            num1 = num1 * 10 + (version1[i] - '0');
            i++;
        }
        if (i < v1 && version1[i] == '.') i++;
        while (j < v2 && version2[j] != '.') {
            num2 = num2 * 10 + (version2[j] - '0');
            j++;
        }
        if (j < v2 && version2[j] == '.') j++;
        if (num1 < num2) 
        return -1;
        else if (num1 > num2)
         return 1;
    }
    return 0; 
}
};
