//==============================================================================
// 355. Design Twitter
// C++
// Tag: Design(Hash Table, Heap)
// Company: Amazon
//==============================================================================
// Summary:
// https://leetcode.com/problems/design-twitter/description/

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {}
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        shared_ptr<tweet> newsFeed(new tweet(tweetId, time++));
        tables1[userId].push_back(newsFeed);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    std::vector<int> getNewsFeed(int userId) {
        priority_queue<shared_ptr<tweet>, vector<shared_ptr<tweet>>, helper> tables3;
        vector<shared_ptr<tweet>> mine = tables1[userId];
        vector<int> tmp;
        int step = 10;

        for (int i = 0; i < mine.size(); ++i) {
            tables3.push(mine[i]);
        }
                
        for (auto n:tables2[userId]) {
            vector<shared_ptr<tweet>> notMine = tables1[n];
            for (int i = 0 ; i < notMine.size(); ++i) {
                tables3.push(notMine[i]);
            }
        }
        
        while (!tables3.empty() && step-- > 0) {
            tmp.push_back(tables3.top()->id);
            tables3.pop();
        }
        
        return tmp;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            tables2[followerId].insert(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (tables2.find(followerId) != tables2.end() && followerId != followeeId) {
            tables2[followerId].erase(followeeId); 
        }
    }
    
private:
    struct tweet {
        int id;
        int postTime;
        tweet(int id, int postTime):id(id), postTime(postTime) {}
    };
    
    unordered_map<int, vector<shared_ptr<tweet>>> tables1;
    unordered_map<int, unordered_set<int>> tables2;
    int time = 0;

    struct helper {
        bool operator() (shared_ptr<tweet> &a, shared_ptr<tweet> &b) {
            return a->postTime < b->postTime;
        }
    };
};
 
/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
