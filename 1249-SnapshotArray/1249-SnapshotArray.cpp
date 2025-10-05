// Last updated: 10/5/2025, 8:56:12 AM
class SnapshotArray {
    int snap_id;
    vector<map<int, int>> history;

public:
    SnapshotArray(int length) {
        snap_id = 0;
        history.resize(length);
        for (int i = 0; i < length; ++i) {
            history[i][0] = 0;
        }
    }

    void set(int index, int val) {
        history[index][snap_id] = val;
    }

    int snap() {
        return snap_id++; 
    }

    int get(int index, int snap_id) {
        auto it = history[index].upper_bound(snap_id);
        if (it == history[index].begin()) return 0;
        --it;
        return it->second;
    }
};
