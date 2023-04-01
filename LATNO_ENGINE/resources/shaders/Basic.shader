//#shader vertex
//#version 330 core
//
//layout(location = 0) in vec4 position;
//
//
//void main()
//{
//	gl_Position = position;
//};
//
//#shader fragment
//#version 330 core
//
//layout(location = 0) out vec4 color;
//
//
//uniform vec4 u_Color;
//
//void main()
//{
//	color = u_Color;
//};

// TEXTURE RENDERING STUFF BELOW

#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;

out vec2 v_TexCoord;

uniform mat4 u_ModelViewProjectionMatrix;

void main()
{
	gl_Position = u_ModelViewProjectionMatrix * position;
	v_TexCoord = texCoord;
};

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec2 v_TexCoord;

uniform vec4 u_Color;
uniform sampler2D u_Texture;

void main()
{
	vec4 texColor = texture(u_Texture, v_TexCoord);
	color = texColor;
};
