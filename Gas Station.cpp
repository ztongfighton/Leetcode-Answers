class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.empty() || cost.empty()) return -1;
        const int n = gas.size();
        const int m = cost.size();
        if (m != n) return -1;
        
        int sum = 0, tank = 0;
        int idx = 0;
        for (int i = 0; i < n; ++i){
            sum += gas[i] - cost[i];
            tank += gas[i] - cost[i];
            if (tank < 0) {
                idx = i + 1;
                tank = 0;
            }
        }
        
        if (sum >= 0) return idx;
        else return -1;
    }
};
