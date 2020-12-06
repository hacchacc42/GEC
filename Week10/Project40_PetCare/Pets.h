#ifndef PETS_H
#define PETS_H
#include <iostream>

using namespace std;

class Pet
{
public:
	Pet() {}
	Pet(string name)
	{
		cout << "Your new "<<name<<" has arrived ." << endl;
		p_name = name;
	}
	~Pet() {}

	virtual void Speak()
	{
		cout << "*Cute noises*" << endl;
	}

	void Mood()
	{ 
		cout << "I am you "<<p_name<<" and I feel ";
		int mood = GetMood();
		if (mood > 15)
		{
			cout << "mad" << endl;
		}
		else if (mood > 10)
		{
			cout << "frustrated" << endl;
		}
		else if (mood > 5)
		{
			cout << "okay" << endl;
		}
		else
		{
			cout << "happy" << endl;
		}
	}

	void Feed(int food) 
	{
		cout << "Pet has ate" << endl;
		p_hunger -= food;
		cout << "Your " << p_name;
		if (food > 2)
		{
			cout << " enjoyed the food." << endl;
		}
		else if (food > 0)
		{
			cout << " ate his food sadly." << endl;
		}
		else
		{
			cout << " is begin to feel sick from the food." << endl;
		}
		if (p_hunger < 0)
		{
			cout << "It seems that your " << p_name << " is full." << endl;
			p_hunger = 0;
		}
		PassingTime(food > 0 ? 3-food: 3);
	}

	void Play(int fun)
	{
		cout << "You've played with your pet" << endl;
		cout << "Your " << p_name;
		if (fun > 2)
		{
			cout << " enjoyed the time." << endl;
		}
		else if (fun > 0)
		{
			cout << " is feeling more ok." << endl;
		}
		else
		{
			cout << " hate the actuvity." << endl;
		}
		p_bored -= fun;
		if (p_bored < 0)
		{
			p_bored = 0;
		}
		PassingTime(fun >0 ? 3-fun: 3);
	}
protected:
	int GetMood()
	{
		return( p_hunger + p_bored);
	}

	void PassingTime(int time)
	{
		p_hunger += time;
		p_bored += time;
	}
	string p_name = "pet";
private:

	int p_hunger=4;
	int p_bored=4;
};

class Dog : public Pet
{
	
public:
	Dog(string name)
	{
		cout << "Your new " << name << " has arrived ." << endl;
		p_name = name;
	}
	void Speak()
	{
		cout << "Woof!" << endl;
		PassingTime(1);

	}
};

class Cat : public Pet
{
public:
	Cat(string name)
	{
		cout << "Your new " << name << " has arrived ." << endl;
		p_name = name;
	}
	void Speak()
	{
		cout << "Meow!" << endl;
		PassingTime(1);
	}
};

class Hamster : public Pet
{
public:
	Hamster(string name)
	{
		cout << "Your new " << name << " has arrived ." << endl;
		p_name = name;
	}
	void Speak()
	{
		cout << "*Hamster noises*!" << endl;
		PassingTime(1);
	}
};
#endif // !PETS_H
