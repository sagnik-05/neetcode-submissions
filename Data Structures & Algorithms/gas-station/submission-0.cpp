class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(accumulate(cost.begin(), cost.end(), 0) > accumulate(gas.begin(), gas.end(), 0)) return -1;
        int start = 0, g = 0;
        for(int i = 0; i<gas.size(); i++){
            g += gas[i] - cost[i];
            if(g < 0){
                g = 0;
                start = i+1;
            }
        }
        return start;
    }
};
