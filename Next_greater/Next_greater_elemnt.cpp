vector<int> get_next(vector<int>&vec)
{
stack<int> s;
        s.push(0);
        vector<int> next(n);
        for (int i = 1; i < n; i++) {
 
            if (s.empty()) {
                s.push(i);
                continue;
            }
            while (s.empty() == false
                   && vec[s.top()] < vec[i]) {
                next[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) {
            next[s.top()] = -1;
            s.pop();
        }
}