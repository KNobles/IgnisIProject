#ifndef STATEMACHINE_H
#define STATEMACHINE_H
#include "State.h"
#include <memory>
#include <stack>

typedef std::unique_ptr<State> stateRef;

class StateMachine
{
    public:
        StateMachine();
        virtual ~StateMachine();

        void addState(stateRef newState, bool isReplacing = true);
        void removeState();

        void processStateChanges();

        stateRef &getActiveState();

    protected:

    private:
        std::stack<stateRef> _states;
        stateRef _newState;
        bool _isRemoving;
        bool _isAdding;
        bool _isReplacing;
};

#endif // STATEMACHINE_H
