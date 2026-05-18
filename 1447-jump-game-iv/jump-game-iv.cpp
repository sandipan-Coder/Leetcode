class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        vector<int> vis(n, false);
        int steps = 0;

        for(int i = 0; i < n; i++)
            mp[arr[i]].push_back(i);
        
        queue<int> q;
        q.push(0);
        vis[0] = true;

        while(!q.empty()) {

            int size = q.size();

            while(size--){

                int curr = q.front();
                q.pop();

                if(curr == n-1)
                    return steps;
                
                int left = curr - 1;
                int right = curr + 1;

                if(left >= 0 && !vis[left]) {
                    q.push(left);
                    vis[left] = true;
                }

                if(right < n && !vis[right]) {
                    q.push(right);
                    vis[right] = true;
                }

                for(int idx: mp[arr[curr]]) {

                    if(!vis[idx]) {
                        q.push(idx);
                        vis[idx] = true;
                    }
                }

                mp.erase(arr[curr]);
            }

            steps++;
        }

        return -1;
    }
};