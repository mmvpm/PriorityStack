#include <algorithm>
#include <cassert>
#include <string>

#include "PriorityStack.hpp"

void test_right_priority() {
    std::vector<std::pair<int, int>> test_queries = {
        // {priority, value}
        {2, 1},
        {5, 6},
        {4, 3},
        {3, 5},
        {1, 2},
    };

    PriorityStack<int> stack;
    for (auto &i : test_queries) {
        stack.Push(i.first, i.second);
    }

    sort(test_queries.begin(), test_queries.end(), std::greater<>());
    for (auto &i : test_queries) {
        int actual = stack.Pop();
        int expected = i.second;
        assert(actual == expected);
    }
}

void test_right_order() {
    std::vector<int> test_queries = {1, 2, 3, 4, 5, 6};

    PriorityStack<int> stack;
    for (int i = (int) test_queries.size() - 1; i >= 0; --i) {
        stack.Push(0, test_queries[i]);
    }
    for (auto &expected: test_queries) {
        int actual = stack.Pop();
        assert(actual == expected);
    }
}

void test_string_type() {
    std::vector<std::pair<int, std::string>> test_queries = {
        // {priority, value}
        {5, "1"},
        {4, "6"},
        {4, "7"},
        {3, "3"},
        {3, "5"},
    };
    std::vector<std::pair<int, std::string>> test_answers = {
        // {priority, value}
        {5, "1"},
        {4, "7"},
        {4, "6"},
        {3, "5"},
        {3, "3"},
    };

    PriorityStack<std::string> stack;
    for (auto &i : test_queries) {
        stack.Push(i.first, i.second);
    }
    for (auto &expected: test_answers) {
        std::string actual = stack.Pop();
        assert(actual == expected.second);
    }
}

void test_empty() {
    PriorityStack<int> stack;
    assert(stack.IsEmpty() == true);

    stack.Push(0, 0);
    assert(stack.IsEmpty() == false);
}

void test_clear() {
    PriorityStack<int> stack;
    assert(stack.IsEmpty() == true);

    stack.Push(0, 0);
    assert(stack.IsEmpty() == false);

    stack.Clear();
    assert(stack.IsEmpty() == true);
}

int main() {
    test_right_priority();
    test_right_order();
    test_string_type();
    test_empty();
    test_clear();

    return 0;
}
