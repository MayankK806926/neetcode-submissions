class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> hshMap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hshMap[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto it = hshMap.find(key);
        if(it == hshMap.end()) return "";

        const auto& vec = it->second;
        auto cmp = [](int time,const pair<int,string>& p){
            return time < p.first;
        };

        auto iter = upper_bound(vec.begin(),vec.end(),timestamp,cmp);

        if(iter == vec.begin()) return "";

        return (iter-1)->second;
    }
};
