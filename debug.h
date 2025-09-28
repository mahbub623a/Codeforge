#ifndef DEBUG_H
#define DEBUG_H

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define see(...) print_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define see(...) 42
#endif

// Forward declaration
template <typename T>
string to_string_debug(const T& value);

// ---------- Primitive / arithmetic ----------
template <>
inline string to_string_debug<const char*>(const char* const & s) {
    return "\"" + string(s) + "\"";
}

template <>
inline string to_string_debug<string>(const string& s) {
    return "\"" + s + "\"";
}

template <>
inline string to_string_debug<char>(const char& c) {
    return string(1, c);
}

// ---------- Pair ----------
template <typename A, typename B>
string to_string_debug(const pair<A, B>& p) {
    return "(" + to_string_debug(p.first) + ", " + to_string_debug(p.second) + ")";
}

// ---------- Tuple ----------
template <typename Tuple, size_t... I>
string tuple_to_string(const Tuple& t, index_sequence<I...>) {
    stringstream ss;
    ss << "(";
    ((ss << (I == 0 ? "" : ", ") << to_string_debug(get<I>(t))), ...);
    ss << ")";
    return ss.str();
}

template <typename... Args>
string to_string_debug(const tuple<Args...>& t) {
    return tuple_to_string(t, index_sequence_for<Args...>{});
}

// ---------- Map ----------
template <typename K, typename V>
string to_string_debug(const map<K, V>& m) {
    stringstream ss;
    ss << "{";
    bool first = true;
    for (auto &kv : m) {
        if (!first) ss << ", ";
        first = false;
        ss << to_string_debug(kv.first) << " => " << to_string_debug(kv.second);
    }
    ss << "}";
    return ss.str();
}

// ---------- Generic containers ----------
template <typename T>
string range_to_string(const T& container) {
    stringstream ss;
    ss << "{";
    bool first = true;
    for (auto &x : container) {
        if (!first) ss << ", ";
        first = false;
        ss << to_string_debug(x);
    }
    ss << "}";
    return ss.str();
}

// ---------- Raw pointers ----------
template <typename T>
string to_string_debug(T* ptr) {
    return ptr ? "<ptr>" : "nullptr";
}

// ---------- C-strings ----------
inline string to_string_debug(const char* s) {
    return s ? "\"" + string(s) + "\"" : "nullptr";
}

inline string to_string_debug(char* s) {
    return s ? "\"" + string(s) + "\"" : "nullptr";
}

// ---------- Generic / Iterable ----------
template <typename T>
string to_string_debug(const T& value) {
    if constexpr (is_arithmetic<T>::value) {
        return to_string(value);
    } else if constexpr (is_same<T,string>::value) {
        return "\"" + value + "\"";
    } else if constexpr (requires { begin(value); end(value); }) {
        return range_to_string(value); // iterable containers
    } else if constexpr (is_pointer<T>::value) {
        return value ? "<ptr>" : "nullptr";
    } else {
        return "<non-printable>";
    }
}

// ---------- Stack (top -> bottom) ----------
template <typename T, typename Container>
string to_string_debug(const stack<T, Container>& s) {
    stack<T, Container> copy = s;
    vector<T> elems;
    while (!copy.empty()) {
        elems.push_back(copy.top());
        copy.pop();
    }
    return range_to_string(elems);
}

// ---------- Queue (front -> back) ----------
template <typename T, typename Container>
string to_string_debug(const queue<T, Container>& q) {
    queue<T, Container> copy = q;
    vector<T> elems;
    while (!copy.empty()) {
        elems.push_back(copy.front());
        copy.pop();
    }
    return range_to_string(elems);
}

// ---------- Priority Queue (top -> bottom) ----------
template <typename T, typename Container, typename Compare>
string to_string_debug(const priority_queue<T, Container, Compare>& pq) {
    priority_queue<T, Container, Compare> copy = pq;
    vector<T> elems;
    while (!copy.empty()) {
        elems.push_back(copy.top());
        copy.pop();
    }
    return range_to_string(elems);
}

// ---------- Base case ----------
inline void print_out(const char* names) {
    cerr << "\n";
}

// ---------- Recursive case ----------
template <typename T, typename... Args>
void print_out(const char* names, T value, Args... args) {
    const char* comma = strchr(names, ',');
    if (comma) {
        cerr.write(names, comma - names) << " = " << to_string_debug(value) << " ";
        print_out(comma + 1, args...);
    } else {
        cerr << names << " = " << to_string_debug(value) << "\n";
    }
}

#endif // DEBUG_H
