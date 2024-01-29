class MyQueue {
public:
stack<int> input;
stack<int> output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(!output.empty()){
            int ele = output.top();
            output.pop();
            return ele;
        }
        else{
            while(!input.empty()){
                int ele = input.top();
                input.pop();
                output.push(ele);
            }
            int ele = output.top();
            output.pop();
            return ele;
        }
    }
    
    int peek() {
        if(!output.empty()){
            return output.top();
        }
        else{
            while(!input.empty()){
                int ele = input.top();
                input.pop();
                output.push(ele);
            }
            return output.top();
        }
        
    }
    
    bool empty() {
        if(input.empty() and output.empty()) return true;
        else return false;
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */