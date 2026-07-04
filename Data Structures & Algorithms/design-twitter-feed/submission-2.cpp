class Twitter {
    
public:
    int time;
    unordered_map<int, unordered_set<int>> followee;
    unordered_map<int, vector<pair<int,int>>> tweets;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        int count=0;
        for(int i=tweets[userId].size()-1;i>=0&&count<10;i--,count++){
            pq.push(tweets[userId][i]);
        }
        for(int id: followee[userId]){
            int count=0;
        for(int i=tweets[id].size()-1;i>=0&&count<10;i--,count++){
            pq.push(tweets[id][i]);
        }
        }
        vector<int> feed;
        while(feed.size()<10&&!pq.empty()) {
            feed.push_back(pq.top().second);
            pq.pop();
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        followee[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followee[followerId].erase(followeeId);
    }
};
