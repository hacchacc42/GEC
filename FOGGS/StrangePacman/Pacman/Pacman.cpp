#include "Pacman.h"
#include <iostream>
using namespace std;
#include <sstream>
#include <stdlib.h>
#include <time.h>

Pacman::Pacman(int argc, char* argv[]) : Game(argc, argv), pacmanSpeed(0.5f)
{
	srand(time(NULL));
	_pacmanCurentFrame = 0;
	_frameCount = 0;
	_paused = false;
	_start = true;
	_pKeyDown = false;
	_eKeyDown = false;
	_qKeyDown = false;
	_pacmanDirection = 0;

	//Initialise important Game aspects
	Graphics::Initialise(argc, argv, this, width, height, false, 25, 25, "Pacman", 60);
	Input::Initialise();

	// Start the Game Loop - This calls Update and Draw in game loop
	Graphics::StartGameLoop();
}

Pacman::~Pacman()
{
	delete _pacmanTexture;
	delete _pacmanSourceRect;

	delete _munchieBlueTexture;
	delete _munchieSourceRect;

	delete _blockTexture;
	delete _blockSourceRect;

	delete _cherryTexture;
	delete _cherrySourceRect;
}
int choice;
void Pacman::LoadContent()
{
	// Set Menu Paramters
	_menuBackground = new Texture2D();
	_menuBackground->Load("Textures/Transparency.png", false);
	_menuRectangle = new Rect(0.0f, 0.0f, width, height);
	_menuStringPosition = new Vector2(width/2-64, height/2-64);

	// Load Pacman
	_pacmanTexture = new Texture2D();
	_pacmanTexture->Load("Textures/Pacman1.png", false);
	_pacmanPosition = new Vector2(100.0f, 100.0f);
	_pacmanSourceRect = new Rect(0.0f, 0.0f, 32, 32);

	// Load Block
	_blockTexture = new Texture2D();
	_blockTexture->Load("Textures/Blocks.png", false);
	_blockPosition = new Vector2(150.0f, 500.0f);
	_blockSourceRect = new Rect(0.0f, 0.0f, 32, 32);
	
	// Load Munchie
	_munchieBlueTexture = new Texture2D();
	_munchieBlueTexture->Load("Textures/Munchie.png", false);
	_muchiePosition = new Vector2(100.0f, 100.0f);
	_munchieSourceRect = new Rect(0.0f, 0.0f, 12, 12);

	// Load Cherry
	_cherryTexture = new Texture2D();
	_cherryTexture->Load("Textures/Cherry.png", false);
	_cherryPosition = new Vector2(20.0f, 500.0f);
	_cherrySourceRect = new Rect(0.0f, 0.0f, 32, 32);

	//Load Funky
	_fT = new Texture2D();
	_fT->Load("Textures/Funky.png", false);
	_fP = new Vector2(400.0f, 500.0f);
	_fSR = new Rect(0.0f, 0.0f, 64, 64);
	// Set string position
	_stringPosition = new Vector2(10.0f, 25.0f);
}

