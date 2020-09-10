//
//                 __  __            __           
//                / / / /__  __ ____/ /_____ ____ 
//               / /_/ // / / // __  // ___// __ \
//              / __  // /_/ // /_/ // /   / /_/ /
//             /_/ /_/ \__, / \__,_//_/    \____/ 
//                    /____/                      
//
//              The Hydro Programming Language
//

#include "Engine.hpp"

namespace hydro::engine
{
Engine::Engine()
{
    mDocument = nullptr;
    mActive = false;
    mCommandChain = new CommandChain{};
    mInterpreter = new Interpreter{mCommandChain};
}

Engine::~Engine()
{
    delete mInterpreter;
    delete mCommandChain;
}

void Engine::start()
{
    if(mActive || !mDocument)
        return; // already active or document not initialized
    
    mActive = true;

    while (mActive)
        if(!mPaused)
            run();
}

void Engine::stop()
{
    if(!mActive)
        return;
    mActive = mPaused = false;
    mInterpreter->kill();
}

void Engine::pause()
{
    if(!mActive || mPaused)
        return;
    mPaused = true;
    mInterpreter->pause();
}

void Engine::resume()
{
    if(mPaused)
    {
        mPaused = false;
        //mInterpreter->resume();
    }
}

void Engine::run()
{
    if (!mCommandChain->isEmpty())
        return;

    // pipeline

    // phase 1: validation

    // phase 2: allocation

    // phase 3: emulation
    mInterpreter->run();

    // phase 4: output

    // phase 5: free memory
}

} // namespace hydro::engine
