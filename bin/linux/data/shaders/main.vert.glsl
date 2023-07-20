#version 400

layout(location=0) in vec3 vertices;

uniform mat4 u_proj;
uniform mat4 u_view;
uniform mat4 u_model;


void main() {
    gl_Position = u_proj * u_view * u_model * vec4(vertices, 1.0);
}