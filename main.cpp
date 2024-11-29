#include <iostream>
#include<fstream>
#include <string>
using namespace std;

class item{
	string itemname;
	string supplier;
	int quantity;
	int price;
	
	public:
		static int itemcount;
		item(){
		}
		
		item(int a){
		
			cout<<"\n\n---------------INPUT ITEM DETAILS---------------";
			cout << endl<<" Enter item name: ";
			cin >> itemname;
			
			cout << " Enter the supplier brand: ";
			cin >> supplier;
			
			int pos; 
			do{
						
				cout << " Enter the quantity required: ";
				cin >> quantity;
				void exceptionhandle();
			
		    } while (pos==-1);
			
			cout << " Enter price: Rs. ";
			cin >> price;	
			itemcount++;
		}
		
		item (string n, string s, int q, int p): itemname(n), supplier(s), quantity(q), price(p){	itemcount++;}
		
		void set_itemName(  string itemname){			this->itemname = itemname;		}
		void set_supplier(  string supplier){			this->supplier = supplier;		}
		void set_quantity( const int quantity){			this->quantity = quantity;		}
		void set_price( const float price){			this->price = price;		}
		string get_itemName() const{			return itemname;		}
		string get_supplier() const{			return supplier;		}
	    int get_quantity() const{			return quantity;		}
		int get_price() const{			return price;		}
		
		int exceptionhandle(){
			int pos;
			try{
				if(!(int)quantity)
					throw -1;
					
			    else{
			       cout<<"\n\n Data stored successfully!"<<endl;
			       pos = 0;
			    }
		    }
			catch(int a){
				cout<<"\n\n Exception caught! Input other than integer value...."<<endl;
			}
			return pos;
			
		}
		
		void display(){
			cout<<" --------------ITEM DETAILS---------------";
			cout <<endl<< " Item name: " << itemname << endl;
			cout << " Supplier: " << supplier << endl;
			cout << " Quantity: " << quantity << endl;
			cout << " Price: Rs. " << price << endl << endl;
			
		}
};  
int item::itemcount=0;

class finance{
	static double balance;
	double expense;
	double profit;
	public :
	Finance(){	return 0;	}

	friend class accountant;
	
	static void addExpense(double expense){
		int n = 1;
		do{
			try{
				if(!(double)expense)
				throw 'a';
				
			    else 
			      n = 0;
			}
		
			catch(char a){
				cout<< "\n\n Exception caught! Input other than string value....";
				cout<< "\n\n Enter expense value : ";
				cin >> expense;
			}

		}while (n == 1);
	
		balance  = balance - expense;
		cout << "\n Current balance : Rs. "<< balance;
		
	}
	
	static void addProfit(double profit){
		int n = 1;
		do{
			try{
				if(!(double)profit)
				throw 'a';
				
			    else 
			      n = 0;
			}
			
			catch(char a){
				cout<< "\n\n Exception caught! Input other than string value....";
				cout<< "\n\n Enter profit value : ";
				cin >> profit;
			}

		}while (n == 1);

		balance  = balance + profit;
		cout << "\n Current balance : Rs. "<< balance;
	}
	
	
};
double finance::balance=0;

class table{
	bool available;
	string wing, tablenum;
	public:
		friend class employee;
		friend class reservation;
		static int totalb;
		
		void setavail(bool n){	available = n;	}
		bool getavail(){	return available;	}		
		string getwing(){	return wing;	}		
		void setwing(string n){	wing = n;	}
		string gettablenum(){	return tablenum;	}		
		void settablenum(string n){	tablenum = n;	}
		table():available(true){
			totalb++;	
			cout << endl << " Enter wing: ";
			getline(cin,wing);
			
			cout << " Enter table number: ";
			cin >> tablenum;
		}
			
		table(string w, string b): wing(w), tablenum(b), available(true){
			totalb++ ;
		}
		static int bpos(string tn, string w, table *b[]){

			for (int i = 0 ; i < table::totalb ; i++){
				if ( tn == (*b[i]).gettablenum() && w == (*b[i]).getwing() ){
					return i;
				}				
			}
			return -1;	
		}		
		
		static void addtable(table *b[]){
			*( b+(table :: totalb-1) ) = new table();	
		}
		
		void display(){
			cout << endl << " Wing: " << wing << endl;
			cout << " Table number: " << tablenum << endl;
			cout << " Available: " << ((available == true) ? "Yes" : "No") << endl;
		}
};
int table :: totalb = 0;

class reservation{
	string id, name;
	string tablenum, wing;
	
