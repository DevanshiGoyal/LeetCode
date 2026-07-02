
class MedianFinder {
public:
// better approach 
//we avoid repeated sorting
//addNum	O(n)
//findMedian	O(1)
    vector<int> arr;

    MedianFinder() {

    }

    void addNum(int num) {

        // Find correct position using binary search

        auto it = lower_bound(arr.begin(), arr.end(), num); //O(log n)

        // Insert at correct position

        arr.insert(it, num); //O(n)
    }

    double findMedian() {

        int n = arr.size();

        // Odd number of elements

        if (n % 2 == 1) {
            return arr[n / 2];
        }

        // Even number of elements

        return (arr[n / 2] + arr[n / 2 - 1]) / 2.0;
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */