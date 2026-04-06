class MedianFinder {
private:
    priority_queue<int> maxHeap; // left side (smaller half)
    priority_queue<int, vector<int>, greater<int>> minHeap; // right side (larger half)

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // add to maxHeap
        maxHeap.push(num);

        // move largest of left to right
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // balance sizes
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        return maxHeap.top();
    }
};
