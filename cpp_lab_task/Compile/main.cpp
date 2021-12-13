#include <iostream>
#include "Re2NFA.h"

int main() {
    Lexical::Re2NFA re2Nfa("(a|b)*(aa|bb)(a|b)*");
    printf("\n-----------------step 1 regex to NFA ---------------------\n");
    re2Nfa.Infix2Suffix();
    re2Nfa.GenerateNFA();
    re2Nfa.ShowNFA();
    printf("\n-----------------step 2 NFA to DFA ---------------------\n");

    return 0;
}
