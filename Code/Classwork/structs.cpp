#include<iostream>

using namespace std;

struct student
{
	int classYear;
	double gpa;
	string nickname;
	bool isCool;
	
	
};

int main()
{
	student aiden;
	student aj;
	
	cout << "\nWhat is the first student's nickname?\n";
	cin >> aiden.nickname;
	
	cout << "\n";
	
	cout << aiden.nickname << "!  What a fun name!\n\n";
	
	cout << "What is " << aiden.nickname << "'s class year?";
	cin >> aiden.classYear;
	
	if(aiden.classYear >= 2028)
	{
		cout << "\nDang gen Alpha-er\n\n";
	}
	else
	{
		cout << "Baby Zoomer!\n\n";
	}

	return 0;
}