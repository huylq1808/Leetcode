#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // Tạo bảng đánh dấu với kích thước tương tự bảng board, ban đầu đều là false.
        vector<vector<bool>> mark(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                // Nếu ký tự tại vị trí (i, j) là ký tự đầu tiên của từ cần tìm
                if (board[i][j] == word[0]) {
                    // Bắt đầu tìm kiếm từ vị trí này
                    if (searching(board, mark, i, j, word, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool searching(vector<vector<char>>& board, vector<vector<bool>>& mark, int x, int y, string& word, int word_pos) {
        // Nếu đã tìm đủ từ
        if (word_pos == word.size()) {
            return true;
        }

        // Nếu vị trí này ra ngoài bảng hoặc đã được đánh dấu hoặc không khớp với ký tự hiện tại
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || mark[x][y] || board[x][y] != word[word_pos]) {
            return false;
        }

        // Đánh dấu vị trí hiện tại là đã sử dụng
        mark[x][y] = true;

        // Tìm kiếm các ô lân cận (trên, dưới, trái, phải)
        if (searching(board, mark, x + 1, y, word, word_pos + 1) ||
            searching(board, mark, x - 1, y, word, word_pos + 1) ||
            searching(board, mark, x, y + 1, word, word_pos + 1) ||
            searching(board, mark, x, y - 1, word, word_pos + 1)) {
            return true;
        }

        // Nếu không tìm thấy, bỏ đánh dấu vị trí này
        mark[x][y] = false;

        return false;
    }
};



int main(){
    

    return 0;
}