A conditional variable is a mechanism that synchronizes with a shared global variable between threads, which consists of two actions: one thread waits for "conditional variables set up" and hangs; the other thread makes "conditions set up" (giving conditions to set up a signal).
Conditional detection is carried out under the protection of mutex. If a condition is false, a thread automatically blocks and releases a mutex that waits for state changes. If another thread changes the condition, it signals the associated conditional variable, wakes one or more threads waiting for it, reobtains the mutex, and reevaluate the condition.
If two processes share readable and written memory, conditional variables can be used to achieve thread synchronization between the two processes. 
condition variables must unlock mutex before signal
条件变量的注意事项：
1.一定要和mutex配合使用，临界区的条件要加锁然后再进行修改，否则有可能造成条件变量的无限等待。
2.检测要操作的内容一定要加锁，假设忘了加锁，也一定要用while来检测而不是if，while可以多一次的检测。
3.扔信号的时候，最好要在临界区里面扔，不要在临界区外面扔，因为在释放锁以后再signal有可能造成我们要的数据被其他被唤醒的线程不当操作
