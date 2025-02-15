# OpenGL Project Example

best way to lean OpenGL : ```https://learnopengl.com```



## CAMERA

### Cách chuyển sang tọa độ camera và dùng phép chiếu

```C++
void useCameraMatrix(GLuint view_location, GLuint projection_location)
```

lấy view và projection loc từ shader, gọi hàm này trước khi draw object

### Thay đổi vị trí camera

```C++
void setCamPos(vec4 position)
```