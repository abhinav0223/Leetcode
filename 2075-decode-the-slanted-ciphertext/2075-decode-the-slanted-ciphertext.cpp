class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1) return encodedText;

        int n = encodedText.size();
        int cols = n / rows;
        vector<string> matrix(rows, string(cols, ' '));
        for (int i = 0; i < n; i++) {
            matrix[i / cols][i % cols] = encodedText[i];
        }
        string result;
        result.reserve(n);

        for (int startCol = 0; startCol < cols; startCol++) {
            for (int r = 0; r < rows; r++) {
                int c = startCol + r;
                if (c < cols) {
                    result += matrix[r][c];
                }
            }
        }
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};