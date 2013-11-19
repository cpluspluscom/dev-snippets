###__Description__  

This snippet shows how you can guarantee that a thread will complete before the caller function's
scope exits.

###__Usage Example__  

In the example below the function runMyThread() will create a new thread to run myFunction()
and then we want it to process some other information and then wait untill the thread running myFunction() is done.

After doSomethingElseWithThisThread() is done we will reach the end of runMyThread() which will cause it to start
destroying it's local objects in reverse order which will cause the ScopedThread object to call it's destructor which
in turn will call the std::thread::join() which will make it wait for the thread to finish.

```cpp
void myFunction()
{
    // Does something
}

void runMyThread()
{
    ScopedThread sThread(std::thread(myFunction));
    
    doSomethingElseWithThisThread();
} // Once we hit the end of the function it will start calling the destructors for all the local objects
```
