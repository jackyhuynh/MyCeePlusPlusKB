# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Repository Overview

This is a comprehensive C++ knowledge base and educational repository for teaching Data Structures, Design Patterns, and C++ fundamentals at college and university level.

## Repository Structure

- **Fundamentals/**: Basic C++ concepts (chapters 1-13) - program structure, functions, arrays, pointers, memory management
- **DataStructure/**: Implementations (chapters 1-19) of linked lists, stacks, queues, trees, heaps, graphs, sorting/searching algorithms
- **DesignPattern/**: SOLID principles, Singleton, Factory, Builder, Adapter, Bridge, Composite, Prototype patterns
- **AdvanceC++/**: Multithreading, data exchange with Docker services
- **Robotic/**: Robotic design and self-driving car implementations
- **OS_MachineLanguage/**: Operating system and computer architecture concepts

## Build and Test Commands

### Compilation
```bash
# Standard compilation (C++17 required)
g++ -std=c++17 source.cpp -o output

# Multiple files
g++ -std=c++17 main.cpp implementation.cpp -o program

# With debugging
g++ -std=c++17 -g source.cpp -o debug_output
```

### Testing (GoogleTest)
```bash
# Compile tests
g++ -std=c++17 TestFile.cpp ImplementationFile.cpp -lgtest -lgtest_main -pthread -o test_runner
./test_runner
```

### Docker Services
```bash
cd AdvanceC++/30_DataExchange
docker-compose up --build
docker-compose down
```

## Code Architecture

### File Naming Conventions
- Headers: `{ClassName}.h`
- Implementation: `{ClassName}.cpp` 
- Tests: `Test{ClassName}.cpp` or `{ClassName}Tests.cpp`
- ADT implementations: `ADT{Structure}.cpp`
- Driver programs: `driver.cpp` or `main.cpp`
- Templates: `.hpp` files

### Common Patterns
- Manual implementations (no STL) for teaching purposes
- Exception handling with try/catch blocks
- Virtual methods for polymorphism
- Each data structure directory contains header, implementation, and test files

## Testing Strategy

- GoogleTest framework for unit testing
- Test files demonstrate edge cases and proper usage
- Manual testing via driver programs
- Exception handling validation in test cases