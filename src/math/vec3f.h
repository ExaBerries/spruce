#pragma once
#include <iostream>

namespace spruce {
    struct vec3f {
        float x;
        float y;
        float z;
    };

    void log(vec3f& vector);
}
