class Twitter {
   public:
    vector<vector<int>> followee;
    vector<pair<int, int>> tweets;
    Twitter() { followee.resize(101); }

    void postTweet(int userId, int tweetId) { tweets.push_back({userId, tweetId}); }

    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        int idx = tweets.size() - 1;
        vector<int> info = followee[userId];
        while (feed.size() < 10 && idx >= 0) {
            if (tweets[idx].first==userId){
                feed.push_back(tweets[idx].second);
            }else{
                for(int id: info){
                    if(tweets[idx].first==id){
                        feed.push_back(tweets[idx].second);
                    }
                }
            }
            idx--;
            }
            return feed;
    }

    void follow(int followerId, int followeeId) {
        followee[followerId].push_back(followeeId);
        // follower[followeeId].push_back(followerId);
    }

    void unfollow(int followerId, int followeeId) {
        for (int i = 0; i < followee[followerId].size(); i++) {
            if (followee[followerId][i] == followeeId) {
                swap(followee[followerId][i], followee[followerId][followee[followerId].size() - 1]);
                followee[followerId].pop_back();
                break;
            }
        }
    }
};
