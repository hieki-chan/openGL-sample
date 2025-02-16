# OpenGL Project Example

best way to lean OpenGL : ```https://learnopengl.com```


## CREATE AND RENDER A NEW OBJECT

Cách tạo mới 1 object và test object này. Ví dụ tạo 1 object:

1. Để tránh xung đột với master thì nên tạo branch mới

```
git checkout -b test-object
```

2. Tạo file cần thiết ở branch mới

Cần tạo 3 files sau:
- ```object.h``` : header để dùng trong main, thêm vào thư mục ```include/objects```
- ```object.cpp``` : file cpp để code object, thêm vào thư mục ```objects```
- ```test-object.cpp``` : chứa main để render object trong branch này.

object.h

```C++
#pragma once

// include opengl utils
#include "core/openGL.h"

// include file cube neu object duoc dung len tu cube
#include "cube.h"

// ham draw object
void drawObject(vec3 position, vec3 rotation, vec3 scale);
```

object.cpp

```C++
// include file object.h
#include "objects/object.h"

// ham draw object vi du
void drawObject(vec3 position, vec3 rotation, vec3 scale)
{
	drawCube(vec3(), vec3(), vec3(1, 1, 1), color(1, 1, 1, 1));

	drawCube(vec3(1, 1, 1), vec3(), vec3(.2, .2, 3), color(1, 1, 1, 1));
}
```

test-object.cpp

```C++
// day la file chua ham main, vao file main.cpp copy full code sau do uncomment code
// trong do se co ham display

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

	introScreen();  //ui

	drawAxes();     // truc xyz toa do (envỉonment)


	drawObject(vec3(), vec3(), vec3(1, 1, 1));  //goi ham draw object do do day


	glEnable(GL_DEPTH_TEST);

	glutSwapBuffers();
}
```


# CORE

core in render engine

## DEFAULT CUBE

```C++
// dùng cube: core/cube.h
include "objects/cube.h"
```

```C++
// vẽ 1 cube tại position với góc xoay rotation tỉ lệ scale và màu color
// color là typedef vec4
void drawCube(vec3 position, vec3 rotation, vec3 scale, color color);
```

## CAMERA

#### Camera view and Projection

```C++
// camera định nghĩa trong header core/camera.h, triển khai trong core/camera.cpp
include "core/camera.h"
```

```C++
// chuyển sang tọa độ camera và dùng phép chiếu perspective 
// view và projection location từ shader program, gọi hàm này trước khi draw object
void useCameraMatrix(GLuint view_location, GLuint projection_location);
```

#### Camera position

```C++
// thay đổi tọa độ camera (eye)
void setCameraPos(const vec4& position);
```

#### Zoom in/out

```C++
// zoom camera, value > 0 thì phóng to, value < 0 thì thu nhỏ, value = 0 thì không đổi
void zoomCamera(float value);
```

```C++
// set tốc độ zoom
void setZoomSpeed(float zoomSpeed);
```

#### Camera Motion

```C++
// chuyển động của camera xoay quanh gốc tọa độ khi di chuyển chuột
void cameraMotion(int mouseX, int mouseY, int& lastMouseX, int& lastMouseY);
```

## INPUT

#### Keyboard

## ENVIRONMENT

```C++
//init environment
initEnvironment();
//gọi trong hàm display để vẽ trục xyz
drawAxes();
```

## LIGHTING

## UI

```C++
// vẽ text (times new roman) tại tọa độ màn hình (x, y) chiều sâu z
void rasterText(const vec3& viewPort, const char* stringToDisplay);
```