## Lab 2
### Two readers & two writers working together

Four programs should be created: two "*readers*" and two "*writers*". Each writer should write a message to shared memory exactly once, and each reader should print only one of two messages, so that messages from all writers are printed.

This task should be done using three algorithms for breaking concurrency ties:

- **Garland**: one of readers is explicitly told to start the process, and every programs passes an execution flow to a concrete reader or writer.
- **Spinlocks**: a program aquires shared resources before doing its job using atomic operations and other programs are constantly checking resources availability in loop.
- **Peterson's algorithm**: break ties using [Peterson's algorithm](https://en.wikipedia.org/wiki/Peterson%27s_algorithm).
