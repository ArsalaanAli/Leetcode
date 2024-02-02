class User{
public:
    vector<vector<int>> tweets;
    set<User*> following;
    User(){
        following.insert(this);
    }
};
class Twitter {
public:
    int time = 0;
    unordered_map<int, User*> users;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        if(!users[userId]){
            users[userId] = new User();
        }
        users[userId]->tweets.push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        if(!users[userId]){
            return {};
        }
        vector<int> ret;
        vector<int> indexes;
        for(auto other : users[userId]->following){
            cout<<other<<" "<<other->tweets.size()<<endl;
            indexes.push_back(other->tweets.size()-1);
        }
        for(int i = 0; i<10; i++){
            for(int j : indexes){
                cout<<j<<endl;
            }
            int curTime = -1;
            int curTweet = -1;
            int ind = 0;
            int selInd = 0;
            for(auto other : users[userId]->following){
                if(indexes[ind]<0){
                    ind++;
                    continue;
                }
                vector<int> tweet = other->tweets[indexes[ind]];
                if(tweet[0] > curTime){
                    curTime = tweet[0];
                    curTweet = tweet[1];
                    selInd = ind;
                }
                ind++;
            }
            if(curTweet == -1){
                return ret;
            }
            indexes[selInd]--;
            for(int j : indexes){
                cout<<j<<endl;
            }
            ret.push_back(curTweet);
        }
        return ret;
    }
    
    void follow(int followerId, int followeeId) {
        if(!users[followerId]){
            users[followerId] = new User();
        }
        if(!users[followeeId]){
            users[followeeId] = new User();
        }
        users[followerId]->following.insert(users[followeeId]);
    }
    
    void unfollow(int followerId, int followeeId) {
        users[followerId]->following.erase(users[followeeId]);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */