# Queue Usecase

### **Basic Queue Problem (Level 1):**

#### Problem: Implement a Queue Using Arrays

**Description:**
Create a queue using an array. Implement the following operations:

- `enqueue(x)`: Insert an element `x` into the queue.
- `dequeue()`: Remove and return the front element from the queue.
- `front()`: Get the front element of the queue without removing it.
- `isEmpty()`: Check if the queue is empty.

**Solution Approach:**

- Maintain an array with front and rear pointers.
- The front points to the first element, and the rear points to the last.
- Implement a circular queue to optimize space.

### **Intermediate Queue Problem (Level 2):**

#### Problem: Reverse a Queue

**Description:**
Given a queue, reverse the order of its elements.

**Example:**
Input: 1 → 2 → 3 → 4  
Output: 4 → 3 → 2 → 1

**Solution Approach:**

- Use recursion or a stack to reverse the queue. Push elements onto the stack as you dequeue, then enqueue the elements
  back from the stack.

### **Advanced Queue Problem (Level 3):**

#### Problem: Implement a Queue Using Two Stacks

**Description:**
Implement a queue using two stacks (`stack1` and `stack2`).

- Use `stack1` for enqueue operations and `stack2` for dequeue operations.

**Solution Approach:**

- For enqueue (`enqueue(x)`), push elements onto `stack1`.
- For dequeue (`dequeue()`), if `stack2` is empty, move all elements from `stack1` to `stack2`, and pop the top of
  `stack2`.

### **Advanced Problem (Level 4):**

#### Problem: First Non-Repeating Character in a Stream

**Description:**
You are given a stream of characters. Find the first non-repeating character at each point in the stream.

**Example:**
Input: "aabbccde"  
Output: a, a, -, -, -, -, d, d

**Solution Approach:**

- Use a queue to store characters and a hash map to count occurrences.
- Traverse the stream, add characters to the queue, and keep track of their frequency. Remove characters from the front
  of the queue if they become repeating.

### **Real-World Queue Use Case in Operating Systems:**

#### **Queue in Job Scheduling:**

In operating systems, **job scheduling** uses queues extensively. Jobs (processes) waiting to be executed are maintained
in **scheduling queues**, and different types of queues can be used based on the scheduling algorithm.

1. **Ready Queue:**
    - Holds processes that are ready to be executed by the CPU.
    - Processes are dequeued when assigned to the CPU, and new processes are enqueued when they are ready.

2. **I/O Queue:**
    - Holds processes waiting for I/O operations to complete.
    - Once the I/O is finished, the process is moved back to the ready queue.

#### **Problem: Round Robin Scheduling**

**Description:**
Simulate **Round Robin Scheduling** using a queue. Processes arrive at different times and are executed in time slices.
Use a queue to hold the processes and implement a Round Robin Scheduler.

**Example:**
Process Arrival: [P1: 0ms, P2: 2ms, P3: 4ms]  
Time Slice: 4ms  
Execution Time: [P1: 8ms, P2: 5ms, P3: 3ms]  
Simulate how the scheduler will execute these processes.

**Solution Approach:**

- Use a queue to hold processes based on their arrival time.
- Dequeue the process, execute it for the time slice, and if it's not finished, re-enqueue it at the back of the queue.

### **Advanced Problem (Level 5):**

#### Problem: Implement Multi-level Feedback Queue (MLFQ)

**Description:**
Simulate the **Multi-level Feedback Queue (MLFQ)** scheduling algorithm, which uses multiple queues with different
priority levels. Processes are initially placed in the highest priority queue, and they move down if they do not
complete within the given time slice.

**Solution Approach:**

- Use multiple queues to represent different priority levels.
- A process starts in the top-level queue and is moved to a lower-level queue if it uses up its time slice without
  completing.
- Higher-priority queues are emptied before lower-priority queues.

---

### **Use Cases of Queue in Operating Systems:**

1. **Process Scheduling:**
    - **Round Robin Scheduling**: Each process is assigned a time slice, and the CPU cycles through the processes in a
      queue-like manner.
    - **First-Come-First-Serve (FCFS)**: Processes are scheduled in the order of arrival using a queue.

2. **I/O Buffering:**
    - Queues are used to store data waiting for I/O operations, ensuring that multiple processes can access input/output
      devices efficiently.

3. **Print Queue:**
    - Multiple print jobs are stored in a queue, where the printer processes each job in the order they arrive.

4. **Network Packet Queues:**
    - Routers and switches use queues to manage network packets, ensuring that packets are processed in the order they
      arrive or based on priority.
