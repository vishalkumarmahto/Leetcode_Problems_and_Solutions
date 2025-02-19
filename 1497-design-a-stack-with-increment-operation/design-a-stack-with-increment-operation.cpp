class CustomStack {
public:
    int MaxSize;
    deque<int> dq;
    CustomStack(int maxSize) { MaxSize = maxSize; }

    void push(int x) {
        if (dq.size() < MaxSize)
            dq.push_back(x);
    }

    int pop() {
        int val = -1;
        if (dq.size()) {
            val = dq.back();
            dq.pop_back();
        }
        return val;
    }

    void increment(int k, int val) {

        int n = min(k, int(dq.size()));
        for (int i = 0; i < n; i++)
            dq[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */