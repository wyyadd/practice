//
// Created by wyyadd on 11/29/21.
//

#ifndef COMPILE_RE2NFA_H
#define COMPILE_RE2NFA_H

#include <string>
#include <unordered_map>
#include <vector>
#include <stack>

namespace Lexical {
    using std::string;
    using std::unordered_map;
    using std::vector;
    using std::pair;


    // NFA node
    struct NFA {
        explicit NFA(int state) {
            state_ = state;
        }

        // 节点状态
        int state_;
        // 该节点指向位置 char->弧上的值，int->指向节点状态
        vector<std::pair<char, int>> links_;
        // epsilon 指向节点
        vector<int> epsilon_;
    };

    // NFA set
    struct NFASet {
        explicit NFASet(NFA *n, char c) {
            NFAs_head.emplace_back(std::make_pair(c, n));
            NFAs_tail = n;
        }

        // 指向该NFA集合头部所有NFA
        std::vector<std::pair<char, NFA *>> NFAs_head;
        // NFA集合的尾部
        NFA *NFAs_tail;
    };

    class Re2NFA {
    public:
        explicit Re2NFA(string regex);

        // 正则表达式前缀转后缀
        void Infix2Suffix();

        // 由后缀正则表达式转成NFA
        void GenerateNFA();

        void ShowNFA();

    private:

        // 预处理正则表达式: 在第一位是操作数、‘*’或‘)’且第二位是操作数或‘(’之间加入连接符‘&’
        static string PreprocessInfixRegex(string &regex);

        // stack的top两个元素串行合并
        static void LinkNFA(std::stack<NFASet> &stack);

        vector<NFA *> nfa_;
        string infix_regex_;
        string suffix_regex_;
        unordered_map<char, int> in_stack_priority_;
        unordered_map<char, int> in_coming_priority_;

    };

}// namespace Lexical

#endif //COMPILE_RE2NFA_H