#version 460 core
layout(location = 0) out vec3 FragColor;

in vec4 ourColor;
in vec2 TexCoord;

uniform sampler2D ourTexture;

void main()
{
    FragColor = texture(ourColor, TexCoord);
}