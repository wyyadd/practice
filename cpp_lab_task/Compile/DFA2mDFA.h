//
// Created by wyyadd on 12/15/21.
//

#ifndef COMPILE_DFA2mDFA_H
#define COMPILE_DFA2mDFA_H

#include <utility>
#include <vector>
#include <set>
#include "NFA2DFA.h"

namespace Lexical {
    using std::vector;
    using std::set;
    using std::stack;

    struct mDFA {
        int state_;
        bool dead = true;
        bool infiniteLoop = false;
        vector<std::pair<char, mDFA*>> links_;
    };

    struct Group {
        set<int> member_;
    };

    class DFA2mDFA {
    public:
        explicit DFA2mDFA(vector<DFA *> DFA, set<char> charSet);

        void GenerateGroup();

        bool DivideGroup(Group *g, char c, stack<Group *> &s);

        void Generate_mDFA();

        int getGroupState(int s);

        void ReduceRedundancy(mDFA *start);

        void CacheInfiniteLoop();

        void Show_mDFA();

        bool Check(const std::string& s);

        bool walkThroughDFA(const std::string &s, int po, mDFA *m_dfa);


    private:
        const vector<DFA *> DFA_;
        const set<char> charSet_;
        vector<Group *> Group_;
        vector<mDFA *> mDFA_;
        mDFA *entry = nullptr;
        mDFA *exit = nullptr;
    };
}
#endif //COMPILE_DFA2mDFA_H
