/*
Vertex shader with vertex color
attribute modifier
*/

#version 410 core

//uniform mat4  g_transform_localToWorld;
//uniform mat4  g_transform_worldToView;
//uniform mat4  g_transform_viewToScreen;
//uniform vec4 vertexColorModifier;


//Input
layout(location = 0) in vec3 i_local_position;

//Output
layout(location = 0) out vec3 o_local_texture;

void main()
{
	/*vec4 position_world = vec4(i_local_position, 1.0) * g_transform_localToWorld;
	vec4 position_view = position_world * g_transform_worldToView;
	vec4 screenPosition = position_view * g_transform_viewToScreen;*/
	vec4 screenPosition = vec4(i_local_position, 1);
	gl_Position = screenPosition;	
	vec3 skyBoxTexture = i_local_position.xyz;
	o_local_texture = skyBoxTexture /** vertexColorModifier.xyz*/;
}