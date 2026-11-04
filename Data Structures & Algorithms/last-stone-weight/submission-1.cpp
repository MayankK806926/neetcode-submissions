class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        if(n == 1) return stones.back();
        if(n == 2) return abs(stones[0]-stones[1]);
        priority_queue<int> pq;

        for(int i=0;i<n;++i){
            pq.push(stones[i]);
        }

        while(!pq.empty()){
            if(pq.size() == 1) break;
            int x = pq.top();pq.pop();
            int y = pq.top();pq.pop();
            if(x == y) continue;
            else pq.push(abs(x-y));
        }

        return (pq.empty() ? 0 : pq.top());
    }
};