	public:
		
		friend class employee;		
		static int totalp;
		
		string getid(){	return id;	}
		void setid(string n){	id = n;	}		
		string getname(){	return name;	}		
		void setname(string n){	name = n;	}
		string getwing(){	return wing;	}		
		void setwing(string n){	wing = n;	}
		string gettablenum(){	return tablenum;	}		
		void settablenum(string n){	tablenum = n;	}
		
		reservation(table* b[]){
			totalp++;
			
			cout << endl << " Enter reservation ID: ";
			cin >> id;
			
			cout << " Enter name: ";
			getline(cin, name);
			getline(cin, name);
			
			int pos;
			do{
				cout << " Enter wing: ";
				getline(cin, wing); 
				
				cout << " Enter table number: ";
				getline(cin, tablenum);
				
				pos = table::bpos(tablenum, wing, b);
				try{
				
				    if(pos == -1)           
				        throw pos;
                    
	     			else
					(*b[pos]).setavail(false);
			    } 
				catch(int pos){
					cout<<" Table/ Wing not found....."<<endl;
				}
		    }while(pos == -1);
			
			cout << " Reservation Check-in successful!"<< endl;
		}
		
		reservation(string i, string n, string w, string bn, table *b[]): id(i), name(n), wing(w), tablenum(bn){
			totalp++;
			int pos = table::bpos(tablenum, wing, b);
			(*b[pos]).setavail(false);
		}
		
		void display(){
			cout<<"\n\n-----------------RESERVATION DETAILS-----------------";
			cout << endl << " Customer ID: " << id << endl;
			cout << " Name: "  << name << endl;
			cout << " Wing: " << wing  << endl;
			cout << " Table number: " << tablenum  << endl;
			
		}
		
		static int ppos(string id, reservation *p[]){

			for (int i = 0 ; i < reservation::totalp ; i++){
				if ( id == (*p[i]).getid() ){
					return i;
				}				
			}
			return -1;	
		}		
		
};
int reservation :: totalp = 0;

class employee{
	string userid, pw;
	
	public:
		static int totals;
		
		string getuserid(){	return userid;	}	
		string getpw(){	return pw;	}		
		void setuserid(string n){	userid = n;	}		
		void setpw(string n){	pw = n;	}
		
		employee(string e){
			totals++;					
			
			cout << endl << " Enter " << e << " ID: ";
			cin >> userid;
			
			string pw2;
			do{
				cout << " Enter password: ";
				cin >> pw;
				
				cout << " Re-enter password: ";
				cin >> pw2;
				
				try{
				
				    if (pw != pw2)
				    	throw 505;
				    	
				    else{
					    cout << " " << e << " Account made successfully" << endl;
					    cout << " Account ID: " << userid << endl;
				    }
				}
				catch(...){
					cout << " Passwords don't match! Try again" << endl;
				}
				
			} while (pw!=pw2);
			
		}
		
		employee(string i, string p): userid(i), pw(p){
			totals++;
		}
	virtual void menu(){
		cout << endl << " 0- Log out " << endl;
		cout << " 1- View reservation report " << endl;
		cout << " 2- View table report " << endl;
	}
	
	virtual int getchoice() = 0;

	static void logout(){
		cout << endl << " Logging out  . . ." << endl << endl;
	}
	
	static void viewreservation(reservation *p[]){
		
		string searchID;
		int pos;
		do{
			cout << endl << " Enter reservation ID: ";
			cin >> searchID;
			
			pos = reservation::ppos(searchID, p);
			try{
			
			    if (pos == -1)
			    	throw pos;
				
			}
			catch(int pos){
				cout << " Customer not found. . . Please retry" << endl;
		    }
		} while (pos == -1);
		
		(*p[pos]).display();
	}
	
	static void viewtable(table *b[]){
		
		string tablenum, wing;
		cout<<"\n\n---------------INPUT DETAILS---------------";
		cout<< "\n Enter table number: ";
		cin >> tablenum;
		cout << " Enter wing: ";
		getline(cin, wing);
		getline(cin, wing);
		int pos = table::bpos(tablenum, wing, b);
		(*b[pos]).display();
	}
		
	static int spos(string userID, string pw, employee *s[]){
	
		for (int i = 0 ; i < employee::totals ; i++){				
			if ( userID == (*s[i]).getuserid() && pw == (*s[i]).getpw() ){
				return i;
			}				
		}			
		return -1;
		
	}
		
