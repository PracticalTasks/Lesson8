#include<iostream>
#include <vector>

using namespace std;

//TASK 1
template<typename T>
T my_div(T num, T denom)
{
	if(denom == 0)
		throw - 1;
	return num /= denom;
}

//TASK 2
class Ex
{
public:
	float x;
	Ex(float _x):x(_x)
	{}

};

class Bar
{
	float y;
public:
	Bar(float _y = 0) : y(_y)
	{}
	void set(float a)
	{
		if ((y + a) > 100)
		{
			Ex ex(y * a);
			throw ex;
		}
		else
			y = a;
	}
};

//TASK 3
enum Direction
{
	dUp, dDown, dRight, dLeft
};

class OffTheField
{
public:
	int posX;
	int posY;
	string direction;
	int step;
	OffTheField(int x, int y, Direction _direction, int _step) : posX(x), posY(y), step(_step)
	{
		vector<string> arrDirection;
		arrDirection= { "up","down","right","left" };
		direction = arrDirection[_direction];
	}
};

class IllegalCommand
{
public:
	int step;
	string direction;
	IllegalCommand(int _step,Direction _direction) : step(_step)
	{
		vector<string> arrDirection;
		arrDirection = { "up","down","right","left" };
		direction = arrDirection[_direction];
	}
};

const int SZ{ 10 };

class Robot
{	
	int posX;
	int posY;
	bool arr[SZ][SZ];
	
public:
	Robot(int y=0,int x=0):posY(y),posX(x)
	{
		for (int i{}; i < SZ; ++i)
			for (int j{}; j < SZ; ++j)
				arr[i][j] = 0;

		arr[posY][posX] = 1;
	}

	void move(Direction direction,int step)
	{
		if (step > 9)
		{
			IllegalCommand obj(step,direction);
			throw obj;
		}

		switch (direction)
		{
		case(dUp):
			arr[posY][posX] = 0;
			posY -= step;
			break;

		case(dDown):
			arr[posY][posX] = 0;
			posY += step;
			break;

		case(dRight):
			arr[posY][posX] = 0;
			posX += step;
			break;

		case(dLeft):
			arr[posY][posX] = 0;
			posX -= step;
		}
		
		if (posX > 9 || posY > 9)
		{
			OffTheField obj(posX,posY,direction,step);
			throw obj;
		}

		arr[posY][posX] = 1;
	}

	void draw()
	{
		for (int i{}; i < SZ; ++i)
		{
			for (int j{}; j < SZ; ++j)
			{
				cout << arr[i][j]<<' ';
			}
			cout << '\n';
		}
		cout << "\n\n";
				
	}
};




int main()
{
	//Task 1
	{
		cout << "Task 1\n";
		try
		{
			cout<<my_div(25, 0);
		}
		catch(int a)
		{
			cout <<"Error: "<<a<<" Devided by zero\n";
		}
	}

	//Task 2
	{
		cout << "\n\nTask 2\n";
		Bar bar(50);
		int var{ 0 };
		while (true)
		{
			cout << "enter an integer:";
			cin >> var;
			if (var == 0)
				break;
			try
			{
				bar.set((float)var);
			}
			catch (Ex obj)
			{
				cout << "Error: " << obj.x << '\n';
			}
		}
	}

	//Task 3
	{
		cout << "\n\nTask 3\n";
		Robot robot(3,2);
		robot.draw();
		try
		{
			robot.move(dRight, 3);
			robot.move(dDown, 7);
			robot.draw();
		}
		catch(OffTheField obj)
		{
			cout <<"Error OffTheField" <<"\nPosition X:" << obj.posX << " Y:" << obj.posY<<"\nDirection:"<<obj.direction<<"\nStep:"<<obj.step<<'\n';
		}
		catch (IllegalCommand obj)
		{
			cout << "Error IllegalCommand" <<"\nDirection:" << obj.direction << "\nStep:" << obj.step << '\n';
		}
	}
}