attribute vec3 position;
uniform mat4 projectionMatrix;
uniform mat4 modelViewMatrix;
void main()
{
    gl_Position = projectionMatrix * vec4(position, 1.0);
}
