#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Student {
    private:
    
    int number;
	char name[50];
	int physics_m, chemistry_m, math_m, english_m;
	double average; 
	char grade; // A, B, C or F
	void calculate();
	
    public:
	void getdata();		
	void showdata() const;	
	void show_table() const;
	int return_number() const;
};

void Student::calculate(){
    average = (physics_m+chemistry_m+math_m+english_m) / 4;
    if(average >= 60)
        grade = 'A';
    else if(average >= 50)
        grade = 'B';
    else if(average>= 40)
        grade = 'C';
    else
        grade = 'F';
}

void Student::getdata(){
    cout << "Enter student's number: " << endl;
    cin >> number;
    cout << "Enter student's name: " << endl;
    cin >> name;
    cin.ignore(); //cleaning the buffer
    cin.getline(name, 50);
    cout<<"Enter the marks in physics out of 100 : " << endl;
    cin>>physics_m;
	cout<<"Enter the marks in chemistry out of 100 : " << endl;
	cin>>chemistry_m;
	cout<<"Enter the marks in maths out of 100 : " << endl;
	cin>>math_m;
	cout<<"Enter the marks in english out of 100 : " << endl;
	cin>>english_m;
	calculate();
    
}

void Student::showdata() const{
    cout << "Student's number: " << number << endl;
    cout << "Student's name: " << name << endl;
    cout << "Physics out of 100: " << physics_m << endl;
    cout << "Chemistry out of 100: " << chemistry_m << endl;
    cout << "Maths out of 100: " << math_m << endl;
    cout << "English out of 100: " << english_m << endl;
    cout << "Average mark: " << average << endl;
    cout << "Grade: " << grade << endl;
}

void Student::show_table() const{
    cout<<number<<setw(6)<<" "<<name<<setw(10)<<physics_m<<setw(4)
    <<chemistry_m<<setw(4)<<math_m<<setw(4)
    <<english_m<<setw(4)<<average<<setw(8)<<grade<<setw(6)<<endl; //setw for output width
}

int Student::return_number() const{
    return number;
}


void enter();
void show_all();	
void search(int n);	
void edit(int n);	
void delete_s(int n);	
void class_result();	
void data();		
void welcome();		
void entry();

int main()
{
    int n;
	cout.setf(ios::fixed|ios::showpoint); //setf - formating output (fixed point in double, decimal point is always written)
	cout<<setprecision(2); // program outputs decimal number to two decimal places
	welcome();
	do
	{
		system("cls"); //cleaning the screen
		cout<<"\n\n\n\tSTUDENT REGISTER SYSTEM"<< endl;
		cout<<"\n\n\t1. ENTRY/EDIT DATA"<< endl;
		cout<<"\n\n\t2. SHOW DATA"<< endl;
		cout<<"\n\n\t3. EXIT"<< endl;
		cout<<"\n\n\tPlease, select your option (1-3) "<< endl;
		cin>>n;
		switch(n)
		{
			case 1: entry();
				break;
			case 2: data();
				break;
			case 3: break;
			default :cout<<"\a";
		}
    }while(n != 3);

    return 0;
}

void welcome(){
    cout << "\n\n\n\tHELLO! WELCOME TO STUDENT REGISTER SYSTEM!" << endl;
    cout << "\n\n\n\tYOU CAN STORAGE THE MARK DATA OF YOUR STUDENTS HERE" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "\n\n\n\tTHANK YOU FOR USING THIS SYSTEM" << endl;
}

void entry(){
    int n;
    int num;
   do
	{
		system("cls"); //cleaning the screen
		cout << "\n\n\n\tYOU CAN ENTRY OF EDIT YOUR DATA HERE" << endl;
		cout << "\n\n\t1. ENTER STUDENT" << endl;
		cout << "\n\n\t2. EDIT INFORMATION ABOUT STUDENT" << endl;
		cout << "\n\n\t3. SEARCH INFORMATION ABOUT STUDENT" << endl;
	    cout << "\n\n\t4. DELETE INFORMATION ABOUT STUDENT" << endl;
	    cout << "\n\n\t5. SHOW INFORMATION ABOUT ALL STUDENTS" << endl;
	    cout << "\n\n\t6. BACK TO MENU" << endl;
		cout << "\n\n\tPlease, select your option (1-6) " << endl;
		cin >> n;
		switch(n)
		{
			case 1: enter();
				    break;
			case 2: cout << "Enter the student number: " << endl;
			        cin>> num;
			        edit(num);
				    break;
			case 3: cout << "Enter the student number: " << endl;
			        cin>> num;
			        search(num);
				    break;
			case 4: cout << "Enter the student number: " << endl;
			        cin>> num;
			        delete_s(num);
			case 5: show_all();
			        break;
			case 6: break;
			default :cout<<"\a";
				entry();
		}
	}while(n != 6);
    
}

