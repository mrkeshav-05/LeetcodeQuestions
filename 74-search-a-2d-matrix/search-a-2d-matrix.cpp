class Solution {
public:
    bool search(vector<int> mat, int target){
        int low = 0;
        int high = mat.size()-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(mat[mid] == target){
                return true;
            }else if(mat[mid] > target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0; i<m; i++){
            if(matrix[i][n-1] >= target && target >= matrix[i][0]){
                return search(matrix[i], target);
            }
        }
        return false;
    }
};