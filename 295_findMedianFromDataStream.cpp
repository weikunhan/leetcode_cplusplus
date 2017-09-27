//==============================================================================
// 295. Find Median from Data Stream
// C++
// Tag: Design(Heap)
//==============================================================================
// Summary:
// https://leetcode.com/problems/find-median-from-data-stream/description/

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) {
        tables2.push(-num);
        tables1.push(-tables2.top()); 
        tables2.pop();
        
        if (tables1.size() > tables2.size()) {
            tables2.push(-tables1.top());
            tables1.pop();
        }
    }
    
    double findMedian() {
        if (tables1.size() < tables2.size()) {
            return -tables2.top();
        } else {
            return (tables1.top() - tables2.top()) / 2.0;
        }
    }

private:
    priority_queue<long> tables1;
    priority_queue<long> tables2;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
