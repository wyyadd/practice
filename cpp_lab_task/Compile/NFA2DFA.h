//
// Created by wyyadd on 12/13/21.
//

#ifndef COMPILE_NFA2DFA_H
#define COMPILE_NFA2DFA_H

#include <utility>
#include <vector>
#include <unordered_map>
#include <set>
#include "Re2NFA.h"


namespace Lexical {
    using std::vector;
    using std::set;

    struct DFA {
        explicit DFA(int state) {
            state_ = state;
        }

        int state_;
        bool acceptable = false;
        vector<std::pair<char, int>> links_;
    };

    struct D_state {
        D_state(std::set<int> NFAStates, int state) {
            NFAStates_ = std::move(NFAStates);
            state_ = state;
        }

        std::set<int> NFAStates_;
        int state_;
    };

    class NFA2DFA {
    public:
        explicit NFA2DFA(vector<NFA *> nfa, set<char> charSet);

        void GenerateDFA();

        std::set<int> e_closure(NFA *nfa);

        std::set<int> e_closure(const std::vector<NFA *> &T);

        std::vector<NFA *> Move(const std::set<int> &T, char c);

        int Get_DStates(const std::set<int> &states);

        void ShowDFA();

        vector<DFA*> getDFA();

    private:
        const vector<NFA *> nfa_;
        const std::set<char> charSet_;
        vector<D_state *> D_states_;
        vector<DFA *> D_tran_;
    };

}

#endif //COMPILE_NFA2DFA_H
