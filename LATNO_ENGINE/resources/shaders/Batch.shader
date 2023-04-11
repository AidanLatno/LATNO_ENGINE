#shader vertex
#version 450 core

layout(location = 0) in vec3 a_Position;
//layout(location = 1) in vec4 a_Color;

uniform mat4 u_ViewProj;
uniform mat4 u_Transform;



void main()
{
	//v_Color = a_Color;
	gl_Position = u_ViewProj * u_Transform * vec4(a_Position, 1.0);
};

#shader fragment
#version 450 core

layout(location = 0) out vec4 o_Color;

//in vec4 v_Color;

//uniform vec4 u_Color;
//uniform sampler2D u_Texture;

void main()
{
	//vec4 texColor = texture(u_Texture, v_TexCoord);
	//o_Color = v_Color;
	o_Color = vec4(1.0);
};
