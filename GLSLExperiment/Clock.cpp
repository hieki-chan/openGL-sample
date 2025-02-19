//Chương trình vẽ 1 hình lập phương đơn vị theo mô hình lập trình OpenGL hiện đại

#include "Angel.h"  /* Angel.h là file tự phát triển (tác giả Prof. Angel), có chứa cả khai báo includes glew và freeglut*/


// remember to prototype
void generateGeometry( void );
void initGPUBuffers( void );
void shaderSetup( void );
void display( void );
void keyboard( unsigned char key, int x, int y );


typedef vec4 point4;
typedef vec4 color4;
using namespace std;

// Số các đỉnh của các tam giác
const int NumPoints = 36;

point4 points[NumPoints]; /* Danh sách các đỉnh của các tam giác cần vẽ*/
color4 colors[NumPoints]; /* Danh sách các màu tương ứng cho các đỉnh trên*/


point4 vertices[8]; /* Danh sách 8 đỉnh của hình lập phương*/
color4 vertex_colors[8]; /*Danh sách các màu tương ứng cho 8 đỉnh hình lập phương*/

GLuint program, model_loc;
mat4 model,
	model_obj,
	model_x;
	 
GLfloat l=0,
		r=0;
GLfloat xx = 0,
		yy = 0,
		zz = 0,
		aa = 0;
void initCube()
{
	// Gán giá trị tọa độ vị trí cho các đỉnh của hình lập phương
	vertices[0] = point4(-0.5, -0.5, 0.5, 1.0);
	vertices[1] = point4(-0.5, 0.5, 0.5, 1.0);
	vertices[2] = point4(0.5, 0.5, 0.5, 1.0);
	vertices[3] = point4(0.5, -0.5, 0.5, 1.0);
	vertices[4] = point4(-0.5, -0.5, -0.5, 1.0);
	vertices[5] = point4(-0.5, 0.5, -0.5, 1.0);
	vertices[6] = point4(0.5, 0.5, -0.5, 1.0);
	vertices[7] = point4(0.5, -0.5, -0.5, 1.0);

	// Gán giá trị màu sắc cho các đỉnh của hình lập phương	
	vertex_colors[0] = color4(0.0, 0.0, 0.0, 1.0); // black
	vertex_colors[1] = color4(1.0, 0.0, 0.0, 1.0); // red
	vertex_colors[2] = color4(1.0, 1.0, 0.0, 1.0); // yellow
	vertex_colors[3] = color4(0.0, 1.0, 0.0, 1.0); // green
	vertex_colors[4] = color4(0.0, 0.0, 1.0, 1.0); // blue
	vertex_colors[5] = color4(1.0, 0.0, 1.0, 1.0); // magenta
	vertex_colors[6] = color4(1.0, 1.0, 1.0, 1.0); // white
	vertex_colors[7] = color4(0.0, 1.0, 1.0, 1.0); // cyan
}
int Index = 0;
void quad(int a, int b, int c, int d)  /*Tạo một mặt hình lập phương = 2 tam giác, gán màu cho mỗi đỉnh tương ứng trong mảng colors*/
{
	colors[Index] = vertex_colors[a]; points[Index] = vertices[a]; Index++;
	colors[Index] = vertex_colors[b]; points[Index] = vertices[b]; Index++;
	colors[Index] = vertex_colors[c]; points[Index] = vertices[c]; Index++;
	colors[Index] = vertex_colors[a]; points[Index] = vertices[a]; Index++;
	colors[Index] = vertex_colors[c]; points[Index] = vertices[c]; Index++;
	colors[Index] = vertex_colors[d]; points[Index] = vertices[d]; Index++;
}
void makeColorCube(void)  /* Sinh ra 12 tam giác: 36 đỉnh, 36 màu*/
{
	quad(1, 0, 3, 2);
	quad(2, 3, 7, 6);
	quad(3, 0, 4, 7);
	quad(6, 5, 1, 2);
	quad(4, 5, 6, 7);
	quad(5, 4, 0, 1);
}
void generateGeometry( void )
{
	initCube();
	makeColorCube();
}


void initGPUBuffers( void )
{
	// Tạo một VAO - vertex array object
	GLuint vao;
    glGenVertexArrays( 1, &vao );     
    glBindVertexArray( vao );

    // Tạo và khởi tạo một buffer object
    GLuint buffer;
    glGenBuffers( 1, &buffer );
    glBindBuffer( GL_ARRAY_BUFFER, buffer );
    glBufferData( GL_ARRAY_BUFFER, sizeof(points)+sizeof(colors), NULL, GL_STATIC_DRAW );

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(points), points);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(points), sizeof(colors), colors); 
	
}


void shaderSetup( void )
{
	// Nạp các shader và sử dụng chương trình shader
    program = InitShader( "vshader1.glsl", "fshader1.glsl" );   // hàm InitShader khai báo trong Angel.h
    glUseProgram( program );

    // Khởi tạo thuộc tính vị trí đỉnh từ vertex shader
    GLuint loc_vPosition = glGetAttribLocation( program, "vPosition" );
	glEnableVertexAttribArray( loc_vPosition );
    glVertexAttribPointer(loc_vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );

	GLuint loc_vColor = glGetAttribLocation(program, "vColor");
	glEnableVertexAttribArray(loc_vColor);
	glVertexAttribPointer(loc_vColor, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(points)));

	model_loc = glGetUniformLocation(program, "Model");
	glEnable(GL_DEPTH_TEST);
    
	glClearColor( 1.0, 1.0, 1.0, 1.0 );        /* Thiết lập màu trắng là màu xóa màn hình*/
}
void VeHinhLapPhuong(mat4 _kichthuoc, mat4 _matrix) {
	glUniformMatrix4fv(model_loc, 1, GL_TRUE, model * model_obj* _matrix * _kichthuoc);
	glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}
