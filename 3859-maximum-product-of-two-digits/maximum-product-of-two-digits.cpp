class Solution {
public:
    int maxProduct(int n) {
        // optimal 
        // we need to max digits for max prod 
        int largest = 0, secondLargest = 0;

        while (n > 0) {
            int digit = n % 10;
            if (digit >= largest) {
                secondLargest = largest;
                largest = digit;
            } else if (digit > secondLargest) {
                secondLargest = digit;
            }
            n /= 10;
        }

        return largest * secondLargest;
    }
};