class AuthenticationManager
{
public:
    AuthenticationManager(int timeToLive)
    {
        _timeToLive = timeToLive;
    }

    void generate(string tokenId, int currentTime)
    {
        hash[tokenId] = currentTime + _timeToLive;
    }

    void renew(string tokenId, int currentTime)
    {
        if (hash.count(tokenId) && hash[tokenId] > currentTime)
        {
            hash[tokenId] = currentTime + _timeToLive;
        }
    }

    int countUnexpiredTokens(int currentTime)
    {
        int cnt = 0;
        for (auto &[_, time] : hash)
        {
            if (time > currentTime)
                cnt++;
        }
        return cnt;
    }

private:
    int _timeToLive;
    unordered_map<string, int> hash;
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */