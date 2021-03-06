//
// Created by Younes on 21/01/2018.
//

#pragma once


namespace Younux{
    class State{
    public:
        virtual void Init() = 0;

        virtual void HandleInput() = 0;
        virtual void Update(float dt) = 0;
        virtual void Draw(float dt) = 0;

        virtual void Pause() {}
        virtual  void Resume() {}

    };


}