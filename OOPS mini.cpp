#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include<fstream>
using namespace std;
static int count1 = 0;
class person
{
protected:
	string mobile;
	char persons[50];
	string email;
	int age;

public:
	string name;  
	int getdata();
};
int op;
int person::getdata()
{
	fstream file;
	cout << "ENTER YOUR FULL NAME " << endl;
	getline(cin >> ws, name);
	cout << "ENTER YOUR AGE" << endl;
	cin >> age;
	cout << "ENTER MOBILE NO." << endl;
	getline(cin >> ws, mobile);
	cout << "ENTER EMAIL ID ";
	cin >> email;
	if (op == 3)
    {
		return 0;//STAFF;
	}
	else
	{
		file.open("PASSENGER.txt", ios::app);
		file << "NAME: " << name << endl;
		file << "AGE: " << age << endl;
		file << "MOBILE: " << mobile << endl;
		file << "EMAIL: " << email << endl;
		file << endl<<endl;
		file.close();
	}
}
class addon;
string passenger1;
class passenger : virtual public person
{
protected:
	string id;
	string flightype;
	string passport = "-";
public:
	friend class addon;
	void getpass();
	virtual void displaydataa(string passenger1 = "NORMAL", string flightype = "DOMESTIC") = 0;
};
void passenger::getpass()
{
	cout << "ENTER PASSENGER TYPE(NORMAL / STUDENT)\n";
	getline(cin >> ws, passenger1);
	fstream file;
	file.open("PASSENGER.txt",ios::app);
	file <<"PASSENGER TYPE: "<< passenger1<<endl;
	file.close();
	if (passenger1 == "STUDENT")
	{
		cout << "ENTER STUDENT ID " << endl;
		cin >> id;
	}
	system("CLS");
}
class staff : virtual public person
{
protected:
	string role;
	int emp_id;
	string post;
	char flight[20], air[10];
	float x, xii;
	string address, ex;

public:
	void flightassign();
	int applypost();
	void display();
	void m_salary();
	friend int stafff(staff &s);
};
void staff::flightassign()
{
	int b;
	cout << "FROM WHICH AIRLINE YOU BELONG TO\n";
	cin >> air;
	cout << "ENTER YOUR CURRENT AIRPORT LOCATION\n";
	cin >> flight;
	cout << "AVAILABLE " << air << " FLIGHTS FROM " << flight << "\n";
	cout << "1. " << air << " " << rand() % 100 + 101 << flight << " TO JAIPUR " << setw(30) << "22.00--------->23.10" << endl;
	cout << "2. " << air << " " << rand() % 100 + 101 << flight << " TO BANGLORE " << setw(28) << "18.00--------->19.10" << endl;
	cout << "3. " << air << " " << rand() % 100 + 101 << flight << " TO KOLKATA " << setw(29) << "12.30--------->13.45" << endl;
	cout << "4. " << air << " " << rand() % 100 + 101 << flight << " TO CHANDIGARH " << setw(26) << "16.00--------->18.10" << endl;
	cout << "ENTER YOUR CHOICE\n";
	cin >> b;
	if (b == 1 || b == 2 || b == 3 || b == 4)
	{
		cout << "FLIGHT IS ASSIGNED SUCCESSFULLY\n";
	}
	else
	{
		cout << "INVALID FLIGHT!!ENTER AGAIN\n";
	}
}
void staff::m_salary()
{
	cout << "1.CLEANER(RS.1000/DAY)\n2.SECURITY(RS.2000/DAY)\n3.AIR HOSTESS(2500 / DAY)\n4.PILOT(RS.8500 / DAY)\n5.GROUND STAFF(RS.1200 / DAY)\n6.AIRLINE BAGGAGE HANDLER(RS.3500 / DAY)\n";
	cout.width(60);
	cout.fill('*');
	cout << "ENTER YOUR POST";
	cout << setfill('*') << setw(60) << "" << endl;
	getline(cin >> ws, role);
	if (role == "CLEANER")
		cout << "MONTHLY SALARY IS RS. " << 30 * 1000 << endl;
	else if (role == "SECURITY")
		cout << "MONTHLY SALARY IS RS. " << 30 * 2000 << endl;
	else if (role == "AIR HOSTESS")
		cout << "MONTHLY SALARY IS RS. " << 30 * 2500 << endl;
	else if (role == "PILOT")
		cout << "MONTHLY SALARY IS RS. " << 30 * 8500 << endl;
	else if (role == "GROUND STAFF")
		cout << "MONTHLY SALARY IS RS. " << 30 * 1200 << endl;
	else if (role == "AIRLINE BAGGAGE HANDLER")
		cout << "MONTHLY SALARY IS RS. " << 30 * 3500 << endl;
	else
		cout << "INVALID ENTRY" << endl;
}
void staff::display()
{
	cout << "POST: " << post << "\nNAME: " << name << "\nAGE: " << age << "\nMOBILE: " << mobile << "\nEMAIL: " << email << "\nADDRESS: " << address << "\nXTH PERCENTAGE: " << x << "\nXII th PERCENTAGE: " << xii
		<< "\nEXPERIENCE: " << ex << endl;
}
int staff::applypost()
{
	int num;
	cout << "1.CLEANER\n2.SECURITY\n3.AIR HOSTESS\n4.PILOT\n5.GROUND STAFF\n6.AIRLINE BAGGAGE HANDLER\n7.EXIT\n";
	cout << "ENTER THE POST FOR WHICH YOU WANT TO APPLY\n";
	getline(cin >> ws, post);
	if (post == "EXIT")
	{
		return (0);
	}
	getdata();
	cout << "ENTER YOUR ADDRESS\n";
	getline(cin >> ws, address);
	cout << "ENTER YOUR Xth PERCENTAGE\n";
	cin >> x;
	cout << "ENTER YOUR XIIth/DIPLOMA PERCENTAGE\n";
	cin >> xii;
	cout << "ENTER YOUR EXPERIENCE IF ANY\n";
	getline(cin >> ws, ex);
	cout << "APPLICATION SUBMITTED SUCCESSFULLY\n";
	cout << "\n\nAPPLICATION\n";
	display();
}
int stafff(staff &s)
{
	while (1)
	{
		int ops;
		cout << "1.FLIGHT ASSIGNMENT" << endl;
		cout << "2.CALCULATE MONTHLY SALARY" << endl;
		cout << "3.EXIT" << endl;
		cout << "ENTER YOUR CHOICE" << endl;
		cin >> ops;
		system("CLS");
		switch (ops)
		{
		case 1:
			s.flightassign();
			break;
		case 2:
			s.m_salary();
			break;
		case 3:
			return (1);
		default:
			cout << "WRONG CHOICE ENTER AGAIN";
		}
	}
}
class flightsearch : public passenger, public staff
{
protected:
	string departure;
	string date;
	string destination;
	string classs;
	char dir_con[20];

public:
	void flight_search();
	void flightdisplay();
	void displaydataa(string passenger1 = "NORMAL", string flightype = "DOMESTIC")
	{
		cout << setw(45) << setfill(' ') << " " << "NAME:" << setw(30) << name << endl
			<< setw(45) << setfill(' ') << " " << "MOBILE:" << setw(28) << mobile << endl
			<< setw(45) << setfill(' ') << " " << "EMAIL ID:" << setw(26) << email << endl
			<< setw(45) << setfill(' ') << " " << "PASSENGER TYPE:" << setw(20) << passenger1 << endl
			<< setw(45) << setfill(' ') << " " << "FLIGHTYPE:" << setw(25) << flightype << endl
			<< setw(45) << setfill(' ') << " " << "PASSPORT NUMBER:" << setw(17) << passport << setfill(' ') << endl;
	}
	friend class addon;
};
int indigo[3], vistara[3], air_india[3], akasaair[3];
int indigo_c[3], vistara_c[3];
double t[10], p[10];
double ticket_price = 0;
void flightsearch::flightdisplay()
{
	int h[10], m[10], u[10], hh[10], mm[10], j = 1, k = rand() % 100;

	for (int i = 1; i <= 8; i++)
	{
		h[i] = rand() % 24;
		m[i] = rand() % 60;
		u[i] = ((h[i] * 60 + m[i]) + k);
		hh[i] = u[i] / 60;
		mm[i] = u[i] % 60;
	}
	if (strcmp(dir_con, "DIRECT"))
	{
		if ((destination == "MUMBAI") || (destination == "BANGLORE"))
		{
			try
			{
				if ((destination == "MUMBAI") || (destination == "BANGLORE"))
				{
					throw(dir_con);
				}
			}
			catch (...)
			{
				cout << "OOPS!NO RESULT FOUND FOR YOUR SEARCH,WE SUGEST YOU MODIFY YOUR SEARCH" << endl;
			}
		}
		else
		{
			cout << "CONNECTED FLIGHTS FROM " << departure << " TO " << destination << endl;
			cout << endl;
			cout << "1. " << departure << " TO MUMBAI T1 " << endl;
			p[j] = rand() % 100 + 3000;
			indigo_c[1] = rand() % 100 + 101;
			cout << "INDIGO|6E" << indigo_c[1] << " " << endl
				<< h[j] << ":" << m[j] << "------->" << hh[j] << ":" << mm[j] << " RS." << p[j]
				<< "/-" << endl;
			j++;
			cout << "MUMBAI T2 TO " << destination << endl;
			p[j] = rand() % 100 + 4000;
			vistara_c[1] = rand() % 100 + 101;
			cout << "VISTARA|UK" << vistara_c[1] << " " << endl
				<< h[j] << ":" << m[j] << "------->" << hh[j] << ":" << mm[j] << " RS." << p[j]
				<< "/-" << endl;
			j++;
			cout << endl
				<< endl;
			cout << "2. " << departure << " TO BANGLORE " << endl;
			p[j] = rand() % 100 + 3000;
			indigo_c[2] = rand() % 100 + 101;
			cout << "INDIGO|6E" << indigo_c[2] << " " << endl
				<< h[j] << ":" << m[j] << "------->" << hh[j] << ":" << mm[j] << " RS." << p[j]
				<< "/-" << endl;
			j++;
			cout << "BANGLORE TO " << destination << endl;
			p[j] = rand() % 100 + 4000;
			vistara_c[2] = rand() % 100 + 101;
			cout << "VISTARA|UK" << vistara_c[2] << " " << endl
				<< h[j] << ":" << m[j] << "------->" << hh[j] << ":" << mm[j] << " RS." << p[j]
				<< "/-" << endl;
			j++;
		}
	}
	else
	{
		cout << "DIRECT FLIGHTS FROM " << departure << " TO " << destination << endl;
		cout << endl;
		for (int i = 0; i < 2; i++)
		{
			t[j] = rand() % 100 + 3000;
			indigo[i + 1] = rand() % 100 + 101;
			cout << (1 + (i * 4)) << ".INDIGO|6E" << indigo[i + 1] << " " << endl
				<< h[j] << ":" << m[j] << "------->" << hh[j] << ":" << mm[j] << " RS." << t[j]
				<< "/-" << endl;
			j++;
			t[j] = rand() % 100 + 4000;
			vistara[i + 1] = rand() % 100 + 101;
			cout << (2 + (i * 4)) << ".VISTARA|UK" << vistara[i + 1] << " " << endl
				<< h[j] << ":" << m[j] << "------->" << hh[j] << ":" << mm[j] << " RS." << t[j]
				<< "/-" << endl;
			j++;
			t[j] = rand() % 100 + 3500;
			air_india[i + 1] = rand() % 100 + 101;
			cout << (3 + (i * 4)) << ".AIR INDIA|AI" << air_india[i + 1] << " " << endl
				<< h[j]
				<< ":" << m[j] << "------->" << hh[j] << ":" << mm[j] << " RS." << t[j] << "/-" << endl;
			j++;
			t[j] = rand() % 100 + 2000;
			akasaair[i + 1] = rand() % 100 + 101;
			cout << (4 + (i * 4)) << ".AKASAAIR|QP" << akasaair[i + 1] << " " << endl
				<< h[j]
				<< ":" << m[j] << "------->" << hh[j] << ":" << mm[j] << " RS." << t[j] << "/-" << endl;
			j++;
		}
	}
}
int count2 = 0;
void flightsearch::flight_search()
{
	count2++;
	cout << "ENTER DEPARTURE AIRPORT" << endl;
	cin >> departure;
	cout << "ENTER ARRIVAL AIRPORT" << endl;
	cin >> destination;
	while (departure == destination)
	{
		cout << "INVALID ENTRY(DESTINATION AND DEPARTURE AIRPORT CANT BE THE SAME)" << endl;
		cout << "ENTER DETAILS AGAIN" << endl;
		system("CLS");
		cout << "ENTER DEPARTURE AIRPORT" << endl;
		cin >> departure;
		cout << "ENTER ARRIVAL AIRPORT" << endl;
		cin >> destination;
		if (departure != destination)
		{
			break;
		}
	}
	cout << "ENTER DATE OF TRAVEL" << endl;
	cin >> date;
	cout << "DIRECT/CONNECTED\n";
	cin >> dir_con;
	fstream file("PASSENGER.txt", ios::app);
	file <<endl<<"DEPARTURE: " << departure << endl << "DESTINATION: " << destination << endl << "DATE: " << date << endl << "DIRECT/CONNECTED: " << dir_con << endl;	file << endl;
	file.close();
	system("CLS");
	flightdisplay();
}

