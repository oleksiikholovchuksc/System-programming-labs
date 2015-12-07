## Lab 2
### Two readers & two writers working together

Four programs should be created: two "*readers*" and two "*writers*". Writers write messages to shared memory and readers read and print it.

This task should be done using three algorithms for breaking concurrency ties:

- **Garland**: one of readers is explicitly told to start the process, and every programs passes an execution flow to a concrete reader or writer.
- **Spinlocks**: a program aquires shared resources before doing its job using atomic operations and other programs are constantly checking resources availability in loop.
- **Peterson's algorithm**: break ties using [Peterson's algorithm](https://en.wikipedia.org/wiki/Peterson%27s_algorithm). *Optional assignment. Got the idea, didn't implement due to the lack of time.*