void Pacman::Update(int elapsedTime)
{
	// Gets the current state of the keyboard
	Input::KeyboardState* keyboardState = Input::Keyboard::GetState();
	if (!_paused && !_start)
	{
		// Checks if D key is pressed
		if (keyboardState->IsKeyDown(Input::Keys::D) || keyboardState->IsKeyDown(Input::Keys::RIGHT)) {
			_pacmanPosition->X += pacmanSpeed * elapsedTime; //Moves Pacman across X axis (right)
			_pacmanDirection = 0;
			_pacmanSourceRect->Y = _pacmanSourceRect->Height * _pacmanDirection;
		}
		else if (keyboardState->IsKeyDown(Input::Keys::S) || keyboardState->IsKeyDown(Input::Keys::DOWN)) {
			_pacmanPosition->Y += pacmanSpeed * elapsedTime; //Moves Pacman across Y axis (down)
			_pacmanDirection = 1;
			_pacmanSourceRect->Y = _pacmanSourceRect->Height * _pacmanDirection;

		}
		// Checks if A key is pressed
		else if (keyboardState->IsKeyDown(Input::Keys::A) || keyboardState->IsKeyDown(Input::Keys::LEFT)) {
			_pacmanPosition->X -= pacmanSpeed * elapsedTime; //Moves Pacman across X axis (left)
			_pacmanDirection = 2;
			_pacmanSourceRect->Y = _pacmanSourceRect->Height * _pacmanDirection;
		}
		// Checks if W key is pressed
		else if (keyboardState->IsKeyDown(Input::Keys::W) || keyboardState->IsKeyDown(Input::Keys::UP)) {
			_pacmanPosition->Y -= pacmanSpeed * elapsedTime; //Moves Pacman across Y axis (up)
			_pacmanDirection = 3;
			_pacmanSourceRect->Y = _pacmanSourceRect->Height * _pacmanDirection;
		}
		//reset button
		if (keyboardState->IsKeyDown(Input::Keys::R))
		{
			_start = true;
		}
		//Speeding
	if (keyboardState->IsKeyDown(Input::Keys::Q) && !_qKeyDown) {
		_qKeyDown = true;
		pacmanSpeed -= .1f;
	}
	if (keyboardState->IsKeyUp(Input::Keys::Q))
	{
		_qKeyDown = false;
	}
	if (keyboardState->IsKeyDown(Input::Keys::E) && !_eKeyDown) {
		_eKeyDown = true;
		pacmanSpeed += .1f;
	}
	if (keyboardState->IsKeyUp(Input::Keys::E))
	{
		_eKeyDown = false;
	}
		//Update animation frame
		_frameCount++;
		if (_frameCount >= frameRate)
		{
			_frameCount = 0;
		}	
	}
	if (!_start)
	{
		_menuBackground->Load("Textures/Transparency.png", false);
			// Check If P is pressed
		if (keyboardState->IsKeyDown(Input::Keys::P) && !_pKeyDown)
		{
			_pKeyDown = true;
			_paused = !_paused;
		}
		if (keyboardState->IsKeyUp(Input::Keys::P) )
		{
			_pKeyDown = false;
		}
	}
	if (_start) 
	{
		_menuBackground->Load("Textures/Menu.png", false);
		if ((keyboardState->IsKeyDown(Input::Keys::A))) 
		{
			_pacmanTexture->Load("Textures/Pacman1.png", false);
			_start = false;
			pacmanSpeed = .5f;
		}
		else if ((keyboardState->IsKeyDown(Input::Keys::B)))
		{
			_pacmanTexture->Load("Textures/Pacman2.png", false);
			_start = false;
			pacmanSpeed = .3f;
		}
		else if ((keyboardState->IsKeyDown(Input::Keys::C)))
		{
			_pacmanTexture->Load("Textures/Pacman3.png", false);
			_start = false;
			pacmanSpeed = 1.0f;
		}
		else if ((keyboardState->IsKeyDown(Input::Keys::D)))
		{
			_pacmanTexture->Load("Textures/Pacman4.png", false);
			_start = false;
			pacmanSpeed = .7f;
		}
	}

	

	//Check if Pacman is colliding with any border
	if (_pacmanPosition->X + _pacmanSourceRect->Width > width)
	{
		// Pacman hit right wall - reset his position
		_pacmanPosition->X = 0;
	}
	if (_pacmanPosition->X + _pacmanSourceRect->Width < 0 + _pacmanSourceRect->Width) //0 is the left side of the game
	{
		// Pacman hit left wall - reset his position
		_pacmanPosition->X = width - _pacmanSourceRect->Width;
	}
	if (_pacmanPosition->Y + _pacmanSourceRect->Height > height)
	{
		// Pacman hit upper wall - reset his position
		_pacmanPosition->Y = 0;
	}
	if (_pacmanPosition->Y + _pacmanSourceRect->Height < 0 + _pacmanSourceRect->Height)//0 is the top side of the game
	{
		// Pacman hit bottom wall - reset his position
		_pacmanPosition->Y = height - _pacmanSourceRect->Height;
	}	

}

