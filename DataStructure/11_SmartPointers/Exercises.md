# Smart pointers

Smart pointers in C++ provide automatic memory management and help prevent memory leaks and dangling pointers. Here are some applications where smart pointers can be effectively used:

### 1. **Memory Management in Game Development**
- **Application**: Game engines (like Unreal Engine) use smart pointers to manage resources such as game objects, textures, and audio files.
- **How?**: `std::shared_ptr` and `std::weak_ptr` are used for object ownership and avoiding circular dependencies.

### 2. **Resource Management in GUI Applications**
- **Application**: Managing UI components dynamically created in Qt or other GUI frameworks.
- **How?**: `std::unique_ptr` ensures that UI components are properly cleaned up when no longer needed.

### 3. **Networking Applications**
- **Application**: Managing connections, requests, and responses in client-server architectures.
- **How?**: Using `std::shared_ptr` to keep track of active sessions, and `std::weak_ptr` to prevent circular dependencies.

### 4. **Multithreading and Parallel Processing**
- **Application**: Managing thread-safe data in concurrent programming.
- **How?**: `std::shared_ptr` is used to share resources safely between threads, while `std::weak_ptr` avoids cyclic references.

### 5. **Database Connection Management**
- **Application**: Handling connections to databases dynamically.
- **How?**: `std::shared_ptr` maintains active connections, while `std::weak_ptr` prevents reference cycles.

### 6. **Filesystem Operations (Virtual Filesystems)**
- **Application**: Managing dynamically allocated file handles and streams.
- **How?**: `std::unique_ptr` ensures file handles are closed when they go out of scope.

### 7. **Plugin Systems and Dynamic Libraries**
- **Application**: Managing dynamically loaded plugins.
- **How?**: `std::shared_ptr` can manage plugin lifecycle and prevent premature deallocation.

### 8. **Computer Vision & Image Processing**
- **Application**: Managing large datasets (e.g., OpenCV images).
- **How?**: `std::shared_ptr` is used to share images across multiple processing modules efficiently.

### 9. **IoT and Embedded Systems**
- **Application**: Managing dynamically allocated sensor data buffers.
- **How?**: `std::unique_ptr` ensures buffers are freed automatically.

### 10. **Compiler Design (AST Representation)**
- **Application**: Managing Abstract Syntax Trees (ASTs) in compilers.
- **How?**: `std::shared_ptr` allows multiple references to tree nodes, while `std::weak_ptr` prevents cycles.

---

## **Exercise 1: Managing Game Objects in a Game Engine**
In this example:
- **`GameObject`** represents a game entity.
- **`std::unique_ptr`** ensures each object has one owner.
- **`std::shared_ptr`** is used for objects that need multiple references.
- **`std::weak_ptr`** prevents circular references when objects reference each other.

---

### **C++ Code: Smart Pointer Example in a Game Engine**
```cpp
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// Game Object Class
class GameObject {
public:
    string name;

    GameObject(string n) : name(n) {
        cout << "GameObject " << name << " created.\n";
    }

    ~GameObject() {
        cout << "GameObject " << name << " destroyed.\n";
    }

    void update() {
        cout << name << " is updating...\n";
    }
};

// Game World that holds objects
class GameWorld {
private:
    vector<unique_ptr<GameObject>> objects;  // Unique ownership of objects

public:
    void addObject(string name) {
        objects.push_back(make_unique<GameObject>(name));
    }

    void updateAll() {
        for (auto& obj : objects) {
            obj->update();
        }
    }
};

// Scene using shared and weak pointers
class Scene {
public:
    shared_ptr<GameObject> player;  // Shared ownership
    vector<weak_ptr<GameObject>> enemies;  // Weak references to avoid circular dependencies

    void addEnemy(shared_ptr<GameObject> enemy) {
        enemies.push_back(enemy);
    }

    void showEntities() {
        cout << "Scene Entities:\n";
        cout << "Player: " << player->name << "\n";
        for (auto& enemy : enemies) {
            if (auto e = enemy.lock()) {  // Convert weak_ptr to shared_ptr safely
                cout << "Enemy: " << e->name << "\n";
            } else {
                cout << "Enemy destroyed.\n";
            }
        }
    }
};

int main() {
    cout << "=== Unique Pointer Example (Game World) ===\n";
    GameWorld world;
    world.addObject("Hero");
    world.addObject("Villain");
    world.updateAll();

    cout << "\n=== Shared and Weak Pointer Example (Scene) ===\n";
    Scene scene;
    
    // Shared ownership of player
    auto player = make_shared<GameObject>("Player1");
    scene.player = player;

    // Shared ownership of enemies
    auto enemy1 = make_shared<GameObject>("Enemy1");
    auto enemy2 = make_shared<GameObject>("Enemy2");

    scene.addEnemy(enemy1);
    scene.addEnemy(enemy2);

    scene.showEntities();

    // Simulating object destruction
    cout << "\nDestroying Enemy1...\n";
    enemy1.reset();  // Manually destroying shared_ptr, weak_ptr prevents circular issues
    scene.showEntities();

    cout << "\nExiting main...\n";
    return 0;
}
```

---

### **Explanation**
1. **Using `std::unique_ptr` in `GameWorld`**
    - Ensures that objects have a **single owner** and are **automatically destroyed** when the world is deleted.

2. **Using `std::shared_ptr` in `Scene`**
    - The `player` is stored as a **shared pointer**, allowing multiple references.
    - `enemies` are stored as **shared pointers**, so they are dynamically allocated.

3. **Using `std::weak_ptr` in `Scene`**
    - `enemies` are weak references to avoid circular references.
    - If an `enemy` is destroyed, `weak_ptr.lock()` prevents accessing a dangling pointer.

---

### **Expected Output**
```
=== Unique Pointer Example (Game World) ===
GameObject Hero created.
GameObject Villain created.
Hero is updating...
Villain is updating...

=== Shared and Weak Pointer Example (Scene) ===
GameObject Player1 created.
GameObject Enemy1 created.
GameObject Enemy2 created.
Scene Entities:
Player: Player1
Enemy: Enemy1
Enemy: Enemy2

Destroying Enemy1...
GameObject Enemy1 destroyed.
Scene Entities:
Player: Player1
Enemy destroyed.
Enemy: Enemy2

Exiting main...
GameObject Enemy2 destroyed.
GameObject Player1 destroyed.
GameObject Hero destroyed.
GameObject Villain destroyed.
```

---

### **Key Takeaways**
✅ **`std::unique_ptr`** - Used for single ownership (GameWorld objects).  
✅ **`std::shared_ptr`** - Used for shared ownership (Scene entities).  
✅ **`std::weak_ptr`** - Avoids circular references (Scene enemies).