# CodingPlayground
This project comprises of some common coding problems, experimental code, setup scripts, algorithms and data structures and design patterns developed predominantly in C++   

It was private earlier but I decided to make it public for 2 reasons:   
  **a.** *People can benefit from code for common problems, algorithms and design patterns*  
  **b.** *I can have fresh and multiple set of eyes on my code helping me to improve its quality*  

## Contents
The directory contents are explained below for better navigation. For build instructions, refer to the next section in this readme  

### Design Patterns
This section/directory contains code examples for 23 design patterns concieved by **Gang of Four** in 1994  
There are 3 standard subsections: Structural, Creational and Behavioural   
Each subsection directory contains a source file for each design pattern under the 3 categories mentioned above  

### DSA (Data structures and algorithms) Problems
This section directory (DSA_Exercises) contains various DSA problem statements and their solutions in form of source code.  
A problem statements document for each category is placed under their respective directory. The source file containing the solution in the same directory is mentioned at end of every problem.  
#### Some directions and requests to get the best out of this section:  
- Try solving the problems on your own and then verify your solution using the same `main()` function used inside the solution for respective problem
- Once you're getting expected output with the default input parameters, put your solution to test with 4-5 additional test cases
- Evaluate my solution and also put that to test with your own test cases to uncover hidden bugs and then compare it with yours
- Review my solution because it may contain redundancies or defects. Please raise a PR or create an issue as you see fit in such cases

### General coding problems or experimental code
This section directory `ExperimentalCode` contains purely exprimental code based on new C++ concepts I learnt. I have left it in here just in case it benefits anyone who is also learning C++ or is a new programmer  
Experts in C++ can safely ignore this section  

### Utils
This directory contains common utilities in form of headers or shared libraries required commonly by most of the sources in this project. This can help reduce duplication and also binary size in some cases if methods are defined in a shared library instead of the source code.  

### Misc
This directory contains some misc scripts and code used to set up my project environment or developed to evaluate a concept.  
The reason it ends up here and not in the experimental code section is because of its nature. For instance, `DL_API_shell.c` is a source file containing the dynamic loader API from `libdl.so` shared library and needs to be compiled differently from how other source files in experimental code are built in cmake as shown below:
```
gcc -rdynamic -o DL_API_shell DL_API_shell.c -ldl
```
The shell scripts may not apply to your project env setup but in case they do, run them as root using `sudo` 

## Build Instructions
This project has been set up with the cmake build tool at every level for different sections to provide more fexibility while building.  
Secondly, this project does not have a unified binary/library linked with other relocatable object files, each source file being a standalone app  

At each level cmake adds subdirectories for the downstream directories. By default the top level cmake will build all the sources residing in all the section directories. This can be a waste of time if you're intending to work with any one section, for instance `DesignPatterns`  
In such scenarios, comment out (cmake comments start with `#`) the `add_subdirectory()` calls which are not required. In our example, the top-level cmake will look something like this:
```
add_subdirectory(DesignPatterns)
#add_subdirectory(DSA_Exercises)
#add_subdirectory(ExperimentalCode)
```
This will generate only the `DesignPatterns` source code binaries under `bin`  
This rule can be applied recursively for downstream directories in similar manner to save build time  
Once the required subdirectories are setup in cmake, run `Clean Reconfigure All` followed by `Clean Rebuild All` to build the sources if you've opened the project in VSCode  
In other cases, run the following commands on the command prompt at root level of the project
```
mkdir build
cd build
cmake ..
make
```
The output for involved sources will be generated in the `bin` directory of the project under their respective section directories

## Contribution
**Please note that the code herein is not perfect!** There might be better and more optimized ways of implementing some tasks and that's exactly the intention of exposing this repo to the public.  
I am inviting suggestions and modifications on the code in any of the above sections.  
You can either email (amoldhamale1105@gmail.com) me your suggesstions/modifications or create a new branch and raise a pull request against the master branch  
You can also raise issues on github if you discover any    

<font size="5">**Happy coding and learning!**</font>
