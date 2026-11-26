class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //queue for bfs: stores {current word, number of transformations so far}
        //bfs guarantees the first time we reach endWord it is via the shortest path
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        //Store wordList in a hash set for O(M) avg lookup and deletion
        //where is the length of each word
        unordered_set<string> st(wordList.begin(), wordList.end());

        //remove beginWord so we don't revisit it and form a cycle
        st.erase(beginWord);

        while(!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            //target reached; return the shortest transformation sequence length 
            if(word == endWord) return steps;

            //Try changing every character of the current word to 'a'-'z'
            for (int i = 0; i < word.size(); i++) {
                char original = word[i]; //save original character to restore later 
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    //if the transformed word exists in the remaining wordList
                    if (st.find(word) != st.end()) {
                        //mark as visited immediately by removing it from the set 
                        //to prevent redundant visits from other paths
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }

                //restore the original character before moving to the next index
                word[i] = original;
            }
        }
        //no valid transformation sequence exits
        return 0;
    }
};

// N = num of words in wordList 
// M = len of each word 
// TC: O(N * M^2)
// set initialization: inserting N words of length M into the unordered_set takes O(N * M) avg time 
// BFS traversal: bcoz each word is erased from the set upon discovery at most N + 1 words are pushed into and popped from the q
// Word generation and lookups: for each popped word we iterate over M postions and try 26 letters 
// each st.find(word) operation hashes and compares a string of length M taking O(M) avg time 
// This gives O(26 * M * M) = O(M^2) work per word 

// SC: O(N * M)
// unordered set holds up to N strings of length M requiring O(N * M) space 
// in worst case BFS queue can also store up to O(N) strings of length M 