	static int spos(string userID, employee *s[]){

		for (int i = 0 ; i < employee::totals ; i++){				
			if ( userID == (*s[i]).getuserid() ){
				return i;
			}				
		}			
		return -1;
		
	}
	
	void display(){
		cout<<"\n\n---------------EMPLOYEE DETAILS---------------"<<endl;
		cout << " Employee account: " << userid << endl << " Password: " << pw << endl;
	}
			
};
int employee :: totals = 0;

class accountant : public employee{
	
	public:
		accountant() : employee("Accountant"){		}
		accountant(string i, string p) : employee(i, p){		}
		
		void menu(){	
			employee::menu();
			cout << " 3- Add expense" << endl;
			cout << " 4- Add profit" << endl;
			
		}
		
		int getchoice(){
			int c;
			do{
				cout << endl << " Enter choice: ";
				cin >> c;
				if (c <0 || c > 4){
					cout << " Invalid choice. Try again" << endl;
				}
				
			} while (c < 0  || c > 4 );
			
			if ( c == 3)
				c = 6;
				
			if (c == 4)
				c = 7;
			
			return c;
		}
		
		static void expense(){
			double expense;
			cout << " Enter expense : ";
			cin >> expense;
			finance::addExpense(expense);
		}
		
		static void profit(){
			double profit;
			cout << " Enter profit : ";
			cin >> profit;
			finance::addProfit(profit);
		}
		
};

class wingstaff : public employee{
	public:
		wingstaff() : employee("Wing Staff"){					}
		wingstaff(string i, string p) : employee(i, p){		}
		
		void menu(){	
			employee::menu();
			cout << " 3- Evacuate table (shift reservation) " << endl;
			cout << " 4- Remove reservation " << endl;
			
		}
		
		int getchoice(){
			int c;
			do{
				cout << endl << " Enter choice: ";
				cin >> c;
				
				if (c < 0 || c > 4){
					cout << " Invalid choice. Try again" << endl;
				}
				
			
			} while (c < 0  || c > 4 );
	
			return c;
		}
		
		static void evactable(string tablenum, string wing, table *b[]){
			
			int pos;
			pos = table::bpos(tablenum, wing, b);
		
			(*b[pos]).setavail(true);
	
		}
		
		static void deletereservation(reservation *p[], table *b[]){
			string searchID;
			int pos;
			do{
				cout << endl << " Enter reservation customer ID: ";
				cin >> searchID;
				
				pos = reservation::ppos(searchID, p);
				
				try{
				    if (pos == -1){
				    	throw pos;
					}
				}
				catch(int pos){
					cout << " Customer not found. . . Please retry" << endl;
				}
			} while (pos == -1);
			
			cout << " Evacuating table . . . " << endl;
			
			evactable((*p[pos]).gettablenum(), (*p[pos]).getwing(), b	);
			delete p[pos];
			reservation::totalp--;
			
			cout << " Customer Check-out successful! " << endl;
			
		}
		
		static void changetable(reservation *p[], table *b[]){
			
			string searchID;
			int pos;
			do{
				cout << endl << " Enter reservation ID: ";
				cin >> searchID;
				
				pos = reservation::ppos(searchID, p);
				
				try{
				
				    if (pos == -1)
				        throw pos;
				}
				catch(int pos){
					cout << " Customer not found. . . Please retry" << endl;
				}
			} while (pos == -1);
			
			evactable(		(*p[pos]).gettablenum(), (*p[pos]).getwing(), b	);
			cout << " Previous table evacuated" << endl;
			
			int pos2;
			do{
				string tablenum;
				cout << " Enter new table number: ";
				cin >> tablenum;
				
				string wing; 
				cout << " Enter new table wing: ";
				cin >> wing;
				
				pos2 = table::bpos(tablenum, wing, b);
				
				if (pos2 == -1)
					cout << " Table not found in " << wing << " wing . . ." << endl;
				else if ( (*b[pos2]).getavail() == false){	
					cout << " Table is already occupied . . ." << endl;
					pos2=-1;
				}
				else{
					(*b[pos2]).setavail(false);
					(*p[pos]).settablenum(		(*b[pos]).gettablenum()	);
					
				}
					
				
			} while (pos2 == -1);
				
		}
		
};

class receptionist : public employee{
	public:
		receptionist() : employee("Receptionist"){		}
		receptionist(string i, string p) : employee(i, p){		}
		
		void menu(){	
			employee::menu();
			cout << " 3- Add reservation " << endl;
			
		}
		
