# Giải Thuật `Strange Printer` (Hard Problem) Sử Dụng Dynamic Programming

## Mô tả bài toán

Cho một chuỗi `s`, bạn cần tìm số lần in tối thiểu mà một máy in có thể in chuỗi `s`. Máy in có thể in một dải ký tự giống nhau liên tục trong một lần, và sau mỗi lần in, máy in có thể chuyển sang in một dải ký tự khác.

## Ý tưởng sử dụng Dynamic Programming (DP)

### 1. Khởi tạo bảng DP

- Tạo một bảng `dp[i][j]` với `dp[i][j]` đại diện cho số lần in tối thiểu để in chuỗi con từ vị trí `i` đến `j`.
- Kích thước bảng DP là `n x n`, với `n` là độ dài của chuỗi `s`.

### 2. Cài đặt bảng DP

- **Trường hợp cơ bản**:
  - Nếu `i == j` (chuỗi con chỉ có một ký tự), thì `dp[i][j] = 1` (chỉ cần một lần in).

- **Trường hợp tổng quát**:
  - Đối với mỗi đoạn chuỗi từ `i` đến `j`, xét tất cả các điểm cắt `k` (với `i <= k < j`).
  - Nếu ký tự ở vị trí `k` và `j` trùng nhau (`s[k] == s[j]`), có thể kết hợp chúng lại để giảm số lần in cần thiết.

### 3. Cập nhật bảng DP

- Bắt đầu tính các giá trị của bảng DP từ các đoạn chuỗi ngắn (độ dài 1) đến các đoạn chuỗi dài hơn.
- Cập nhật giá trị `dp[i][j]` cho mọi `i` và `j`.

### 4. Kết quả cuối cùng

- Kết quả của bài toán là giá trị `dp[0][n-1]`, đại diện cho số lần in tối thiểu cần thiết cho toàn bộ chuỗi `s`.

## Mã giả (Pseudo code)

```cpp
int strangePrinter(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; --i) {
        dp[i][i] = 1;  // Một ký tự cần một lần in
        for (int j = i + 1; j < n; ++j) {
            dp[i][j] = dp[i + 1][j] + 1;  // In ký tự s[i] riêng biệt trước
            for (int k = i + 1; k <= j; ++k) {
                if (s[k] == s[i]) {
                    dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
                }
            }
        }
    }

    return dp[0][n - 1];
}
```

Đoạn mã Markdown trên trình bày chi tiết về cách tiếp cận Dynamic Programming cho bài toán `Strange Printer`. Bạn có thể sao chép đoạn mã này vào tài liệu của mình để sử dụng hoặc tham khảo khi cần. 

### Reference From ChatGPT
