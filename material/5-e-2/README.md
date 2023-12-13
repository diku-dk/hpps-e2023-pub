# Introduction

Before getting on to these exercises, do make sure you have completed the first set of networking exercises.

Today's exercise class is a quick introduction to Locking and Race Conditions. These are concurrency issues that we will be exploring more after Christmas, but they are being introduced here as we have potentially introduced some problems that may need to be solved in A5. Races and Locks are common programming terms, which are both googlable, and explained in more detail within the course material.

# The problem

To illustrate the potential problem lets consider a very simple program of two process types, a client and a server. The server contains a variable, which the client shall request. The client will then increment that variable by 1, and tell the server the new variable. The client will then sleep for a time, and then loop. This has been crudely illustrated below:


    client                      server

                                var is 14
            --> get var -->
            <-- var is 14 <--
    var is 14
    var+=1
    var is 15
           --> var is 15 -->
                                var is 15
    wait
            --> get var -->
                  .....

To illustrate this system in practice, take a look at no_race.py, and try running:

    python3 no_race.py

You should get some relatively boring output of the form:

    1
    2
    3
    4
    5
    6
    7
    ...

This will continue on forever, but let it run for 30 seconds or so to convince yourself that its going to count up by one each time, then hit Ctrl C a few times to abort.

This system isn't terribly interesting on its own, but gets slightly more interesting when we add multiple clients. Each of these clients can act in parallel, meaning at literally the same time (more on this in the new year), but we only have 1 server. 

To run a version with multiple clients then we need to run:

    python3 no_race_socket.py

Note that this code is exactly the same as before, expect that we are now starting 12 clients at the same time, each querying the same server. You should get some more relatively boring output of the form:

    1
    2
    3
    4
    5
    6
    7
    ...

If you let that run for a while you'll see that it is still counting up one at a time. This is great as it means our result is still correct, but the problem now is that the single server can only serve one client at a time. Currently our server handling is very quick, so we won't really mind but this is terrible practice and we always want a server to be able to handle multiple requests at once.

We've seen in the previous exercise and the lecture, the way to do this in Python is to use the socketserver library. This has a separate handle function that is called on each request the server receives, and can be called in parallel. We can run this using:

    python3 race_socketserver.py

This should eventually produce some output like so:

    1
    2
    2
    2
    3
    4
    5
    5
    6
    ...

This is a classic race condition, our output is wrong as some operations (the servers reading of the value and the servers final updating of the value) have been interleaved to produce an incorrect result.

Note that depending on you machine you might need to prompt the system to break by adding in a sleep statement on line 21 of race_socketserver.py, so if you've run it for a while without problem then do that.

To fix this we need to prevent multiple handler functions from updating the servers handle_count variable at the same time. Within Python the easy way to do this is with a threading.Lock class, which has handily been added to line 43 of race_socketserver.py. A example lock is shown in locking_example.py, which starts two threads that just print when they start and stop. A lock has two key functions, acquire() and release(), and the special feature that only one thread can acquire a lock at any one time. If you run:

    python3 locking_example.py

you should that one thread claims the lock instantly and prints that it is starting. Once it has slept it prints that it is done and releases the lock, which the other thread immediately acquires and starts. You can comment out lines 6 and 10 to see the difference in behaviour.

# Task 1

Hopefully you're now convinced that we can use locks to enforce only one thread having access to a thread at a time. Your task is to introduce locking into the race_socketserver.py's handle function on line 28. 

# Task 2

Introducing locking is great if it enforces correctness on our programs. But it also enforces sequentialism, and the problem was caused by us wanting to do many things at once. Therefore we usually want to minimise the amount of parts we keep behind a lock. The locking_example.py code locks the entire contents of the thread behind a lock, meaning we have just introduced all the overhead of creating threads only to then run them one at a time. This isn't good practice which is why we'll return to this problem after Christmas. Usually you don't need to lock down the entire thread, just access to shared variables. In our case that's the handle_count variable. With this knowledge, can you reduce the amount of the handle function that you are locking? 


