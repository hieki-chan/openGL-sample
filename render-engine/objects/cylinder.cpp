#include "objects/cylinder.h"

#include "core/camera.h"
#include "core/lighting.h"

#include<iostream>

// Số đỉnh: Mỗi mặt bên của hình trụ là 1 quad (2 tam giác) → 6 đỉnh; có 16 mặt bên
const int CYLINDER_SIDES = 16;
const int CYLINDER_VERTEX_COUNT = CYLINDER_SIDES * 6;

// Mảng dữ liệu hình học
point4 cylinder_points[CYLINDER_VERTEX_COUNT];
point4 cylinder_vertices[CYLINDER_SIDES * 2];  // 16 đỉnh trên + 16 đỉnh dưới = 32 đỉnh
vec3 cylinder_normals[CYLINDER_VERTEX_COUNT];

// Shader và các biến liên quan
GLuint cylinder_program;
GLuint cylinder_mloc, cylinder_vloc, cylinder_ploc;
GLuint cylinder_VAO, cylinder_VBO;

mat4 cylinderModelMatrix;

// Hàm tạo các đỉnh cho hình trụ (chỉ tạo phần mặt bên)
void createCylinder()
{
    float angleStep = 2.0f * M_PI / CYLINDER_SIDES;
    for (int i = 0; i < CYLINDER_SIDES; i++) {
        float angle = i * angleStep;
        float x = cos(angle) * 0.5f;
        float z = sin(angle) * 0.5f;
        // Đỉnh trên (y = 0.5)
        cylinder_vertices[i] = point4(x, 0.5f, z, 1.0f);
        // Đỉnh dưới (y = -0.5)
        cylinder_vertices[i + CYLINDER_SIDES] = point4(x, -0.5f, z, 1.0f);
    }
}

int cylinderr_index = 0;
void cylinder_quad(int a, int b, int c, int d)
{
    // Tính vector cạnh và normal cho mặt hiện tại
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
    // Với mỗi cạnh của vòng tròn, tạo 1 quad (mặt bên)
    for (int i = 0; i < CYLINDER_SIDES; i++) {
        int next = (i + 1) % CYLINDER_SIDES;
        cylinder_quad(i, next, next + CYLINDER_SIDES, i + CYLINDER_SIDES);
    }
}

// Khởi tạo các buffer và shader
void initCylinderBuffers()
{
    // Tạo vertex array object
    cylinder_VAO = initVAO();

    // Tạo vertex buffer object, truyền dữ liệu points và sau đó normals
    cylinder_VBO = initVBO(sizeof(cylinder_points) + sizeof(cylinder_normals), cylinder_points, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(cylinder_points), sizeof(cylinder_normals), cylinder_normals);

    // Khởi tạo shader program
    cylinder_program = InitShader("objects/cube/cube_vshader.glsl", "objects/cube/cube_fshader.glsl");

    // Lấy vị trí attribute và thiết lập các pointer
    GLuint loc_vPos = glGetAttribLocation(cylinder_program, "vPosition");
    GLuint loc_vNormal = glGetAttribLocation(cylinder_program, "vNormal");

    glEnableVertexAttribArray(loc_vNormal);
    glVertexAttribPointer(loc_vNormal, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(cylinder_points)));

    glEnableVertexAttribArray(loc_vPos);
    glVertexAttribPointer(loc_vPos, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

    // Lấy uniform locations cho các ma trận chuyển đổi
    cylinder_mloc = glGetUniformLocation(cylinder_program, "model");
    cylinder_vloc = glGetUniformLocation(cylinder_program, "view");
    cylinder_ploc = glGetUniformLocation(cylinder_program, "projection");

    glEnable(GL_DEPTH_TEST);

    glUseProgram(cylinder_program);
}

void initCylinder()
{
    createCylinder();
    makeCylinder();
    initCylinderBuffers();
}

// Hàm vẽ hình trụ, sử dụng các ma trận camera và model
void drawCylinder(vec3 position, vec3 rotation, vec3 scale, color mainColor)
{
    // Gắn shader và VAO
    bind(cylinder_program, cylinder_VAO);

    // Sử dụng ma trận camera (hàm useCameraMatrix được định nghĩa ở nơi khác)
    useCameraMatrix(cylinder_vloc, cylinder_ploc);

    // Tính ma trận model cho instance hiện tại
    mat4 instance = TRS(position, rotation, scale);
    glUniformMatrix4fv(cylinder_mloc, 1, GL_TRUE, cylinderModelMatrix * instance);

    // Set màu cho đối tượng
    setUniformVec4(cylinder_program, "mainColor", mainColor);

    // Thiết lập thông số ánh sáng: vị trí, màu và vị trí camera (CAM_POS_3 được định nghĩa ở nơi khác)
    useLights(cylinder_program, "lightPosition", "lightColor", "viewPosition", CAM_POS_3);

    // Vẽ hình trụ
    glDrawArrays(GL_TRIANGLES, 0, CYLINDER_VERTEX_COUNT);

    // Giải phóng binding
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

