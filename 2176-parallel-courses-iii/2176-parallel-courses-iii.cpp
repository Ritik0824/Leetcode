class Solution {
    using int2=pair<int, int>;// (course, time)
public:
    //Kahn's algorithm
    vector<vector<int>> adj;
    vector<int> indeg;

    void build_adj(vector<vector<int>>& relations) {
        #pragma unroll
        for (vector<int>& x : relations) {
            adj[x[0]].push_back(x[1]);//x[0]=prevCourse
            indeg[x[1]]++;
        }
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) 
    {
        adj.resize(n+1);//1-indexed
        indeg.assign(n+1, 0);//1-indexed
        
        build_adj(relations);
        queue<int2> q; 
        
        //Taking a course must wait for all precourses taken
        vector<int> maxTime(n+1, 0);//1-indexed

        //Push the course without prevCourse to the queue q
        #pragma unroll
        for(int i=1; i<=n; i++){
            if (indeg[i]==0){
                //time[i]= how many months for the (i+1)th course.
                //Since parallel courses, all start
                q.emplace(i, time[i-1]);
                maxTime[i]=time[i-1];
            //    cout<<"i:"<<i<<", time="<<time[i-1]<<endl;
            }
        }
        int ans=0;
        //Perform  topological sort using BFS (Kahn's algorithm) 
        while (!q.empty()) {
            auto [i, t]= q.front();
            q.pop();
            for (int j : adj[i]) {// course i is precourese for j
                maxTime[j]=max(t+time[j-1], maxTime[j]);
                if (--indeg[j]==0){
                    q.emplace(j, maxTime[j]);
                }
            }
        }
        ans=*max_element(maxTime.begin(), maxTime.end());
        return ans;
    }
};