// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"
int prioritet(char ch) {
    switch (ch) {
    case '(':
        return 0;
    case ')':
        return 1;
    case '+':
        return 2;
    case '-':
        return 2;
    case '*':
        return 3;
    case '/':
        return 3;
    default:
        return -1;
    }
}
std::string infx2pstfx(std::string inf)
{
  std::string pstfx;
    int i = 0;
    char ch = inf[i];
    char top = 0;
    TStack <char> stackChar;
    while (ch) {
        int pr;
        pr = prioritet(ch);
        if (pr > -1) {
            if ((pr == 0 || pr > prioritet(top) ||
                stackChar.isEmpty()) && ch != ')') {
                if (stackChar.isEmpty())
                    top = ch;
                stackChar.push(ch);
            } else if (ch == ')') {
                while (stackChar.get() != '(') {
                    pstfx.push_back(stackChar.get());
                    pstfx.push_back(' ');
                    stackChar.pop();
                }
                stackChar.pop();
                if (stackChar.isEmpty())
                    top = 0;
            } else {
                while (!stackChar.isEmpty() &&
                       prioritet(stackChar.get()) >= pr) {
                    pstfx.push_back(stackChar.get());
                    pstfx.push_back(' ');
                    stackChar.pop();
                  }
                if (stackChar.isEmpty())
                    top = ch;
                stackChar.push(ch);
            }
        } else {
            pstfx.push_back(ch);
            pstfx.push_back(' ');
        }
        ch = inf[++i];
    }
    while (!stackChar.isEmpty()) {
        pstfx.push_back(stackChar.get());
        pstfx.push_back(' ');
        stackChar.pop();
    }
    pstfx.erase(pstfx.end() - 1, pstfx.end());
    return pstfx;
}
int calculating(char operation, int n1, int n2) {
    switch (operation) {
    case '+':
        return n1 + n2;
        break;
    case '-':
        return n1 - n2;
        break;
    case '*':
        return n1 * n2;
        break;
    case '/':
        return n1 / n2;
        break;
    }
}


int eval(std::string pst)
{
    TStack <int> stackInt;
    int i = 0, result = 0;
    char ch = pst[i];
    while (ch) {
        if (ch >= '0' && ch <= '9') {
            int insertInt = 0;
            int dec = 1;
            while (ch != ' ') {
                insertInt += (ch - 48) * dec;
                dec *= 10;
                ch = pst[++i];
            }
            stackInt.push(insertInt);
        } else {
            char operation = ch;
            i++;
            int n2 = stackInt.get();
            stackInt.pop();
            int n1 = stackInt.get();
            stackInt.pop();
            int result = calculating(operation, n1, n2);
            stackInt.push(result);
        }
        if (i < pst.size())
            ch = pst[++i];
        else
            ch = 0;
    }
    result = stackInt.get();
    stackInt.pop();
    return result;
}
