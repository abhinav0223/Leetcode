
class Spreadsheet {
private:
    int rows;
    vector<vector<int>> grid; // rows x 26 grid

    // Convert "A1" -> (row, col)
    pair<int,int> parseCell(const string &cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1; // rows are 1-indexed
        return {row, col};
    }

    // Check if the string is a cell reference (starts with a letter)
    bool isCellRef(const string &s) {
        return isalpha(s[0]);
    }

    // Get value from either a cell or an integer
    int getOperandValue(const string &s) {
        if (isCellRef(s)) {
            auto [r, c] = parseCell(s);
            if (r >= 0 && r < rows && c >= 0 && c < 26) {
                return grid[r][c];
            }
            return 0; // invalid → treat as 0
        } else {
            return stoi(s);
        }
    }

public:
    Spreadsheet(int rows) {
        this->rows = rows;
        grid.assign(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        auto [r, c] = parseCell(cell);
        grid[r][c] = value;
    }
    
    void resetCell(string cell) {
        auto [r, c] = parseCell(cell);
        grid[r][c] = 0;
    }
    
    int getValue(string formula) {
        // Formula always in the form "=X+Y"
        string expr = formula.substr(1); // remove '='
        size_t plusPos = expr.find('+');
        string left = expr.substr(0, plusPos);
        string right = expr.substr(plusPos + 1);

        int val1 = getOperandValue(left);
        int val2 = getOperandValue(right);
        return val1 + val2;
    }
};
