# Codeforge

**Codeforge** is a personal repository for competitive programming resources, templates, algorithms, snippets, and learning notes. It’s designed to help you quickly access reusable code and improve problem-solving skills during contests.

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
| **Primitive Types** | `int x = 42; show(x);` | `x = 42` | Works with `int`, `long`, `long long`, `double`, `float`, `bool`, `char` |
| **Char** | `char c = 'A'; show(c);` | `c = A` | Single character |
| **String (std::string / const char\*)** | `string s = "hi"; show(s);` | `s = "hi"` | Always wrapped in quotes |
| **Pairs** | `pair<int,int> p = {1,2}; show(p);` | `p = (1, 2)` | Works for any type of pair elements |
| **Tuples** | `tuple<int,string,double> t = {1,"hi",3.14}; show(t);` | `t = (1, "hi", 3.140000)` | Handles nested tuples too |
| **Vector / List / Deque / Set / Unordered Set** | `vector<int> v = {1,2,3}; show(v);` | `v = {1, 2, 3}` | Iterables printed recursively in `{...}` |
| **Map / Unordered Map** | `map<int,string> mp = {{1,"one"}, {2,"two"}}; show(mp);` | `mp = {1 => "one", 2 => "two"}` | Key => Value format |
| **Stack** | `stack<int> st; st.push(1); st.push(2); show(st);` | `st = {2, 1}` | Prints **top → bottom** |
| **Queue** | `queue<int> q; q.push(1); q.push(2); show(q);` | `q = {1, 2}` | Prints **front → back** |
| **Priority Queue** | `priority_queue<int> pq; pq.push(1); pq.push(3); pq.push(2); show(pq);` | `pq = {3, 2, 1}` | Prints **top → bottom** (natural priority order) |
| **Nested Containers** | `vector<pair<int,int>> vp = {{1,2},{3,4}}; show(vp);` | `vp = {(1, 2), (3, 4)}` | Works recursively |
| **Pointers** | `int* ptr = &x; show(ptr);` | `<ptr>` or `nullptr` | Prints `<ptr>` for valid pointers, `nullptr` for null |
| **Lambda / Unknown Type** | `auto f = [](){}; show(f);` | `<non-printable>` | Any type not directly supported prints `<non-printable>` |