void Pacman::DrawMap()
{
	SpriteBatch::BeginDraw();
	SpriteBatch::Draw(_blockTexture, _blockPosition, _blockSourceRect);
	for (int i = 0; i < 10; i++)
	{
		SpriteBatch::Draw(_blockTexture, _blockPosition, _blockSourceRect);
		_blockPosition->X += 32;
	}
	SpriteBatch::EndDraw();
}
int testx = 1;
int testyx=1;
int testyy = 1;
void Pacman::Draw(int elapsedTime)
{
	// Allows us to easily create a string
	std::stringstream stream;
	stream << "Pacman X: " << _pacmanPosition->X << " Y: " << _pacmanPosition->Y << endl;
	stream << "Speed :" << pacmanSpeed * 10 << endl;

	SpriteBatch::BeginDraw(); // Starts Drawing
	SpriteBatch::Draw(_fT, _fP, _fSR); //Draws Funky
	SpriteBatch::Draw(_pacmanTexture, _pacmanPosition, _pacmanSourceRect); // Draws Pacman
	SpriteBatch::Draw(_munchieBlueTexture, _muchiePosition, _munchieSourceRect); //Draws Muchie
	SpriteBatch::Draw(_blockTexture, _blockPosition, _blockSourceRect); // Draws Pacman
	SpriteBatch::Draw(_cherryTexture, _cherryPosition, _cherrySourceRect); // Draws Cherry
	// 6 FRAMES / SECOND
	if (!_paused) {
		_blockPosition->Y += testx * 10;
		_fP->Y += testyy * 6;
		_fP->X += testyx * 9;
	}
		if (!_paused) {
			if (_frameCount % 10 == 3) {
				_fSR->Height = 64 + (rand() % 64 - 32);
				_fSR->Width = 64 + (rand() % 64 - 32);
			}
		}
		_fSR -> Y = _fP -> Y;
		_fSR->X = _fP->X;
		if (_blockPosition->Y > height- _blockSourceRect->Height || _blockPosition->Y < 0)
		{
			testx = -testx;
		}
		if (_fP->Y > height - _fSR->Height || _fP->Y < 0)
		{
			testyy = -testyy;
		}
		if (_fP->X > width - _fSR->Width || _fP->X < 0)
		{
			testyx = -testyx;
		}
	if (_frameCount < frameS)
	{
		_munchieSourceRect->X = _munchieSourceRect->Height * 0;
		_pacmanSourceRect->X = _pacmanSourceRect->Height * 0; 
		_blockSourceRect->X = _blockSourceRect->Height * 0;
		_cherrySourceRect->X = _cherrySourceRect->Height * 0;
	}
	else if (_frameCount >= frameS && _frameCount < frameS * 2)
	{
		_pacmanSourceRect->X = _pacmanSourceRect->Height * 1;
		_blockSourceRect->X = _blockSourceRect->Height * 1;
	}
	else if (_frameCount >= frameS * 2 && _frameCount < frameS * 3)
	{
		_pacmanSourceRect->X = _pacmanSourceRect->Height * 2;
		_blockSourceRect->X = _blockSourceRect->Height * 2;
	}
	else if (_frameCount >= frameS * 3 && _frameCount < frameS * 4)
	{
		_munchieSourceRect->X = _munchieSourceRect->Height * 1;
		_pacmanSourceRect->X = _pacmanSourceRect->Height * 3;
		_blockSourceRect->X = _blockSourceRect->Height * 3;
		_cherrySourceRect->X = _cherrySourceRect->Height * 1;
	}
	else if (_frameCount >= frameS * 4 && _frameCount < frameS * 5)
	{
		_pacmanSourceRect->X = _pacmanSourceRect->Height * 2;
		_blockSourceRect->X = _blockSourceRect->Height * 2;
	}
	else {
		_pacmanSourceRect->X = _pacmanSourceRect->Height * 1;
		_blockSourceRect->X = _blockSourceRect->Height * 1;
	}
	// Draws String
	SpriteBatch::DrawString(stream.str().c_str(), _stringPosition, Color::Yellow);
	//PAUSE
	if (_paused)
	{
		std::stringstream menuStream;
		menuStream << "PAUSED!";
		SpriteBatch::Draw(_menuBackground, _menuRectangle, nullptr);
		SpriteBatch::DrawString(menuStream.str().c_str(), _menuStringPosition,Color::Yellow);
	}
	//START
	if (_start)
	{
		std::stringstream menuStream;
		menuStream << "Welcome to Pac Man v5.9 Beta Early Acces" << endl;
		menuStream << "Select your Character:" << endl;
		menuStream << "A.Normal Pac-Man" << endl << "B.Coller Pac-Man" << endl << "C.Ghost Pac-Man" << endl<< "D.Miss Pac - Man" << endl;
		SpriteBatch::Draw(_menuBackground, _menuRectangle, nullptr);
		SpriteBatch::DrawString(menuStream.str().c_str(), _menuStringPosition, Color::Yellow);
	}
	SpriteBatch::EndDraw(); // Ends Drawing
}