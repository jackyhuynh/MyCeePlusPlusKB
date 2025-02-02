# Round Robin Queue and Load Balancers

---

## Byte Byte Go, Top 6 Load Balancing Algorithms

🔹 Static Algorithms

1. Round Robin
   The client requests are sent to different service instances in sequential order. The services are usually required to
   be stateless.

2. Sticky round-robin
   This is an improvement of the round-robin algorithm. If Alice’s first request goes to service A, the following
   requests go to service A as well.

3. Weighted round-robin
   The admin can specify the weight for each service. The ones with a higher weight handle more requests than others.

4. Hash
   This algorithm applies a hash function on the incoming requests’ IP or URL. The requests are routed to relevant
   instances based on the hash function result.

🔹 Dynamic Algorithms

5. Least connections
   A new request is sent to the service instance with the least concurrent connections.

6. Least response time
   A new request is sent to the service instance with the fastest response time.

## **Round Robin Load Balancer Concept:**

In **Round Robin Load Balancing**, incoming requests are distributed sequentially to a list of servers, one by one. The
idea is that each server gets an equal share of the requests, ensuring load distribution.

1. **First Request** → Server 1
2. **Second Request** → Server 2
3. **Third Request** → Server 3
4. **Fourth Request** → Back to Server 1 (and so on...)

It cycles through the available servers in a **circular manner**, making sure that no server is overwhelmed while others
are idle.

### **How a Queue Might Be Involved:**

While Round Robin itself doesn’t necessarily rely on a **traditional queue** (like those found in data structures where
elements are enqueued and dequeued), it **conceptually** functions similarly to a circular queue. Here’s how:

- **Queue-Like Rotation:**  
  Round Robin rotates over a collection of servers in a cyclical fashion, much like a circular queue:
    - Each server gets selected in a fixed order.
    - After the last server in the list is assigned a request, it loops back to the first server.

- **Server List:**  
  In a Round Robin algorithm, the list of servers could be implemented using a **ring buffer** (circular data structure)
  or a simple array where the load balancer keeps track of the current server index, and each time a request arrives,
  it "cycles" through the servers.

- **Request Assignment:**  
  Although it’s not a traditional queue where requests are added and removed, Round Robin behaves like a **queueing
  system** in the sense that requests are dispatched sequentially and the system "queues" the next available server for
  the upcoming request.

### **Steps in Round Robin Load Balancer:**

1. **Track Current Server:** The load balancer keeps track of the index (or pointer) to the current server in the list.
2. **Assign Request:** When a request comes in, it assigns the request to the server at the current index.
3. **Update Pointer:** After each assignment, the pointer moves to the next server in the list.
4. **Wrap Around:** When the last server in the list is reached, the pointer wraps back to the first server, simulating
   a circular queue.

### **Key Differences from a Traditional Queue:**

- **In a queue**, requests enter in a first-in, first-out (FIFO) order and leave after processing.
- **In Round Robin**, servers are "queued" to handle requests in a circular fashion, but no actual request objects are
  stored in a queue structure. Instead, the load balancer just forwards each request immediately to the next server in
  line.

### **Advantages of Round Robin Load Balancer:**

- **Simplicity**: It's easy to implement and understand.
- **Fair Distribution**: Each server gets approximately an equal share of the requests.
- **Low Overhead**: It doesn’t require complicated logic or state tracking beyond the current index.

### **Variants of Round Robin Load Balancing:**

1. **Weighted Round Robin:** Servers have different capacities, so they are assigned a weight. Servers with higher
   weights get more requests than those with lower weights, but still in a round-robin fashion.
2. **Least Connection + Round Robin:** Combines the round-robin approach with checking the number of active connections
   on each server. Servers with fewer active connections may get assigned a request sooner.

### **Conclusion:**

While Round Robin Load Balancing doesn’t use a **traditional queue data structure** for request storage, it can be seen
as queue-like in its scheduling of servers for request handling. Each server takes turns in handling requests in a
circular manner, which is similar to how a circular queue operates in distributing items.
