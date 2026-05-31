class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long curr_mass=mass;
        multiset<long long>rem(asteroids.begin(),asteroids.end());
        while(!rem.empty()){
            auto it=rem.upper_bound(curr_mass);
            if(it==rem.begin()){
                return false;
            }
            it--;
            curr_mass+=*it;
            rem.erase(it);
        }
        return true;
    }
};