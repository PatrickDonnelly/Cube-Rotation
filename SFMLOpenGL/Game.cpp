#include <Game.h>

bool updatable = false;

//gpp::Vector3 v3;

Game::Game() : window(sf::VideoMode(800, 600), "OpenGL Cube")
{
	index = glGenLists(1);
}

Game::~Game(){}

void Game::run()
{

	initialize();

	sf::Event event;

	while (isRunning){

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	// glNewList(index, GL_COMPILE);
	// Creates a new Display List
	// Initalizes and Compiled to GPU
	// https://www.opengl.org/sdk/docs/man2/xhtml/glNewList.xml
}

void Game::setUpCube()
{
	glNewList(index, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		//Front Face

		glColor3f(0.25f, 0.5f, 1.0f);
		glVertex3f(cubePoints[0].getX(), cubePoints[0].getY(), cubePoints[0].getZ());
		glVertex3f(cubePoints[1].getX(), cubePoints[1].getY(), cubePoints[1].getZ());
		glVertex3f(cubePoints[2].getX(), cubePoints[2].getY(), cubePoints[2].getZ());

		glColor3f(0.3f, 0.6f, 1.0f);
		glVertex3f(cubePoints[2].getX(), cubePoints[2].getY(), cubePoints[2].getZ());
		glVertex3f(cubePoints[3].getX(), cubePoints[3].getY(), cubePoints[3].getZ());
		glVertex3f(cubePoints[0].getX(), cubePoints[0].getY(), cubePoints[0].getZ());

		//Back Face
		glColor3f(1.0f, 0.4f, 0.5f);
		glVertex3f(cubePoints[5].getX(), cubePoints[5].getY(), cubePoints[5].getZ());
		glVertex3f(cubePoints[4].getX(), cubePoints[4].getY(), cubePoints[4].getZ());
		glVertex3f(cubePoints[7].getX(), cubePoints[7].getY(), cubePoints[7].getZ());

		glColor3f(1.0f, 0.25f, 0.4f);
		glVertex3f(cubePoints[7].getX(), cubePoints[7].getY(), cubePoints[7].getZ());
		glVertex3f(cubePoints[6].getX(), cubePoints[6].getY(), cubePoints[6].getZ());
		glVertex3f(cubePoints[5].getX(), cubePoints[5].getY(), cubePoints[5].getZ());

		//Top Face
		glColor3f(0.8f, 0.8f, 0.8f);
		glVertex3f(cubePoints[3].getX(), cubePoints[3].getY(), cubePoints[3].getZ());
		glVertex3f(cubePoints[2].getX(), cubePoints[2].getY(), cubePoints[2].getZ());
		glVertex3f(cubePoints[6].getX(), cubePoints[6].getY(), cubePoints[6].getZ());

		glColor3f(0.6f, 0.6f, 0.6f);
		glVertex3f(cubePoints[6].getX(), cubePoints[6].getY(), cubePoints[6].getZ());
		glVertex3f(cubePoints[7].getX(), cubePoints[7].getY(), cubePoints[7].getZ());
		glVertex3f(cubePoints[3].getX(), cubePoints[3].getY(), cubePoints[3].getZ());

		//Bottom Face
		glColor3f(0.0f, 6.0f, 0.0f);
		glVertex3f(cubePoints[4].getX(), cubePoints[4].getY(), cubePoints[4].getZ());
		glVertex3f(cubePoints[5].getX(), cubePoints[5].getY(), cubePoints[5].getZ());
		glVertex3f(cubePoints[1].getX(), cubePoints[1].getY(), cubePoints[1].getZ());

		glColor3f(0.0f, 8.0f, 0.3f);
		glVertex3f(cubePoints[1].getX(), cubePoints[1].getY(), cubePoints[1].getZ());
		glVertex3f(cubePoints[0].getX(), cubePoints[0].getY(), cubePoints[0].getZ());
		glVertex3f(cubePoints[4].getX(), cubePoints[4].getY(), cubePoints[4].getZ());

		//Left Face
		glColor3f(0.7f, 0.6f, 0.5f);
		glVertex3f(cubePoints[4].getX(), cubePoints[4].getY(), cubePoints[4].getZ());
		glVertex3f(cubePoints[0].getX(), cubePoints[0].getY(), cubePoints[0].getZ());
		glVertex3f(cubePoints[3].getX(), cubePoints[3].getY(), cubePoints[3].getZ());

		glColor3f(0.8f, 0.4f, 0.45f);
		glVertex3f(cubePoints[3].getX(), cubePoints[3].getY(), cubePoints[3].getZ());
		glVertex3f(cubePoints[7].getX(), cubePoints[7].getY(), cubePoints[7].getZ());
		glVertex3f(cubePoints[4].getX(), cubePoints[4].getY(), cubePoints[4].getZ());

		//Right Face
		glColor3f(0.65f, 1.0f, 0.8f);
		glVertex3f(cubePoints[1].getX(), cubePoints[1].getY(), cubePoints[1].getZ());
		glVertex3f(cubePoints[5].getX(), cubePoints[5].getY(), cubePoints[5].getZ());
		glVertex3f(cubePoints[6].getX(), cubePoints[6].getY(), cubePoints[6].getZ());

		glColor3f(0.5f, 0.9f, 0.9f);
		glVertex3f(cubePoints[6].getX(), cubePoints[6].getY(), cubePoints[6].getZ());
		glVertex3f(cubePoints[2].getX(), cubePoints[2].getY(), cubePoints[2].getZ());
		glVertex3f(cubePoints[1].getX(), cubePoints[1].getY(), cubePoints[1].getZ());
	}
	glEnd();
	glEndList();
}

void Game::update()
{
	elapsed = clock.getElapsedTime();
	setUpCube();

	Matrix3 translationMatrix;
	Matrix3 scalerMatrix;
	Matrix3 rotationMatrix;

	if (elapsed.asSeconds() >= 1.0f / 60)
	{
		clock.restart();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		{
			for (int i = 0; i < 8; i++)
			{
				cubePoints[i] = rotationMatrix.rotationX(rotationAngle) * cubePoints[i];
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
		{
			for (int i = 0; i < 8; i++)
			{
				cubePoints[i] = rotationMatrix.rotationY(rotationAngle) * cubePoints[i];
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			for (int i = 0; i < 8; i++)
			{
				cubePoints[i] = rotationMatrix.rotationZ(rotationAngle) * cubePoints[i];
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			translationMatrix = translationMatrix.translation(-0.2f, 0.0f);
			for (int i = 0; i < 8; i++)
			{
				cubePoints[i] = translationMatrix * cubePoints[i];
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			translationMatrix = translationMatrix.translation(0.2f, 0.0f);
			for (int i = 0; i < 8; i++)
			{
				cubePoints[i] = translationMatrix * cubePoints[i];
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			translationMatrix = translationMatrix.translation(0.0f, -0.2f);
			for (int i = 0; i < 8; i++)
			{
				cubePoints[i] = translationMatrix * cubePoints[i];
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			translationMatrix = translationMatrix.translation(0.0f, 0.2f);
			for (int i = 0; i < 8; i++)
			{
				cubePoints[i] = translationMatrix * cubePoints[i];
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			scalerMatrix = scalerMatrix.Scale3D(101);
			for (int i = 0; i < 8; i++)
			{
				cubePoints[i] = scalerMatrix * cubePoints[i];
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			scalerMatrix = scalerMatrix.Scale3D(99);
			for (int i = 0; i < 8; i++)
			{
				cubePoints[i] = scalerMatrix * cubePoints[i];
			}
		}
	}
}

void Game::draw()
{
	//cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//cout << "Drawing Cube " << endl;
	glLoadIdentity();
	//glRotatef(rotationAngle, 0, 0, 1); // Rotates the camera on Y Axis
	glTranslatef(0, 0, -8.0f);
	glCallList(1);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

