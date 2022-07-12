class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        for(int i = 0;i<9;i++){
            unordered_set<int> s1,s2;
            for(int j = 0;j<9;j++){
                if(b[i][j]=='.')continue;
                if(s1.find(b[i][j])!=s1.end())return false;
                s1.insert(b[i][j]);
            }
            for(int j = 0;j<9;j++){
                if(b[j][i]=='.')continue;
                if(s2.find(b[j][i])!=s2.end())return false;
                s2.insert(b[j][i]);
            }
        }
        for(int i= 0;i<3;i++){
            for(int j = 0;j<3;j++){
                unordered_set<int> s;
                for(int ki =0;ki<3;ki++){
                    for(int kj =0;kj<3;kj++){
                        if(b[i*3+ki][j*3+kj]=='.')continue;
                        if(s.find(b[i*3+ki][j*3+kj])!=s.end())return false;
                        s.insert(b[i*3+ki][j*3+kj]);
                    }
                }
            }
        }
        return true;
    }
};