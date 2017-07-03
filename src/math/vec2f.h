#pragma once

#include <stdio.h>

namespace spruce {
    struct vec2f {
        float x;
        float y;
    };
    
    void log(vec2f& vector);
}
