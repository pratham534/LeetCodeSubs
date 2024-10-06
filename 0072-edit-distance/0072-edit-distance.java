import java.util.ArrayList;
import java.util.List;

class Solution {
    private List<List<Integer>> dp;

    public int function(String word1, String word2, int i, int j) {
        if (j < 0 && i < 0)
            return 0;
        if (j < 0 && i >= 0)
            return i + 1;
        if (i < 0 && j >= 0)
            return j + 1;
        if (dp.get(i).get(j) != -1)
            return dp.get(i).get(j);
        if (word1.charAt(i) == word2.charAt(j)) {
            int result = function(word1, word2, i - 1, j - 1);
            dp.get(i).set(j, result);
            return result;
        }
        int deleteOp = 1 + function(word1, word2, i - 1, j);
        int replaceOp = 1 + function(word1, word2, i - 1, j - 1);
        int insertOp = 1 + function(word1, word2, i, j - 1);
        int result = Math.min(deleteOp, Math.min(replaceOp, insertOp));
        dp.get(i).set(j, result);
        return result;
    }

    public int minDistance(String word1, String word2) {
        int n = word1.length();
        int m = word2.length();
        dp = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            List<Integer> row = new ArrayList<>();
            for (int j = 0; j < m; j++) {
                row.add(-1);
            }
            dp.add(row);
        }
        return function(word1, word2, n - 1, m - 1);
    }
}
