class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size() - 1;
        int columns = matrix[0].size() - 1;

        // search for adequate row
        int low = 0;
        int high = rows;
        int foundRow = -1;

        while (low <= high) {
            int middle = low + (high - low) / 2;
            if (matrix[middle][0] <= target && matrix[middle][columns] >= target) {
                foundRow = middle;
                break;
            } else if (matrix[middle][0] < target) {
                low = middle + 1;
            } else if (matrix[middle][0] > target) {
                high = middle - 1;
            }
        }

        if (foundRow == -1) {
            return false;
        }
        // search for adequate column

        low = 0;
        high = columns;

        while (low <= high) {
            int middle = low + (high - low) / 2;
            if (matrix[foundRow][middle] == target) {
                return true;
            } else if (matrix[foundRow][middle] > target) {
                high = middle - 1;
            } else if (matrix[foundRow][middle] < target) {
                low = middle + 1;
            }
        }

        return false;
    }
};
