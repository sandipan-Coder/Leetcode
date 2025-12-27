#define ll long long
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        map<int, int>booked;

        // Custom Comparator
        auto cmp = [](const pair<ll, int> &a, const pair<ll, int> &b){

            if(a.first == b.first)
                return a.second > b.second;
            else
                return a.first > b.first;
        };
        // decltype(cmp) this is used at the greater of pq part.
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>>pq;
        priority_queue<int, vector<int>, greater<>>freeroom;

        // push all Free-Rooms
        for(int i = 0; i < n; i++){
            freeroom.push(i);
        }

        sort(meetings.begin(), meetings.end());
        for(auto met: meetings){

            ll start = met[0];
            ll end = met[1];

            while(!pq.empty() && pq.top().first <= start){

                freeroom.push(pq.top().second);
                pq.pop();
            }

            if(!freeroom.empty()){

                booked[freeroom.top()]++;
                pq.push({end, freeroom.top()});
                freeroom.pop();
            }
            else{

                booked[pq.top().second]++;
                auto it = pq.top();
                pq.pop();
                pq.push({it.first + end - start, it.second});

            }
        }

        int maxMeeting = 0, roomNo = -1;
        for(auto ele: booked){

            if(ele.second > maxMeeting){
                maxMeeting = ele.second;
                roomNo = ele.first;
            }
        }

        return roomNo;
    }
};