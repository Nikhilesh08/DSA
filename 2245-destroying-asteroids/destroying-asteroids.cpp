class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long curr_mass=mass;
        for(int num : asteroids){
            if(num>curr_mass){
                return false;
            }
            else{
                curr_mass+=num;
            }
        }
        return true;
    }
};