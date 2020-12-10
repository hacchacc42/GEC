#include "Pacman.h"
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iomanip>
Pacman::Pacman(int argc, char* argv[]) : Game(argc, argv)
{
	timeBegin = 60 * 90;
	begin = false;//For powerups
	srand(time(NULL));
	isColliding = false;
	level = 0;
	_pacman = new Player();
	_pacman->canEatGhost = false;
	_pacman->lives = 3;
	for (int i = 0; i < MUCHIECOUNT; i++)
	{
		_munchie[i] = new Atributes();
	}
	for (int i = 0; i < BLOCKCOUNT; i++)
	{
		_blocks[i] = new Atributes();
	}
	for (int i = 0; i < GHOSTCOUNT; i++)
	{
		_ghost[i] = new Enemy();
		_ghost[i]->speedMultiplier = 1.0f;
		_eyes[i] = new Atributes();
	}
	_cherry = new Atributes();
	_map = new Atributes();
	for (int i = 0; i < 4; i++)
	{
		_charColider[i] = new Atributes();

		_powerUps[i] = new Atributes();
	}
	pointsMultiplier = 1.0f;
	_sellect = new Atributes();
	//Buttons
	_startB = new Button();
	_leaderB = new Button();
	_characterB = new Button();
	_quitB = new Button();
	//Default Pacman Stats
	_pacman->direction = 0;
	_pacman->speed = .225f;
	_pacman->speedMultiplier = 1.0f;
	_pacman->character = 0;
	_frameCount = 0;
	_paused = false;
	_highscore = false;
	_start = true;
	_charSelect = false;
	_pKeyDown = false;
	_wKeyDown = false;
	_sKeyDown = false;
	//SOUND
	//Initialise audio
	Audio::Initialise();
	if (!Audio::IsInitialised())
	{
		cout << "NO AUDIO" << endl;
	}
	//Initialise important Game aspects
	Graphics::Initialise(argc, argv, this, width, height, false, 25, 25, "Pacman", 60);
	Input::Initialise();
	// Start the Game Loop - This calls Update and Draw in game loop
	Graphics::StartGameLoop();
}


Pacman::~Pacman()
{
	delete _pop;
	delete _intro;
	delete _ghostS;
	delete _rip;

	delete _pacman->texture;
	delete _pacman->sourceRect;
	delete _pacman;

	for (int i = 0; i < MUCHIECOUNT; i++)
	{
		delete _munchie[i]->texture;
		delete _munchie[i]->sourceRect;
		delete _munchie[i];
	}
	for (int i = 0; i < BLOCKCOUNT; i++)
	{
		delete _blocks[i]->texture;
		delete _blocks[i]->sourceRect;
		delete _blocks[i];
	}
	for (int i = 0; i < 4; i++)
	{
		delete _charColider[i]->texture;
		delete _charColider[i]->sourceRect;
		delete _charColider[i];

		delete _powerUps[i]->texture;
		delete _powerUps[i]->sourceRect;
		delete _powerUps[i];
		
		delete _ghost[i]->texture;
		delete _ghost[i]->sourceRect;
		delete _ghost[i];

		delete _eyes[i]->texture;
		delete _eyes[i]->sourceRect;
		delete _eyes[i];
	}
	delete _cherry->texture;
	delete _cherry->sourceRect;
	delete _cherry;

	delete _map->texture;
	delete _map->sourceRect;
	delete _map;
}

