class MedianFinder {
public:
    vector<int> nums;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(nums.empty()){
            nums.push_back(num);
            return;
        }
        int l=0, r=nums.size() -1;
        int mid = 0;
        while(l<=r){
            mid = l + (r-l)/2;
            if(num>nums[mid]) l = mid+1;
            else r = mid -1;
        }
        nums.insert(nums.begin()+l, num);
    }
    
    double findMedian() {
        int n= nums.size();
        double ans = 0;
        if(n%2 != 0){
            ans = nums[n/2];
        }else{
            ans = (nums[n/2] + nums[(n/2) - 1])/2.0;
        }
        return ans;
    }
};
