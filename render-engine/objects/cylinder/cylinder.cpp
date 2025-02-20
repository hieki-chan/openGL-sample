#include "objects/cylinder.h"
#include "core/camera.h"
#include "core/lighting.h"

const int CYLINDER_SIDES = 256;
const int CYLINDER_VERTEX_COUNT = CYLINDER_SIDES * 6 + CYLINDER_SIDES * 3 * 2;

point4 cylinder_points[CYLINDER_VERTEX_COUNT];
point4 cylinder_vertices[CYLINDER_SIDES * 2];
vec3 cylinder_normals[CYLINDER_VERTEX_COUNT];

GLuint cylinder_VAO, cylinder_VBO;

mat4 cylinderModelMatrix;

void createCylinder()
{
    float angleStep = 2.0f * M_PI / CYLINDER_SIDES;
    for (int i = 0; i < CYLINDER_SIDES; i++) {
        float angle = i * angleStep;
        float x = cos(angle) * 0.5f;
        float z = sin(angle) * 0.5f;
        cylinder_vertices[i] = point4(x, 0.5f, z, 1.0f);
        cylinder_vertices[i + CYLINDER_SIDES] = point4(x, -0.5f, z, 1.0f);
    }
}

int cylinderr_index = 0;
void cylinder_quad(int a, int b, int c, int d)
{
    vec4 u = cylinder_vertices[b] - cylinder_vertices[a];
    vec4 v = cylinder_vertices[c] - cylinder_vertices[b];
    vec3 normal = normalize(cross(u, v));
    cylinder_normals[cylinderr_index] = normal; cylinder_points[cylinderr_index] = cylinder_vertices[a]; cylinderr_index++;
    cylinder_normals[cylinderr_index] = normal; cylinder_points[cylinderr_index] = cylinder_vertices[b]; cylinderr_index++;
    cylinder_normals[cylinderr_index] = normal; cylinder_points[cylinderr_index] = cylinder_vertices[c]; cylinderr_index++;
    cylinder_normals[cylinderr_index] = normal; cylinder_points[cylinderr_index] = cylinder_vertices[a]; cylinderr_index++;
    cylinder_normals[cylinderr_index] = normal; cylinder_points[cylinderr_index] = cylinder_vertices[c]; cylinderr_index++;
    cylinder_normals[cylinderr_index] = normal; cylinder_points[cylinderr_index] = cylinder_vertices[d]; cylinderr_index++;
}

void makeCylinder()
{
    for (int i = 0; i < CYLINDER_SIDES; i++) {
        int next = (i + 1) % CYLINDER_SIDES;
        cylinder_quad(i, next, next + CYLINDER_SIDES, i + CYLINDER_SIDES);
    }
    vec3 topNormal = vec3(0.0f, 1.0f, 0.0f);
    point4 topCenter = point4(0.0f, 0.5f, 0.0f, 1.0f);
    for (int i = 0; i < CYLINDER_SIDES; i++) {
        int next = (i + 1) % CYLINDER_SIDES;
        cylinder_normals[cylinderr_index] = topNormal; cylinder_points[cylinderr_index] = topCenter; cylinderr_index++;
        cylinder_normals[cylinderr_index] = topNormal; cylinder_points[cylinderr_index] = cylinder_vertices[i]; cylinderr_index++;
        cylinder_normals[cylinderr_index] = topNormal; cylinder_points[cylinderr_index] = cylinder_vertices[next]; cylinderr_index++;
    }
    vec3 bottomNormal = vec3(0.0f, -1.0f, 0.0f);
    point4 bottomCenter = point4(0.0f, -0.5f, 0.0f, 1.0f);
    for (int i = 0; i < CYLINDER_SIDES; i++) {
        int next = (i + 1) % CYLINDER_SIDES;
        cylinder_normals[cylinderr_index] = bottomNormal; cylinder_points[cylinderr_index] = bottomCenter; cylinderr_index++;
        cylinder_normals[cylinderr_index] = bottomNormal; cylinder_points[cylinderr_index] = cylinder_vertices[next + CYLINDER_SIDES]; cylinderr_index++;
        cylinder_normals[cylinderr_index] = bottomNormal; cylinder_points[cylinderr_index] = cylinder_vertices[i + CYLINDER_SIDES]; cylinderr_index++;
    }
}

void initCylinderBuffers()
{
    cylinder_VAO = initVAO();
    cylinder_VBO = initVBO(sizeof(cylinder_points) + sizeof(cylinder_normals), cylinder_points, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(cylinder_points), sizeof(cylinder_normals), cylinder_normals);
    GLuint cylinder_program = engine::defaultShader.program;
    GLuint loc_vPos = glGetAttribLocation(cylinder_program, "vPosition");
    GLuint loc_vNormal = glGetAttribLocation(cylinder_program, "vNormal");
    glEnableVertexAttribArray(loc_vNormal);
    glVertexAttribPointer(loc_vNormal, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(cylinder_points)));
    glEnableVertexAttribArray(loc_vPos);
    glVertexAttribPointer(loc_vPos, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
}

void initCylinder()
{
    createCylinder();
    makeCylinder();
    initCylinderBuffers();
}

void drawCylinder(const vec3& position, const vec3& rotation, const vec3& scale, const color& mainColor, engine::shader shader)
{
    bind(shader.program, cylinder_VAO);
    useCameraMatrix(shader.vloc, shader.ploc);
    mat4 instance = TRS(position, rotation, scale);
    glUniformMatrix4fv(shader.mloc, 1, GL_TRUE, cylinderModelMatrix * instance);
    setUniformVec4(shader.program, "mainColor", mainColor);
    useLights(shader.program, "lightPosition", "lightColor", "viewPosition", CAM_POS_3);
    glDrawArrays(GL_TRIANGLES, 0, CYLINDER_VERTEX_COUNT);
    unbind();
}

mat4 cylinderTransformMatrix(mat4 matrix)
{
    return cylinderModelMatrix = matrix;
}

mat4 cylinderTransform(const vec3& position, const vec3& rotation, const vec3& scale)
{
    return cylinderModelMatrix = TRS(position, rotation, scale);
}

void cylinderReset()
{
    cylinderModelMatrix = identity();
}