//Load Content
void Pacman::LoadContent()
{
	//Audio
	_pop = new SoundEffect();
	if (!_pop->Load("Audio/pop.wav"))
	{
		cout << "Failed to load" << endl;
	}
	if (!_pop->IsLoaded())
	{
		cout << "POP MISING" << endl;
	}

	_intro = new SoundEffect();
	if (!_intro->Load("Audio/intro.wav"))
	{
		cout << "Failed to load" << endl;
	}
	if (!_intro->IsLoaded())
	{
		cout << "INTRO MISING" << endl;
	}

	_ghostS = new SoundEffect();
	if (!_ghostS->Load("Audio/ghost.wav"))
	{
		cout << "Failed to load" << endl;
	}
	if (!_ghostS->IsLoaded())
	{
		cout << "GHOST MISING" << endl;
	}

	_rip = new SoundEffect();
	if (!_rip->Load("Audio/rip.wav"))
	{
		cout << "Failed to load" << endl;
	}
	if (!_rip->IsLoaded())
	{
		cout << "GHOST MISING" << endl;
	}
	//Ghost
	Texture2D* ghostTex = new Texture2D();
	ghostTex->Load("Textures/Ghosts.png", false);
	for (int i = 0; i < GHOSTCOUNT; i++)
	{
		_ghost[i]->texture = ghostTex;
		_ghost[i]->sourceRect = new Rect(0.0f,32.0f+ 32.0f*i, 32.0f, 32.0f);
		_ghost[i]->position = new Vector2(400.0f, 100.0f*i);
		_ghost[i]->speed = .2f;
		_ghost[i]->direction = 0;

		_eyes[i]->texture = ghostTex;
		_eyes[i]->sourceRect = new Rect(0.0f, 160.0f, 32.0f, 16.0f);
		_eyes[i]->position = new Vector2(400.0f, 100.0f * i);
	}

	// Set Menu Paramters
	_menuBackground = new Texture2D();
	_menuBackground->Load("Textures/MenuTest.png", false);

	_menu2Background = new Texture2D();
	_menu2Background->Load("Textures/MenuTest1.png", false);

	_charBackground = new Texture2D();
	_charBackground->Load("Textures/CharSelect.png", false);

	_highScoreBackground = new Texture2D();
	_highScoreBackground->Load("Textures/MenuTest.png", false);

	_menuRectangle = new Rect(0.0f, 0.0f, width, height);
	_menuStringPosition = new Vector2(186.0f, 500.0f);

	//Char Select + power ups
	_sellect->texture = new Texture2D();
	_sellect->texture->Load("Textures/Select.png", false);
	_sellect->sourceRect = new Rect(0.0f, 0.0f, 24.0f, 39.0f);
	_sellect->position = new Vector2(180.0f, 222.0f);

	Texture2D* colectableTex = new Texture2D();
	colectableTex->Load("Textures/Collectables.png", false);
	for (int i = 0; i < 4; i++)
	{
		_charColider[i]->sourceRect = new Rect(0.0f, 0.0f, 226.0f, 226.0f);

		_powerUps[i]->texture = colectableTex;
		_powerUps[i]->sourceRect = new Rect(0.0f, 0.0f, 24.0f, 24.0f);
		_powerUps[i]->position = new Vector2(-100.0f, -100.0f);
	}
	_charColider[0]->position = new Vector2(48.0f ,220.0f);
	_charColider[1]->position = new Vector2(352.0f,220.0f);
	_charColider[2]->position = new Vector2(48.0f ,544.0f);
	_charColider[3]->position = new Vector2(352.0f,544.0f);


	// Load Pacman
	_pacman->texture = new Texture2D();
	_pacman->texture->Load("Textures/Pacman.png", false);
	_pacman->position = new Vector2(100.0f, 100.0f);
	_pacman->sourceRect = new Rect(0.0f, 0.0f, 32.0f, 32.0f);
	
	//Load Map
	_map->texture = new Texture2D();
	_map->texture->Load("Textures/Map.png", false);
	_map->position = new Vector2(0.0f, 100.0f);
	_map->sourceRect = new Rect(0.0f, 0.0f, 608, 704);

	//Load Blocks
	Texture2D* blockTex = new Texture2D();
	blockTex->Load("Textures/BlockTest.png", false);
	for (int i = 0; i < BLOCKCOUNT; i++)
	{
		_blocks[i]->texture = blockTex;
		_blocks[i]->sourceRect = new Rect(0.0f, 0.0f, 20.0f, 20.0f);
	}
	for (int i = 0, j = 0; i < 418; i++)
	{
		if (map[i] == 2)
		{
			_blocks[j]->position = new Vector2(32.0f * (i % 19), 32.0f * (i / 19) + 32 * 3);
			j++;
		}
	}
	// Load _munchies
	Texture2D* munchieTex = new Texture2D();
	munchieTex->Load("Textures/munchie.png", false);
	for (int i = 0; i < MUCHIECOUNT; i++)
	{
		_munchie[i]->texture = munchieTex;
		_munchie[i]->sourceRect = new Rect(0.0f, 0.0f, 12.0f, 12.0f);
	}
	for (int i = 0, k = 0; i < 418; i++)
	{
		if (map[i] == 1)
		{
			_munchie[k]->position = new Vector2(32.0f * (i % 19) + 11, 32.0f * (i / 19) + 32 * 3 + 14);
			k++;
		}
	}

	// Load Cherry
	_cherry->texture = new Texture2D();
	_cherry->texture->Load("Textures/Cherry.png", false);
	_cherry->position = new Vector2(20.0f, 500.0f);
	_cherry->sourceRect = new Rect(0.0f, 0.0f, 32, 32);

	// Load Buttons
	_buttonsTexture = new Texture2D();
	_buttonsTexture->Load("Textures/menu.png", false);
	//Start Button
	_startB->position= new Vector2(186.0f, 446.0f);
	_startB->sourceRect = new Rect(0.0f, 0.0f, 237.0f, 80.0f);
	//Controls Button
	_leaderB->position = new Vector2(186.0f, 554.0f);
	_leaderB->sourceRect = new Rect(0.0f, 0.0f, 237.0f, 80.0f);
	//Character Selection Button
	_characterB->position = new Vector2(186.0f, 662.0f);
	_characterB->sourceRect = new Rect(0.0f, 0.0f, 237.0f, 80.0f);
	//Quit button
	_quitB->position = new Vector2(186.0f, 770.0f);
	_quitB->sourceRect = new Rect(0.0f, 0.0f, 237.0f, 80.0f);


	// Set string position
	_stringPosition = new Vector2(10.0f, 25.0f);
}

