class Solution {
public:
    bool dfs(int i, int j, int k, string word, vector<vector<char>>& board){
        if(k==word.length())return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]=='*' || board[i][j]!=word[k])return false;
        char c = board[i][j];
        board[i][j] = '*';
        bool f = dfs(i+1, j, k+1, word, board)|dfs(i-1, j, k+1, word, board)|dfs(i,j+1, k+1, word, board)|dfs(i,j-1,k+1, word, board);
        if(f)return true;
        board[i][j]=c;
        return false;
        
    }
    bool should_reverse(const string & word){
        auto first_not_equal_to_front = word.find_first_not_of(word.front(), 1);
        if (first_not_equal_to_front == std::string::npos) return false;
        auto last_not_equal_to_back = word.find_last_not_of(word.back(), word.size() - 2);
        return first_not_equal_to_front >= (word.size() - last_not_equal_to_back);
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(should_reverse(word))reverse(word.begin(),word.end());
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                if(dfs(i, j, 0, word,board))return true;
            }
        }
        return false;
        
    }
};