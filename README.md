# OpenGL Project Example

best way to lean OpenGL : ```https://learnopengl.com```


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

## INPUT

#### Keyboard

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