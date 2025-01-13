
struct mesh
{
	float* vertices;
	float* vertexColors;
	
public:
	mesh(float* vertices, float* vertexColors) : vertices(vertices), vertexColors(vertexColors)
	{
	}
};