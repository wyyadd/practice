#include <iostream>
#include "Re2NFA.h"
#include "NFA2DFA.h"
#include "DFA2mDFA.h"

int main() {
//    Lexical::Re2NFA re2Nfa("(a|b)*(aa|bb)(a|b)*");
    Lexical::Re2NFA re2Nfa("(a|b*)(aa|bb)(a|b)*a(b|c)d*");
//    Lexical::Re2NFA re2Nfa("ab*cd*");
//
    printf("\n-----------------step 1 regex to NFA ---------------------\n");
    re2Nfa.Infix2Suffix();
    re2Nfa.GenerateNFA();
    re2Nfa.ShowNFA();
    printf("\n-----------------step 2 NFA to DFA ---------------------\n");
    Lexical::NFA2DFA nfa2Dfa(re2Nfa.getNfa(),re2Nfa.getCharSet());
    nfa2Dfa.GenerateDFA();
    nfa2Dfa.ShowDFA();
    printf("\n-----------------step 3 DFA to mDFA ---------------------\n");
    Lexical::DFA2mDFA dfa2MDfa(nfa2Dfa.getDFA(),re2Nfa.getCharSet());
    dfa2MDfa.GenerateGroup();
    dfa2MDfa.Generate_mDFA();
    dfa2MDfa.Show_mDFA();
    printf("\n-----------------step 4 Test ---------------------\n");
    int choice = 0;
    while (true){
        printf("0进行判断操作，-1退出, 请输入:");
        scanf("%d",&choice);
        if(choice == -1)
            break;
        printf("请输入判断字符串:");
        std::string s;
        std::cin >> s;
        if(dfa2MDfa.Check(s))
            printf("满足\n");
        else
            printf("不满足\n");
    }
    return 0;
}
