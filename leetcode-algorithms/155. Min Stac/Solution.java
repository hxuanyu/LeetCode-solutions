class MinStack {

    public MinStack() {

    }

    public void push(int x) {
        if (!minstack.isEmpty()) {
            minstack.add(Math.min(minstack.peek(), x));
            vstack.add(x);
        } else {
            vstack.add(x);
            minstack.add(x);
        }
    }

    public void pop() {
        if (!vstack.isEmpty()) {
            vstack.pop();
            minstack.pop();
        }
    }

    public int top() {
        if (vstack.isEmpty()) return -1;

        return vstack.peek();
    }

    public int getMin() {
        if (vstack.isEmpty()) return -1;

        return minstack.peek();
    }

    Stack<Integer> vstack = new Stack<>();
    Stack<Integer> minstack = new Stack<>();
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
