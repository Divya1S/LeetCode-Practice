class Solution {
    //maps each visited word to its shortest step count (level) from beginWord
    unordered_map<string, int> mpp;
    //stores all valid shortest transformation sequences
    vector<vector<string>> ans;
    //stores beginWord for quick access during DFS backtracking
    string b;

    //backtracks from endWord to beginWOrd using the shortest-path lvels in mpp
    void dfs(string word, vector<string>& seq) {
        //base case reached beginWord, so we have a complete shortest path
        if (word == b) {
            //reverse to get the path from beginWord -> endWord
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            //reverse to restore seq's state for further backtracking
            reverse(seq.begin(), seq.end());
            return;
        }

        int steps = mpp[word];
        int sz = word.size();

        //try changing each character of the current word to 'a'....'z'
        for (int i = 0; i < sz; i++) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                //Only move to a word that exists in mpp and is strictly one level closer to beginWord
                if (mpp.find(word) != mpp.end() && mpp[word] + 1 == steps) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back(); //backtrack
                }
            }
            word[i] = original; //restore the original character
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        //store wordList in a hash set for O(L) avg time lookup and deletion
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        b = beginWord;

        //initialize BFS from beginWord at level 1
        q.push(beginWord);
        mpp[beginWord] = 1;
        st.erase(beginWord); //Mark beginWord as visted

        int sz = beginWord.size();

        //bfs to compute the shortest distance from beginWOrd to every reachable word
        while (!q.empty()) {
            string word = q.front();
            int steps = mpp[word];
            q.pop();

            //stop early once endWord is popped, all shortest paths to it are already mapped
            if (word == endWord) break; 

            //generate all 1-character transformations of the current word
            for (int i = 0; i < sz; i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.count(word)) {
                        q.push(word);
                        st.erase(word); //erase immediately to avoid revisiting at a deeper level
                        mpp[word] = steps + 1; //record its shortest distance from beginWord
                    }
                }
                word[i] = original; //restore the original character
            }
        }
        
        //if the endWord was reached reconstruct all shortest paths via DFS
        if (mpp.find(endWord) != mpp.end()) {
            vector<string> seq = {endWord};
            dfs(endWord, seq);
        }

        return ans;
    }
};

// TC: O(N * L^2 + P * K * L^2)

// SC: O(N * L)