void bagio() {
	VeHinhLapPhuong(Scale(0.01, 0.05, 0.01), Translate(-0.03, 0, -0.2 + -0.02));
	VeHinhLapPhuong(Scale(0.01, 0.05, 0.01), Translate(-0.03, 0, -0.2 + 0.));
	VeHinhLapPhuong(Scale(0.01, 0.05, 0.01), Translate(-0.03, 0, -0.2 + 0.02));
}
void muoihaigio() {
	VeHinhLapPhuong(Scale(0.01, 0.05, 0.01), Translate(-0.03, 0.2, -0.04));
	VeHinhLapPhuong(Scale(0.01, 0.05, 0.01), Translate(-0.03, 0.2, -0.02));
	VeHinhLapPhuong(Scale(0.01, 0.06, 0.01), Translate(-0.03, 0.2, +0.02) * RotateX(45));
	VeHinhLapPhuong(Scale(0.01, 0.06, 0.01), Translate(-0.03, 0.2, +0.02) * RotateX(-45));
}
void saugio() {
	VeHinhLapPhuong(Scale(0.01, 0.05, 0.01), Translate(-0.03, -0.2, -0.03));
	VeHinhLapPhuong(Scale(0.01, 0.05, 0.01), Translate(-0.03, -0.2, 0) * RotateX(-30));
	VeHinhLapPhuong(Scale(0.01, 0.05, 0.01), Translate(-0.03, -0.2, 0.02) * RotateX(30));
}
void chingio() {
	VeHinhLapPhuong(Scale(0.01, 0.05, 0.01), Translate(-0.03, 0, 0.2 + 0.02));
	VeHinhLapPhuong(Scale(0.01, 0.06, 0.01), Translate(-0.03, 0, 0.2 - 0.02) * RotateX(45));
	VeHinhLapPhuong(Scale(0.01, 0.06, 0.01), Translate(-0.03, 0, 0.2 - 0.02) * RotateX(-45));
}
void kimgio() {
	VeHinhLapPhuong(Scale(0.01, 0.12, 0.01), Translate(-0.03, 0.06, 0));
}
void kimphut() {
	VeHinhLapPhuong(Scale(0.01, 0.17, 0.01), Translate(-0.03, 0.085, 0));
}
void kimgiay() {
	VeHinhLapPhuong(Scale(0.01, 0.15, 0.01), Translate(-0.03, 0.075, 0));
}
void sogio() {
	bagio();
	muoihaigio();
	saugio();
	chingio();
}
void Tron(GLint aa, GLfloat x,GLfloat y, GLfloat z) {
	mat4 instance = Scale(0.05, 0.5, 0.5) * RotateX(aa);
	glUniformMatrix4fv(model_loc, 1, GL_TRUE, model * instance);
	glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}
void MatDongHo() {
	for (int i = 0; i < 180; i++) {
		Tron(i, 0.05, 0.5, 0.5);
	}
}
GLfloat kim_giay_quay = 0;
GLfloat kim_gio_quay = 0;
GLfloat kim_phut_quay = 0;
#include <ctime>
void dongho() {
	//Mặt đồng hồ
	MatDongHo();

	time_t now = time(0);
	tm* timeinfo = localtime(&now);
	int hour = timeinfo->tm_hour;
	int min = timeinfo->tm_min;
	int sec = timeinfo->tm_sec;

	sogio();
	mat4 tmp = model;
	kim_giay_quay = 360.0 * sec / 60;
	kim_phut_quay = 360.0 * min / 60 + kim_giay_quay / 60;
	kim_gio_quay = 360.0 * hour / 12 + kim_phut_quay / 12;
	model = tmp * RotateX(-kim_giay_quay);
	kimgiay();
	model = tmp * RotateX(-kim_phut_quay);
	kimphut();
	model = tmp * RotateX(-kim_gio_quay);
	kimgio();
}


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	model = model *  RotateZ(-30) * RotateY(-45) * RotateZ(10);
	model_obj = RotateX(20) * Translate(xx,yy,zz);
	dongho();
	glutSwapBuffers();
}
void keyboard( unsigned char key, int x, int y )
{
	// keyboard handler

	switch (key) {
	case 033:			// 033 is Escape key octal value
		exit(1);		// quit program
		break;
	case 'x':
		xx++;
		break;
	case 'y':
		yy++;
		break;
	case 'z':
		zz++;
		break;
	}
}


int main( int argc, char **argv )
{
	// main function: program starts here

    glutInit( &argc, argv );                       
    glutInitDisplayMode( GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowSize( 640, 640 );                 
	glutInitWindowPosition(100,150);               
    glutCreateWindow( "Drawing a Cube" );            

   
	glewInit();										

    generateGeometry( );                          
    initGPUBuffers( );							   
    shaderSetup( );                               

    glutDisplayFunc( display );                   
    glutKeyboardFunc( keyboard );                  

	glutMainLoop();
    return 0;
}
