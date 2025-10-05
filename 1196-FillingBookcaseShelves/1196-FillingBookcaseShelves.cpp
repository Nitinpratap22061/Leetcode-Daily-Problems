// Last updated: 10/5/2025, 8:56:22 AM
class Solution {
public:
    int WIDTH;
    int n;
    int t[1001][1001];

    int solve(vector<vector<int>>& books, int i, int remaining_width, int max_height) {
        if (i >= n) {
            return max_height;
        }

        if (t[i][remaining_width] != -1) {
            return t[i][remaining_width];
        }

        int bookW = books[i][0];
        int bookH = books[i][1];
        int keep = INT_MAX;
        int skip;

        // keep the book on the same shelf if it fits
        if (bookW <= remaining_width) {
            keep = solve(books, i + 1, remaining_width - bookW, max(max_height, bookH));
        }

        // skip the book to a new shelf
        skip = max_height + solve(books, i + 1, WIDTH - bookW, bookH);

        return t[i][remaining_width] = min(keep, skip);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n = books.size();
        WIDTH = shelfWidth;
        memset(t, -1, sizeof(t)); // Initialize the memoization table with -1
        int remaining_width = shelfWidth;
        int max_height = 0;
        return solve(books, 0, remaining_width, max_height);
    }
};
