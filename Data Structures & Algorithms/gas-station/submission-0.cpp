class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n= gas.size();

        int totalGas = 0, totalCost = 0;
        for(int i=0; i<n; i++){
            totalGas += gas[i];
            totalCost += cost[i];
        }
        if(totalCost>totalGas) return -1;
        
        int fuel = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            fuel += (gas[i] - cost[i]);
            if(fuel<0){
                ans = i+1;
                fuel =0;
            }
        }
        return ans;
    }
};
