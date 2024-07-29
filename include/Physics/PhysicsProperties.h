#include <glm/glm.hpp>

#pragma once

using namespace glm;

/// @brief Gravity constant vector
const vec3 GRAVITY = vec3(0.0f, -9.81f, 0.0f); 
/// @brief Air resistance constant vector
const vec3 AIR_RESISTANCE = vec3(0.0f, 0.0f, 0.0f);
/// @brief Vaccuum permittivity constant
const float VACUUM_PERMITTIVITY = 8.854187817e-12f;
/// @brief Vacuum permeability constant
const float VACUUM_PERMEABILITY = 1.2566370614e-6f;
/// @brief Speed of light constant
const float SPEED_OF_LIGHT = 299792458.0f;
/// @brief Electron volt constant (Joules)
const float ELECTRON_VOLT = 1.602176634e-19f;
/// @brief Universal gravitational constant (Meters cubed per kilogram second squared)
const float GRAVITATIONAL_CONSTANT = 6.67430e-11f;