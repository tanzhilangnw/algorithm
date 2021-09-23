//给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words，找出所有同时在二维网格和字典中出现的单词。

//单词必须按照字母顺序，通过 相邻的单元格 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。
//提示：
//
//m == board.length
//n == board[i].length
//1 <= m, n <= 12
//board[i][j] 是一个小写英文字母
//1 <= words.length <= 3 * 104
//1 <= words[i].length <= 10
//words[i] 由小写英文字母组成
//words 中的所有字符串互不相同

struct TrieNode {
    string word;
    unordered_map<char, TrieNode*> children;
    TrieNode() {
        this->word = "";
    }

};

void InsertTrie(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (auto c : word) {
        if (!node->children.count(c))
            node->children[c] = new TrieNode();
        node = node->children[c];
    }
    node->word = word;
}



class Solution {
public:
    int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

    bool dfs(vector<vector<char>>& board, int x, int y, TrieNode* root, set<string>& res) {
        char ch = board[x][y];

        if (!root->children.count(ch))
            return   false;
        root = root->children[ch];
        if (root->word.size() > 0)
        {
            res.insert(root->word);
        }

        board[x][y] = '#';
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx >= 0 && ny >= 0 && nx < board.size() && ny < board[0].size()) {
                if (board[nx][ny] != '#') {
                    dfs(board, nx, ny, root, res);
                }
            }
        }
        board[x][y] = ch;
        return true;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        set<string> res;
        vector<string> ans;

        for (auto& word : words) {
            InsertTrie(root, word);
        }

        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, i, j, root, res);
            }
        for (auto& word : res) {
            ans.emplace_back(word);
        }
        return ans;
    }
};