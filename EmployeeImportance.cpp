//leetcode 690

/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    unordered_map<int,int> id_to_index;
    int getImportance(vector<Employee*> employees, int id) {
        for(int i=0;i<employees.size();++i) {
            id_to_index[employees[i]->id] = i;
        }
        Employee* root=employees[id_to_index[id]];
        return getImportance(root, employees);
    }
    
    int getImportance(Employee* root, vector<Employee*> & employees) {
        int res = root->importance;
        for(int i=0;i<root->subordinates.size();++i) {
            int id = root->subordinates[i];
            Employee* child = employees[id_to_index[id]];
            res += getImportance(child, employees);
        }
        return res;
    }
};
