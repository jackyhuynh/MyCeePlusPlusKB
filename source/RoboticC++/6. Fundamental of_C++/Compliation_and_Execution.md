# Compilation and Execution

Material retrieved from [Udacity.com](https://classroom.udacity.com/courses/ud210/lessons/1343a461-102f-41e1-b505-bf9ec62f427b/concepts/b1e0db7a-619e-4f23-a30d-b505d84ae3bc)

## Object Files
Compiling source code, like a single .cpp file, results in something called an [object file](https://en.wikipedia.org/wiki/Object_file). An object file contains machine code but may not be executable in and of itself. Among other things, object files describe their own public APIs (usually called symbols) as well as references that need to be resolved from other object files. Depended upon object files might come from other source files within the same project or from external or system libraries.

In order to be executable, object files need to be linked together.

## Linking
Linking is the process of creating an executable by effectively combining object files. During the linking process, the linker (the thing that does the linking) resolves symbolic references between object files and outputs a self-contained binary with all the machine code needed to execute.

As an aside, linking is not required for all programs. Most operating systems allow dynamic linking, in which symbolic references point to libraries that are not compiled into the resulting binary. With dynamic linking, these references are resolved at runtime. An example of this is a program that depends on a system library. At runtime, the symbolic references of the program resolve to the symbols of the system library.

There are pros and cons of dynamic linking. On the one hand, dynamically linked libraries are not linked within binaries, which keeps the overall file size down. However, if the library changes at any point, your code will automatically link to the new version. Like any changing dependency, difficult to fix and surprising bugs sometimes arise when versions change.

![img](https://github.com/jackyhuynh/Introduction_to_Robotic_Design_and_Development/blob/main/6.%20Fundamental%20of_C%2B%2B/images/Linking.PNG)

## Compiling to Executable with a Compiler
Technically, you only need a compiler to compile C++ source code to a binary. A compiler does the dirty work of writing machine code for a given processor architecture. There are many compilers available. For this course, we picked the open source GNU Compiler Collection, more commonly called G++ or GCC. gcc is a command line tool.

There are two challenges with using gcc alone, both of which relate to the fact that most C++ projects are large. For one thing, you need to pass the paths for all of the project's source header files and cpp files to gcc. This is in addition to any compiler flags or options. You can easily end up with single call to gcc that spans multiple lines on a terminal, which is unruly and error-prone.

Secondly, large projects will usually contain multiple linked binaries, each of which is compiled individually. If you're working in large project and only change one .cpp file, you generally only need to recompile that one binary - the rest of your project does not need to be compiled again! Compiling an entire project can take up to hours for large projects, and as such being intelligent about only compiling binaries with updated source code can save lots of time. GCC in and of itself is not smart enough to recognize what files in your project have changed and which haven't, and as such will recompile binaries needlessly - you'd need to manually change your gcc calls for the same optimizations. Luckily, there are tools that solve both of these problems!

### Open a Terminal
You may wish to consult these references as you work through this lesson.

    * Using C++ in a Unix Environment

    * Using C++ in a Windows Environment
Let's do a step-by-step example of compiling from the terminal.

This is the easiest, most direct method.

    - Step 1: Open a terminal window
    - Step 2: Make sure you have the C++ libraries loaded on your machine.
    - Step 3: Go to the directory where you saved your program.
    - Step 4: Compile the program.

#### Step 1:

Open a terminal window.

On my Mac machine I can open a terminal window by going to the menu where all my applications are stored and selecting the terminal application.

Here is a screenshot of the terminal icon on my computer.

![img](https://github.com/jackyhuynh/Introduction_to_Robotic_Design_and_Development/blob/main/6.%20Fundamental%20of_C%2B%2B/images/screen-shot-2017-03-23-at-10.05.02-am.png)

Now, let's find out if we have C++ on my computer:

Open a terminal window - you'll notice when you open your window it may have a black background with white text. I changed mine to have a white background with black text to make it easier for you to see.

![img](https://github.com/jackyhuynh/Introduction_to_Robotic_Design_and_Development/blob/main/6.%20Fundamental%20of_C%2B%2B/images/screen-shot-2017-03-23-at-10.19.13-am.png

Notice the prompt on my terminal.
It is:

    catherinegamboa ~ $

The '$' is the standard shell prompt for Unix/Linux. Yours may be different.
Check out Shell Prompt Explained for more information.
You can also see my name catherinegamboa ~. This is valuable information. It tells me which directory I'm in. My terminal starts in the top level directory of my computer.

#### Step 2:
Make sure you have the C++ libraries loaded on your machine.

Let's find out if we have C++ on our computer.
At the terminal prompt, type in
```
g++ -help
```
For some systems you may have type:
```
G++ --help
```
Type g++ -help at the prompt. When I enter this command I get a long list of helpful information about the C++ compiler. If text like this was printed, you have g++ on your computer and you can access it. If you got something saying "no such command" you either don't have C++ installed on your computer or you have it but it is not properly configured in your pathname.

You will have to figure out which problem you have and fix it. troubleshooting this problem is beyond the scope of this course

We're in a Unix environment now, so we'll need to know a few Unix commands.

- Unix Command

    - pwd: print working directory
    - cd: change directory
    - ls: list the contents of the directory
    **If you are using a Windows machine, open a "Select Command Prompt' window.
    - HELP: You will see a list of commands. They are different than the Unix commands.
    - CHDIR : change directory
    - DIR: print the files and folders in the working directory

#### Step 3:
We have completed the steps necessary to compile:

    - Open a terminal window
    - Navigate to the correct directory
    - Make sure you file(s) are in the directory

I am going to compile a program called:
```
assignment2.cpp
```
The command to compile this file is:
```
g++ filename.cpp -o nameOfExecutableCode

For example:
        g++ assignment2.cpp -o a2
```
- g++ is the command to compile
- assignment2.cpp is the file to be compiled
- -o is the command that says you want name of the executable file
- a2 is the name I want to give the executable file.

#### Step 4:
In summary to compile in a terminal:

    - Open a terminal window
    - change the working directory to the directory of the program
    - Make sure names of folders and files do not have spaces in them
    - To compile the program: g++ filename.cpp -o executableName
    - To execute the program: ./executableName

Common mistakes when executing in the terminal:
    - Make sure there are no spaces in filenames
    - Make sure all the files you need are in the working directory (including header files), use 'ls' to check

