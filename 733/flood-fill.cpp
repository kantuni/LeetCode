class Solution {
  private:
    void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int newColor) {
      int n = image.size(), m = image[0].size();
      if (r < 0 or r >= n or c < 0 or c >= m) {
        return;
      }
      if (image[r][c] != oldColor) {
        return;
      }
      image[r][c] = newColor;
      dfs(image, r + 1, c, oldColor, newColor);
      dfs(image, r - 1, c, oldColor, newColor);
      dfs(image, r, c + 1, oldColor, newColor);
      dfs(image, r, c - 1, oldColor, newColor);
    }
  
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
      if (image[sr][sc] != newColor) {
        dfs(image, sr, sc, image[sr][sc], newColor);
      }
      return image;
    }
};
