#include "objects/sphere.h"
#include "core/camera.h"
#include "core/lighting.h"

const int SPHERE_SLICES = 32;
const int SPHERE_STACKS = 32;
const int SPHERE_VERTEX_COUNT = SPHERE_STACKS * SPHERE_SLICES * 6;

point4 sphere_points[SPHERE_VERTEX_COUNT];
vec3 sphere_normals[SPHERE_VERTEX_COUNT];

GLuint sphere_VAO, sphere_VBO;

mat4 sphereModelMatrix;

void createSphere()
{
    int index = 0;
    float dPhi = M_PI / SPHERE_STACKS;
    float dTheta = 2.0f * M_PI / SPHERE_SLICES;
    float radius = 0.5f;
    for (int i = 0; i < SPHERE_STACKS; i++) {
        float phi1 = i * dPhi;
        float phi2 = (i + 1) * dPhi;
        for (int j = 0; j < SPHERE_SLICES; j++) {
            float theta1 = j * dTheta;
            float theta2 = (j + 1) * dTheta;
            point4 A = point4(radius * sin(phi1) * cos(theta1),
                radius * cos(phi1),
                radius * sin(phi1) * sin(theta1),
                1.0f);
            point4 B = point4(radius * sin(phi1) * cos(theta2),
                radius * cos(phi1),
                radius * sin(phi1) * sin(theta2),
                1.0f);
            point4 C = point4(radius * sin(phi2) * cos(theta2),
                radius * cos(phi2),
                radius * sin(phi2) * sin(theta2),
                1.0f);
            point4 D = point4(radius * sin(phi2) * cos(theta1),
                radius * cos(phi2),
                radius * sin(phi2) * sin(theta1),
                1.0f);
            vec3 nA = normalize(vec3(A.x, A.y, A.z));
            vec3 nB = normalize(vec3(B.x, B.y, B.z));
            vec3 nC = normalize(vec3(C.x, C.y, C.z));
            vec3 nD = normalize(vec3(D.x, D.y, D.z));
            sphere_points[index] = A; sphere_normals[index] = nA; index++;
            sphere_points[index] = B; sphere_normals[index] = nB; index++;
            sphere_points[index] = C; sphere_normals[index] = nC; index++;
            sphere_points[index] = A; sphere_normals[index] = nA; index++;
            sphere_points[index] = C; sphere_normals[index] = nC; index++;
            sphere_points[index] = D; sphere_normals[index] = nD; index++;
        }
    }
}

void initSphereBuffers()
{
    sphere_VAO = initVAO();
    sphere_VBO = initVBO(sizeof(sphere_points) + sizeof(sphere_normals), sphere_points, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(sphere_points), sizeof(sphere_normals), sphere_normals);

    GLuint sphere_program = engine::defaultShader.program;

    GLuint loc_vPos = glGetAttribLocation(sphere_program, "vPosition");
    glEnableVertexAttribArray(loc_vPos);
    glVertexAttribPointer(loc_vPos, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    GLuint loc_vNormal = glGetAttribLocation(sphere_program, "vNormal");
    glEnableVertexAttribArray(loc_vNormal);
    glVertexAttribPointer(loc_vNormal, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(sphere_points)));
}

void initSphere()
{
    createSphere();
    initSphereBuffers();
}

void drawSphere(const vec3& position, const vec3& rotation, const vec3& scale, const color& mainColor, engine::shader shader)
{
    bind(shader.program, sphere_VAO);

    useCameraMatrix(shader.vloc, shader.ploc);
    mat4 instance = TRS(position, rotation, scale);
    glUniformMatrix4fv(shader.mloc, 1, GL_TRUE, sphereModelMatrix * instance);
    setUniformVec4(shader.program, "mainColor", mainColor);
    useLights(shader.program, "lightPosition", "lightColor", "viewPosition", CAM_POS_3);
    glDrawArrays(GL_TRIANGLES, 0, SPHERE_VERTEX_COUNT);
    unbind();
}

mat4 sphereTransformMatrix(mat4 matrix)
{
    return sphereModelMatrix = matrix;
}

mat4 sphereTransform(const vec3& position, const vec3& rotation, const vec3& scale)
{
    return sphereModelMatrix = TRS(position, rotation, scale);
}

void sphereReset()
{
    sphereModelMatrix = identity();
}
