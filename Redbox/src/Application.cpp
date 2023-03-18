#include <iostream>
#include "engine/Engine.h"
#include "publicDefinitions.hpp"

int main(void)
{
    cEngine* engine = new cEngine();
    
    if (!engine->startupEngine())
    {
        return -1;
    }

    while (engine->update())
    {
        //LOG("Engine update");
    }

    delete engine;
    return 0;
}