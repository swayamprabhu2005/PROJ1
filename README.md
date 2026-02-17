Online Recipe Book (C++)
Overview

The Online Recipe Book is a console-based C++ application that allows users to create an account, log in, and manage recipes.
Users can add or view recipes categorized as:

Veg or Non-Veg

Main Course or Dessert

All data is stored in text files for persistence.

Features

User authentication system (sign up and login)

Separate storage for usernames and passwords

Add recipes with:

Title

Ingredients

Cooking steps

Categorized recipe storage:

Veg Main Course

Veg Dessert

Non-Veg Main Course

Non-Veg Dessert

View existing recipes from files

File Structure
project/
│
├── main.cpp
├── usernames.txt
├── passwords.txt
├── veg maincourse.txt
├── veg dessert.txt
├── non-veg maincourse.txt
└── non-veg dessert.txt
