# 🧮 small-C-collection

A personal collection of small programming projects written in C, aimed at deepening my understanding of how things work at a lower level. 

My prior experience has mostly been with higher-level languages such as Python, MATLAB, Perl, and VB.net. This repo showcases my implementations of some typical beginner projects in a lower-level language.

This repository isn’t intended to be a polished software suite; it’s purely a place for me to document and learn.

**Note:** Currently, it contains only one project, but I plan to expand it over time with more simple programs.


## 🚀 Projects

### 1. Calculator CLI (🧠 Infix → Postfix → Evaluation)

A simple command-line calculator that:
- Accepts arithmetic expressions like `2 + 3 * 4 - 5`
- Converts infix to postfix (Reverse Polish Notation)
- Evaluates the result using a stack-based algorithm

#### 🔧 How It Works
- Manual tokenisation of input
- Operator precedence handled via shunting yard algorithm
- Recursive postfix evaluation
- Built from scratch without external libraries

#### 📂 Folder Structure
src/ # Source code (.c/.h files)
obj/ # Compiled object files (not tracked in Git)
bin/ # Compiled binaries (not tracked in Git)

#### 🛠️ Build Instructions
```bash
make            # Build the project
./bin/calc      # Run the calculator
make clean      # Clean compiled files
```

## 🛤️ What's Next?
- This repo may grow to include:
- 📝 A to-do list manager
- 🧮 A toy interpreter/compiler
- 🖼️ A JPEG compression algorithm 

### 📚 Why?
I'm using this project as a way to:
- Learn C deeply by building from scratch
- Understand concepts like tokenisation, parsing, memory layout
- Explore the boundaries of how much can be done without libraries

### 💬 Feedback
Feel free to open issues or suggest improvements :)

