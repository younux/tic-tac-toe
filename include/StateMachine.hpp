//
// Created by Younes on 21/01/2018.
//

#pragma once

#include <memory>
#include <stack>

#include "State.hpp"


namespace Younux {

    typedef std::unique_ptr<State> StateRef;

    class StateMachine{
    public:
        StateMachine() {}
        ~StateMachine() {}

        void AddState(StateRef newState, bool isReplacinng = true);
        void RemoveState();

        void ProcessStateChanges();

        StateRef& GetActiveState();

    private:
        std::stack<StateRef> _states;
        StateRef _newState;

        bool _isRemoving;
        bool _isAdding;
        bool _isReplacing;


    };

}