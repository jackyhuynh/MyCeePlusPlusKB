# Exercises

## **Exercise 2: Priority Queue for Urgent Registrations**
### **Objective:**
Modify the system to allow **priority registration**.

### **Instructions:**
1. Extend the **`Student`** class by adding a **priority level** (`1 = High, 2 = Medium, 3 = Low`).
2. Modify **`RegistrationQueue`** to be a **priority queue**:
    - Students with a lower priority number (e.g., 1) should be processed **before** those with a higher number.
3. Implement a `priorityEnqueue(Student student)` function that ensures high-priority students get registered first.

### **Sample Output:**
```
Student Bob (ID: 201, Priority: 2) added to the queue.
Student Alice (ID: 202, Priority: 1) added to the queue.
Student John (ID: 203, Priority: 3) added to the queue.
Processing Alice (ID: 202) first due to high priority.
Processing Bob (ID: 201).
Processing John (ID: 203).
```

---

## **Exercise 3: Simulating Multiple Registration Desks**
### **Objective:**
Use **multiple queues** to simulate multiple registration counters.

### **Instructions:**
1. Create `CounterQueue` objects for different registration counters.
2. When a student registers:
    - Assign them to the **counter with the shortest queue**.
3. Process students **independently** at each counter.

### **Sample Output:**
```
Student John assigned to Counter 1.
Student Alice assigned to Counter 2.
Student Bob assigned to Counter 1.
Processing John at Counter 1.
Processing Alice at Counter 2.
Processing Bob at Counter 1.
```

---

## **Exercise 4: Circular Queue for Limited Registrations**
### **Objective:**
Use a **circular queue** for a system with **limited spots**.

### **Instructions:**
1. Modify `RegistrationQueue` to support a **fixed-size circular queue**.
2. When the queue is full, **new students must wait** until a spot is available.

### **Sample Output:**
```
Queue Full! Student David must wait.
Processing student John...
Spot available! David is added to the queue.
```