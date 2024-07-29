#include <Object.h>

#pragma once

class PhysicsObject : Object {
private:
    // physics data

    /// @brief The object's velocity (meters per second)
    vec3 velocity;
    /// @brief The object's acceleration (meters per second squared)
    vec3 acceleration;
    /// @brief The object's angular velocity (radians per second)
    vec3 angularVelocity;
    /// @brief The object's angular acceleration (radians per second squared)
    vec3 angularAcceleration;
    /// @brief The object's mass (kilograms)
    float mass;
    /// @brief The object's drag. Not true drag, but rather a coefficient that scales
    /// a force in the opposite direction of the object's velocity.
    float drag;
    /// @brief The object's angular drag. Not true drag, but rather a coefficnent that scales
    /// a force in the opposite direction of the object's angular velocity.
    float angularDrag;
    /// @brief The object's coefficient of static friction.
    float staticFriction;
    /// @brief The object's coefficient of kinetic friction.
    float kineticFriction;
    /// @brief The object's coefficient of restitution.
    float restitution;

public:
    void PhysicsUpdate();
};