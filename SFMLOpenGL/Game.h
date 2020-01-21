#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <Vector3.h>
#include <Matrix3.h>
#include <vector>


using namespace std;
//using namespace sf;
//using namespace gpp;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	sf::Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();
	void setUpCube();

	GLuint index;
	sf::Clock clock;
	sf::Time elapsed;

	float rotationAngle = 2.0f;

	Vector3 v{ 1,1,1 };

	Vector3 cubePoints[8]{ {-1.0f, -1.0f, 1.0f},
						{1.0f, -1.0f, 1.0f},
						{1.0f, 1.0f, 1.0f},
						{-1.0f, 1.0f, 1.0f},

						{-1.0f, -1.0f, -1.0f},
						{1.0f, -1.0f, -1.0f},
						{1.0f, 1.0f, -1.0f},
						{-1.0f, 1.0f, -1.0f} };  //8 

	
	Matrix3 matrix;
};