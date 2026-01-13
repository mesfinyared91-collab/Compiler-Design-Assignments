# Question 3 – Parse Tree for Input "1100"

This question demonstrates how to construct a **parse tree** for a given input string using a simple grammar.

## Grammar


S → 1S0 | 10


## Input String


1100


## Explanation
1. Start with the **start symbol** `S`.  
2. Apply the rule `S → 1S0` to expand the root `S`.  
3. Apply the rule `S → 10` to the inner `S` to complete the derivation.  

**Resulting string:**  


1 (10) 0 = 1100


The parse tree represents how the input string is derived **step by step** from the grammar.  
Reading the leaves from left to right produces the original string: `1100`.
<img width="1536" height="1024" alt="ChatGPT Image Jan 12, 2026, 01_49_38 AM" src="https://github.com/user-attachments/assets/8c428149-93be-45ac-98de-cc486c6b5e6f" />





