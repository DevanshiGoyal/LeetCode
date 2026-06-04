class Solution {
public:
    int totalWaviness(int num1, int num2) {

        int total_waviness = 0;

        for (int numVal = num1; numVal <= num2; numVal++) {

            string num = to_string(numVal);

            if (num.size() < 3) {
                continue;
            }

            int peak = 0, valley = 0;

            for (int j = 1; j < num.size() - 1; j++) {

                int prev = num[j - 1] - '0';
                int curr = num[j] - '0';
                int next = num[j + 1] - '0';

                if (curr > prev && curr > next) {
                    peak++;
                }
                else if (curr < prev && curr < next) {
                    valley++;
                }
            }

            total_waviness += peak + valley;
        }

        return total_waviness;
    }
};

/*
Tc
n=num2 - num1 + 1
d=no of digits (at most 10 for int)
tc: O(n × d)

sc: O(d) for string
*/