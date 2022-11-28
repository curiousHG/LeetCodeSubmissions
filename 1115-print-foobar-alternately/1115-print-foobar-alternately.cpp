class FooBar {
    mutex m;
    condition_variable cv;
    bool turn = true;
private:
    int n;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
        	// printFoo() outputs "foo". Do not change or remove this line.
            unique_lock<mutex> lock(m);
            while(!turn)cv.wait(lock);
            printFoo();
            turn = false;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);
            while(turn)cv.wait(lock);
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            turn = true;
            cv.notify_all();
        }
    }
};