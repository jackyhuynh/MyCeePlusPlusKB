## Hashing Exercises

**1. Basic Hash Function**

* **Objective:** Understanding how a simple hash function works.
* **Problem:** Given the following hash function: `h(key) = key % table_size`, where `table_size` is 10, calculate the hash values for the following keys: 25, 13, 8, 105, 32.

**2. Collision Resolution - Linear Probing**

* **Objective:** Implementing collision resolution using linear probing.
* **Problem:** Insert the following keys into a hash table of size 7 using the hash function `h(key) = key % 7` and linear probing to resolve collisions: 15, 22, 8, 9, 16, 23. Show the state of the hash table after all keys have been inserted.

**3. Collision Resolution - Separate Chaining**

* **Objective:** Implementing collision resolution using separate chaining.
* **Problem:** Insert the following keys into a hash table of size 5 using the hash function `h(key) = key % 5` and separate chaining to resolve collisions. Each slot in the hash table should point to a linked list. Keys: 12, 26, 30, 17, 29, 38. Show the final state of the hash table.

**4. Hash Table Search**

* **Objective:** Understanding how to search for a key in a hash table.
* **Problem:** Given a hash table of size 11 with the following keys (and using linear probing):
    * Index 0: \[ \]
    * Index 1: 45
    * Index 2: 23
    * Index 3: \[ \]
    * Index 4: 56
    * Index 5: 18
    * Index 6: 92
    * Index 7: 14
    * Index 8: \[ \]
    * Index 9: 67
    * Index 10: \[ \]

    The hash function used is `h(key) = key % 11`. Trace the steps to find the following keys: 56, 18, and 24. Indicate the number of probes for each search.

**5. Rehashing**

* **Objective:** Understanding the concept of rehashing.
* **Problem:** You have a hash table of size 5 with the hash function `h(key) = key % 5` and linear probing. The table currently contains the following keys:
    * Index 0: 20
    * Index 1: \[ \]
    * Index 2: 2
    * Index 3: 8
    * Index 4: \[ \]

    You need to insert the keys 27 and 13. However, the table is becoming too full, so you decide to rehash to a new table of double the size (10). Show the steps involved in rehashing and the final state of the new hash table after inserting 27 and 13. Use the same hash function, but with the new table size: `h(key) = key % 10`.
