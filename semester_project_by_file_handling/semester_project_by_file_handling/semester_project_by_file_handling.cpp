#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;
void login();				//check the login requirements
void semester_data();
void faculty_data();
void student_data();
void course_enrollment();
void spring();
void fall();
void courses_data(int a);
int  check_password(string pass);
void check_student_pass(int a);
void check_faculty_pass();
void upload_attendance();
int  check_teacher_access();
void veiw_courses();
void veiw_students_enroll_in_course();
void create_assingment_quiz();
void assingment_create_list();
void quiz_create_list();
void mark_assingment();
void mark_quiz();
void find_assingment();
void find_quiz();
void veiw_grades();
void veiw_attendance();
void veiw_challan();
void store_semester_data();
void store_faculty_data();
void store_student_data();
void store_course_enroll();
void store_quiz_mark_data();
void store_assingment_marks();
void store_quiz_creation();
void store_assingment_creation();
void store_attendance();
void read_all_data();
void read_semester_data();
void read_student_data();
void read_teacher_data();
void read_course_enroll();
void read_quiz_mark_data();
void read_assingment_marks();
void read_quiz_creation();
void read_assingment_creation();
void read_attendance();
struct course_enroll		//use for the course enrollment of the students this will used in calculating the fee and displaying the student data for the teacher
{
	int sem;
	string name;
	string course;
	int fee;
	int reg;
	course_enroll* nptr;
};
struct attendance
{
	string course_name;
	int reg_s;
	string student_name;
	int date;
	string month;
	int year;
	string status;
	attendance* nptr;
};
struct course
{
	string course_name;
	int credit_hours;
	string teacher;
	string course_id;
	int fee;
	string teacher_id;
};
class assingment_quiz_class
{
public:
	string name_a;
	int reg_student_a;
	string subject_a;
	int assingment_no;
	int total_ass;
	int abs_ass;
	int  marks_assingment;
	string name_q;
	int reg_student_q;
	string subject_q;
	int quiz_no;
	int abs_quiz;
	int total_quiz;
	int marks_quiz;		//apply the absolute gradding
	void assingment_create()
	{
		cout << "\nAssingment # ";
		cin >> assingment_no;
		cout << "\nSubject : ";
		cin >> subject_a;
		cout << "\nTotal marks : ";
		cin >> total_ass;
		cout << "Absolute marks : ";
		cin >> abs_ass;
	}
	void assingment_setter_mark(string n, int reg, string sub, int total, int ass_no, int marks_obt, int mark_abs)
	{
		//working
		name_a = n;
		reg_student_a = reg;
		//	cout << reg_student_a << endl;
		subject_a = sub;
		//	cout << subject_a << endl;
		total_ass = total;
		//	cout << total_ass << endl;
		assingment_no = ass_no;
		//	cout << assingment_no << endl;
		abs_ass = mark_abs;
		marks_assingment = marks_obt;
		//	cout << "\ncheck 6\n";//check
	}
	void quiz_setter_mark(string n, int reg, string sub, int total, int ass_no, int marks_obt, int mark_abs)
	{
		name_q = n;
		reg_student_q = reg;
		subject_q = sub;
		total_quiz = total;
		quiz_no = ass_no;
		abs_quiz = mark_abs;
		marks_quiz = marks_obt;
	}
	int return_ass_no()
	{
		return assingment_no;
	}
	void quiz_create()
	{
		cout << "\nQuiz # ";
		cin >> quiz_no;
		cout << "\nSubject : ";
		cin >> subject_q;
		cout << "\nTotal marks : ";
		cin >> total_quiz;
		cout << "Absolute marks : ";
		cin >> abs_quiz;
	}
	int return_quiz_no()
	{
		return quiz_no;
	}
	int assingment_total()
	{
		return total_ass;
	}
	int quiz_total()
	{
		return total_quiz;
	}
	int assingment_abs()
	{
		return abs_ass;
	}
	int quiz_abs()
	{
		return abs_quiz;
	}
};
class student
{
protected:
	string password;
public:
	string name, city, country, birth, address, cinc;
	int reg, marks, course_enroll;
	long long phone_number;
	void set_data()
	{
		cout << "\nEnter the Name : ";
		cin.ignore();
		getline(cin, name);
		cout << "\nEnter the Registration number : ";
		cin >> reg;
		cout << "\nEnter the Phone_number : ";
		cin >> phone_number;
		cout << "\nEnter the City : ";
		cin.ignore();
		getline(cin, city);
		cout << "\nEnter the Country : ";
		cin.ignore();
		getline(cin, country);
		cout << "\nEnter the Date of Birth : ";
		cin.ignore();
		getline(cin, birth);
		cout << "\nEnter the address : ";
		cin.ignore();
		getline(cin, address);
		cout << "\nEnter the CNIC number : ";
		cin.clear();
		cin.ignore();
		getline(cin, cinc);
		cout << "\nEnter the password : ";
		getline(cin, password, '\n');
	}
	void set_password(string p)
	{
		password = p;
	}
	string password_return_base()
	{
		return password;
	}
};
class faculty :public student
{

};
class admin :public faculty
{
public:
	int sem_no, i;
	int course_nos;
	course* ptr;
	admin()
	{

		ptr = NULL;
	}
	void create_semester()
	{
		cout << "\nEnter the semester number : ";
		cin >> sem_no;
		cout << "\nHow many courses do you want to Offer : ";
		cin >> course_nos;
		ptr = new course[course_nos];
		for (i = 0; i < course_nos; i++)
		{
			cout << "\n\t [ COURSE # " << i+1 << " ] \n";
			cout << endl << "\nEnter the Name of the Course : ";
			cin.ignore();
			cin >> ptr[i].course_name;
			cout << "\nEnter the ID of Course : ";
			cin >> ptr[i].course_id;
			cout << "\nEnter the Creit hours of Course : ";
			cin >> ptr[i].credit_hours;
			cout << "\nEnter the Name of the teacher of the Course : ";
			cin.ignore();
			cin >> ptr[i].teacher;
			cout << endl;
			cout << "\nEnter the FEE of Course : ";
			cin >> ptr[i].fee;
		}
	}
	long long return_phone()
	{
		return phone_number;
	}
	string return_city()
	{
		return city;
	}
	string return_country()
	{
		return country;
	}
	string return_birth()
	{
		return birth;
	}
	string return_address()
	{
		return address;
	}
	string return_cnic()
	{
		return cinc;
	}
	int get_semester_no()
	{
		return sem_no;
	}
	int get_courses_no()
	{
		return course_nos;
	}
	string get_courses_name(int j)
	{
		return ptr[j].course_name;
	}
	int get_courses_hour(int j)
	{
		return ptr[j].credit_hours;
	}
	string get_courses_teacher(int j)
	{
		return ptr[j].teacher;
	}
	string get_courses_id(int j)
	{
		return ptr[j].course_id;
	}
	int get_courses_fee(int j)
	{
		return ptr[j].fee;
	}
	void faculty_data()
	{
		faculty::set_data();
	}
	void student_data()
	{
		student::set_data();
	}
	string return_pass()
	{
		return student::password;
	}
	int semester_no()
	{
		return sem_no;
	}
	string return_name()
	{
		return name;
	}
	int return_reg()
	{
		return reg;
	}
	~admin()
	{
		delete ptr;
	}
};
struct assingment
{
	assingment_quiz_class assingment_1;
	assingment* nptr;
};
struct quiz
{
	assingment_quiz_class quiz_1;
	quiz* nptr;
};
struct semester
{
	admin a1;				//this is the type of course because by creationg the semsenter the admin can create the course and create the reqired things i the same semester 
	semester* nptr;
};
char op;
string admin_password = "2004";
semester* fptr_sem = NULL;//file witting done																	//file writing done
semester* fptr_faculty = NULL;																					//file witting done																		
semester* fptr_student = NULL;																					//file witting done
course_enroll* fptr_course = NULL;																				//file writing done
semester* find;
semester* currentptr_student = NULL;
semester* currentptr_semester = NULL;
string password_check;
attendance* fptr_attendance = NULL;																				//file writing done 
assingment* fptr_assingment = NULL;																				//file writing done
quiz* fptr_quiz = NULL;																							//file writing done 
assingment* fptr_assingment_mark = NULL;		//use this to show grades of particular student in assingment	//file writing done  
quiz* fptr_quiz_mark = NULL;		//use this to show grades of particular student in quiz						//file writing done
assingment* find_ass = fptr_assingment;			// no file
quiz* find_q = fptr_quiz;   //marks entry		// no file
string course_check;
fstream file_semester;
fstream file_student;
fstream file_teacher;
fstream file_course_enroll;
fstream file_quiz_mark;
fstream file_assingmnet_mark;
fstream file_quiz_create;
fstream file_assingment_create;
fstream file_attendance;
int main()
{
	read_semester_data();						
	read_student_data();
	read_teacher_data();							
	read_course_enroll();
	read_quiz_mark_data();
	read_assingment_marks();
	read_quiz_creation();
	read_assingment_creation();
	read_attendance();
	//read_all_data();
	// starting of menu
	while (1)
	{
		cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~ WELCOME TO THE STUDENT REGISTRATION PORTAL ~~~~~~~~~~~~~~~~~~~~~~~~~~~ ";
		cout << "\n\nWHO ARE YOU?\n";
		cout << "\n1. ADMIN"
			<< "\n2. FACULTY MEMBER"
			<< "\n3. STUDENT"
			<< "\n\n4. EXIT  \n"
			<< "\nOPTION : ";
		cin >> op;
		switch (op)
		{
		case '1':
			login();
			system("PAUSE");
			system("CLS");
			break;
		case '2':
			login();
			system("PAUSE");
			system("CLS");
			break;
		case '3':
			login();
			system("PAUSE");
			system("CLS");
			break;
		case'4':
			store_semester_data();
			store_student_data();
			store_faculty_data();
			store_course_enroll();
			store_quiz_mark_data();
			store_assingment_marks();
			store_quiz_creation();
			store_assingment_creation();
			store_attendance();
			exit(0);
			break;
		default:
			cout << "\n!!!!!!!!!!!!!!!!! WRONG INPUT !!!!!!!!!!!!!!!!!!\n";
			break;
		}
	}
}
void login()
{
	int count_a = 0;
	int count_fac = 0;
	int count_stud = 0;
	char op_student, op_teacher;
	int decision;
	cin.clear();
	cin.ignore();
	while (count_a != 3 && count_fac != 3 && count_stud != 3)
	{
		cout << "\nPLEASE ENTER YOUR PASSWORD : ";
		getline(cin, password_check);
		count_a++;
		count_fac++;
		count_stud++;
		if (op == '1')
		{
			if (password_check == admin_password)
			{
				while (1)
				{
					cout << "\n\t<------------------ [ ADMIN ] ---------------->\n";
					char task;
					cout << "\nWhich operation do you want to perform ? ";
					cout << "\n1. OFFER SEMESTER";
					cout << "\n2. ENTER FACULTY MEMBER"
						<< "\n3. ENTER STUDENT DATA"
						<< "\n4.RETURN TO MAIN MENU";
					cout << "\nOPTION : ";
					cin >> task;
					switch (task)
					{
					case'1':
						semester_data();
						system("PAUSE");
						system("CLS");
						break;
					case'2':
						faculty_data();
						system("PAUSE");
						system("CLS");
						break;
					case'3':
						student_data();
						system("PAUSE");
						system("CLS");
						break;
					case'4':
						break;
					default:
						cout << "\n!!!!!!!!!!!!!!! WRONG INPUT !!!!!!!!!!!!!!!!";
						break;
					}
					if (task == '4')
					{
						break;
					}
				}
				break;
			}
			else
			{
				cout << "\nInvalid password\n";
			}
			if (count_a == 3)		//check how many wrong attempts ?
			{
				cout << "\nYOU ENTERED 3 TIME WRONG PASSWORD PLEASE TRY AGAIN\n";
			}
		}
		else
		{
			if (op == '2')
			{
				if (fptr_faculty == NULL)
				{
					cout << "\nTHERE IS NO FACULTY MEMBER IN THE LIST \n";
					break;
				}
				else
				{
					decision = check_password(password_check);
					if (decision == 1)
					{
						while (1)
						{
							cout << "\n\t<--------------------- [ FACULTY ] --------------------->\n";
							cout << "\nWhich operation do you want to perform ? \n";
							cout << "\n1. UPLOAD ATTENDANCE\n";
							cout << "\n2. ASSINGMENT/QUIZ\n";
							cout << "\n3. VEIW ASSINGNED COURSES\n";
							cout << "\n4. VEIW STUDENT ENROLLED IN A COURSE\n";
							cout << "\n5. RETURN TO MAIN MENU\n";
							cout << "\nANSWER OF TEACHER : ";
							cin >> op_teacher;
							switch (op_teacher)
							{
							case'1':
								upload_attendance();
								system("PAUSE");
								system("CLS");
								//upload attendance
								break;
							case'2':
								create_assingment_quiz();
								system("PAUSE");
								system("CLS");
								//assingments/quizes
								break;
							case'3':
								veiw_courses();
								system("PAUSE");
								system("CLS");
								//assined courses
								break;
							case'4':
								veiw_students_enroll_in_course();
								system("PAUSE");
								system("CLS");
								//veiw students enrolled
								break;
							case'5':
								break;
							default:
								cout << "\n!!!!!!!!!!!!!!!!! WRONG INPUT !!!!!!!!!!!!!!!!!!!\n";
								break;
							}
							if (op_teacher == '5')
							{
								break;
							}
						}
						break;
					}
					else
					{
						cout << "\nInvalid password\n";
					}
					if (count_fac == 3)		//check how many wrong attempts ?
					{
						cout << "\nYOU ENTERED 3 TIME WRONG PASSWORD PLEASE TRY AGAIN\n";
					}
				}
			}
			else
			{
				if (fptr_student == NULL)
				{
					cout << "\nTHERE IS NO STUDENT IN THE LIST \n";
					break;
				}
				else
				{
					decision = check_password(password_check);
					if (decision == 1)
					{
						while (1)
						{
							cout << "\n\t<------------------------ [ STUDENT ] ---------------------->\n";
							cout << "\nWhich operation do you want to perform ? \n";
							cout << "\n1. COURSE ENROLLMENT\n";
							cout << "\n2. VEIW ATTENDANCE\n";
							cout << "\n3. VEIW MARKS\n";
							cout << "\n4. PRINT CHALLAN\n";
							cout << "\n5. RETURN TO MAIN MENU\n";

							cout << "\nOPTION FOR STUDENT : ";
							cin >> op_student;
							switch (op_student)
							{
							case'1':
								course_enrollment();	//course eenrollment
								system("PAUSE");
								system("CLS");
								break;
							case'2':
								veiw_attendance();
								cout << endl;
								system("PAUSE");
								system("CLS");
								//veiw attendance
								break;
							case'3':
								veiw_grades();
								system("PAUSE");
								system("CLS");
								//veiw marks
								break;
							case'4':
								veiw_challan();
								system("PAUSE");
								system("CLS");
								//veiw fee challan
								break;
							case'5':
								break;
							default:
								cout << "\n!!!!!!!!!!!!!!!!! WRONG INPUT !!!!!!!!!!!!!!!!!!!\n";
								break;
							}
							if (op_student == '5')
							{
								break;
							}
						}
						break;
					}
					else
					{
						cout << "\nInvalid password\n";
					}
					if (count_stud == 3)		//check how many wrong attempts ?
					{
						cout << "\nYOU ENTERED 3 TIME WRONG PASSWORD PLEASE TRY AGAIN\n";
					}
				}
			}
		}
	}
}
void semester_data()
{
	semester* ptr;
	ptr = new semester;
	ptr->a1.create_semester();
	if (fptr_sem == NULL)
	{
		fptr_sem = ptr;
		ptr->nptr = NULL;
	}
	else
	{
		semester* current_ptr = fptr_sem;
		while (current_ptr->nptr != NULL)
		{
			current_ptr = current_ptr->nptr;
		}
		current_ptr->nptr = ptr;
		ptr->nptr = NULL;
	}
}
void faculty_data()
{
	semester* ptr_fac;
	ptr_fac = new semester;
	ptr_fac->a1.faculty_data();
	if (fptr_faculty == NULL)
	{
		fptr_faculty = ptr_fac;
		ptr_fac->nptr = NULL;
	}
	else
	{
		semester* current_ptr = fptr_faculty;
		while (current_ptr->nptr != NULL)
		{
			current_ptr = current_ptr->nptr;
		}
		current_ptr->nptr = ptr_fac;
		ptr_fac->nptr = NULL;
	}
}
void student_data()
{
	semester* ptr_stud;
	ptr_stud = new semester;
	ptr_stud->a1.student_data();
	if (fptr_student == NULL)
	{
		fptr_student = ptr_stud;
		ptr_stud->nptr = NULL;
	}
	else
	{
		semester* current_ptr = fptr_student;
		while (current_ptr->nptr != NULL)
		{
			current_ptr = current_ptr->nptr;
		}
		current_ptr->nptr = ptr_stud;
		ptr_stud->nptr = NULL;
	}
}
int check_password(string pass)
{
	int flag = 0;
	if (op == '2')
	{
		::find = fptr_faculty;
		while (::find != NULL)
		{
			if (::find->a1.return_pass() == pass)
			{
				flag = 1;
				break;
			}
			else
			{
				::find = ::find->nptr;
			}
		}
		if (flag == 0)
		{
			cout << "\n!!!!!!!!!!!!!!!!! INVALID PASSWORD !!!!!!!!!!!!!!!!!!\n";
			return 0;
		}
		else
		{
			cout << "\n*************** CONGRATULATIONS ***************\n";
			return 1;
		}
	}
	if (op == '3')
	{
		::find = fptr_student;
		while (::find != NULL)
		{
			if (::find->a1.password_return_base() == pass)
			{
				flag = 1;
				break;
			}
			else
			{
				::find = ::find->nptr;
			}
		}
		if (flag == 0)
		{
			cout << "\n!!!!!!!!!!!!!!!!! INVALID PASSWORD !!!!!!!!!!!!!!!!!!\n";
			return 0;
		}
		else
		{
			cout << "\n*************** CONGRATULATIONS ***************\n";
			return 1;
		}
	}
}
void course_enrollment()
{
	char op_c;
	cout << "\nIN WHICH CATAGORY YOU WANT TO ENROLL ? \n";
	cout << "\n1. FALL\n";
	cout << "\n2. SPRING\n";
	while (1)
	{
		cout << "\nOPTION : ";
		cin >> op_c;
		switch (op_c)
		{
		case'1':
			fall();
			break;
		case'2':
			spring();
			break;
		default:
			cout << "\n!!!!!!!!!!!!!!!!! WRONG INPUT !!!!!!!!!!!!!!!!!!!\n";
			break;
		}
		break;
	}
}
void spring()
{
	int sem_choose, ans;
	semester* ptr;
	ptr = fptr_sem;
	if (fptr_sem == NULL)
	{
		cout << "\nThere is no semester offered\n";
	}
	else
	{
		cout << setw(25) << left << "Semester No." << setw(25) << left << "Catagory\n";
		while (ptr != NULL)
		{
			if (ptr->a1.semester_no() == 2 || ptr->a1.semester_no() == 4 || ptr->a1.semester_no() == 6 || ptr->a1.semester_no() == 8)
			{
				cout << endl << setw(25) << left << ptr->a1.semester_no() << setw(25) << left << "SPRING" << endl;
			}
			ptr = ptr->nptr; // Move the pointer to the next node in every iteration
		}
	}
	while (1)
	{
		cout << "\nIn which semester do you want to enroll ? \n";
		cin >> sem_choose;
		if (sem_choose == 2 || sem_choose == 4 || sem_choose == 6 || sem_choose == 8)
		{
			while (1)
			{
				courses_data(sem_choose);
				cout << "\nDO you want to enroll another course ?      1. (YES)        2. (NO)";
				cin >> ans;
				if (ans == 2)
				{
					break;
				}
				else
				{
					continue;
				}
			}
			if (ans == 2)
			{
				break;
			}
		}
		else
		{
			continue;
		}
	}
}
void fall()
{
	int sem_choose, ans;
	semester* ptr;
	ptr = fptr_sem;
	if (fptr_sem == NULL)
	{
		cout << "\nThere is no semester offered\n";
	}
	else
	{
		cout << setw(25) << left << "Semester No." << setw(25) << left << "Catagory\n";
		while (ptr != NULL)
		{
			if (ptr->a1.semester_no() == 1 || ptr->a1.semester_no() == 3 || ptr->a1.semester_no() == 5 || ptr->a1.semester_no() == 7)
			{
				cout << endl << setw(25) << left << ptr->a1.semester_no() << setw(25) << left << "FALL" << endl;
			}
			ptr = ptr->nptr; // Move the pointer to the next node in every iteration
		}
	}
	while (1)
	{
		cout << "\nIn which semester do you want to enroll ? \n";
		cout << "\nOption : ";
		cin >> sem_choose;
		if (sem_choose == 1 || sem_choose == 3 || sem_choose == 5 || sem_choose == 7)
		{
			while (1)
			{
				courses_data(sem_choose);
				cout << "\nDO you want to enroll another course ?      1. (YES)        2. (NO)\n";
				cout << "OPTION : ";
				cin >> ans;
				if (ans == 2)
				{
					break;
				}
				else
				{
					continue;
				}
			}
			if (ans == 2)
			{
				break;
			}
		}
		else
		{
			continue;
		}
	}
}
void courses_data(int a)
{
	int i = 0, op_course, j = 0;
	course_enroll* ptr;
	ptr = new course_enroll;
	check_student_pass(a);
	ptr->sem = currentptr_semester->a1.semester_no();
	ptr->name = currentptr_student->a1.return_name();
	ptr->reg = currentptr_student->a1.return_reg();
	cout << setw(25) << left << "SR.no" << setw(25) << left << "Course ID" << setw(25) << left << "Course" << setw(25) << left << "Credit Hours" << setw(25) << left << "Teacher\n";
	while (j < currentptr_semester->a1.course_nos)
	{
		cout << endl << setw(25) << left << i + 1 << setw(25) << left << currentptr_semester->a1.get_courses_id(i) << setw(25) << left << currentptr_semester->a1.get_courses_name(i) << setw(25) << left << currentptr_semester->a1.get_courses_hour(i) << setw(25) << left << currentptr_semester->a1.get_courses_teacher(i) << endl;
		i++;
		j++;
	}
	cout << "\nWhich course do you want to select ? ";
	cout << "\nOption : ";
	cin >> op_course;
	cout << "\n<--------------- ENROLLED ----------------->";
	ptr->course = currentptr_semester->a1.get_courses_name(op_course - 1);
	ptr->fee = currentptr_semester->a1.get_courses_fee(op_course - 1);
	if (fptr_course == NULL)
	{
		fptr_course = ptr;
		ptr->nptr = NULL;
	}
	else
	{
		course_enroll* current_ptr = fptr_course;
		while (current_ptr->nptr != NULL)
		{
			current_ptr = current_ptr->nptr;
		}
		current_ptr->nptr = ptr;
		ptr->nptr = NULL;
	}

}
void check_student_pass(int a)
{
	currentptr_student = fptr_student;
	while (currentptr_student != NULL)
	{
		if (currentptr_student->a1.return_pass() == password_check)
		{
			break;
		}
		currentptr_student = currentptr_student->nptr;
	}
	currentptr_semester = fptr_sem;
	while (currentptr_semester != NULL)
	{
		if (currentptr_semester->a1.semester_no() == a)
		{
			break;
		}
		currentptr_semester = currentptr_semester->nptr;
	}
}
void upload_attendance()
{
	int desion;
	desion = check_teacher_access();
	if (desion == 1)
	{
		string name;
		int reg, flag = 0, reg_student;
		cout << "\nEnter the registration no of student : ";
		cin >> reg;
		semester* student_find = fptr_student;
		if (fptr_student == NULL)
		{
			cout << "\nThere is no student in the list\n";
		}
		else
		{
			while (student_find != NULL)
			{
				if (student_find->a1.return_reg() == reg)
				{
					reg_student = student_find->a1.return_reg();
					name = student_find->a1.return_name();
					flag = 1;
					break;
				}
				student_find = student_find->nptr;
			}
		}
		if (flag == 1)
		{
			int op;
			while (1)
			{
				attendance* ptr;
				ptr = new attendance;
				ptr->reg_s = reg_student;
				ptr->student_name = name;
				//	cout << "\nEnter the name of the course : ";
				//	cin >> ptr->course_name;
				ptr->course_name = course_check;    //testing
				cout << "\nEnter the status of the student :   (p) for present        (a) for absent\n";
				cout << "\nANSWER : ";
				cin >> ptr->status;
				cout << "\nEnter the Date : ";
				cin >> ptr->date;
				cout << "\nEnter the Month : ";
				cin >> ptr->month;
				cout << "\nEnter the Year : ";
				cin >> ptr->year;
				if (fptr_attendance == NULL)
				{
					fptr_attendance = ptr;
					ptr->nptr = NULL;
				}
				else
				{
					attendance* current_ptr = fptr_attendance;
					while (current_ptr->nptr != NULL)
					{
						current_ptr = current_ptr->nptr;
					}
					current_ptr->nptr = ptr;
					ptr->nptr = NULL;
				}
				cout << "\nDo you want to marks attendance for the same student ?     1. (YES)      2.(NO)";
				cout << "\nOPTION : ";
				cin >> op;
				if (op == 1)
				{
					continue;
				}
				else
					break;
			}
		}
		else
		{
			cout << "\n!!!!!!!!!!!!!!!!! Invalid registration no !!!!!!!!!!!!!!!!!!!!!!!\n";
		}
	}
	else
	{
		cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!! You are not relative to to that course !!!!!!!!!!!!!!!!!!!!!";
	}
}
void veiw_courses()
{
	check_faculty_pass();
}
void check_faculty_pass()
{
	int i, j = 0;
	string name;
	semester* ptr_check_name;			// this is for geetting the name of teacher 
	ptr_check_name = fptr_faculty;
	semester* ptr_course_no = fptr_sem;		// this will giv course nos in particular semester and its name
	if (fptr_faculty == NULL)
	{
		cout << "\n!!!!!!!!! NO DATA !!!!!!!!!!!!!!!!\n";
	}
	else
	{
		while (ptr_check_name != NULL)
		{
			if (ptr_check_name->a1.return_pass() == password_check)
			{
				name = ptr_check_name->a1.return_name();
				// it is working till here
				while (ptr_course_no != NULL)
				{
					for (i = 0; i < ptr_course_no->a1.course_nos; i++)
					{
						if (name == ptr_course_no->a1.get_courses_teacher(i))
						{
							j++;
							cout << endl << j << ". " << ptr_course_no->a1.get_courses_name(i) << endl;
						}
					}
					ptr_course_no = ptr_course_no->nptr;
				}
			}
			ptr_check_name = ptr_check_name->nptr;
		}
	}
}
void veiw_students_enroll_in_course()
{
	int decsion;
	decsion = check_teacher_access();
	if (decsion == 1)
	{
		int i = 0;
		string course_student_veiw;
		check_faculty_pass();
		cout << "\nStudents of which course do you want to see ? \n";
		cout << "\nANSWER (WRITE THE NAME OF COURSE) : ";
		cin >> course_student_veiw;
		course_enroll* ptr_find;
		ptr_find = fptr_course;
		if (fptr_course == NULL)
		{
			cout << "\nThere is no student\n";
		}
		else
		{
			cout << setw(25) << left << "SR No." << setw(25) << left << "Semester No." << setw(25) << left << "Name" << setw(25) << left << "Course\n";
			while (ptr_find != NULL)
			{
				i++;
				if (ptr_find->course == course_student_veiw)
				{
					cout << endl << setw(25) << left << i << setw(25) << left << ptr_find->sem << setw(25) << left << ptr_find->name << setw(25) << left << ptr_find->course << endl;
				}
				ptr_find = ptr_find->nptr;
			}
		}
	}
	else
	{
		cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!! You are not relative to this course !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
	}
}
void create_assingment_quiz()
{
	int desion;
	desion = check_teacher_access();
	if (desion == 1)
	{
		char op_assing_quiz;
		while (1)
		{
			cout << "\nWhich operation do you want to perform ? \n"
				<< "\n1. Create Assingment\n"
				<< "\n2. Mark Assingment\n"
				<< "\n3. Create Quiz\n"
				<< "\n4. Mark Quiz\n"
				<< "\n5. Return\n"
				<< "\nOPTION : ";
			cin >> op_assing_quiz;
			switch (op_assing_quiz)
			{
			case'1':
				assingment_create_list();
				break;
			case'2':
				mark_assingment();
				break;
			case'3':
				quiz_create_list();
				break;
			case'4':
				mark_quiz();
				break;
			case'5':
				break;
			default:
				cout << "\n!!!!!!!!!!!!!!!!!!!! WRONG INPUT !!!!!!!!!!!!!!!";
				break;
			}
			if (op_assing_quiz == '5')
			{
				break;
			}
		}
	}
	else
	{
		cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!! You are not relative to this course !!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
	}
}
void assingment_create_list()
{
	assingment* ptr;
	ptr = new assingment;
	ptr->assingment_1.assingment_create();
	if (fptr_assingment == NULL)
	{
		fptr_assingment = ptr;
		ptr->nptr = NULL;
	}
	else
	{
		assingment* current_ptr = fptr_assingment;
		while (current_ptr->nptr != NULL)
		{
			current_ptr = current_ptr->nptr;
		}
		current_ptr->nptr = ptr;
		ptr->nptr = NULL;
	}
}
void quiz_create_list()
{

	quiz* ptr;
	ptr = new quiz;
	ptr->quiz_1.quiz_create();
	if (fptr_quiz == NULL)
	{
		fptr_quiz = ptr;
		ptr->nptr = NULL;
	}
	else
	{
		quiz* current_ptr = fptr_quiz;
		while (current_ptr->nptr != NULL)
		{
			current_ptr = current_ptr->nptr;
		}
		current_ptr->nptr = ptr;
		ptr->nptr = NULL;
	}
}
void mark_assingment()
{
	int flag = 0;
	int reg_find, reg, marks_ob;
	string name;
	find_assingment();
	assingment* ptr;
	ptr = new assingment;
	semester* student_find = fptr_student;
	ptr->nptr = NULL;
	cout << "\nEnter the registration no of the student : ";
	cin >> reg_find;
	if (fptr_student == NULL)
	{
		cout << "\nThere is no student in the list\n";
	}
	else
	{
		while (student_find != NULL)
		{
			if (student_find->a1.return_reg() == reg_find)
			{
				reg = student_find->a1.return_reg();
				name = student_find->a1.return_name();
				flag = 1;
				break;
			}
			student_find = student_find->nptr;
		}
	}
	if (flag == 1)
	{
		cout << "\nEnter the marks Obtain : ";
		cin >> marks_ob;
		ptr->assingment_1.assingment_setter_mark(name, reg, find_ass->assingment_1.subject_a, find_ass->assingment_1.assingment_total(), find_ass->assingment_1.return_ass_no(), marks_ob, find_ass->assingment_1.assingment_abs());
		if (fptr_assingment_mark == NULL)
		{
			fptr_assingment_mark = ptr;
		}
		else
		{
			assingment* current_ptr = fptr_assingment_mark;
			while (current_ptr->nptr != NULL)
			{
				current_ptr = current_ptr->nptr;
			}
			current_ptr->nptr = ptr;
		}
	}
	else
	{
		cout << "\n!!!!!!!!!!!!!!!!!!!!! Invalid Registration No !!!!!!!!!!!!!!!!!!!!!!!!";
		return;
	}
}
void mark_quiz()
{

	int flag = 0;
	int reg_find, reg, marks_ob;
	string name;
	find_quiz();
	quiz* ptr;
	ptr = new quiz;
	semester* student_find = fptr_student;
	ptr->nptr = NULL;
	cout << "\nEnter the registration no of the student : ";
	cin >> reg_find;
	if (fptr_student == NULL)
	{
		cout << "\nThere is no student in the list\n";
	}
	else
	{
		while (student_find != NULL)
		{
			if (student_find->a1.return_reg() == reg_find)
			{
				reg = student_find->a1.return_reg();
				name = student_find->a1.return_name();
				flag = 1;
				break;
			}
			student_find = student_find->nptr;
		}
	}
	if (flag == 1)
	{
		cout << "\nEnter the marks Obtain : ";
		cin >> marks_ob;
		ptr->quiz_1.quiz_setter_mark(name, reg, find_q->quiz_1.subject_q, find_q->quiz_1.quiz_total(), find_q->quiz_1.return_quiz_no(), marks_ob, find_q->quiz_1.quiz_abs());
		if (fptr_quiz_mark == NULL)
		{
			fptr_quiz_mark = ptr;
		}
		else
		{
			quiz* current_ptr = fptr_quiz_mark;
			while (current_ptr->nptr != NULL)
			{
				current_ptr = current_ptr->nptr;
			}
			current_ptr->nptr = ptr;
		}
	}
	else
	{
		cout << "\n!!!!!!!!!!!!!!!!!!!!! Invalid Registration No !!!!!!!!!!!!!!!!!!!!!!!!";
		return;
	}
}
void find_assingment()
{
	int ass_no;
	cout << "\nEnter the assingment# : ";
	cin >> ass_no;
	find_ass = fptr_assingment;
	if (fptr_assingment == NULL)
	{
		cout << "\nThere is no assingment in the list\n";
	}
	while (find_ass != NULL)
	{
		if (find_ass->assingment_1.return_ass_no() == ass_no)
		{
			cout << "\ncheck 3\n";//check
			break;
		}
		find_ass = find_ass->nptr;
	}
}
void find_quiz()
{
	int quiz_no;
	cout << "\nEnter the quiz# : ";
	cin >> quiz_no;
	find_q = fptr_quiz;
	if (fptr_quiz == NULL)
	{
		cout << "\nThere is no quiz in the list\n";
	}
	while (find_q != NULL)
	{
		if (find_q->quiz_1.quiz_no == quiz_no)
		{
			break;
		}
		find_q = find_q->nptr;
	}
}
void veiw_grades()
{
	int reg;
	float marks, total_marks = 0;
	cout << "\nEnter your registration no : ";
	cin >> reg;
	assingment* currentptr = fptr_assingment_mark;
	quiz* current_ptr_quiz = fptr_quiz_mark;
	if (fptr_assingment_mark == NULL)
	{
		cout << "\nThere is Nothing in Assingments\n";
	}
	else
	{
		cout << "\n\n\t<--------------------- MARKS OF ASSINGMENTS ----------------->\n\n";
		//   (working)
		while (currentptr != NULL)
		{
			if (currentptr->assingment_1.reg_student_a == reg)
			{
				marks = (currentptr->assingment_1.marks_assingment * currentptr->assingment_1.abs_ass) / float(currentptr->assingment_1.assingment_total());
				total_marks = marks + total_marks;
				cout << "\nAssingment# " << currentptr->assingment_1.assingment_no << "\t Subject : " << currentptr->assingment_1.name_a << "\tObtain Marks : " << currentptr->assingment_1.marks_assingment << "\tObsolute Marks : " << marks << endl;
			}
			currentptr = currentptr->nptr;
		}
	}
	if (fptr_quiz_mark == NULL)
	{
		cout << "\nThere is Nothing in Quiz\n";
	}
	else
	{
		cout << "\n\n\t<--------------------- MARKS OF QUIZES ----------------->\n\n";
		//working
		while (current_ptr_quiz != NULL)
		{
			if (current_ptr_quiz->quiz_1.reg_student_q == reg)
			{
				marks = (current_ptr_quiz->quiz_1.marks_quiz * current_ptr_quiz->quiz_1.abs_quiz) / float(current_ptr_quiz->quiz_1.quiz_total());
				total_marks = total_marks + marks;
				cout << "\nQuiz# " << current_ptr_quiz->quiz_1.quiz_no << "\tSubject : " << current_ptr_quiz->quiz_1.name_q << "\t\tObtain Marks : " << current_ptr_quiz->quiz_1.marks_quiz << "\tObsolute Marks : " << marks << endl;
			}
			current_ptr_quiz = current_ptr_quiz->nptr;
		}
	}
	cout << "\n\n\tTOTAL MARKS = " << total_marks << endl;
}
void veiw_attendance()
{
	int reg;
	cout << "\nEnter your registration no : ";
	cin >> reg;
	attendance* find = fptr_attendance;
	if (fptr_attendance == NULL)
	{
		cout << "\nThere is no Data";
	}
	else
	{						//display issuse
		cout << setw(25) << left << "DATE" << setw(25) << left << "Registration NO" << setw(25) << left << "Name" << setw(25) << left << "Course" << setw(25) << left << "Status\n";
		while (find != NULL)
		{
			string temp;
			if (find->reg_s == reg)
			{
				temp = to_string(find->date) + " " + (find->month) + " " + to_string(find->year);
				cout << endl << setw(25) << left << temp << setw(25) << left << find->reg_s << setw(25) << left << find->student_name << setw(25) << left << find->course_name << setw(25) << left << find->status;
			}
			find = find->nptr;
		}
	}


}
void veiw_challan()
{
	int total = 0, transport = 15000, hostel = 28000, library = 5000, ip_fee = 1000;
	int reg, op_challan;
	cout << "\nEnter your registration no : ";
	cin >> reg;
	cout << "\nDo you want to take Transport : 1. (YES)      2. (NO)";
	cout << "\nOPTION : ";
	cin >> op_challan;
	if (op_challan == 1)
	{
		total = total + transport;
	}
	cout << "\nDo you want to take Hostel Room : 1. (YES)      2. (NO)";
	cout << "\nOPTION : ";
	cin >> op_challan;
	if (op_challan == 1)
	{
		total = total + hostel;
	}
	total = total + ip_fee + library;
	course_enroll* find = fptr_course;
	cout << "\n\n\t<<<<------------------ FEE CHALLAN ----------------------->>>>\n";
	if (fptr_course == NULL)
	{
		cout << "\nThere is no Data \n";
	}
	else
	{
		cout << setw(25) << left << "Semester" << setw(25) << left << "Course" << setw(25) << left << "FEE\n";
		while (find != NULL)
		{
			if (find->reg == reg)
			{
				cout << endl << setw(25) << left << find->sem << setw(25) << left << find->course << setw(25) << left << find->fee << endl;
				total = total + find->fee;
			}
			find = find->nptr;
		}
	}
	cout << endl;
	cout << "\nTransport Fee             : " << transport;
	cout << "\nHostel Fee                : " << hostel;
	cout << "\nIP_Fee                    : " << ip_fee;
	cout << "\nLibrary Fee               : " << library;
	cout << "\n\nTotal Amonut to be Paid : " << total << endl;
	cout << "\n\n\t<<<<------------------ THANK YOU ----------------------->>>>\n";
}
int check_teacher_access()
{
	int i, flag = 0;
	string name_check;
	cout << "\n\nEnter your name : ";
	cin >> name_check;
	cout << "\n\nEnter the course name : ";
	cin >> course_check;
	semester* access_teacher = fptr_sem;
	if (fptr_sem == NULL)
	{
		cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!! There is no course !!!!!!!!!!!!!!!!!!!!!!!!!\n";
	}
	else
	{
		while (access_teacher != NULL)
		{
			for (i = 0; i < access_teacher->a1.get_courses_no(); i++)
			{
				if (access_teacher->a1.get_courses_teacher(i) == name_check && access_teacher->a1.get_courses_name(i) == course_check)
				{
					flag = 1;
				}
			}
			access_teacher = access_teacher->nptr;
		}
		if (flag == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}
void store_semester_data()//semester file handling done
{
	file_semester.open("semester.txt", ios::out);
	if (!file_semester)
	{
		cout << "\n!!!!!!!!!!!!!!!!! File Failed to open !!!!!!!!!!!!!!!!";
	}
	else
	{
		semester* current_ptr = fptr_sem;
		while (current_ptr != NULL)
		{
			file_semester << current_ptr->a1.get_semester_no() << endl;
			file_semester << current_ptr->a1.course_nos << endl;
			for (int i = 0; i < current_ptr->a1.course_nos; i++)
			{
				file_semester << current_ptr->a1.get_courses_name(i) << endl;
				file_semester << current_ptr->a1.get_courses_id(i) << endl;
				file_semester << current_ptr->a1.get_courses_hour(i) << endl;
				file_semester << current_ptr->a1.get_courses_teacher(i) << endl;
				file_semester << current_ptr->a1.get_courses_fee(i) << endl;
			}
			current_ptr = current_ptr->nptr;
		}
		file_semester.close();
	}
}					//file reading done
void store_student_data()//done to strore student data
{
	file_student.open("student.txt", ios::out);
	if (!file_student)
	{
		cout << "\n!!!!!!!!!!!!!!!! Student file failled to open !!!!!!!!!!!!!!!!!!!!!!\n";
	}
	else
	{
		semester* current_ptr = fptr_student;
		while (current_ptr != NULL)
		{
			file_student << current_ptr->a1.return_name() << endl;
			file_student << current_ptr->a1.return_reg() << endl;
			file_student << current_ptr->a1.return_phone() << endl;
			file_student << current_ptr->a1.return_city() << endl;
			file_student << current_ptr->a1.return_country() << endl;
			file_student << current_ptr->a1.return_birth() << endl;
			file_student << current_ptr->a1.return_address() << endl;
			file_student << current_ptr->a1.return_cnic() << endl;
			file_student << current_ptr->a1.return_pass() << endl;
			current_ptr = current_ptr->nptr;
		}
		file_student.close();
	}
}					//file reading done
void store_faculty_data()
{
	file_teacher.open("teacher.txt", ios::out);
	if (!file_teacher)
	{
		cout << "\n!!!!!!!!!!!!!!!! Teacher file failled to open !!!!!!!!!!!!!!!!!!!!!!\n";
	}
	else
	{
		semester* current_ptr = fptr_faculty;
		while (current_ptr != NULL)
		{
			file_teacher << current_ptr->a1.return_name() << endl;
			file_teacher << current_ptr->a1.return_reg() << endl;
			file_teacher << current_ptr->a1.return_phone() << endl;
			file_teacher << current_ptr->a1.return_city() << endl;
			file_teacher << current_ptr->a1.return_country() << endl;
			file_teacher << current_ptr->a1.return_birth() << endl;
			file_teacher << current_ptr->a1.return_address() << endl;
			file_teacher << current_ptr->a1.return_cnic() << endl;
			file_teacher << current_ptr->a1.return_pass() << endl;
			current_ptr = current_ptr->nptr;
		}
		file_teacher.close();
	}
}					//file reading done 
void store_course_enroll()
{
	file_course_enroll.open("course_enroll.txt", ios::out);
	if (!file_course_enroll.is_open())
	{
		cout << "\n!!!!!!!!!!!!!!!! course_enroll file failled to open !!!!!!!!!!!!!!!!!!!!!!\n";
		return;
	}
	else
	{
		course_enroll* current_ptr = fptr_course;
		while (current_ptr != NULL)
		{
			file_course_enroll << current_ptr->sem << endl;
			file_course_enroll << current_ptr->name << endl;
			file_course_enroll << current_ptr->reg << endl;
			file_course_enroll << current_ptr->course << endl;
			file_course_enroll << current_ptr->fee << endl;
			current_ptr = current_ptr->nptr;
		}
		file_course_enroll.close();
	}
}				//file reading done
void store_quiz_mark_data()
{
	file_quiz_mark.open("Quiz_marks.txt", ios::out);
	if (!file_quiz_mark)
	{
		cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!! File of quiz marks failled to open !!!!!!!!!!!!!!!!!!!!!!!!\n";
	}
	else
	{
		quiz* current_ptr = fptr_quiz_mark;
		while (current_ptr != NULL)
		{
			file_quiz_mark << current_ptr->quiz_1.name_q << endl;
			file_quiz_mark << current_ptr->quiz_1.reg_student_q << endl;
			file_quiz_mark << current_ptr->quiz_1.subject_q << endl;
			file_quiz_mark << current_ptr->quiz_1.total_quiz << endl;
			file_quiz_mark << current_ptr->quiz_1.quiz_no << endl;
			file_quiz_mark << current_ptr->quiz_1.abs_quiz << endl;
			file_quiz_mark << current_ptr->quiz_1.marks_quiz << endl;
			current_ptr = current_ptr->nptr;
		}
		file_quiz_mark.close();
	}
}
void store_assingment_marks()
{
	file_assingmnet_mark.open("assingment_marks.txt", ios::out);
	if (!file_assingmnet_mark)
	{
		cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!! File of assingment marks is failled to open !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
	}
	else
	{
		assingment* current_ptr = fptr_assingment_mark;
		while (current_ptr != NULL)
		{
			file_assingmnet_mark << current_ptr->assingment_1.name_a << endl;
			file_assingmnet_mark << current_ptr->assingment_1.reg_student_a << endl;
			file_assingmnet_mark << current_ptr->assingment_1.subject_a << endl;
			file_assingmnet_mark << current_ptr->assingment_1.total_ass << endl;
			file_assingmnet_mark << current_ptr->assingment_1.assingment_no << endl;
			file_assingmnet_mark << current_ptr->assingment_1.abs_ass << endl;
			file_assingmnet_mark << current_ptr->assingment_1.marks_assingment << endl;
			current_ptr = current_ptr->nptr;
		}
		file_assingmnet_mark.close();
	}
}
void store_quiz_creation()
{
	file_quiz_create.open("quiz_create.txt", ios::out);
	if (!file_quiz_create)
	{
		cout << "\n!!!!!!!!!!!!!!!!!! File of quiz creation is failled to create !!!!!!!!!!!!!!!!!!!!!!";
	}
	else
	{
		quiz* current_ptr = fptr_quiz;
		while (current_ptr != NULL)
		{
			file_quiz_create << current_ptr->quiz_1.quiz_no << endl;
			file_quiz_create << current_ptr->quiz_1.subject_q << endl;
			file_quiz_create << current_ptr->quiz_1.total_quiz << endl;
			file_quiz_create << current_ptr->quiz_1.abs_quiz << endl;
			current_ptr = current_ptr->nptr;
		}
		file_quiz_create.close();
	}
}
void store_assingment_creation()
{
	file_assingment_create.open("assingment_create.txt", ios::out);
	if (!file_assingment_create)
	{
		cout << "\n!!!!!!!!!!!!!!!!!! File of assingment creation is failled to create !!!!!!!!!!!!!!!!!!!!!!";
	}
	else
	{
		assingment* current_ptr = fptr_assingment;
		while (current_ptr != NULL)
		{
			file_assingment_create << current_ptr->assingment_1.assingment_no << endl;
			file_assingment_create << current_ptr->assingment_1.subject_a << endl;
			file_assingment_create << current_ptr->assingment_1.total_ass << endl;
			file_assingment_create << current_ptr->assingment_1.abs_ass << endl;
			current_ptr = current_ptr->nptr;
		}
		file_assingment_create.close();
	}
}
void store_attendance()
{
	file_attendance.open("attendance.txt", ios::out);
	if (!file_attendance)
	{
		cout << "\n!!!!!!!!!!!!!!!!!!!!!!! File of attendance is failled to create !!!!!!!!!!!!!!!!!!!!!!!!!";
	}
	else
	{
		attendance* current_ptr = fptr_attendance;
		while (current_ptr != NULL)
		{
			file_attendance << current_ptr->course_name << endl;
			file_attendance << current_ptr->reg_s << endl;
			file_attendance << current_ptr->student_name << endl;
			file_attendance << current_ptr->date << endl;
			file_attendance << current_ptr->month << endl;
			file_attendance << current_ptr->year << endl;
			file_attendance << current_ptr->status << endl;
			current_ptr = current_ptr->nptr;
		}
		file_attendance.close();
	}
}														//from here reading of data starts
/*void read_all_data()								// error
{
	read_semester_data();
	read_student_data();
	read_teacher_data();
	read_course_enroll();
	read_quiz_mark_data();
	read_assingment_marks();
	read_quiz_creation();
	read_assingment_creation();
	read_attendance();
}*/
void read_semester_data()				//error
{
	file_semester.open("semester.txt", ios::in);
	if (!file_semester)
	{
		cout << "\n!!!!!!!!!!!!!!!!! File of semester failed to open for read !!!!!!!!!!!!!!!!!!\n";
		return;
	}
	else
	{
		string read;
		int data;

		while (getline(file_semester, read))
		{
			semester* ptr_read;
			ptr_read = new semester;
			int i;
			ptr_read->a1.sem_no = stoi(read);
			getline(file_semester, read);
			ptr_read->a1.course_nos = stoi(read);
			ptr_read->a1.ptr = new course[ptr_read->a1.course_nos];
			for (i = 0; i < ptr_read->a1.course_nos; i++)
			{
				getline(file_semester, read);
				ptr_read->a1.ptr[i].course_name = read;				
				getline(file_semester, read);
				ptr_read->a1.ptr[i].course_id = read;
				getline(file_semester, read);
				ptr_read->a1.ptr[i].credit_hours = stoi(read);
				getline(file_semester, read);
				ptr_read->a1.ptr[i].teacher = read;
				getline(file_semester, read);
				ptr_read->a1.ptr[i].fee = stoi(read);
			}
			if (fptr_sem == NULL)
			{
				fptr_sem = ptr_read;
				ptr_read->nptr = NULL;
			}
			else
			{
				semester* current_ptr = fptr_sem;
				while (current_ptr->nptr != NULL)
				{
					current_ptr = current_ptr->nptr;
				}
				current_ptr->nptr = ptr_read;
				ptr_read->nptr = NULL;
			}
		}
		file_semester.close();
	}
}
void read_student_data()		//done cpmpletly
{
	file_student.open("student.txt", ios::in);
	if (!file_student.is_open())
	{
		cout << "\n!!!!!!!!!!!!!!!!!!!! File of student failed to open for reading !!!!!!!!!!!!!!!!!!!!!!!!!\n";
		return;
	}
	else
	{
		string read;

		while (getline(file_student, read))
		{
			semester* ptr_stud;
			ptr_stud = new semester;
			ptr_stud->a1.name = read;
			getline(file_student, read);
			ptr_stud->a1.reg = stoi(read);
			getline(file_student, read);
			ptr_stud->a1.phone_number = stoi(read);
			getline(file_student, read);
			ptr_stud->a1.city = read;
			getline(file_student, read);
			ptr_stud->a1.country = read;
			getline(file_student, read);
			ptr_stud->a1.birth = read;
			getline(file_student, read);
			ptr_stud->a1.address = read;
			getline(file_student, read);
			ptr_stud->a1.cinc = read;
			getline(file_student, read);
			ptr_stud->a1.set_password(read);				// bcz password is protecteed
			if (fptr_student == NULL)
			{
				fptr_student = ptr_stud;
				ptr_stud->nptr = NULL;
			}
			else
			{
				semester* current_ptr = fptr_student;
				while (current_ptr->nptr != NULL)
				{
					current_ptr = current_ptr->nptr;
				}
				current_ptr->nptr = ptr_stud;
				ptr_stud->nptr = NULL;
			}
		}
		file_student.close();
	}
}
void read_teacher_data()								//done completly
{
	file_teacher.open("teacher.txt", ios::in);
	if (!file_teacher.is_open())
	{
		cout << "\n!!!!!!!!!!!!!!!!!!!! File of teacher failed to open for reading !!!!!!!!!!!!!!!!!!!!!!!!!\n";
		return;
	}
	else
	{
		string read;

		while (getline(file_teacher, read))
		{
			semester* ptr_fac;
			ptr_fac = new semester;
			ptr_fac->a1.name = read;
			getline(file_teacher, read);
			ptr_fac->a1.reg = stoi(read);
			getline(file_teacher, read);
			ptr_fac->a1.phone_number = stoi(read);
			getline(file_teacher, read);
			ptr_fac->a1.city = read;
			getline(file_teacher, read);
			ptr_fac->a1.country = read;
			getline(file_teacher, read);
			ptr_fac->a1.birth = read;
			getline(file_teacher, read);
			ptr_fac->a1.address = read;
			getline(file_teacher, read);
			ptr_fac->a1.cinc = read;
			getline(file_teacher, read);
			ptr_fac->a1.set_password(read);				// bcz password is protecteed
			if (fptr_faculty == NULL)
			{
				fptr_faculty = ptr_fac;
				ptr_fac->nptr = NULL;
			}
			else
			{
				semester* current_ptr = fptr_faculty;
				while (current_ptr->nptr != NULL)
				{
					current_ptr = current_ptr->nptr;
				}
				current_ptr->nptr = ptr_fac;
				ptr_fac->nptr = NULL;
			}
		}
		file_teacher.close();
	}
}
void read_course_enroll()			//done completly
{
	string read;
	file_course_enroll.open("course_enroll.txt", ios::in);
	if (!file_course_enroll.is_open())
	{
		cout << "\n!!!!!!!!!!!!!!!! course_enroll file failled to open for reaading !!!!!!!!!!!!!!!!!!!!!!\n";
		return;
	}
	else
	{
		while (getline(file_course_enroll, read))
		{
			course_enroll* ptr;
			ptr = new course_enroll;
			ptr->sem = stoi(read);
			getline(file_course_enroll, read);
			ptr->name = read;
			getline(file_course_enroll, read);
			ptr->reg = stoi(read);
			getline(file_course_enroll, read);
			ptr->course = read;
			getline(file_course_enroll, read);
			ptr->fee = stoi(read);
			if (fptr_course == NULL)
			{
				fptr_course = ptr;
				ptr->nptr = NULL;
			}
			else
			{
				course_enroll* current_ptr = fptr_course;
				while (current_ptr->nptr != NULL)
				{
					current_ptr = current_ptr->nptr;
				}
				current_ptr->nptr = ptr;
				ptr->nptr = NULL;
			}
		}
		file_teacher.close();
	}
}
void read_quiz_mark_data()					//done completly
{
	string read;
	file_quiz_mark.open("Quiz_marks.txt", ios::in);
	if (!file_quiz_mark.is_open())
	{
		cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!! File of quiz marks failled to open for the reading !!!!!!!!!!!!!!!!!!!!!!!!\n";
		return;
	}
	else
	{
		while (getline(file_quiz_mark, read))
		{
			quiz* ptr;
			ptr = new quiz;
			ptr->nptr = NULL;
			ptr->quiz_1.name_q = read;
			getline(file_quiz_mark, read);
			ptr->quiz_1.reg_student_q = stoi(read);
			getline(file_quiz_mark, read);
			ptr->quiz_1.subject_q = read;
			getline(file_quiz_mark, read);
			ptr->quiz_1.total_quiz = stoi(read);
			getline(file_quiz_mark, read);
			ptr->quiz_1.quiz_no = stoi(read);
			getline(file_quiz_mark, read);
			ptr->quiz_1.abs_quiz = stoi(read);
			getline(file_quiz_mark, read);
			ptr->quiz_1.marks_quiz = stoi(read);
			if (fptr_quiz_mark == NULL)
			{
				fptr_quiz_mark = ptr;
			}
			else
			{
				quiz* current_ptr = fptr_quiz_mark;
				while (current_ptr->nptr != NULL)
				{
					current_ptr = current_ptr->nptr;
				}
				current_ptr->nptr = ptr;
			}
		}
		file_quiz_mark.close();
	}
}
void read_assingment_marks()			//cpmpletly done
{
	string read;
	file_assingmnet_mark.open("assingment_marks.txt", ios::in);
	if (!file_assingmnet_mark.is_open())
	{
		cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!! File of assingment marks is failled to open for the reading !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
		return;
	}
	else
	{
		while (getline(file_assingmnet_mark, read))
		{
			assingment* ptr;
			ptr = new assingment;
			ptr->nptr = NULL;
			ptr->assingment_1.name_a = read;
			getline(file_assingmnet_mark, read);
			ptr->assingment_1.reg_student_a = stoi(read);
			getline(file_assingmnet_mark, read);
			ptr->assingment_1.subject_a = read;
			getline(file_assingmnet_mark, read);
			ptr->assingment_1.total_ass = stoi(read);
			getline(file_assingmnet_mark, read);
			ptr->assingment_1.assingment_no = stoi(read);
			getline(file_assingmnet_mark, read);
			ptr->assingment_1.abs_ass = stoi(read);
			getline(file_assingmnet_mark, read);
			ptr->assingment_1.marks_assingment = stoi(read);
			if (fptr_assingment_mark == NULL)
			{
				fptr_assingment_mark = ptr;
			}
			else
			{
				assingment* current_ptr = fptr_assingment_mark;
				while (current_ptr->nptr != NULL)
				{
					current_ptr = current_ptr->nptr;
				}
				current_ptr->nptr = ptr;
			}
		}
		file_assingmnet_mark.close();
	}
}
void read_quiz_creation()			//completetly done
{
	string read;
	file_quiz_create.open("quiz_create.txt", ios::in);
	if (!file_quiz_create.is_open())
	{
		cout << "\n!!!!!!!!!!!!!!!!!! File of quiz creation is failled to open for the readind !!!!!!!!!!!!!!!!!!!!!!\n";
		return;
	}
	else
	{
		while (getline(file_quiz_create, read))
		{
			quiz* ptr;
			ptr = new quiz;
			ptr->quiz_1.quiz_no = stoi(read);
			getline(file_quiz_create, read);
			ptr->quiz_1.subject_q = read;
			getline(file_quiz_create, read);
			ptr->quiz_1.total_quiz = stoi(read);
			getline(file_quiz_create, read);
			ptr->quiz_1.abs_quiz = stoi(read);
			if (fptr_quiz == NULL)
			{
				fptr_quiz = ptr;
				ptr->nptr = NULL;
			}
			else
			{
				quiz* current_ptr = fptr_quiz;
				while (current_ptr->nptr != NULL)
				{
					current_ptr = current_ptr->nptr;
				}
				current_ptr->nptr = ptr;
				ptr->nptr = NULL;
			}
		}
		file_quiz_create.close();
	}
}
void read_assingment_creation()		//completly done
{
	string read;
	file_assingment_create.open("assingment_create.txt", ios::in);
	if (!file_assingment_create.is_open())
	{
		cout << "\n!!!!!!!!!!!!!!!!!! File of assingment creation is failled to open for reading !!!!!!!!!!!!!!!!!!!!!!\n";
		return;
	}
	else
	{
		while (getline(file_assingment_create, read))
		{
			assingment* ptr;
			ptr = new assingment;
			ptr->assingment_1.assingment_no = stoi(read);
			getline(file_assingment_create, read);
			ptr->assingment_1.subject_a = read;
			getline(file_assingment_create, read);
			ptr->assingment_1.total_ass = stoi(read);
			getline(file_assingment_create, read);
			ptr->assingment_1.abs_ass = stoi(read);
			if (fptr_assingment == NULL)
			{
				fptr_assingment = ptr;
				ptr->nptr = NULL;
			}
			else
			{
				assingment* current_ptr = fptr_assingment;
				while (current_ptr->nptr != NULL)
				{
					current_ptr = current_ptr->nptr;
				}
				current_ptr->nptr = ptr;
				ptr->nptr = NULL;
			}
		}
		file_assingment_create.close();
	}
}
void read_attendance()		//completely done
{
	string read;
	file_attendance.open("attendance.txt", ios::in);
	if (!file_attendance.is_open())
	{
		cout << "\n!!!!!!!!!!!!!!!!!!!!!!! File of attendance is failled to open for the reading !!!!!!!!!!!!!!!!!!!!!!!!!\n";
		return;
	}
	else
	{
		while (getline(file_attendance, read))
		{
			attendance* ptr;
			ptr = new attendance;
			ptr->course_name = read;
			getline(file_attendance, read);
			ptr->reg_s = stoi(read);
			getline(file_attendance, read);
			ptr->student_name = read;
			getline(file_attendance, read);
			ptr->date = stoi(read);
			getline(file_attendance, read);
			ptr->month = read;
			getline(file_attendance, read);
			ptr->year = stoi(read);
			getline(file_attendance, read);
			ptr->status = read;
			if (fptr_attendance == NULL)
			{
				fptr_attendance = ptr;
				ptr->nptr = NULL;
			}
			else
			{
				attendance* current_ptr = fptr_attendance;
				while (current_ptr->nptr != NULL)
				{
					current_ptr = current_ptr->nptr;
				}
				current_ptr->nptr = ptr;
				ptr->nptr = NULL;
			}
		}
		file_attendance.close();
	}
}