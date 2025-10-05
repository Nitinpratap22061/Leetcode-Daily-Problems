// Last updated: 10/5/2025, 8:54:16 AM
class Solution {
public:
    map<int, set<int>> mp;
    set<pair<int, int>> noCommonLangPairs;

    // The solve function now calculates for a given language
    int solve(int lang) {
        int teachings = 0;
        set<int> involvedUsers;

        for (auto& p : noCommonLangPairs) {
            involvedUsers.insert(p.first);
            involvedUsers.insert(p.second);
        }

        for (int u : involvedUsers) {
            if (mp[u].count(lang) == 0) {
                teachings++;
            }
        }

        return teachings;
    }

    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {

        int user = languages.size();
        
        // Step 1: Build the user -> known languages map
        for (int i = 0; i < user; i++) {
            for (int lang : languages[i]) {
                mp[i + 1].insert(lang);
            }
        }

        // Step 2: Collect all problematic friend pairs
        for (int i = 0; i < friendships.size(); i++) {
            int a = friendships[i][0];
            int b = friendships[i][1];

            bool hasCommon = false;
            for (int l : mp[a]) {
                if (mp[b].count(l)) {
                    hasCommon = true;
                    break;
                }
            }

            if (!hasCommon) {
                noCommonLangPairs.insert({a, b});
            }
        }

        // Step 3: Try every language and get the minimum teaching count
        int minTeachings = INT_MAX;
        for (int lang = 1; lang <= n; lang++) {
            minTeachings = min(minTeachings, solve(lang));
        }

        return minTeachings;
    }
};
