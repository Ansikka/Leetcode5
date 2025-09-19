class Spreadsheet {
public:
  unordered_map<string, int> cellValues;
public:
    
    Spreadsheet(int rows) {
     
    }
    void setCell(string cell, int value) {
        cellValues[cell] = value;
    }
    void resetCell(string cell) {
        cellValues.erase(cell);
    }
    int getValue(string formula) {
        int result = 0;
      
       
        stringstream formulaStream(formula.substr(1));
        string token;
      
        while (getline(formulaStream, token, '+')) {

            if (isdigit(token[0])) {
             
                result += stoi(token);
            } else {
              
                result += cellValues.count(token) ? cellValues[token] : 0;
            }
        }
      
        return result;


    }
};
