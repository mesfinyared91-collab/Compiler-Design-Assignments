# 📘 Assignment_01 – Syntax Analysis (Compiler Design)

## 📌 Assignment Overview
**Assignment_01** focuses on the fundamental concepts of **Syntax Analysis** in the course **Principles of Compiler Design**.  
The goal of this assignment is to build a strong **theoretical and practical foundation** in how compilers analyze the structure of source programs using **formal grammars** and **parsing techniques**.

---

## 🧠 Theoretical Component
The assignment begins with a detailed explanation of **Predictive Parsing**, a **top-down parsing technique** that constructs a **leftmost derivation** by scanning the input from **left to right** using a fixed **lookahead symbol**.

Key grammar properties discussed include:
- **LL(1) Grammar characteristics**
- **Elimination of left recursion**
- **Left factoring** to ensure deterministic and efficient parsing

These concepts are essential for building parsers that operate without backtracking and run in linear time.

---

## 💻 Practical Component
As part of the implementation task, a **C++ function** is developed to:
- Identify and count **valid identifiers** from a given source code string

This exercise bridges **compiler theory and real-world programming** by demonstrating how lexical rules such as:
- Keywords
- Identifiers
- Comments
- String literals  

are handled during the analysis phase of a compiler.

---

## ✏️ Problem-Solving Component
The assignment also includes a **grammar analysis problem**, where:
- A given grammar is used to derive a specific input string
- A **parse tree** is constructed to visually represent the syntactic structure

This enhances understanding of:
- Grammar rules
- Derivations
- Hierarchical structure of parsing

---

## ✅ Conclusion
Overall, **Assignment_01** strengthens core compiler design skills by integrating:
- 📘 Theory
- 💻 Coding
- 🧩 Analytical thinking  

It provides a solid foundation for advanced topics such as **parsing algorithms**, **semantic analysis**, and **full compiler implementation**.

---
## 📂 Folder Structure

Assignment_01/
├── 📁 Question1
│   └── 📄 README.md        # Predictive Parsing (Theory)
├── 📁 Question2
│   ├── 💻 identifier.cpp  # C++ program to count valid identifiers
│   └── 📄 README.md       # Program explanation
├── 📁 Question3
│   └── 📄 README.md       # Grammar derivation and parse tree
└── 📄 README.md           # Assignment overview and summary

## ⭐ Note
This repository is created for **academic and learning purposes** as part of the Compiler Design course.

