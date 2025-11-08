// ONLINE RECIPE BOOK
#include<iostream>
#include<vector>
#include<string.h>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
class RECIPE 
{
protected:
	string title;
	vector<string> ingredients;
	vector<string> steps;
public:
	virtual void getrecipedetails() = 0;
	virtual void savetofile(const string& file) = 0;
	virtual void readfromfile(const string& file) = 0;
};
class MainCourse : public RECIPE
{
public:
	void getrecipedetails()
	{
		int x, y;
		cout << "Enter Main Course recipe title: ";
		getline(cin, title);
		cout << "Enter total number of ingredients: ";
		cin >> x;
		cin.ignore();
		cout << "Enter ingredients: ";
		for (int i = 0; i < x; i++) 
		{
			string ingredient;
			getline(cin, ingredient);
			ingredients.push_back(ingredient);
		}
		cout << "Enter total number of steps: ";
		cin >> y;
		cin.ignore();
		cout << "Enter cooking steps: ";
		for (int i = 0; i < y; i++) 
		{
			string step;
			getline(cin, step);
			steps.push_back(step);
		}
	}
	void savetofile(const string& file)
	{
		ofstream recipe;
		recipe.open(file, ios::app);
		recipe << setfill('-') << setw(70) << "" << endl;
		recipe << setfill(' ') << setw(45) << title << endl;
		recipe << setfill('-') << setw(70) << "" << endl;
		recipe << setfill(' ') << setw(25) << "Ingredients: " << endl;
		for (auto& ingredient : ingredients)
		{
			recipe << setw(50) << setiosflags(ios::left) << ingredient << endl;
		}
		recipe << resetiosflags(ios::left) << setfill(' ') << setw(25) << "Steps: " << endl;
		for (auto& step : steps)
		{
			recipe << setw(50) << setiosflags(ios::left) << step << endl;
		}
		recipe << setfill('-') << setw(100) << "" << endl;
		recipe.close();
	}
	void readfromfile(const string& file) 
	{
		ifstream recipe(file);
		string line;
		while (getline(recipe, line)) 
		{
			cout << line << endl;
		}
		recipe.close();
	}
};
class Dessert : public RECIPE
{
public:
	void getrecipedetails()
	{
		int x, y;
		cout << "Enter Dessert recipe title: ";
		getline(cin, title);
		cout << "Enter total number of ingredients: ";
		cin >> x;
		cin.ignore();
		cout << "Enter ingredients: ";
		for (int i = 0; i < x; i++)
		{
			string ingredient;
			getline(cin, ingredient);
			ingredients.push_back(ingredient);
		}
		cout << "Enter total number of steps: ";
		cin >> y;
		cin.ignore();
		cout << "Enter cooking steps: ";
		for (int i = 0; i < y; i++)
		{
			string step;
			getline(cin, step);
			steps.push_back(step);
		}
	}
	void savetofile(const string& file)
	{
		ofstream recipe;
		recipe.open(file, ios::app);
		recipe << setfill('-') << setw(70) << "" << endl;
		recipe << setfill(' ') << setw(45) << title << endl;
		recipe << setfill('-') << setw(70) << "" << endl;
		recipe << setfill(' ') << setw(25) << "Ingredients: " << endl;
		for (auto& ingredient : ingredients) 
		{
			recipe << setw(50) << setiosflags(ios::left) << ingredient << endl;
		}
		recipe << resetiosflags(ios::left) << setfill(' ') << setw(25) << "Steps: " << endl;
		for (auto& step : steps)
		{
			recipe << setw(50) << setiosflags(ios::left) << step << endl;
		}
		recipe << setfill('-') << setw(100) << "" << endl;
		recipe.close();
	}
	void readfromfile(const string& file) 
	{
		ifstream recipe(file);
		string line;
		while (getline(recipe, line))
		{
			cout << line << endl;
		}
		recipe.close();
	}
};
class Category:public MainCourse,public Dessert
{
private:
	vector<RECIPE*> recipes;
public:
	void addRecipe(RECIPE* recipe)
	{
		recipes.push_back(recipe);
	}
	void saverecipesfile(string& category) 
	{
		string filename = category + ".txt";
		for (auto& recipe : recipes)
		{
			recipe->savetofile(filename);
		}
	}
	void viewrecipelist(const string& file) 
	{
		ifstream recipe(file);
		string line;
		while (getline(recipe, line)) 
		{
			cout << line << endl;
		}
		recipe.close();
	}
	string selectrecipefile(const string& category, int typeChoice)
	{
		string filename;
		if (category == "Veg")
		{
			if (typeChoice == 1)
			filename = "veg maincourse.txt";
			else 
			filename = "veg dessert.txt";
		}
		else 
		{
			if (typeChoice == 1)
				filename = "non-veg maincourse.txt";
			else
				filename = "non-veg dessert.txt";
		}
		return filename;
	}
};
class User : public Category
{
private:
	string username;
	string password;
	bool usernameexists(const string& enterUsername) 
	{
		ifstream usernamesfile("usernames.txt");
		string line;
		while (getline(usernamesfile, line))
		{
			if (line == enterUsername) 
			{
				usernamesfile.close();
				return true;
			}
		}
		usernamesfile.close();
		return false;
	}
	bool checkPassword(const string& enterUsername, const string& enterPassword) 
	{
		ifstream usernamesfile("usernames.txt");
		ifstream passwordsfile("passwords.txt");
		string usernameLine, passwordLine;
		while (getline(usernamesfile, usernameLine) && getline(passwordsfile, passwordLine)) 
		{
			if (usernameLine == enterUsername && passwordLine == enterPassword)
			{
				usernamesfile.close();
				passwordsfile.close();
				return true;
			}
		}
		usernamesfile.close();
		passwordsfile.close();
		return false;
	}
	void savedetails(const string& newUsername, const string& newPassword)
	{
		ofstream usernamesfile("usernames.txt", ios::app);
		ofstream passwordsfile("passwords.txt", ios::app);
		usernamesfile << newUsername << endl;
		passwordsfile << newPassword << endl;
		usernamesfile.close();
		passwordsfile.close();
	}
public:
	bool userauthentiation()
	{
		int choice;
		cout << "Do you have an account?\n1. Yes\n2. No\nEnter choice: ";
		cin >> choice;
		cin.ignore();
		if (choice == 1)
		{
			int retrylimit = 3;
			while (retrylimit > 0)
			{
				cout << "Enter username: ";
				getline(cin, username);
				if (usernameexists(username))
				{
					cout << "Enter password: ";
					getline(cin, password);
					if (checkPassword(username, password))
					{
						cout << "Login successful!" << endl;
						cout << setfill('=') << setw(70) << "Welcome to recipe management system" << setw(40) << "" << endl;
						return true;
					}
					else
						cout << "Incorrect password. Please try again." << endl;
				}
				else
					cout << "Username does not exist. Please try again." << endl;
				retrylimit--;
				if (retrylimit == 0)
				{
					cout << "Too many failed attempts. Try after sometime." << endl;
					return false;
				}
			}

		}
		else if (choice == 2)
		{
			cout << "Create a new account:\n";
			cout << "Enter a new username: ";
			getline(cin, username);
			if (usernameexists(username))
			{
				cout << "Username already exists. Try a different username." << endl;
				return userauthentiation();
			}
			else
			{
				cout << "Enter a new password: ";
				getline(cin, password);
				savedetails(username, password);
				cout << "Account created successfully!" << endl;
				return userauthentiation();
			}
		}
		else
		{
			cout << "Invalid choice. Please try again." << endl;
			return false;
		}
	}
	void useroptions()
	{
		string category;
		int typeChoice;
		int optionchoice;
		cout << "Select category: 1. Veg 2. Non-Veg\nEnter choice: ";
		cin >> typeChoice;
		cin.ignore();
		category = (typeChoice == 1) ? "Veg" : "Non-Veg";
		cout << "Select recipe type: 1. Main Course 2. Dessert\nEnter choice: ";
		cin >> typeChoice;
		cin.ignore();
		string filename = selectrecipefile(category, typeChoice);
		cout << "Do you want to:\n1. Add a new recipe\n2. View existing recipes\nEnter your choice: ";
		cin >> optionchoice;
		cin.ignore();
		if (optionchoice == 1)
		{
			if (typeChoice == 1) 
			{
				MainCourse* mainCourse = new MainCourse();
				mainCourse->getrecipedetails();
				addRecipe(mainCourse);
				mainCourse->savetofile(filename);
				cout << "Recipe added successfully \n";
			}
			else
			{
				Dessert* dessert = new Dessert();
				dessert->getrecipedetails();
				addRecipe(dessert);
				dessert->savetofile(filename);
				cout << "Recipe added successfully\n";
			}
		}
		else if (optionchoice == 2)
		{
			cout << "List of recipes:\n";
			viewrecipelist(filename);
		}
		else
		{
			cout << "Invalid choice.\n";
		}
	}
};
int main() 
{
	User user;
	if (user.userauthentiation())
	{
		int choice;
		do {
			cout << "1. Create or View Recipes\n2. Exit\nEnter your choice: ";
			cin >> choice;
			cin.ignore();
			if (choice == 1)
			{
				user.useroptions();
			}
			else if (choice == 2)
			{
				cout << "Exiting program.\n";
			}
			else
			{
				cout << "Invalid choice. Try again.\n";
			}
		} while (choice != 2);
	}
}