void data(){
    int n;
	int number;
	do
	{
	system("cls");
	cout << "\n\n\n\tDATA" << endl;
	cout << "\n\n\n\t1. ALL STUDENTS' RESULTS" << endl;
	cout << "\n\n\t2. INFORMATION ABOUT A STUDENT" << endl;
	cout << "\n\n\t3. BACK TO MENU" << endl;
	cout << "\n\n\n\tChoose your option (1-3): " << endl;
	cin >> n;
	system("cls");
	switch(n)
	{
	case 1 :	class_result(); 
	            break;
	case 2 :	cout << "Enter the student number: " << endl;;
	            cin >> number;
				search(number); 
				break;
	case 3 :	break;
	default:	cout<<"\a";
	}
  }while(n != 3);
}

void class_result(){
    Student s;
	ifstream inFile;
	inFile.open("student.dat",ios::binary); //Open in binary mode
	
	if(!inFile)
	{
		cout<<"Error! File is not opened. Please, press any key to continue.";
		cin.ignore();
		cin.get();
		return;
	}
	
	cout<<"\n\n\t\tSTUDENTS RESULT TABLE \n\n";
	cout<<"##########################################################\n";
	cout<<"St.№       Name        P   C   M   E   Av   Grade"<<endl;
	cout<<"##########################################################\n";
	
	while(inFile.read(reinterpret_cast<char *> (&s), sizeof(Student))) //accept chat and size
	{
		s.show_table();
	}
	
	cin.ignore();
	cin.get();
	inFile.close();
}

void delete_s(int n)
{
	Student s;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	
	if(!inFile)
	{
		cout<<"Error! File is not opened. Please, press any key to continue.";
		cin.ignore();
		cin.get();
		return;
	}
	
	ofstream outFile;
	outFile.open("Temp.dat",ios::out); //File open for writing
	
	inFile.seekg(0,ios::beg); //beginning of the stream
	
	while(inFile.read(reinterpret_cast<char *> (&s), sizeof(Student)))
	{
		if(s.return_number() != n)
		{
			outFile.write(reinterpret_cast<char *> (&s), sizeof(Student));
		}
	}
	
	outFile.close();
	inFile.close();
	
	remove("student.dat");
	rename("Temp.dat","student.dat");
	
	cout<<"\n\n\tInformation about student was successfully deleted" << endl;
	
	cin.ignore();
	cin.get();
}

void edit(int n)
{
	bool found = false; //boolean value for identifying is data written or not
	Student s;
	fstream File;
	File.open("student.dat",ios::binary|ios::in|ios::out); // binary mode | File open for reading and writing
	
	if(!File)
	{
		cout<<"Error! File is not opened. Please, press any key to continue.";
		cin.ignore();
		cin.get();
		return;
	}
	
    	while(!File.eof() && found == false) 
	{

		File.read(reinterpret_cast<char *> (&s), sizeof(Student));
		
		if(s.return_number() == n)
		{
			s.showdata();
			cout<<"\n\nEnter the information you want to edit in this data" << endl;
			s.getdata();
		    	int pos=(-1)*static_cast<int>(sizeof(s));
		    	File.seekp(pos,ios::cur); //	current position in the stream
		    	File.write(reinterpret_cast<char *> (&s), sizeof(Student));
		    	cout<<"\n\n\t Infomation was edited successfully";
		    	found = true;
		}
	}
	
	File.close();
	
	if(found == false)
		cout<<"\n\n Error! Information was not found!" << endl;
		
	cin.ignore();
	cin.get();
}

void search(int n)
{
	Student s;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	
	if(!inFile)
	{
		cout<<"Error! File is not opened. Please, press any key to continue." << endl;
		cin.ignore();
		cin.get();
		return;
	}
	
	bool found = false; //boolean value for identifying is data written or not
	
	while(inFile.read(reinterpret_cast<char *> (&s), sizeof(Student)))
	{
		if(s.return_number() == n)
		{
	  		 s.showdata();
			 found = true;
		}
	}
	
	inFile.close();
	
	if(found == false)
		cout << "\n\nInformation does not exist" << endl;
		
	cin.ignore();
	cin.get();
}

void show_all()
{
	Student s;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	
	if(!inFile)
	{
		cout<<"Error! File is not opened. Please, press any key to continue." << endl;
		cin.ignore();
		cin.get();
		return;
	}
	
	cout<<"\n\n\n\t\tAll RECORDS LIST\n\n" << endl;
	while(inFile.read(reinterpret_cast<char *> (&s), sizeof(Student)))
	{
		s.showdata();
		cout<<"\n\n====================================\n";
	}
	
	inFile.close();
	cin.ignore();
	cin.get();
}

void enter()
{
	Student s;
	ofstream outFile;
	outFile.open("student.dat",ios::binary|ios::app); //appending all output operations happen at the end of the file 
	
	s.getdata();
	
	outFile.write(reinterpret_cast<char *> (&s), sizeof(Student));
	
	outFile.close();
    	cout<<"\n\nData about the student was written successfully" << endl;
	cin.ignore();
	cin.get();
}


