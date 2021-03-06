/*********************************************************************************
 *
 * Inviwo - Interactive Visualization Workshop
 *
 * Copyright (c) 2013-2015 Inviwo Foundation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *********************************************************************************/

#include <inviwo/core/datastructures/light/baselightsource.h>

namespace inviwo {

mat4 getLightTransformationMatrix(vec3 pos, vec3 dir) {
    vec3 A = vec3(0, 0, 1);
    vec3 B = dir;  
    mat4 transformationMatrix;
    // Check if the direction is parallel to the z-axis
    // to avoid division by zero in glm::normalize(glm::cross(A, B)). 
    if (glm::all(glm::lessThan(glm::abs(glm::cross(A, B)), vec3(glm::epsilon<float>())))) {
        // Direction is parallel to z-axis. 
        // Apply rotation by 180 degrees if the direction is along negative z-axis
        float angle = dir.z < 0 ? -static_cast<float>(M_PI) : 0;
        transformationMatrix = glm::translate(pos) * glm::rotate(angle, vec3(0.f, 1.f, 0.f));
    } else {
        float angle = std::acos(glm::dot(A, B));
        vec3 rotationAxis = glm::normalize(glm::cross(A, B));
#ifndef GLM_FORCE_RADIANS
        angle = glm::degrees(angle);
#endif  // GLM_FORCE_RADIANS
        transformationMatrix = glm::translate(pos) * glm::rotate(angle, rotationAxis);
    }
    return transformationMatrix;
}

inviwo::uvec3 LightSource::COLOR_CODE = uvec3(128,64,196);

}
