// Last updated: 10/5/2025, 8:59:29 AM
class Twitter {
public:
    int time = 0;
    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int, int>>> tweets; // user -> {time, tweetId}

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq; // {time, tweetId}
        followMap[userId].insert(userId); // follow self

        for (int followee : followMap[userId]) {
            for (auto &tweet : tweets[followee]) {
                pq.push(tweet); // (time, tweetId)
            }
        }

        vector<int> ans;
        int k = 10;
        while (!pq.empty() && k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId)
            followMap[followerId].erase(followeeId);
    }
};
