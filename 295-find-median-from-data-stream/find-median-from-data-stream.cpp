class MedianFinder {
private:
    priority_queue<int> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;
public:
    MedianFinder() {

    }
    void addNum(int num) {
        maxH.push(num);
        
        // 2. Move the largest from maxH to minH to keep them sorted relative to each other
        minH.push(maxH.top());
        maxH.pop();
        
        // 3. Balance: maxH can have at most one more element than minH
        if (maxH.size() < minH.size()) {
            maxH.push(minH.top());
            minH.pop();
        }
    }
    double findMedian() {
        int i = maxH.top();
        int j = minH.top();
        if(maxH.size() > minH.size()){
            return i;
        }
        return (i+j)/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */