#include <iostream>
using namespace std;

int playerHealth = 1000, enemyHealth = 2000, healthpotion = 3, mana = 200;
bool playing = true;

void Attack(int choice);
bool PlayState();
void HealthCheckAndOutput();
void ResetGame();
int main()
{
	int choice;
	while (playing)
	{
		cout << endl << "You have meet a troll on the brigde between two cities : " << endl;
		cout << "1. Use Sword   2. Use Magic   3. Use Axe   4. Use Bow   5. Drink a health potion" << endl;
		cout << "Be carefull, each choice have different effects." << endl;
		cin >> choice;

		Attack(choice);
		playing=PlayState();
	}
	return 0;
}

void Attack(int choice)
{
	const int choiceC = choice;
	const int swordDamage = 300, magicDamage = 650, axeDamage = 450, bowDamage = 500, healPlayer = 200, fireballCost = 100;
	const int trollSword = 350, trollMagic = 50, trollAxe = 100, trollBow = 75;
	switch (choiceC)
	{
		case 1:
			enemyHealth -= swordDamage;
			playerHealth -= trollSword;
			cout << "You hit the troll with your iron sword!" << endl;
			cout << "The troll hits you with his rusty sword!" << endl;
			HealthCheckAndOutput();
			break;
		case 2:
			if (mana > 0)
			{
				playerHealth -= trollMagic;
				mana -= fireballCost;
				enemyHealth -= magicDamage;
				cout << "You hit the troll with a fire ball!" << endl;
				cout << "You have " << mana << " mana left." << endl;
				cout << "You have been hit by the troll's wind blow!" << endl;
			}
			else
			{
				cout << "You don't have enough mana" << endl;
			}
			HealthCheckAndOutput();
			break;
		case 3:
			enemyHealth -= axeDamage;
			playerHealth -= trollAxe;
			cout << "You hit the troll with a steel axe!" << endl;
			cout << "The troll hits you using a broken axe!" << endl;
			HealthCheckAndOutput();
			break;
		case 4:
			enemyHealth -= bowDamage;
			playerHealth -= trollBow;
			cout << "You hit the troll with your long bow!" << endl;
			cout << "The troll is trying to hit you with a bow, but instead is throwing rocks at you!" << endl;
			HealthCheckAndOutput();
			break;
		case 5:
			if (healthpotion > 0) 
			{
				playerHealth += healPlayer;
				cout << "You drink a health potion!" << endl;
				healthpotion--;
				cout << "You have " << healthpotion << " health potions left" << endl;
				cout << "The troll is amazed by the color of the potion and does nothing!" << endl;
			}
			else 
			{
				playerHealth -= trollAxe;
				cout << "You try to drink a health potion, but realise that you don't have any left!" << endl;
				cout << "The troll saw that you are confused and hit you with an axe!" << endl;
			}
			HealthCheckAndOutput();
			break;
		default:
			cout << "INVALID INPUT!";
			break;
	}
}

bool PlayState()
{
	char playAgain;
	if (enemyHealth <= 0)
	{
		cout << endl << "Great job, you defeated the troll!" << endl;
		cout << "Wanna play again ?(y/n)" << endl;
		cin >> playAgain;
		if (playAgain == 'y')
		{
			ResetGame();
			return true;
		}
		else
		{
			return false;
		}
	}
	if (playerHealth <= 0)
	{
		cout << endl << "Such a shame, the troll has defeten you." << endl;
		cout << "Wanna play again ?(y/n)" << endl;
		cin >> playAgain;
		if (playAgain == 'y')
		{
			
			ResetGame();
			return true;
		}
		else
		{
			return false;
		}
	}
}

//Check if the player health or enemy health is less than 0 and output the remained health
//This function exist just to make the code shorter.
void HealthCheckAndOutput()
{
	if (playerHealth < 0)
	{
		playerHealth = 0;
	}
	if (enemyHealth < 0)
	{
		enemyHealth = 0;
	}
	cout << "You have " << playerHealth << " Health Points left." << endl;
	cout << "The troll have " << enemyHealth << " Health Points left." << endl;
}

//Reset the game default values
void ResetGame()
{
	playerHealth = 1000;
	enemyHealth = 2000;
	healthpotion = 3;
	mana = 200;
}