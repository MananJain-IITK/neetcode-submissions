class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int kth = 0;
    KthLargest(int k, vector<int>& nums) {
        for(int i: nums){
            minHeap.push(i);
            if(minHeap.size() > k) minHeap.pop();
        }
        kth = k;
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > kth) minHeap.pop();
        return minHeap.top();
    }
};
