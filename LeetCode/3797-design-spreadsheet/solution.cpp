class Spreadsheet {
public:
    vector<vector<int>> spreadsheet;
    Spreadsheet(int rows) {
        spreadsheet.resize(rows);
        for (auto &row : spreadsheet)
            row.resize(26);
    }
    void setCell(string cell, int value) {
        const int col = (cell[0] - 'A') , row = (stoi(cell.substr(1))) - 1;
        spreadsheet[row][col] = value;
    }
    void resetCell(string cell) {
        return setCell(std::move(cell) , 0);
    }
    int get_cell(const string& cell) {
        const int col = (cell[0] - 'A') , row = (stoi(cell.substr(1))) - 1;
        return spreadsheet[row][col];
    }
    int getValue(string formula) {
        int sum = 0;
        for (int i = 1 ; i < formula.size() ; i++) {
            bool isCell = false;
            string curr;
            while (formula[i] != '+' && i < formula.size()) {
                if (formula[i] >= 'A' && formula[i] <= 'Z') isCell = true;
                curr.push_back(formula[i]);
                i++;
            }
            if (isCell)
                sum+= get_cell(curr);
            else
                sum+=stoi(curr);
        }
        return sum;
    }
};