		int getchoice(){
			int c;
			do{
				cout << endl << " Enter choice: ";
				cin >> c;
				
				if (c < 0 || c > 3){
					cout << " Invalid choice. Try again" << endl;
				}
				
			} while (c < 0  || c > 3 );
			
			if (c == 3)
				c = 5;
			
			return c;
			

		}


		
		static void addreservation(reservation *p[], table *b[]){
			*( p+(reservation :: totalp-1) ) = new reservation(b);	
		}
		
		static void addaccountant(employee *s[]){
			*( s+(employee :: totals-1) ) = new accountant();	
		}
		
};

class admin{
	
	public:
		static string adminpw;
		static int menu(){
			int c; 
					
			cout << endl << " 0- Log out " << endl;
			cout << " 1- View reservation report " << endl;
			cout << " 2- View table report " << endl;
			cout << " 3- Add accountant " << endl;
			cout << " 4- Add front desk staff / receptionist  " << endl;
			cout << " 5- Add wing staff " << endl;
			cout << " 6- View staff account " << endl;
			cout << " 7- Add item " << endl;
			cout << " 8- View inventory " << endl;
				
			do{
				cout << " Enter choice --> ";
				cin >> c;
				
				if (c <0 || c > 8){
					cout << " Invalid choice. Try again" << endl;
				}
				
			} while (c < 0  || c > 8 );
			
			return c;
		}
		
		static bool login(string pw){
			if (pw == adminpw){
				return true;
			}
			return false;
		}
		
		static void addwingstaff(employee *s[]){
			*( s+(employee :: totals-1) ) = new wingstaff();	
		}
		
		static void addaccountant(employee *s[]){
			*( s+(employee :: totals-1) ) = new accountant();	
		}
		
		static void addreceptionist(employee *s[]){
			*( s+(employee :: totals-1) ) = new receptionist();	
		}
		
		static void additem(item *s[]){
			*( s+(item :: itemcount-1) ) = new item(1);	
		}
		
		static void viewstaff(employee *s[]){
		
			string searchID;
			int pos;
			do{
				cout << endl << " Enter staff ID: ";
				cin >> searchID;
				
				pos = employee::spos(searchID, s);
				
			    try{
				
				    if (pos == -1)
				    	throw pos;
			    }
			    catch(int pos){
					cout << " Staff not found. . . Please retry" << endl;
			    }
			} while (pos == -1);
			
			(*s[pos]).display();
		}
		
		static void inventory(item *items[]){
			for (int i=0 ; i<item::itemcount ; i++){
				cout << " #" << i << " " << endl;
				(*items[i]).display();
				cout << endl;
			}
		}
};
string admin :: adminpw = "admin123";

