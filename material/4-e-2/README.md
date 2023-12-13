# Exercises

## Theory Questions
1) Thrashing and Excessive Context Switching are both concepts that can lead to livelock. What is meant by livelock, and how do these two concepts lead to it?

2) Which of the following programming techniques and data structures are “good” for a demand-paged environment, and which are “bad” (performance-wise)? Explain your answers.
• Stack
• Hash table
• Sequential search of array
• Sequential search of linked list
• Binary search of array
• Vector operations (such as vector addition or computing dot products)

3) How might TLB interactions make context-switching between different processes be less efficient than context-switching between threads within the same process?

## Practical Questions

5) Use 'top' to investigate how many processes. You may also wish to use 'htop' which may have a more easily read UI, or a higher level application such as the Windows Task Manager. Investigate how many processes are running, even when you only have your process monitoring application is open, how many are open when you start your regular browser/music player/social media apps etc. 

6) Write a program that will claim all of your virtual memory. You may have to investigate how much virtual memory your device has. Your program should continuously access this memory.

7) Run several instances of your program at the same time. How many do you need to run before you start seeing performance drop? Can you conclude anything from this about your hardware?