class addon
{
protected:
	string seatno;
	string meal = "-";
	int baggage = 0;
	string fastforwardp = "-";
	char seat[10] = "-";
	string insurance = "-";
	float s = 0, q = 0, d = 0;
	int pnr;
public:
	int seatToIndicerow(string);
	int seatToIndicecol(string);
	void bookseat(string);
	bool isbooked(string);
	bool isValidSeat(string);
	int getaddon();
	void displayaddon(string m = "-", float n = 1);
	void displayaddon(float s = 0, float d = 0, string a = "-");
};
void addon::displayaddon(string m, float n)
{
	cout.setf(ios::left, ios::adjustfield);
	cout << endl << setw(45) << setfill(' ') << " " << "MEAL: " << setw(12) << m << setw(10) << "  " << "QUANTITY :" << n << endl;
}
void addon::displayaddon(float s, float d, string a)
{
	cout << setw(45) << setfill(' ') << " " << "EXTRA BAGGAGE: " << baggage << "KG." << endl;
	cout << setw(45) << setfill(' ') << " " << "FAST CHECK-IN QUANTITY: " << setw(15) << s << endl;
	cout << setw(45) << setfill(' ') << " " << "SEAT: " << setw(15) << a << endl
		<< setw(45) << setfill(' ') << " " << "TRAVEL INSURANCE: " << setw(15) << insurance << endl
		<< setw(45) << setfill(' ') << " " << "NO. OF PASSENGERS : " << setw(15) << d << endl
		<< endl;
}
template <class T>
inline T cal_total(T ad, T ticket_price)
{
	static float convi_fee = 300.75;
	T total;
	if (ad == 0)
	{
		total = ticket_price + convi_fee;
	}
	else
	{
		total = ticket_price + convi_fee + ad;
	}
	return total;
}
double ad = 0;
bool bookedseats[30][6] = { false };
int addon::seatToIndicerow(string s1)
{
	int row = stoi(s1.substr(0, 2));
	return (row);
}
int addon::seatToIndicecol(string s1)
{
	char col = s1.back();
	int colidx = col - 'A';
	return (colidx);
}
void addon::bookseat(string s)
{
	int a = seatToIndicerow(s);
	int b = seatToIndicecol(s);
	bookedseats[a][b] = { true };
}
bool addon::isbooked(string s)
{
	int a = seatToIndicerow(s);
	int b = seatToIndicecol(s);
	return bookedseats[a][b];
}
bool addon::isValidSeat(string s)
{
	if (s.length() != 3)
	{
		return false;
	}
	string row = s.substr(0, 2);
	if (!isdigit(row[0]) || !isdigit(row[1]))
	{
		return false;
	}

	int rowNumber = stoi(row);
	if (rowNumber < 1 || rowNumber > 30)
	{
		return false;
	}

	char col = s[2];
	if (col < 'A' || col > 'F')
	{
		return false;
	}
	return true;
}
int flag1 = 0;
int e = 0;
int opp;
int addon::getaddon()
{
	static double veg = 200.8, nonveg = 400.6;
	int t = 0;
	static float extra_kg = 600.00;
	float q;
	cout << "1.MEAL" << endl;
	cout << "2.EXTRA BAGGAGE" << endl;
	cout << "3.FAST CHECK-IN" << endl;
	cout << "4.SEAT\n5.TRAVEL INSURANCE\n6.SKIP TO PAYMENT\n7.EXIT" << endl;
	cout << "ENTER YOUR CHOICE" << endl;
	cin >> opp;
	switch (opp)
	{
	case 1:
		cout << "ENTER THE MEAL TYPE(VEG/NON-VEG)" << endl;
		getline(cin >> ws, meal);
		cout << "ENTER QUANTITY" << endl;
		cin >> q;
		cout << "ADDED SUCCESSFULLY" << endl;
		if (q == 1)
		{
			displayaddon(meal);
		}
		else
		{
			displayaddon(meal, q);
		}
		displayaddon(0,e);
		if (meal == "VEG")
		{
			ad += (q * veg);
		}
		else
		{
			ad += (q * nonveg);
		}
		break;
	case 2:
		cout << "ENTER THE WEIGHT OF ADDITIONAL BAGGAGE(MAX 30KG.)" << endl;
		cin >> baggage;
		if (baggage <= 30)
		{
			cout << "ADDED SUCCESSFULLY" << endl;
			displayaddon(meal, q);
			displayaddon(0,e+1);
			ad += (baggage * extra_kg);
		}
		else
		{
			cout << "INVALID WEIGHT ENTERED" << endl;
		}
		break;
	case 3:
		cout << "Rs.500 FOR PRIORITY CHECK-IN/BOARDING PER PASSENGER\n DO YOU WISH TO PURCHASE(YES / NO)" << endl;
		cin >> fastforwardp;
		if (fastforwardp == "YES")
		{
			cout << "ENTER NO. OF PASSENGER" << endl;
			cin >> s;
		}
		cout << "ADDED SUCCESSFULLY" << endl;
		displayaddon(meal, 0);
		displayaddon(s,e+1);
		ad += (s * 500);
		break;
	case 4:
		if (t > e)
		{
			cout << "SORRY CAN'T BOOK SEAT MORE THAN " << e + 1 << endl;
			break;
		}
		else
		{
			cout << setfill(' ') << setw(0);
			for (int i = 1; i <= 30; i++)
			{
				if (i == 1 || i == 16)
				{
					cout.setf(ios::right, ios::adjustfield);
					cout << endl
						<< setw(18) << "EXIT" << setw(40) << "EXIT" << endl
						<< endl;
				}
				cout << setw(13) << " ";
				for (char col = 'A'; col <= 'C'; col++)
				{
					seatno = (i < 10 ? "0" : "") + to_string(i) + col;
					if (isbooked(seatno))
					{
						cout << setw(4) << "BKD" << " " << " ";
					}
					else
					{
						cout << setw(4) << seatno << " " << " ";
					}
				}
				cout << setw(13) << " ";
				for (char col = 'D'; col <= 'F'; col++)
				{
					seatno = (i < 10 ? "0" : "") + to_string(i) + col;
					if (isbooked(seatno))
					{
						cout << setw(4) << "BKD" << " ";
					}
					else
					{
						cout << setw(4) << seatno << " ";
					}
				}
				cout << endl;
				if (i == 30)
				{
					cout << endl
						<< setw(18) << "EXIT" << setw(40) << "EXIT" << endl
						<< endl;
				}
			}
			cout << "ENTER YOUR SEAT NUMBER" << endl;
			cin >> seatno;
			if (isValidSeat(seatno))
			{
				if (isbooked(seatno))
				{
					cout << "SEAT ALREADY BOOKED!!\nTRY SOME OTHER SEAT" << endl;
				}
				else
				{
					bookseat(seatno);
					cout << "SEAT BOOKED SUCCESSFULLY" << endl;
				}
			}
			else
			{
				cout << "INVALID SEATNO. ENTERED!!!\nSEAT NOT BOOKED" << endl;
			}
			displayaddon(meal, 0);
			displayaddon(0, e+1, seatno);
			t++;
			break;
		}
	case 5:
		cout << "APPLY FOR THE INSURANCE(Rs.199 PER PASSENGER)YES/NO?" << endl;
		cin >> insurance;
		if (insurance == "YES")
		{
			cout << "ENTER NO. OF PASSENGER" << endl;
			cin >> d;
		}
		cout << "ADDED SUCCESSFULLY" << endl;
		displayaddon(meal, 0);
		displayaddon(0, d);
		ad += (d * 199);
		break;
	case 6:
		if (passenger1!="STUDENT")
		{
			cout << setw(50) << setfill('*') << " " << endl;
			cout << "BASE FARE: " << ticket_price << endl;
			cout << "ADDON'S: " << ad;
			cout << "\nCONVENIENCE FEE: " << 300.75 << endl;
			cout << "\nTOTAL PRICE IS: " << cal_total(ad, ticket_price) << endl;
		}
		else
		{
			cout << "STUDENT DISCOUNT:RS.300\n";
			cout << "BASE FARE: " << ticket_price << endl;
			cout << "ADDON'S: " << ad;
			cout << "\nCONVENIENCE FEE: " << 300.75 << endl;
			cout << "\nTOTAL PRICE IS: " << (cal_total(ad, ticket_price)) - 300 << endl;
		}
		cout << setw(50) << setfill('*') << " " << "TICKET IS BOOKED SUCCESSFULLY!" << setw(31) << setfill('*') << " " << endl;
		cout << setfill(' ');
		flag1 = 1;
		return (0);
		break;
	case 7:
		system("CLS");
		return 0;
	default:
		cout << "INVALID ENTRY!!\nENTER AGAIN";
	}
}

