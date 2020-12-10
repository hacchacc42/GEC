#pragma once

// If Windows and not in Debug, this will run without a console window
// You can use this to output information when debugging using cout or cerr
#ifdef WIN32 
	#ifndef _DEBUG
		#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
	#endif
#endif

// Just need to include main header file
#include "S2D/S2D.h"

// Reduces the amount of typing by including all classes in S2D namespace
using namespace S2D;

// Declares the Pacman class which inherits from the Game class.
// This allows us to overload the Game class methods to help us
// load content, draw and update our game.
class Pacman : public Game
{
private:
	// Data to represent Pacman
	Vector2* _pacmanPosition;
	Rect* _pacmanSourceRect;
	Texture2D* _pacmanTexture;
	int _pacmanDirection;
	int _pacmanCurentFrame;

	// Data to represent Munchie
	Rect* _munchieSourceRect;
	Texture2D* _munchieBlueTexture;
	Vector2* _muchiePosition;
	// Position for String
	Vector2* _stringPosition;

	//Screen Size & fps
	int square = 32;
	int width = 20*square;
	int height = 20*square;
	int frameRate = 24;//Must be a multiple of 6
	int _frameCount;
	int frameS = frameRate / 6;

	// Pacman Stats
	//Speed of Pacman
	float pacmanSpeed = 0.5f;

	// Data for Menu
	Texture2D* _menuBackground;
	Rect* _menuRectangle;
	Vector2* _menuStringPosition;
	bool _paused;
	bool _start;

	//Check if certian keys are pressed
	bool _pKeyDown;
	bool _qKeyDown;
	bool _eKeyDown;

	// Data to represent Blocks
	Vector2* _blockPosition;
	Rect* _blockSourceRect;
	Texture2D* _blockTexture;

	//Data to represent chery
	Vector2* _cherryPosition;
	Rect* _cherrySourceRect;
	Texture2D* _cherryTexture;

	//Data to represent the funky
	Vector2* _fP;
	Rect* _fSR;
	Texture2D* _fT;
public:
	/// <summary> Constructs the Pacman class. </summary>
	Pacman(int argc, char* argv[]);

	/// <summary> Destroys any data associated with Pacman class. </summary>
	virtual ~Pacman();

	/// <summary> All content should be loaded in this method. </summary>
	void virtual LoadContent();

	/// <summary> Called every frame - update game logic here. </summary>
	void virtual Update(int elapsedTime);

	/// <summary> Called every frame - draw game here. </summary>
	void virtual Draw(int elapsedTime);
	void DrawMap();
};