//Reseting all of the buttons to the original form.
void Pacman::ResetAllButtons()
{
	_startB->sourceRect->Y = 0;
	_leaderB->sourceRect->Y = 0;
	_characterB->sourceRect->Y = 0;
	_quitB->sourceRect->Y = 0;
}

void Pacman::UpdateGhost(Enemy* ghost,Atributes* eyes, int elapsedTime)
{
	float ghostspeed = ghost->speed * elapsedTime * ghost->speedMultiplier * pow(1.2, level);
	if (ghost->direction == 0) //Moves Right 
	{
		eyes->sourceRect->X = 0.0f;
		ghost->position->X += ghostspeed;
	}
	else if (ghost->direction == 1) //Moves Left 
	{
		eyes->sourceRect->X = 64.0f;
		ghost->position->X -= ghostspeed;
	}
	else if (ghost->direction == 2)
	{
		eyes->sourceRect->X = 32.0f; //Moves Down
		ghost->position->Y += ghostspeed;
	}
	else
	{
		eyes->sourceRect->X = 96.0f; //Moves Up
		ghost->position->Y -= ghostspeed;
	}

	if (ghost->position->X + ghost->sourceRect->Width >=
		width-32.0f) //Hits Right edge 
	{
		ghost->direction = 1; //Change direction 
	}
	else if (ghost->position->X <= 32.0f) //Hits left edge 
	{
		ghost->direction = 0; //Change direction 
	}
	if (ghost->position->Y <= 32.0f*4)
	{
		ghost->direction = 2;
	}
	else if(ghost->position->Y>=height-32.0f*6)
	{
		if (ghost->position->Y >= height - 32.0f * 4)
		{
		}
		else
		{
			ghost->direction = 3;
		}
	}
	eyes->position->X = ghost->position->X;
	eyes->position->Y = ghost->position->Y;
}
//Menu Function
void Pacman::MenuScreen(Input::KeyboardState* state)
{
	//Buton Navigation
	if (state->IsKeyDown(Input::Keys::W)&& !_wKeyDown)
	{
		_wKeyDown = true;
		if (_menuSelection > 0)
		{
			_menuSelection--;
		}
	}
	else if (state->IsKeyDown(Input::Keys::S) && !_sKeyDown)
	{
		_sKeyDown = true;
		if (_menuSelection < 3)
		{
			_menuSelection++;
		}
	}
	if (state->IsKeyUp(Input::Keys::W))
	{
		_wKeyDown=false;
	}
	if (state->IsKeyUp(Input::Keys::S))
	{
		_sKeyDown = false;
	}
	if (state->IsKeyDown(Input::Keys::SPACE))
	{
		if (_menuSelection == 0)
		{
			_pacman->lives = 3;
			level = 0;
			points = 0;
			NewLevel(level,false);
		}
		else if (_menuSelection == 1)
		{
			_charSelect = false;
			_highscore = true;
			_start = false;
		}
		else if (_menuSelection == 2)
		{
			CharSelect();
		}
		else if (_menuSelection == 3)
		{
			exit(42);
		}
	}
	switch (_menuSelection)
	{
	case 0:
		ResetAllButtons();
		_startB->sourceRect->Y = 83.0f;
		break;
	case 1:
		ResetAllButtons();
		_leaderB->sourceRect->Y = 83.0f;
		break;
	case 2:
		ResetAllButtons();
		_characterB->sourceRect->Y = 83.0f;
		break;
	case 3:
		ResetAllButtons();
		_quitB->sourceRect->Y = 83.0f;
		break;
	}
}

//Character Selection Screen
void Pacman::CharSelect()
{
	_highscore = false;
	_charSelect = true;
	_start = false;
}

//Check the timer
void Pacman::Timer()
{
	timeleft--;
	if (timeleft == 0)
	{
		_start = true;
	}
}

//Selection for char select
void Pacman::Selection(float posx, float posy, float pMult, float speed, const char texture[])
{
	Input::MouseState* mouseState = Input::Mouse::GetState();
	_sellect->position->X = posx;
	_sellect->position->Y = posy;
	if (mouseState->LeftButton == Input::ButtonState::PRESSED)
	{
		pointsMultiplier = pMult;
		_pacman->speed = speed;
		_pacman->texture->Load(texture, false);
		_start = true;
		_charSelect = false;
	}
}
//For the char select menu
void Pacman::CharCollision()
{
	if (_charSelect)
	{
		Input::MouseState* mouseState = Input::Mouse::GetState();
		for (int i = 0; i < 4; i++)
		{
			if (CheckCollision(_charColider[i]->position->X, _charColider[i]->position->Y, _charColider[i]->sourceRect->Width, _charColider[i]->sourceRect->Height,
				mouseState->X, mouseState->Y, 10, 10))
			{
				switch (i)
				{
				case 0:
					//Normal pacman
					Selection(180.0f, 222.0f, 1.0f, .225f, "Textures/Pacman.png");
					break;
				case 1:
					//Miss pacman
					Selection(484.0f, 222.0f, 0.9f, .25f, "Textures/PacmanMiss.png");
					break;
				case 2:
					//Ghost
					Selection(180.0f, 547.0f, 0.8f, .3f, "Textures/PacmanGhost.png");
					break;
				case 3:
					//Mr cool
					Selection(484.0f, 547.0f, 1.1f, .2f, "Textures/PacmanCool.png");
					break;
				}
			}
		}
	}
}

//Ghost Collision
void Pacman::GhostCollision()
{
	for (int i = 0; i < GHOSTCOUNT; i++)
	{
		if (CheckCollision(_ghost[i]->position->X, _ghost[i]->position->Y, _ghost[i]->sourceRect->Width, _ghost[i]->sourceRect->Height,
			_pacman->position->X, _pacman->position->Y, _pacman->sourceRect->Width, _pacman->sourceRect->Height))
		{
			if (_pacman->canEatGhost)
			{
				_ghost[i]->position->X = -1000;
				if (i == 1)
				{
					_ghost[i]->position->Y = 7 * 32 - 3;
				}
				else if (i == 2)
				{
					_ghost[i]->position->Y = 7 * 32 - 3;
				}
				else if(i==3)
				{
					_ghost[i]->position->Y = 23 * 32 ;
				}
				else 
				{
					_ghost[i]->position->Y = 23 * 32;
				}
				Audio::Play(_ghostS);
				points += 1500 * pointsMultiplier* pow(1.2, level);
			}
			else 
			{
				if (_pacman->lives > 1)
				{
					_pacman->lives--;
					NewLevel(level, true);
				}
				else if(_pacman->lives==1)
				{
					sorting();
					_start = false;
					_highscore = true;
					_pacman->lives--;
				}
			}
		}
	}
}

//Munchie COllision
void Pacman::MunchieCollision()
{
	for (int i = 0; i < MUCHIECOUNT; i++)
	{
		if (CheckCollision(_munchie[i]->position->X, _munchie[i]->position->Y, _munchie[i]->sourceRect->Width, _munchie[i]->sourceRect->Height,
			_pacman->position->X, _pacman->position->Y, _pacman->sourceRect->Width, _pacman->sourceRect->Height))
		{
			Audio::Play(_pop);
			_munchie[i]->position->X = -100;
			_munchie[i]->position->Y = -100;
			points += 100 * pointsMultiplier* pow(1.2, level);
			munchieLeft--;
		}
	}
	if (munchieLeft == 0)
	{
		for (int i = 0; i < timeleft / 60; i++)
		{
			points += 150;
		}
		for (int i = 0; i < GHOSTCOUNT; i++)
		{
			_ghost[i]->sourceRect->X = 32 * i + 32;
		}
		if (level == 2)
		{
			sorting();
			_start = false;
			_charSelect = false;
			_highscore = true;
			level++;
		}
		else
		{
			NewLevel(level++, false);
		}
	}
}

//PowerUp Collision
void Pacman::PowerUpCollision()
{
	for (int c = 0; c < 4; c++)
	{
		if (CheckCollision(_powerUps[c]->position->X, _powerUps[c]->position->Y, _powerUps[c]->sourceRect->Width, _powerUps[c]->sourceRect->Height,
			_pacman->position->X, _pacman->position->Y, _pacman->sourceRect->Width, _pacman->sourceRect->Height))
		{
			_powerUps[c]->position->X = -100;
			_powerUps[c]->position->Y = -100;
			points += 500;
			stopTime1(timeleft);
		}
	}
}

//Wall Collision
void Pacman::WallCollision()
{
	for (int i = 0; i < BLOCKCOUNT; i++)
	{
		if (CheckCollision(_blocks[i]->position->X, _blocks[i]->position->Y, _blocks[i]->sourceRect->Width, _blocks[i]->sourceRect->Height,
			_pacman->position->X, _pacman->position->Y, _pacman->sourceRect->Width, _pacman->sourceRect->Height))
		{
			switch (_pacman->direction)
			{
				// (D) Right
			case 0:
				_pacman->position->X = _blocks[i]->position->X - _pacman->sourceRect->Width - 3;
				break;
				// (S) Down
			case 1:
				_pacman->position->Y = _blocks[i]->position->Y - _pacman->sourceRect->Height - 3;
				break;
				// (A) Left
			case 2:
				_pacman->position->X = _blocks[i]->position->X + _pacman->sourceRect->Width - 8;
				break;
				// (W) Up
			case 3:
				_pacman->position->Y = _blocks[i]->position->Y + _pacman->sourceRect->Height - 8;
				break;
			}
		}
	}
}

//Include all colision
void Pacman::Collisions()
{
	//For the char select menu
	CharCollision();
	//Ghost Collision
	GhostCollision();
	//Munchie Collision
	MunchieCollision();
	//PowerUp Collision
	PowerUpCollision();
	//Wall Collision
	WallCollision();
}

//Codie Method with other objects
bool Pacman::CheckCollision(int x1, int y1, int width1, int height1,
	int x2, int y2, int width2, int height2)
{
	int left1 = x1;
	int left2 = x2;
	int right1 = x1 + width1;
	int right2 = x2 + width2;
	int top1 = y1;
	int top2 = y2;
	int bottom1 = y1 + height1;
	int bottom2 = y2 + height2;
	//Checking for colision

	if (bottom1 < top2)
	{
		return false;
	}
	if (top1 > bottom2)
	{
		return false;
	}
	if (right1 < left2)
	{
		return false;
	}
	if (left1 > right2)
	{
		return false;
	}

	return true;
}

//Check if Pacman is colliding with any border
void Pacman::BorderCollision()
{
	if (_pacman->position->X + _pacman->sourceRect->Width > width)
	{
		// Pacman hit right wall - reset his position
		_pacman->position->X = 0;
	}
	if (_pacman->position->X + _pacman->sourceRect->Width < 0 + _pacman->sourceRect->Width) //0 is the left side of the game
	{
		// Pacman hit left wall - reset his position
		_pacman->position->X = width - _pacman->sourceRect->Width;
	}
	if (_pacman->position->Y + _pacman->sourceRect->Height > height - 57)
	{
		// Pacman hit upper wall - reset his position
		_pacman->position->Y = 57;
	}
	if (_pacman->position->Y + _pacman->sourceRect->Height < 57 + _pacman->sourceRect->Height)//57 is the top side of the game
	{
		// Pacman hit bottom wall - reset his position
		_pacman->position->Y = height - _pacman->sourceRect->Height - 57;
	}
}

//Check for player movement input
void Pacman::Input(int elapsedTime, Input::KeyboardState* state)
{
	float pacmanSpeed = _pacman->speed * elapsedTime * _pacman->speedMultiplier;
	// Checks if D key is pressed
	if (state->IsKeyDown(Input::Keys::D) || state->IsKeyDown(Input::Keys::RIGHT)) {
		_pacman->position->X += pacmanSpeed; //Moves Pacman across X axis (right)
		_pacman->direction = 0;
		_pacman->sourceRect->Y = _pacman->sourceRect->Height * _pacman->direction;
	}
	// Checks if S key is pressed
	else if (state->IsKeyDown(Input::Keys::S) || state->IsKeyDown(Input::Keys::DOWN)) {
		_pacman->position->Y += pacmanSpeed; //Moves Pacman across Y axis (down)
		_pacman->direction = 1;
		_pacman->sourceRect->Y = _pacman->sourceRect->Height * _pacman->direction;

	}
	// Checks if A key is pressed
	else if (state->IsKeyDown(Input::Keys::A) || state->IsKeyDown(Input::Keys::LEFT)) {
		_pacman->position->X -= pacmanSpeed; //Moves Pacman across X axis (left)
		_pacman->direction = 2;
		_pacman->sourceRect->Y = _pacman->sourceRect->Height * _pacman->direction;
	}
	// Checks if W key is pressed
	else if (state->IsKeyDown(Input::Keys::W) || state->IsKeyDown(Input::Keys::UP)) {
		_pacman->position->Y -= pacmanSpeed; //Moves Pacman across Y axis (up)
		_pacman->direction = 3;
		_pacman->sourceRect->Y = _pacman->sourceRect->Height * _pacman->direction;
	}
	//reset button
	if (state->IsKeyDown(Input::Keys::R))
	{
		_start = true;
	}

}

//Setting the atributes for a new level/game
void Pacman::NewLevel(int lvl,bool dead)
{
	//Ghost new
	for (int i = 0; i < GHOSTCOUNT; i++)
	{
		_eyes[i]->sourceRect->Y = 5 * 32.0f;
		_ghost[i]->sourceRect->Y = 32.0f * i + 32.0f;
		_ghost[i]->speedMultiplier = 1.0f;
	}
	//Light blue - Left
	_ghost[0]->position->X = 4 * 32.0f;
	_ghost[0]->position->Y = 4 * 32.0f;
	_ghost[0]->direction = 2;
	//Orange - Right
	_ghost[1]->position->X = 14 * 32.0f;
	_ghost[1]->position->Y = 21 * 32.0f;
	_ghost[1]->direction =3;
	//Pink - Top
	_ghost[2]->position->Y = 7 * 32.0f;
	_ghost[2]->position->X = 1 * 32.0f;
	_ghost[2]->direction = 0;
	//Red - Bot
	_ghost[3]->position->Y = 23 * 32.0f;
	_ghost[3]->position->X = 16 * 32.0f;
	_ghost[3]->direction = 1;
	begin = false;
	_pacman->canEatGhost = false;
	_pacman->speedMultiplier = 1.0f;
	_start = false;
	if (!dead)
	{
		Audio::Play(_intro);
		timeleft = 60 * 100;
		munchieLeft = MUCHIECOUNT;
		//DRAW MAP
		for (int i = 0, k = 0, j = 0, c = 0; i < 418; i++)
		{
			if (map[i] == 1)
			{
				_munchie[k]->position = new Vector2(32.0f * (i % 19) + 10, 32.0f * (i / 19) + 32 * 3 + 14);
				k++;
			}
			else if (map[i] == 2)
			{
				_blocks[j]->position = new Vector2(32.0f * (i % 19) + 6, 32.0f * (i / 19) + 32 * 3 + 10);
				j++;
			}
			else if (map[i] == 3)
			{
				_powerUps[c]->position = new Vector2(32.0f * (i % 19) + 4, 32.0f * (i / 19) + 32 * 3 + 10);
				c++;
			}
		}
	}
	else
	{
		Audio::Play(_rip);
	}
	_pacman->position = new Vector2(9 * 32, 19 * 32 + 1);
}

//Update the frame
void Pacman::FrameUpdater()
{
	_frameCount++;
	if (_frameCount >= frameRate)
	{
		_frameCount = 0;
	}
	// 6 FRAMES / SECOND
	if (_frameCount < frameS)
	{
		for (int c = 0; c < 4; c++)
		{
			_powerUps[c]->sourceRect->X = 0;
		}
		_pacman->sourceRect->X = _pacman->sourceRect->Width * 0;
		_cherry->sourceRect->X = _cherry->sourceRect->Width * 0;
	}
	else if (_frameCount >= frameS && _frameCount < frameS * 2)
	{
		for (int c = 0; c < 4; c++)
		{
			_powerUps[c]->sourceRect->X = 24;
		}
		_pacman->sourceRect->X = _pacman->sourceRect->Width * 1;
	}
	else if (_frameCount >= frameS * 2 && _frameCount < frameS * 3)
	{
		for (int c = 0; c < 4; c++)
		{
			_powerUps[c]->sourceRect->X = 48;
		}
		_pacman->sourceRect->X = _pacman->sourceRect->Width * 2;
	}
	else if (_frameCount >= frameS * 3 && _frameCount < frameS * 4)
	{
		for (int c = 0; c < 4; c++)
		{
			_powerUps[c]->sourceRect->X = 72;
		}
		_pacman->sourceRect->X = _pacman->sourceRect->Width * 3;
		_cherry->sourceRect->X = _cherry->sourceRect->Width * 1;
	}
	else if (_frameCount >= frameS * 4 && _frameCount < frameS * 5)
	{
		for (int c = 0; c < 4; c++)
		{
			_powerUps[c]->sourceRect->X = 48;
		}
		_pacman->sourceRect->X = _pacman->sourceRect->Width * 5;
	}
	else {
		for (int c = 0; c < 4; c++)
		{
			_powerUps[c]->sourceRect->X = 24;
		}
		_pacman->sourceRect->X = _pacman->sourceRect->Height * 1;
	}
}

void Pacman::stopTime1(int timerSet)
{
	timeBegin = timerSet - 60*5;
	begin = true;
}
void Pacman::stopTime2(int timer)
{

	if (timer <= timeBegin)
	{
		if (timer == timeBegin)
		{
			_pacman->speedMultiplier = 1.0f;
			_pacman->canEatGhost = false;
			for (int i = 0; i < GHOSTCOUNT; i++)
			{
				_ghost[i]->speedMultiplier = 1.0f;
				_eyes[i]->sourceRect->Y = 5 * 32.0f;
				_ghost[i]->sourceRect->Y = 32.0f*i + 32.0f;
			}
		}
	}
	else
	{
		if (begin) {
			_pacman->canEatGhost = true;
			_pacman->speedMultiplier = 1.5f;
			for (int i = 0; i < GHOSTCOUNT; i++)
			{
				_ghost[i]->speedMultiplier = 1.5f;
				_eyes[i]->sourceRect->Y = 5 * 32.0f + 16;
				_ghost[i]->sourceRect->Y = 0.0f;
			}
		}
	}
}
//Main Update 
void Pacman::Update(int elapsedTime)
{	// Gets the current state of the keyboard
	Input::KeyboardState* keyboardState = Input::Keyboard::GetState();
	//Main Game
	if (!_paused && !_start&& !_charSelect&& !_highscore)
	{
		Input(elapsedTime, keyboardState);
		Collisions();
		FrameUpdater();
		Timer();
		for (int i = 0; i < GHOSTCOUNT; i++)
		{
			UpdateGhost(_ghost[i],_eyes[i], elapsedTime);
		}
		stopTime2(timeleft);
	}
	if (!_start && !_charSelect&&!_highscore)
	{
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
		MenuScreen(keyboardState);
	}
	if (_charSelect)
	{
		Collisions();
	}
	if (_highscore)
	{
		if (keyboardState->IsKeyDown(Input::Keys::Q))
		{
			_charSelect = false;
			_highscore = false;
			_start = true;
		}
	}
	BorderCollision();
}

//Main Draw
void Pacman::Draw(int elapsedTime)
{
	// Allows us to easily create a string
	std::stringstream stream;
	stream << "Timer :     Score :       Level :       Lives : " << endl <<
		std::setw(15) << left << timeleft / 60 << std::setw(15) << left << points << std::setw(15) << left << level + 1 << std::setw(15) << left << _pacman->lives << endl;

	SpriteBatch::BeginDraw(); // Starts Drawing
	SpriteBatch::Draw(_map->texture, _map->position, _map->sourceRect);//Draws Map
	for (int i = 0; i < MUCHIECOUNT; i++)
	{
		SpriteBatch::Draw(_munchie[i]->texture, _munchie[i]->position, _munchie[i]->sourceRect); //Draws Muchie
	}
	for (int c = 0; c < 4; c++)
	{
		SpriteBatch::Draw(_powerUps[c]->texture, _powerUps[c]->position, _powerUps[c]->sourceRect); //Draws Powerups
	}
	/*
	for (int i = 0; i < BLOCKCOUNT; i++)
	{
		SpriteBatch::Draw(_blocks[i]->texture, _blocks[i]->position, _blocks[i]->sourceRect); //Draws Blocks
	}
	*/
	for (int i = 0; i < GHOSTCOUNT; i++)

	{
		SpriteBatch::Draw(_ghost[i]->texture, _ghost[i]->position, _ghost[i]->sourceRect);
		SpriteBatch::Draw(_eyes[i]->texture, _eyes[i]->position, _eyes[i]->sourceRect);
	}
	//SpriteBatch::Draw(_cherry->texture, _cherry->position, _cherry->sourceRect); // Draws Cherry
		SpriteBatch::Draw(_pacman->texture, _pacman->position, _pacman->sourceRect); // Draws Pacman
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
		SpriteBatch::Draw(_menuBackground, _menuRectangle, nullptr);//Draws the background
		SpriteBatch::Draw(_buttonsTexture, _startB->position, _startB->sourceRect);//Draws Start Button
		SpriteBatch::Draw(_buttonsTexture, _leaderB->position, _leaderB->sourceRect);//Draws Controls Button
		SpriteBatch::Draw(_buttonsTexture, _characterB->position, _characterB->sourceRect);//Draws Character Button
		SpriteBatch::Draw(_buttonsTexture, _quitB->position, _quitB->sourceRect);//Draws Quit Button
		SpriteBatch::Draw(_menu2Background, _menuRectangle, nullptr);//Draws the menu words
	}
	if (_charSelect)
	{
		SpriteBatch::Draw(_charBackground, _menuRectangle, nullptr);//Draws the background
		SpriteBatch::Draw(_sellect->texture, _sellect->position, _sellect->sourceRect);//Draws Selected
	}
	if (_highscore)
	{
		SpriteBatch::Draw(_menuBackground, _menuRectangle, nullptr);//Draws the background
		std::stringstream highStream;
		loadScore();
		highStream << "Rank          Scores" << endl << endl;
		for (int i = 9; i >0; i--)
		{
			highStream << 10-i<< "                " << scores[i] << endl;
		}
		highStream << 10 << "              " << scores[0] << endl << endl << endl;
		highStream << "Press Q to go back" << endl;
		SpriteBatch::DrawString(highStream.str().c_str(), _menuStringPosition, Color::Yellow);
	}
	SpriteBatch::EndDraw(); // Ends Drawing
}

//SCORES SECTION

//Load the file
void Pacman::loadScore()
{
	scoreFile.open("scores.txt", ios::in);
	if (!scoreFile.is_open())
	{
		cout << "Fail to load" << endl;
	}
	else
	{
		int len = 0, x;
		while (scoreFile >> x)
		{
			scores[len] = x;
			len++;
		}
		if (len == 10)
		{
			for (int i = 0; i < 10; i++)
			{
				scoreFile >> scores[i];
			}
		}
		else
		{
			cout << "Less than 10 scores, suplying with some 0." << endl;
			for (int i = len; i < 10; i++)
			{
				scores[i] = 0;
			}
		}
		scoreFile.close();
	}
}

//Saves the file
void Pacman::saveScores()
{
	scoreFile.open("scores.txt", ios::out);
	for (int i = 0; i < 10; i++)
	{
		scoreFile << scores[i] << " ";
	}
	scoreFile.close();
}

//Swap Funtion, used for swaping 2 values
void Pacman::Swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

//Sort the scores
void Pacman::sorting()
{
	int value = -1;
	loadScore();
	//Bubble Sort
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 - i; j++)
		{
			if (scores[j] > scores[j + 1])
			{
				Swap(scores[j], scores[j + 1]);
			}
		}
	}
	//Checking the right position
	for (int i = 0; i < 10; i++)
	{
		if (points> scores[i])
		{
			value++;
		}
	}
	//Shifting the others positions
	if (value != -1)
	{
		for (int k = 0; k <= value; k++)
		{
			scores[k] = scores[k + 1];
		}
		scores[value] = points;
	}
	saveScores();
}