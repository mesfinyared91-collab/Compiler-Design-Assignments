# compiler-design-assignment-03
Semantic Rules &amp; Error Detection  Switch Completeness
# Principles of Compiler Design  
## Assignment 03: Semantic Rules & Error Detection

---

### 📌 Topic  
**Enforcing Completeness of Switch Statements for Enums**

---

## 1️⃣ Introduction

In compiler design, **semantic analysis** is the phase that checks whether a program makes logical sense after it has passed lexical and syntax analysis. While syntax analysis ensures that the program follows grammatical rules, semantic analysis ensures **correct meaning**.

One common semantic problem occurs in **switch statements over enum types**. If a switch statement does not handle all possible enum values and does not include a `default` case, it may lead to **runtime errors or undefined behavior**.

This assignment focuses on implementing a semantic rule that ensures:

- All enum values are handled in a switch statement  
**OR**
- A `default` case is provided  

---

## 2️⃣ Problem Statement

### Task  
Design and implement a **semantic analysis pass** that checks whether a switch statement operating on an enum type is complete.

### Rule  
A switch statement is considered **valid** if:
- It contains a `default` case  
**OR**
- It contains a `case` for **every value** defined in the enum  

Otherwise, the compiler must report a **semantic error**.

## Example: Incomplete Switch Statement

```cpp
enum TrafficLight { RED, YELLOW, GREEN };

switch (light) {
    case RED:
    case YELLOW:
        break;
}


❌ Semantic Error:
The enum value GREEN is missing and no default case is provided.

3️⃣ Theoretical Background
What is Semantic Analysis?

Semantic analysis is the third phase of the compiler design process. Its main purpose is to ensure that a program is meaningfully correct after passing lexical and syntax analysis.

It verifies:

Type correctness

Variable declarations

Scope rules

Logical consistency

Role of the Symbol Table

The Symbol Table stores information about program entities such as:

Enum names

Enum values

Variable types

In this assignment:

The enum definition is stored in the symbol table

The switch statement consults this information to verify completeness

4️⃣ Algorithm Design

The semantic checking algorithm follows these steps:

Identify the switch statement

Determine the enum type being switched

Retrieve all enum values from the symbol table

Collect all case labels from the switch body

Check for a default case

If found → switch is valid

Check completeness

Compare enum values with case labels

If any enum value is missing → report a semantic error

5️⃣ Implementation (C++)
Explanation

The C++ program simulates:

Enum definitions

Switch statements

Semantic analyzer logic

It verifies whether:

All enum values are explicitly covered
OR

A default case exists

📄 Source File:
SwitchCompletenessSemanticAnalyzer.cpp

6️⃣ Output Analysis
Test Case 1

Missing GREEN

No default case

❌ Semantic error reported

Test Case 2

All enum values covered

✅ Valid switch

Test Case 3

Default case exists

✅ Valid switch

7️⃣ Conclusion

This assignment successfully demonstrates how semantic rules can be enforced during compiler construction. By ensuring completeness of switch statements over enum types, the compiler prevents potential runtime errors caused by unhandled cases.

The solution highlights the practical use of:

Symbol tables

Abstract syntax representation

Set operations in semantic analysis

