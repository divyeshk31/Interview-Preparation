class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        deque<int> q;
        int n=a.size();
        vector<int> ans;
        if(n==1)
        return ans;
        for(int i=0;i<n;i++){
            while(!q.empty() && a[i]>=a[q.back()])
            q.pop_back();
            q.push_back(i);
        }
        for(int i=k;i<n;i++){
            ans.push_back(a[q.front()]);
            while(!q.empty() && a[i]>=a[q.back()])
            q.pop_back(); wQ    Z v
            if(!q.empty() && q.front()<=i-k)
            q.pop_front();
            q.push_back(i);
        }
       ans.push_back(a[q.front()]);
    
    return ans;
    }
};