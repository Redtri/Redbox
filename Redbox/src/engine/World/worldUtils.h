#pragma once

typedef struct Vector
{
    Vector() : x(0.0f), y(0.0f), z(0.0f) {};
    Vector(float t_xyz) : x(t_xyz), y(t_xyz), z(t_xyz) {};
    Vector(float t_x, float t_y, float t_z) : x(t_x), y(t_y), z(t_z) {};

    float x;
    float y;
    float z;
} Vector;
