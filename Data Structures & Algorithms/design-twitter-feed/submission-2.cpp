class Twitter {
public:
    unordered_map<int,vector<pair<int,int>>> tweets;
    unordered_map<int,unordered_set<int>> follows;
    int time = 0;
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        time++;
        tweets[userId].push_back({ time, tweetId });
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        priority_queue<pair<int,int>> pq;
        for(auto t : tweets[userId]) pq.push(t);
        for(auto f : follows[userId]){
            if (f == userId) continue;
            for(auto t : tweets[f]){
                pq.push(t);
            }
        }
        int count = 10;
        while(!pq.empty() && count--){
            feed.push_back(pq.top().second);
            pq.pop();
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(!follows[followerId].count(followeeId)) return ;
        follows[followerId].erase(followeeId);
    }
};
