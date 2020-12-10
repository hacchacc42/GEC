#pragma once
#define MUCHIECOUNT 152
#define BLOCKCOUNT 211
#define GHOSTCOUNT 4
// If Windows and not in Debug, this will run without a console window
// You can use this to output information when debugging using cout or cerr
#ifdef WIN32 
	#ifndef _DEBUG
		#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
	#endif
#endif

// Just need to include main header file
#include "S2D/S2D.h"
#include <fstream>
// Reduces the amount of typing by including all classes in S2D namespace
using namespace S2D;

// Declares the Pacman class which inherits from the Game class.
// This allows us to overload the Game class methods to help us
// load content, draw and update our game.
class Pacman : public Game
{
private:
	//Input methods  
	void Input(int elapsedTime, Input::KeyboardState* state); 

	//Check methods 
	void CheckPaused(Input::KeyboardState* state, Input::Keys pauseKey);  
	void CheckViewportCollision(); 
	void MenuScreen(Input::KeyboardState* state);

	//Update methods  
	void UpdatePacman(int elapsedTime);  
	void UpdateMunchie(int elapsedTime);
	void FrameUpdater();
	//Colide Methods
	void BorderCollision();
	//Codie Method with other objects 
	bool CheckCollision(int x1, int y1, int width1, int height1,
						int x2, int y2, int width2, int height2);
	void Collisions();
	//Timer Method
	void Timer();
	int timeleft = 60*90;
	int points = 0;
	float pointsMultiplier = 1.0f;
	int level = 0;
	bool isColliding;
	//Structure Definition
//Structure for the player
	struct Player
	{
		int lives = 3;
		bool canEatGhost = false;
		float speed = 0.5f;
		float speedMultiplier = 1.0f;
		int direction;
		int character;
		Rect* sourceRect;
		Texture2D* texture;
		Vector2* position;
	};
	Player* _pacman;
//Struct for enemy
	struct Enemy
	{
		Vector2* position;
		Texture2D* texture;
		Rect* sourceRect;
		float speedMultiplier = 1.0f;
		int direction = 0;
		float speed = .2f;
	};
	Enemy* _ghost[GHOSTCOUNT];
	//Struct for items
	struct Atributes
	{
		Rect* sourceRect;
		Texture2D* texture;
		Vector2* position;
	};
	Atributes* _eyes[GHOSTCOUNT];
	Atributes* _munchie[MUCHIECOUNT];
	int munchieLeft = MUCHIECOUNT;
	Atributes* _map;
	Atributes* _blocks[BLOCKCOUNT];
	Atributes* _charColider[4];
	Atributes* _sellect;
	Atributes* _powerUps[4];
	//Munchie Map
	int map[418] =
	{
		2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
		2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2,
		2, 3, 2, 2, 1, 2, 2, 2, 1, 2, 1, 2, 2, 2, 1, 2, 2, 3, 2,
		2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 2, 2, 2, 1, 2, 2, 1, 2,
		2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
		2, 1, 2, 2, 1, 2, 1, 2, 2, 2, 2, 2, 1, 2, 1, 2, 2, 1, 2,
		2, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 2,
		2, 2, 2, 2, 1, 2, 2, 2, 0, 2, 0, 2, 2, 2, 1, 2, 2, 2, 2,
		0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 2, 1, 2, 0, 0, 0,
		2, 2, 2, 2, 1, 2, 0, 2, 2, 0, 2, 2, 0, 2, 1, 2, 2, 2, 2,
		0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0,
		2, 2, 2, 2, 1, 2, 0, 2, 2, 2, 2, 2, 0, 2, 1, 2, 2, 2, 2,
		0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 2, 1, 2, 0, 0, 0,
		2, 2, 2, 2, 1, 2, 0, 2, 2, 2, 2, 2, 0, 2, 1, 2, 2, 2, 2,
		2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2,
		2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 2, 2, 2, 1, 2, 2, 1, 2,
		2, 3, 1, 2, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 2, 1, 3, 2,
		2, 2, 1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 1, 2, 1, 2, 1, 2, 2,
		2, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 2,
		2, 1, 2, 2, 2, 2, 2, 2, 1, 2, 1, 2, 2, 2, 2, 2, 2, 1, 2,
		2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
		2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	};
	//Score
	int scores[10] = { 0 };
	fstream scoreFile;


	Atributes* _cherry;

	// Position for String
	Vector2* _stringPosition;

	//Audio
	SoundEffect* _pop;
	SoundEffect* _intro;
	SoundEffect* _ghostS;
	SoundEffect* _rip;

	//Screen Size & fps
	int square = 32;
	int width = 19*square;
	int height = 27*square;
	int frameRate = 24;//Must be a multiple of 6
	int _frameCount;
	int frameS = frameRate / 6;

	//Ghost moving
	void UpdateGhost(Enemy* ghost,Atributes* eyes, int elapsedTime);

	// Data for Menu
	Texture2D* _menuBackground;
	Texture2D* _menu2Background;
	Texture2D* _charBackground;
	Texture2D* _highScoreBackground;
	Rect* _menuRectangle;
	Vector2* _menuStringPosition;
	bool _paused;
	bool _start;
	bool _highscore;
	int _menuSelection;

	void CharSelect();
	bool _charSelect;

	//Check if certian keys are pressed
	bool _pKeyDown;
	bool _wKeyDown;
	bool _sKeyDown;


	//Buttons
	Texture2D* _buttonsTexture;
	struct Button
	{
		Vector2* position;
		Rect* sourceRect;
	}*_startB,*_leaderB,*_characterB,*_quitB;
	void Selection(float posx, float posy, float pMult, float speed, const char texture[]);
	//Reset All the buttons
	void ResetAllButtons();
	//Setting data for a new game
	void NewLevel(int lvl,bool dead);

	bool begin = false;
	int timeBegin = 60 * 90;
	void stopTime1(int timerSet);
	void stopTime2(int timer);
	void WallCollision();
	void MunchieCollision();
	void PowerUpCollision();
	void CharCollision();
	void GhostCollision();

	//Scores Functions
	void loadScore();
	void saveScores();
	void sorting();
	void Swap(int& x, int& y);
	void Scores();
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
};