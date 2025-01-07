#version 460 core

layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 texCoords;

uniform mat4 model;
uniform mat4 camera;

flat out vec3 aNormal;

void main()
{
    gl_Position = camera * (model * vec4(aPosition, 1.0));
    aNormal = vec3(model * vec4(normal,1));
}