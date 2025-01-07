#version 460 core

out vec4 FragColor;

flat in vec3 aNormal;

void main()
{
    //FragColor = vec4(1.0, 1.0, 0.0, 1.0);
    FragColor = vec4(1,1,1,1) * (1.4 + (dot(aNormal, vec3(0,0,-1)))) / 2.4;
}