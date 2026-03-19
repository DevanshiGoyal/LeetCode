class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        

        vector<int> prevSmaller(n), nextSmaller(n);

        

        for(int i = 0 ; i<n ; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop() ;
                
            }
            if(st.empty()){
                prevSmaller[i] = -1 ;

            }else prevSmaller[i] = st.top() ;

            st.push(i) ;
        }

        while (!st.empty()) st.pop();

        //NSR

        for (int i = n - 1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop() ;
                
            }
            if(st.empty()){
                nextSmaller[i] = n ;
            }else nextSmaller[i] = st.top() ;

            st.push(i) ;
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int height = heights[i];
            int width = nextSmaller[i] - prevSmaller[i] - 1;
            maxArea = max(maxArea, height * width);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> histogram(cols, 0);
        int answer = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    histogram[j]++;
                else
                    histogram[j] = 0;
            }
            answer = max(answer, largestRectangleArea(histogram));
        }

        return answer;
    }
};