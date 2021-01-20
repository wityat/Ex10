// Copyright 2020 A.SHT
#include "MyStack.h"
#include "postfix.h"



std::string infix2postfix(std::string infix) {
    std::map<char, int> priority = {
            {'(', 0},
            {')', 1},
            {'+', 2},
            {'-', 2},
            {'*', 3},
            {'/', 3},
    };
    std::string postfix;
    MyStack<char> stack(1000);
    for ( auto ch:infix ) {
        if (ch == ' ')
            continue;
        if (priority.find(ch) == priority.end()) {
            postfix += ch;
            postfix += ' ';
        } else {
            if (priority[ch] == 0 ||
                stack.isEmpty() ||
                priority[ch] > priority[stack.get()]) {
                stack.push(ch);
            } else {
                while (!stack.isEmpty() &&
                        priority[ch] <= priority[stack.get()]) {
                    postfix += stack.pop();
                    postfix += ' ';
                }
                if (priority[stack.get()] == 0)
                    stack.pop();
                if (priority[ch] != 1)
                    stack.push(ch);
            }
        }
    }
    while (!stack.isEmpty()) {
        postfix += stack.pop();
        postfix += ' ';
    }

    return postfix;
}
