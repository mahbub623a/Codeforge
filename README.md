# CodeForge

**CodeForge** is a personal repository for competitive programming resources, templates, algorithms, snippets, and learning notes. It’s designed to help you quickly access reusable code and improve problem-solving skills during contests.

## Usage

- Add new algorithms, tricks, or patterns as you learn them.  
- Maintain notes and practice solutions for quick reference and growth.  

## Purpose

This repository serves as a personal toolkit for competitive programming, combining efficiency, learning, and experimentation in one place.

---

> “Forge your code, forge your mind.”


## Debug.h Printable Types Cheat Sheet

| Type / Example | How to Print | Output Format | Notes |
|----------------|-------------|---------------|-------|
| **Primitive Types** | `int x = 42; print(x);` | `x = 42` | Works with `int`, `long`, `long long`, `double`, `float`, `bool`, `char` |
| **Char** | `char c = 'A'; print(c);` | `c = A` | Single character |
| **String (std::string / const char\*)** | `string s = "hi"; print(s);` | `s = "hi"` | Always wrapped in quotes |
| **Pairs** | `pair<int,int> p = {1,2}; print(p);` | `p = (1, 2)` | Works for any type of pair elements |
| **Tuples** | `tuple<int,string,double> t = {1,"hi",3.14}; print(t);` | `t = (1, "hi", 3.140000)` | Handles nested tuples too |
| **Vector** | `vector<int> v = {1,2,3}; print(v);` | `v = {1, 2, 3}` | Works with nested vectors like `vector<vector<int>>` |
| **List / Deque / Set / Unordered Set** | `set<int> s = {1,2,3}; print(s);` | `s = {1, 2, 3}` | Iterables printed in `{...}` |
| **Map / Unordered Map** | `map<int,string> mp = {{1,"one"}, {2,"two"}}; print(mp);` | `mp = {1 => "one", 2 => "two"}` | Key => Value format |
| **Nested Containers** | `vector<pair<int,int>> vp = {{1,2},{3,4}}; print(vp);` | `vp = {(1, 2), (3, 4)}` | Works recursively |
| **Pointers** | `int* ptr = &x; print(ptr);` | `<ptr>` or `nullptr` | Prints `<ptr>` for valid pointers, `nullptr` for null |
| **Lambda / Unknown Type** | `auto f = [](){}; print(f);` | `<non-printable>` | Any type not directly supported prints `<non-printable>` |
