// Last updated: 10/5/2025, 8:52:20 AM
#include <unordered_map>
#include <set>

class NumberContainers {
private:
    unordered_map<int, int> indexMap;       
    unordered_map<int, set<int>> numToIndices; 

public:
    NumberContainers() {}

    void change(int index, int number) {
       
        if (indexMap.find(index) != indexMap.end()) {
            int oldNumber = indexMap[index];
            numToIndices[oldNumber].erase(index);
            if (numToIndices[oldNumber].empty()) {
                numToIndices.erase(oldNumber); 
            }
        }

        
        indexMap[index] = number;
        numToIndices[number].insert(index);
    }

    int find(int number) {
        if (numToIndices.find(number) != numToIndices.end() && !numToIndices[number].empty()) {
            return *numToIndices[number].begin(); 
        }
        return -1;
    }
};

/**
 * Usage:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index, number);
 * int param_2 = obj->find(number);
 */
