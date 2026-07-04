class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> collider; 
        for (int asteroid : asteroids) {
            if (collider.empty())
                collider.push(asteroid);
            else {
                if ((asteroid > 0 && collider.top() < 0) || (asteroid < 0 && collider.top() > 0)) {
                    int temp = collider.top();
                    collider.pop();
                    if(abs(temp)!= abs(asteroid)) collider.push(max(asteroid, temp));
                }
                else{
                    collider.push(asteroid);
                }
            }
        }
        int n = collider.size();
        vector<int> ans(n);
        while(!collider.empty()) {
            ans[--n] = collider.top() ;
            collider.pop();
        }
        return ans;
    }
};