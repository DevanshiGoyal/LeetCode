class Solution {
public:

    // Function to find largest rectangle in histogram
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;

        // Add extra 0 to flush stack at the end
        heights.push_back(0);

        for (int i = 0; i < heights.size(); i++) {

            // If current height is smaller → calculate area
            while (!st.empty() && heights[i] < heights[st.top()]) {

                int h = heights[st.top()];
                st.pop();

                int w;
                if (st.empty()) 
                    w = i;                  // full width
                else 
                    w = i - st.top() - 1;  // between boundaries

                maxArea = max(maxArea, h * w);
            }

            st.push(i);
        }

        return maxArea;
    }

    // Function to find maximal rectangle in matrix
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> height(cols, 0);  // histogram
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {

            // Build histogram for current row
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    height[j] += 1;
                else
                    height[j] = 0;
            }

            // Find max area for this row
            maxArea = max(maxArea, largestRectangleArea(height));
        }

        return maxArea;
    }
};