int main(){
	

	employee * s[100];
	reservation *p[100];
	table * b[100];
	item * items[100];
    
    // loading file values to object array
	item getitems[100];
	item saveitems[100];
	
	item getreservations[100];
	item savereservations[100];
	
	item gettables[100];
	item savetables[100];
	
	// making pointer array point to object array elements
	for (int i = 0 ; i < 1 ; i++){
		items[i] = &getitems[i];
	}

	// hardcoding sample data
	
	*(items+(item :: itemcount-1) ) = new item("utensil packs", "ikea", 50, 100);
	*( items+(item :: itemcount-1) ) = new item("disinfectant bottles", "dettol", 10, 150);
	*( items+(item :: itemcount-1) ) = new item("tablecloth", "gucci", 30, 300);
	*( items+(item :: itemcount-1) ) = new item("freezer", "LG", 5, 25000); 
	
	*( s+(employee :: totals-1) ) = new receptionist("R1", "r");
	
	*( s+(employee :: totals-1) ) = new accountant("A1", "a");
	*( s+(employee :: totals-1) ) = new accountant("A2", "a");
	
	*( s+(employee :: totals-1) ) = new wingstaff("W1", "w");
	*( s+(employee :: totals-1) ) = new wingstaff("W2", "w");
	*( s+(employee :: totals-1) ) = new wingstaff("W3", "w");
	
	*( b+(table :: totalb-1) ) = new table("Family", "1");	
	*( b+(table :: totalb-1) ) = new table("Family", "2");	
	*( b+(table :: totalb-1) ) = new table("VIP", "1");	
	*( b+(table :: totalb-1) ) = new table("VIP", "2");	
	*( b+(table :: totalb-1) ) = new table("Business", "1");	
	*( b+(table :: totalb-1) ) = new table("Business", "2");	
	*( b+(table :: totalb-1) ) = new table("Business", "3");	
	*( b+(table :: totalb-1) ) = new table("Business", "4");	
	
	*( p+(reservation :: totalp-1) ) = new reservation("C1", "Sam Buddy", "Family", "1", b);
	*( p+(reservation :: totalp-1) ) = new reservation("C2", "Annie Wun", "VIP", "2", b);
	*( p+(reservation :: totalp-1) ) = new reservation("C3", "Jane Doe", "Business", "1",  b);	
	


    system("cls");
	cout<<endl<<endl<<endl<<endl<<endl; 
	cout<<"\x1b[93m\t\t.-------..-------..-------..-------..-------..-------..-------.\n";
	cout<<"\t\t| ----- || ----- || ----- || ----- || ----- || ----- || ----- |\n";
	cout<<"\t\t|       ||       ||       ||       ||       ||       ||       |\n";
	cout<<"\t\t|   W   ||   E   ||   L   ||   C   ||   O   ||   M   ||   E   |\n";
	cout<<"\t\t|       ||       ||       ||       ||       ||       ||       |\n";
	cout<<"\t\t| ----- || ----- || ----- || ----- || ----- || ----- || ----- |\n";
	cout<<"\t\t'-------''-------''-------''-------''-------''-------''-------'\n\x1b[97m";  
	cout<<endl<<endl<<endl<<endl<<endl;  
    system("pause");
	system("cls");
	cout<<"\x1b[91m             ________   ___  _____   ___ ___  _____   __  _________ "<<endl; 
	cout<<"            |         ||   ||     | |  ||   ||     | |  ||         |"<<endl;
	cout<<"            |    _    ||   ||     | |  ||   ||     | |  ||    _____|"<<endl;
	cout<<"            |   | )   ||   ||     |_|  ||   ||     |_|  ||   |      "<<endl;
	cout<<"            |   |/    /|   ||   _      ||   ||   _      ||   |  __ |"<<endl;
	cout<<"            |        / |   ||  | |     ||   ||  | |     ||   |___| |"<<endl;
	cout<<"            |_______/  |___||__| |_____||___||__| |_____||_________|\n\n\x1b[97m"<<endl;  
    cout<<"\n _________________________________________________________________________________"<<endl;
	cout<<"|                             MANAGEMENT SYSTEM!                                  |"<<endl;
	cout<<"|_________________________________________________________________________________|"<<endl;
	            
	system("pause");          
	system("cls");
	cout << "\n Sample values have been stored for testing and demo. These can be updated. " <<endl <<endl; 
	cout << "\n Please login to continue " <<endl <<endl; 
	
	int choice;
	
	string userID, pw;
	int userpos;
	
	do {
		
		cout << " Enter user ID: ";
		cin >> userID;
		
		cout << " Enter password: ";
		cin >> pw;
		
		
		if (userID == "Admin" && admin::login(pw) == true){
			cout << endl <<  " Success! Logged in as Admin " << endl;
			
			system("pause");
			do{
				choice = admin::menu();
				
				switch(choice){
					case 0:
						employee::logout();
						break;
					
					case 1:{
						employee::viewreservation(p);
						break;
					}
					
					case 2:{
						employee::viewtable(b);
						break;
					}
						
					case 3:
						admin::addaccountant(s);
						break;
						
					case 4:
						admin::addreceptionist(s);
						break;
						
					case 5:
						admin::addwingstaff(s);
						break;
					
					case 6:
						admin::viewstaff(s);
						break;
						
					case 7:
						admin::additem(items);
						break;
						
					case 8:
						admin::inventory(items);
						break;
						
				}
			} while (choice != 0);
		}
		
		else{
			
			userpos = employee::spos(userID, pw, s);
			
			try{
			
			    if (userpos == -1)
			        throw userpos;
			    
							
			else{
				
				cout << endl <<  " Success! Logged in as employee " <<  ( *s[userpos] ).getuserid() << endl;
				do{
					(*s[userpos]).menu();
					choice = (*s[userpos]).getchoice();
					
					switch(choice){
						case 0:
							employee::logout();
							break;
						
						case 1:{
							employee::viewreservation(p);
							break;
						}
							
						case 2:{
							employee::viewtable(b);
							break;
						}
							
						case 3:{
							wingstaff::changetable(p,b);
							break;
						}
							
						case 4:
							wingstaff::deletereservation(p,b);
							break;
								
						case 5:
							receptionist::addreservation(p,b);
							break;
							
						case 6:{
							accountant::expense();
							break;
							
						case 7:
							accountant::profit();
							break;
							
						}
							
						
					}
				} while (choice != 0);
				
			}
		}
	
		catch(int pos){
			cout << endl << " Not found! Incorrect username or password. . ." << endl << endl;
		}
	}
		
		cout << " ENTER X TO EXIT PROGRAM, L TO LOGIN: ";
		string x;
		cin>>x;
		
		if (x=="X" || x=="x")
			userpos=0;
		else
			userpos = -1;
	
	} while (userpos == -1);
	
	ofstream fout;                 //filing of class items
	fout.open("inventory.txt", ios::out );	
	if(!fout.is_open()) {
		cout << " Error - Item file not opened! \n";
	
		fout.close();
	} 
	else {
	    cout << " Item file opened successfully! \n";
	}
	
	for(int i = 0; i < item::itemcount; i++){
			getitems[i] = (*items[i]);
			getitems[i].display();
	}
	
	
    fout.write((char *)&getitems,sizeof(getitems));
	fout.close();
	
	ifstream fin;
	fin.open("inventory.txt", ios::in | ios::ate);
	if(!fin.is_open()) {
        cout << " Error - Item file not created! \n";
	} 
	else {
		cout << " Item file saved successfully! \n";

	}
	fin.read((char*)&saveitems, sizeof(saveitems));
	
	for(int i = 0; i < item::itemcount; i++){

		saveitems[i].display();
	}
	fin.close();
	
	//filing Method #2
	//item tempitem[item::itemcount];
	
	//file storing
	//fout.open("inventory.txt",ios::out);
	//if(!fout.is_open()) {
	//	cout << " Error - File not opened! \n";
		

    //   fout.close();
	//     else {
	//		cout << " File opened successfully! \n";
	//   }
	//  for(int j = 0; j < item::itemcount ; j++){
    //	fout << tempitem[j].get_itemName();
    //	fout << tempitem[j].get_itemName();
    //	fout << tempitem[j].get_itemName();
    //	fout << tempitem[j].get_itemName();
    // }
    //fout.close();
		
    //	for(int i = 0; i < item::itemcount; i++){
	//		tempites[i] = (*items[i]);
	//		tempitem[i].display();
	//}
    
    //file reading;
    //fin.open("inventory.txt", ios::in);
    // string name, supp;
    //int q;
    //int price;
	//
	//for(int i = 0; i <item::itemcount ; i++){
    //	fin >> name;
	//	tempitem[i].set_itemName(name);
	//	fin >> supp;
	//	tempitem[i].set_supplier(supp);
	//	fin >> q;
	//	tempitem[i].set_quantity(q);
	//	fin >> price;
	//	tempitem[i].set_price(price);
	//}
	//fin().close();
	
			
	//filing of class Resevation to store reseravation details
	fout.open("reservations.txt", ios::out );	
	if(!fout.is_open()) {
		cout << " Error - Reservation file not opened! \n";
	
		fout.close();
	} 
	else {
	    cout << " Reseravtion file opened successfully! \n";
	}
	
	for(int i = 0; i < reservation:: totalp; i++){
		//	getreservations[i] = (*p[i]);
			getreservations[i].display();
	}
	
	
    fout.write((char *)&getreservations,sizeof(getreservations));
	fout.close();
	
	fin.open("Reservations.txt", ios::in | ios::ate);
	if(!fin.is_open()) {
        cout << " Error - Reservation file not created! \n";
	} 
	else {
		cout << " Reservation file saved successfully! \n";

	}
	fin.read((char*)&savereservations, sizeof(savereservations));
	
	for(int i = 0; i < reservation::totalp; i++){

		savereservations[i].display();
	}
	fin.close();	

	//filing for class Table to store Table details
	fout.open("table details.txt", ios::out );	
	if(!fout.is_open()) {
		cout << " Error - Table file not opened! \n";
	
		fout.close();
	} 
	else {
	    cout << " Table file opened successfully! \n";
	}
	
	for(int i = 0; i < table:: totalb; i++){
		//	gettables[i] = (*b[i]);
			gettables[i].display();
	}
	
	
    fout.write((char *)&gettables,sizeof(gettables));
	fout.close();
	
	fin.open("table details.txt", ios::in | ios::ate);
	if(!fin.is_open()) {
        cout << " Error - Table file not created! \n";
	} 
	else {
		cout << " Table file saved successfully! \n";

	}
	fin.read((char*)&savetables, sizeof(savetables));
	
	for(int i = 0; i < table::totalb; i++){

		savetables[i].display();
	}
	fin.close();

	

	
}
