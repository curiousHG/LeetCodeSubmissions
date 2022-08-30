/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int, Employee*> mp;
    int dfs(int id){
        int val = mp[id]->importance;
        for(auto& sub:mp[id]->subordinates){
            val+=dfs(sub);
        }
        return val;
    }
    int getImportance(vector<Employee*> ees, int id) {
        Employee* head;
        for(auto& e:ees){
            mp[e->id] = e;
        }
        return dfs(id);
    }
};