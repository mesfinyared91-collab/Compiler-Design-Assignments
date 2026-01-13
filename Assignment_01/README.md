# 📘 Assignment_01 – Syntax Analysis (Compiler Design)

## 📌 Assignment Overview
**Assignment_01** focuses on the fundamental concepts of **Syntax Analysis** in the course  
**Principles of Compiler Design**. The objective of this assignment is to build a strong
theoretical and practical foundation in how compilers analyze the structure of source programs
using **formal grammars** and **parsing techniques**.

---

## 🧠 Theoretical Component
The assignment begins with a detailed explanation of **Predictive Parsing**, a **top-down parsing**
technique that constructs a **leftmost derivation** by scanning the input from **left to right**
using a fixed **lookahead symbol**.

It highlights essential properties of **LL(1) grammars**, including:
- Elimination of **left recursion**
- Application of **left factoring**
- Deterministic parsing without backtracking
- Linear time complexity **O(n)**

---

## 💻 Practical Component
The practical section includes a **C++ implementation** that identifies and counts
**valid identifiers** from a given source code string.

This task demonstrates how lexical rules such as:
- Keywords
- Identifiers
- Comments
- String literals  

are handled during compiler analysis, connecting **theory with real-world programming**.

---

## ✏️ Problem-Solving Component
The assignment also includes a **grammar analysis problem**, where:
- A given grammar is used to derive a specific input string
- A **parse tree** is constructed to visually represent the syntactic structure

This strengthens understanding of:
- Grammar rules
- Derivations
- Hierarchical parsing

---

## 📂 Folder Structure


Assignment_01/
├── 📁 Question1
│ └── 📄 README.md # Predictive Parsing (Theory)
├── 📁 Question2
│ ├── 💻 identifier.cpp # C++ program to count valid identifiers
│ └── 📄 README.md # Program explanation
├── 📁 Question3
│ └── 📄 README.md # Grammar derivation and parse tree
└── 📄 README.md # Assignment overview and summary


---

## ✅ Conclusion
Overall, **Assignment_01** strengthens core compiler design skills by combining:
- 📘 Theory
- 💻 Coding
- 🧩 Analytical thinking

It prepares students for advanced topics such as **parsing algorithms**, **semantic analysis**,
and **compiler implementation**.

---

## 📚 References
- *Compilers: Principles, Techniques, and Tools* – Aho et al.
- Compiler Design lecture notes
- Online compiler resources

---

## ⭐ Note
This repository is created for **academic and learning purposes** as part of the
**Compiler Design** course.