int h;
void repos()
{
	fstream file("PASSENGER.txt", ios::app);
	int x = file.tellg();
	while (x > 0)
	{
		x--;
		file.seekg(x);char ch;
		file.get(ch);
		if (ch == '\n')
		{
			x++;
			break;
		}
	}
	file << "CANCELLED: " << endl;
	file.close();
}
class booking : public flightsearch, public addon
{
protected:
	string name1;
	string status = "BOOKED";
	int flight_no;
	string flight_name;
	string flight_full;
	string flight_full_C1;
	string flight_full_C2;
	int index;
	double pnr;
public:
	string getFlightFull(string flight_name, int flightArray[], int index);
	booking *ptr;
	void book();
	int modify(booking &d);
	int cancel(booking &b);
	int review(booking &c);
	friend int operation(booking &obja);
	friend class addon;
	bool operator==(booking &obja)
	{
		if (name == obja.name1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	booking()
	{ }
	booking(int f)
	{
		cout << setw(70) << setfill(' ') << "WELCOME TO AIRPORT MANAGEMENT SYSTEM " << setw(66) << setfill(' ');
	}
	~booking()
	{
		cout << setw(70) << setfill(' ') << "THANK YOU FOR VISTING " << name << "!" << setw(70) << setfill(' ') << "";
	}
	void details()
	{
		booking *ptr1 = ptr;
		cout << setw(45) << setfill(' ') << " " << "DEPARTURE AIRPORT: " << setw(10) << departure << endl
			<< setw(45) << setfill(' ') << " " << "ARRIVAL AIRPORT: " << setw(12) << destination << endl
			<< setw(45) << setfill(' ') << " " << "DATE OF TRAVEL : " << setw(12) << date << endl;
		if (strcmp(dir_con, "DIRECT"))
		{
			cout << setw(45) << setfill(' ') << " " << "FLIGHT NO.S : " << setw(14) << flight_full_C1 << "\tAND\t" << flight_full_C2 << endl;
		}
		else
		{
			cout << setw(45) << setfill(' ') << " " << "FLIGHT NO : " << setw(14) << flight_full << endl;

		}
		cout << endl
			<< setw(20) << setfill(' ') << " " << "PASSENGER DETAILS:\n"
			<< endl;
		if (h == 2)
		{

			for (int i = 0; i <= e; i++)
			{
				ptr->pnr = rand() % 100 + 101;
				cout << setw(30) << setfill(' ') << " " << "PNR NO.: " << setw(20) << ptr->pnr << endl;
				ptr->displaydataa(passenger1);
				cout << setw(45) << setfill(' ') << " " << "SEAT NO. " << setw(30) << ptr->seatno;
				cout << endl << endl;
				ptr++;
				if (i > e)
					break;
			}
			setfill(' ');
			ptr = ptr1;
		}
		if (h == 5 || h == 3)
		{
			int emptycount = 0;
			int z = 0;
			cout << setw(30) << setfill(' ') << " " << "PNR NO.: " << setw(20) << ptr->pnr << endl;
			ifstream file("PASSENGER.txt");
			string line;
			cout << setw(45) << setfill(' ') << " " << "DETAILS: \n";
			while (getline(file, line))
			{
				if (z == 1)
				{
					cout << setw(45) << setfill(' ') << " " << line << endl;
					if (line.empty())
					{
						emptycount++;
					}
					else { emptycount = 0; }
					if (emptycount == 2)
						break;
				}
				else if (line.find(name1) != string::npos)
				{
					if (h == 3)
					{
						/*file.close();
						repos();
						ifstream file("PASSENGER.txt");*/
						cout << setw(45) << setfill(' ') << " " << line << endl;
					}
					else
					{
						cout << setw(45) << setfill(' ') << " " << line << endl;
					}
					z = 1;
				}

			}
			file.close();
			cout << setw(45) << setfill(' ') << " " << "SEAT NO. " << setw(30) << ptr->seatno;
			cout << endl << endl;
			setfill(' ');
		}
	}
	};
		
int operation(booking &obja)
{
	while (1)
	{
		cout << setw(100) << setfill('*') << " ";
		cout << setfill(' ');
		cout << "\n1.SEARCH A FLIGHT" << endl;
		cout << "2.BOOK A FLIGHT" << endl;
		cout << "3.CANCEL A FLIGHT" << endl;
		cout << "4.MODIFY/EDIT FLIGHT DETAILS\n5.VIEW TICKET\n6.EXIT" << endl;
		cout << "ENTER YOUR CHOICE" << endl;
		cin >> h;
		system("CLS");
		switch (h)
		{
		case 1:
			obja.flight_search();
			break;
		case 2:
			// obja.booking::book();
			if (op == 2 && count2 == 0)
			{
				cout << "SORRY!FIRST YOU NEED TO SEARCH YOUR FLIGHT\n";
				break;
			}
			else
			{
				obja.book();
				if (flag1 == 1)
				{
					obja.details();
					break;
				}
			}
		case 3:
			obja.cancel(obja);
			break;
		case 4:
			obja.modify(obja);
			break;
		case 5:
			obja.review(obja);
			break;
		case 6:
			return (0);
		default:
			cout << "WRONG CHOICE ENTER AGAIN";
		}
	}
}
string booking::getFlightFull(string flight_name, int flightArray[], int index)
{
	int flight_no = flightArray[index];
	return flight_name + to_string(flight_no);
}
void booking::book()
{
	
	count1++;
	int o;
	flightdisplay();
	jump0:
	cout << endl
		<< "SELECT YOUR FLIGHT FROM ABOVE" << endl;
	cin >> o;
   if (strcmp(dir_con, "CONNECTED"))
	{
		if (o == 1)
		{
			flight_full = getFlightFull("INDIGO|6E", indigo, 1);
		}
		else if (o == 2)
		{
			flight_full = getFlightFull("VISTARA|UK", vistara, 1);
		}
		else if (o == 3)
		{
			flight_full = getFlightFull("AIR INDIA|AI", air_india, 1);
		}
		else if (o == 4)
		{
			flight_full = getFlightFull("AKASAAIR|QP", akasaair, 1);
		}
		else if (o == 5)
		{
			flight_full = getFlightFull("INDIGO|6E", indigo, 2);
		}
		else if (o == 6)
		{
			flight_full = getFlightFull("VISTARA|UK", vistara, 2);
		}
		else if (o == 7)
		{
			flight_full = getFlightFull("AIR INDIA|AI", air_india, 2);
		}
		else if (o == 8)
		{
			flight_full = getFlightFull("AKASAAIR|QP", akasaair, 2);
		}
		else
		{
			cout << "INVALID FLIGHT OPTION CHOSEN" << endl;
			goto jump0;
		}
		ticket_price = t[o];
	}
	else
	{
		if (o == 1)
		{
			ticket_price = p[o] + p[o + 1];
		}
		else
		{
			ticket_price = p[o + 1] + p[o + 2];
		}
		if (o == 1)
		{
			flight_full_C1 = getFlightFull("INDIGO|6E", indigo_c, 1);
			flight_full_C2 = getFlightFull("VISTARA|UK", vistara_c, 1);
		}
		else if (o == 2)
		{
			flight_full_C1 = getFlightFull("INDIGO|6E", indigo_c, 2);
			flight_full_C2 = getFlightFull("VISTARA|UK", vistara_c, 2);
		}
	}
	char add[10];
	ptr = new booking[20];
	booking *ptr1 = ptr;
	ptr->getpass();
	fstream file("PASSENGER.txt",ios::app);
	file << "PASSENGER DETAIS\n\n";
	if (dir_con == "CONNECTED")
	{
		file << "FLIGHT: "<<flight_full << endl;
	}
	else
	{
		file << "FLIGHT: " << flight_full_C1 << " AND " << flight_full_C2 << endl;
	}
	file.close();
ptr->getdata();
	cout << "DO YOU WANT TO BOOK MORE PASSENGERS?(YES/NO)" << endl;
	cin >> add;
	if (strcmp(add, "YES"))
	{
		system("CLS");
		while (1)
		{
			e = 0;
			ptr->getaddon();
			ptr++;
			if (opp == 7 || opp == 6)
				break;
		}
		ptr = ptr1;
	}
	else
	{
		cout << "ENTER NO.OF SEATS YOU WANT TO BOOK" << endl;
		cin >> e;
		jump9:
		for (int i = 1; i <= e; i++)
		{

			ptr++;
			ptr->getdata(); 
			if (passenger1 == "STUDENT")
			{
				cout << "ENTER STUDENT ID " << endl;
				cin >> ptr->id;
			}
		}
		ticket_price += (e * ticket_price);
		ptr = ptr1;
		while (1)
		{
			system("CLS");
			ptr->getaddon();
			ptr++;
			if (opp == 7 || opp == 6)
				break;
		}
		ptr = ptr1;
	}
}
double testpnr;
int booking::cancel(booking &b)
{
	booking *ptr1 = ptr;
	int choi, flag = 0;
	cout << "ENTER YOUR NAME" << endl;
	getline(cin >> ws, name1);
	cout << "ENTER YOUR PNR NO." << endl;
	cin >> testpnr;
	for (int k = 0; k < e + 1; k++)
	{
		if (ptr->pnr != testpnr)
		{
			ptr++;
		}
		else
		{
			if (ptr->status != "CANCELLED")
			{
				if (*ptr == b)
				{
					cout.width(45);
					cout.fill('*');
					cout << " ";
					cout << "TICKET IS CANCELLED SUCCESSFULLY**************\n";
					details();
					displayaddon(meal, s);
					displayaddon(q, d);
					cout << "STATUS:CANCELLED\n";
					flag = 1;
					ptr->status = "CANCELLED";
					break;
				}
			}
			else
			{
				cout << "TICKET IS ALREADY CANCELLED\n";
				flag = 1;
				break;
			
			}
		}
	}
		if (flag == 0)
		{
			cout << "RECORD NOT FOUND!" << endl;
			while (1)
			{
				cout << "1.ENTER VALID NAME & PNR AGAIN" << endl;
				cout << "2.EXIT" << endl;

				cout << "ENTER YOUR CHOICE" << endl;
				cin >> choi;
				system("CLS");
				switch (choi)
				{
				case 1:
					system("CLS");
					ptr = ptr1;
					cancel(b);
					break;
				case 2:
					return 0;
				default:
					cout << "WRONG CHOICE ENTER AGAIN" << endl;
				}
			}
		}
		ptr = ptr1;
}
int booking::review(booking &c)
{
	booking *ptr1 = ptr;
	int opp, flag = 0, flag5 = 0;
	cout << "ENTER YOUR NAME" << endl;
	getline(cin >> ws, name1);
	cout << "ENTER PNR NUMBER\n";
	cin >> testpnr;
	if (count1 == 0)
	{
		cout << "RECORD NOT FOUND!\n";
		return (0);
	}
	else
	{
		for (int i = 0; i < e + 1; i++)
			{
				if (ptr->pnr != testpnr)
				{
					ptr++;
				}
				else
				{
				if (ptr->status != "CANCELLED")
				{
					if (*ptr == c)
					{
						cout.width(80);
						cout.fill('*');
						cout << " ";
						cout << endl;
						details();
						displayaddon(meal, s);
						displayaddon(q, d);
						flag = 1;
						break;
					}
					ptr++;
				}
				else
				{
					cout << "TICKET IS ALREADY CANCELLED !" << endl;
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0)
		{
			cout << "RECORD NOT FOUND!" << endl;
			while (1)
			{
				cout << "1.ENTER VALID NAME & PNR AGAIN" << endl;
				cout << "2.EXIT" << endl;

				cout << "ENTER YOUR CHOICE" << endl;
				cin >> opp;
				switch (opp)
				{
				case 1:
					system("CLS");
					ptr = ptr1;
					review(c);
					break;
				case 2:
					return 0;
				default:
					cout << "WRONG CHOICE ENTER AGAIN" << endl;
				}
			}
		}
		ptr = ptr1;
	}
}
int booking::modify(booking &d)
{
	booking *ptr1 = ptr;
	int choice, flag = 0, x;
	cout << "ENTER YOUR NAME" << endl;
	getline(cin >> ws, name1);
	cout << "ENTER YOUR PNR AGAIN\n";
	cin >> testpnr;
	if (count1 == 0)
	{
		cout << "RECORD NOT FOUND!\n";
		return (0);
	}
	else
	{
		
		for (int i = 0; i < e + 1; i++)
		{
			if (ptr->pnr != testpnr)
			{
				ptr++;
			}
			else
			{
				if (ptr->status != "CANCELLED")
				{
					if (*ptr == d)
					{
						ptr->displaydataa();
						cout.width(60);
						cout.fill('*');
						cout << "\nMODIFY FLIGHT DETAILS" << endl;
						cout << "1.MODIFY DEPARTURE AIRPORT" << endl;
						cout << "2. MODIFY ARRIVAL AIRPORT" << endl;
						cout << "3. MODIFY DAT OF TRAVEL" << endl;
						cout << "4. MODIFY PASSENGER INFORMATION" << endl;
						cout << "ENTER YOUR CHOICE: ";
						cin >> choice;
						flag = 1;
						switch (choice)
						{
						case 1:
							cout << "ENTER NEW DEPARTURE AIRPORT: ";
							cin >> ptr->departure;
							cout << "NEW TICKET NEEDS TO BE ISSUED." << endl;
							ptr->getdata();
							break;
						case 2:
							cout << "ENTER NEW ARRIVAL AIRPORT: ";
							cin >> ptr->destination;
							cout << "NEW TICKET NEEDS TO BE ISSUED." << endl;
							ptr->getdata();
							break;
						case 3:
							cout << "ENTER NEW DATE OF TRAVEL: ";
							cin >> ptr->date;
							cout << "NEW TICKET NEEDS TO BE ISSUED." << endl;
							ptr->getdata();
							break;
						case 4:
							cout << "MODIFYING PASSENGER INFORMATION." << endl;
							ptr->getdata();
							break;
						default:
							cout << "INVALID CHOICE!!!\tTRY AGAIN" << endl;
						}
						cout << "FLIGHT DETAILS MODIFIED SUCCESSFULLY." << endl;
					}
					ptr++;
				}
				else
				{
					cout << "TICKET IS ALREADY CANCELLED !" << endl;
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0)
		{
			cout << "RECORD NOT FOUND!" << endl;
			while (1)
			{
				cout << "1.ENTER VALID PNR AGAIN" << endl;
				cout << "2.EXIT" << endl;

				cout << "ENTER YOUR CHOICE" << endl;
				cin >> x;
				switch (x)
				{
				case 1:
					cancel(d);
					break;
				case 2:
					return 0;
				default:
					cout << "WRONG CHOICE ENTER AGAIN" << endl;
				}
			}
		}
		ptr = ptr1;
	}
}
int flag2 = 0;
int passwordcheck()
{
	string pass;
	cout << "ENTER ADMIN PASSWORD\n";
	cin >> pass;
	if (pass == "23CE103" || pass == "23CE113")
	{
		return 1;
	}
	else
		return 0;
}
void welcome(booking &b)
{
	int passcheck = 0;
	cout << "ENTER YOUR NAME\n";
	getline(cin>>ws,b.name);
	system("CLS");
	while (1)
	{
		cout << "HELLO " << b.name << "!" << endl;
		cout << "\nENTER\n 1.IF A PASSENGER\n 2.IF STAFF\n 3.JOB APPLICANT\n 4.EXIT" << endl;
		cin >> op;
		cout.fill(' ');
		system("CLS");
		switch (op)
		{
		case 1:
			operation(b);
			flag2 = 1;
			break;
		case 2:
			passcheck = passwordcheck();
			if (passcheck == 1)
			{
				cout << setw(50) << "LOGIN SUCCESSFULL" << setw(40) << "" << endl;
				stafff(b);
			}
			else
			{
				system("CLS");
				cout << setw(65) << "INVALID PASSWORD ENTER AGAIN\n";
				passwordcheck();
			}
			flag2 = 1;
			break;
		case 3:
			b.applypost();
			flag2 = 1;
			break;
		case 4:
			break;
		default:
			cout << "INVALID ENTRY \n ENTER AGAIN!!\n";
		}
		if (flag2 == 1)
			break;
		if (op == 4)
			break;
	}
}
int main()
{
		int op;{
		booking b(1);
		welcome(b);
		int a;
	jump1:
		cout << "\n\n1.GO BACK TO MAIN SCREEN\n  EXIT(PRESS ANY NO.)\n";
		cin >> a;
		system("CLS");

		if (a == 1)
		{
		jump:
			if (flag2 == 1) // atleast once welcome has been called
			{
				system("CLS");
				cout << setw(70) << setfill(' ') << "WELCOME TO AIRPORT MANAGEMENT SYSTEM " << setw(66) << setfill(' ');
				welcome(b);
				goto jump1;
				goto jump;
			}
		}
	}
}