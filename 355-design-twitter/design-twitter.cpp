class Twitter {
private:
    int timeStamp;

    // Tweet structure
    struct Tweet {
        int id;
        int time;
        Tweet* next;

        Tweet(int id, int time) {
            this->id = id;
            this->time = time;
            this->next = nullptr;
        }
    };

    // User structure
    struct User {
        int id;
        unordered_set<int> followed;
        Tweet* tweet_head;

        User(int id) {
            this->id = id;
            tweet_head = nullptr;
            follow(id); // follow self
        }

        void follow(int userId) {
            followed.insert(userId);
        }

        void unfollow(int userId) {
            followed.erase(userId);
        }

        void post(int tweetId, int timeStamp) {
            Tweet* t = new Tweet(tweetId, timeStamp);
            t->next = tweet_head;
            tweet_head = t;
        }
    };

    unordered_map<int, User*> userMap;

public:
    Twitter() {
        timeStamp = 0;
    }

    // Post tweet
    void postTweet(int userId, int tweetId) {
        if (userMap.find(userId) == userMap.end()) {
            userMap[userId] = new User(userId);
        }

        userMap[userId]->post(tweetId, timeStamp++);
    }

    // Get News Feed
    vector<int> getNewsFeed(int userId) {
        vector<int> result;

        if (userMap.find(userId) == userMap.end())
            return result;

        auto cmp = [](Tweet* a, Tweet* b) {
            return a->time < b->time; // max heap
        };

        priority_queue<Tweet*, vector<Tweet*>, decltype(cmp)> pq(cmp);

        // Get all followed users
        for (int followeeId : userMap[userId]->followed) {
            if (userMap[followeeId]->tweet_head != nullptr) {
                pq.push(userMap[followeeId]->tweet_head);
            }
        }

        int count = 0;

        while (!pq.empty() && count < 10) {
            Tweet* t = pq.top();
            pq.pop();

            result.push_back(t->id);
            count++;

            if (t->next != nullptr) {
                pq.push(t->next);
            }
        }

        return result;
    }

    // Follow
    void follow(int followerId, int followeeId) {
        if (userMap.find(followerId) == userMap.end()) {
            userMap[followerId] = new User(followerId);
        }

        if (userMap.find(followeeId) == userMap.end()) {
            userMap[followeeId] = new User(followeeId);
        }

        userMap[followerId]->follow(followeeId);
    }

    // Unfollow
    void unfollow(int followerId, int followeeId) {
        if (userMap.find(followerId) == userMap.end() || followerId == followeeId)
            return;

        userMap[followerId]->unfollow(followeeId);
    }
};
