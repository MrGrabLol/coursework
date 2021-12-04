#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

///By Alexander Bogomolov: BIV194

//ofstream << ifstream >> REMEMBER

using namespace std;

class Student{
	protected:
		string name;
		string surname;
		string patronymic;
		string group;
		float algebra;
		float english;
		float programming;
		float geometry;
		float average;
		string additional_info;
	public:
		Student():name("Ivan"),surname("Ivanov"),patronymic("Ivanovich"),group("BIG000"),algebra(0),english(0),programming(0),geometry(0),average(0),additional_info("None"){}
		Student(string n, string s, string patr, string gr,
				int a, int e, int p, int geo, double ave,
				string ai):name(n),surname(s),patronymic(patr),group(gr),algebra(a),english(e),programming(p),geometry(geo),average(ave),additional_info(ai){}
		~Student(){
			cout<<"Student deleted successfully!"<<endl;
		}
		void changeAlgebra(){
			float alg;
			do{
				cout<<"Change algebra to: ";
				cin>>alg;
			}while(alg<0||alg>10);
			algebra=alg;
			cout<<endl;
		}
		void changeEnglish(){
			float eng;
			do{
				cout<<"Change english to: ";
				cin>>eng;
			}while(eng<0||eng>10);
			english=eng;
			cout<<endl;
		}
		void changeProgramming(){
			float pro;
			do{
				cout<<"Change programming to: ";
				cin>>pro;
			}while(pro<0||pro>10);
			programming=pro;
			cout<<endl;
		}
		void changeGeometry(){
			float geo;
			do{
				cout<<"Change geometry to: ";
				cin>>geo;
			}while(geo<0||geo>10);
			geometry=geo;
			cout<<endl;
		}
		inline void changeName(){
			string n;
			cout<<"Change name to: ";
			cin>>n;
			name=n;
			cout<<endl;
		}
		inline void changeSurname(){
			string sur;
			cout<<"Change surname to: ";
			cin>>sur;
			surname=sur;
			cout<<endl;
		}
		inline void changePatronymic(){
			string patron;
			cout<<"Change patronymic to: ";
			cin>>patron;
			patronymic=patron;
			cout<<endl;
		}
		inline void setAverage(){
			average=(algebra+english+programming+geometry)/4;
		}
		inline void changeGroup(){
			string gro;
			cout<<"Change group to(MIEM style is required): ";
			cin>>gro;
			group=gro;
			cout<<endl;
		}
		inline void changeAdditionalInfo(){
			string info;
			cout<<"Change additional info to: ";
			cin>>info;
			additional_info=info;
			cout<<endl;
		}
		friend ostream & operator << (ostream &, const Student &);
		friend void showStudent(int numb, Student s[]){
			cout<<"--------------------This is all info about all students in your university--------------------"<<endl<<endl<<endl;
			for(int i=0;i<numb;++i){
				cout<<"Student: "<<s[i].name<<" "<<s[i].surname<<" "<<s[i].patronymic<<endl;
				cout<<"Student's group: "<<s[i].group<<endl;
				cout<<"Student's score -> "<<endl;
				cout<<"     Algebra: "<<s[i].algebra<<endl;
				cout<<"     English: "<<s[i].english<<endl;
				cout<<"     Programming: "<<s[i].programming<<endl;
				cout<<"     Geometry: "<<s[i].geometry<<endl;
				cout<<"Student's average score: "<<s[i].average<<endl;
				cout<<"Student's additional info: "<<s[i].additional_info<<endl;
				cout<<endl;
			}
		}
		friend void fillInfo(int numb, Student s[]){
			for(int i=0;i<numb;++i){
				cout<<endl<<"-----Student #"<<i+1<<"-----"<<endl;
				s[i].changeName();
				s[i].changeSurname();
				s[i].changePatronymic();
				s[i].changeGroup();
				s[i].changeAlgebra();
				s[i].changeEnglish();
				s[i].changeProgramming();
				s[i].changeGeometry();
				s[i].setAverage();
				s[i].changeAdditionalInfo();
			}
		}
		friend void inputInFile(ofstream &f, Student s[], int numb){//this is utterly retarded
			for(int i=0;i<numb;++i){
				f<<s[i].name<<endl;
				f<<s[i].surname<<endl;
				f<<s[i].patronymic<<endl;
				f<<s[i].group<<endl;
				f<<s[i].algebra<<endl;
				f<<s[i].english<<endl;
				f<<s[i].programming<<endl;
				f<<s[i].geometry<<endl;
				f<<s[i].average<<endl;
				f<<s[i].additional_info<<endl;
			}
			//f.clear();
			//f.seekg(0,ios::beg);
		}
		friend getFromFile(fstream &f, Student ss[], int numb){
			for(int i=0;i<numb;++i){
				f>>ss[i].name;
				f>>ss[i].surname;
				f>>ss[i].patronymic;
				f>>ss[i].group;
				f>>ss[i].algebra;
				f>>ss[i].english;
				f>>ss[i].programming;
				f>>ss[i].geometry;
				f>>ss[i].average;
				f>>ss[i].additional_info;
			}
			f.clear();
			f.seekg(0,ios::beg);
		}
		friend void copy(Student sreal[], Student svirt[], int num){
			for(int i=0;i<num;++i){
				svirt[i].name=sreal[i].name;
				svirt[i].surname=sreal[i].surname;
				svirt[i].patronymic=sreal[i].patronymic;
				svirt[i].group=sreal[i].group;
				svirt[i].algebra=sreal[i].algebra;
				svirt[i].english=sreal[i].english;
				svirt[i].programming=sreal[i].programming;
				svirt[i].geometry=sreal[i].geometry;
				svirt[i].average=sreal[i].average;
				svirt[i].additional_info=sreal[i].additional_info;
			}
		}
		friend void sortByNameSurnamePatronymic(Student sss[], int num){
			Student temp;
			for(int i=0;i<num-1;++i){
				for(int j=i+1;j<num;++j){
					if(sss[i].surname>sss[j].surname){
						temp=sss[i];
						sss[i]=sss[j];
						sss[j]=temp;
					}
				}
			}
			int counter=1;
			int x=0;
			bool flag=false;
			while(x<num){
				while(sss[x].surname==sss[x+counter].surname){
					counter++;
					flag=true;
				}
				if(flag==true){
					counter=counter-1;
					for(int i=x;i<x+counter;++i){
						for(int j=i+1;j<=x+counter;++j){
							if(sss[i].name>sss[j].name){
								temp=sss[i];
								sss[i]=sss[j];
								sss[j]=temp;
							}
						}
					}
					x=x+counter;
					counter=1;
					flag=false;
				}else{
					x++;
				}
			}
			counter=1;
			x=0;
			flag=false;
			while(x<num){
				while(sss[x].name==sss[x+counter].name){
					counter++;
					flag=true;
				}
				if(flag==true){
					counter=counter-1;
					for(int i=x;i<x+counter;++i){
						for(int j=i+1;j<=x+counter;++j){
							if(sss[i].patronymic>sss[j].patronymic){
								temp=sss[i];
								sss[i]=sss[j];
								sss[j]=temp;
							}
						}
					}
					x=x+counter;
					counter=1;
					flag=false;
				}else{
					x++;
				}
			}
		}
		friend void sortByGroup(Student gr[], int num){
			Student tmp;
			for(int i=0;i<num-1;++i){
				for(int j=i+1;j<num;++j){
					if(gr[i].group>gr[j].group){
						tmp=gr[i];
						gr[i]=gr[j];
						gr[j]=tmp;
					}
				}
			}
		}
		friend void sortByTopAverage(Student top[], int num){
			Student tmptop;
			for(int i=0;i<num-1;++i){
				for(int j=i+1;j<num;++j){
					if(top[i].average<top[j].average){
						tmptop=top[i];
						top[i]=top[j];
						top[j]=tmptop;
					}
				}
			}
		}
		friend void sortByWorstAverage(Student worst[], int num){
			Student tmpworst;
			for(int i=0;i<num-1;++i){
				for(int j=i+1;j<num;++j){
					if(worst[i].average>worst[j].average){
						tmpworst=worst[i];
						worst[i]=worst[j];
						worst[j]=tmpworst;
					}
				}
			}
		}
		friend void showOnlyGood(Student good[], int num){
			for(int i=0;i<num;++i){
				if(good[i].algebra>=6 && good[i].english>=6 && good[i].programming>=6 && good[i].geometry>=6){
					cout<<good[i];
				}
			}
		}
		friend void showOnlyBad(Student bad[], int num){
			for(int i=0;i<num;++i){
				if(bad[i].algebra<6 && bad[i].english<6 && bad[i].programming<6 && bad[i].geometry<6){
					cout<<bad[i];
				}
			}
		}
};

ostream & operator << (ostream & out, const Student &s){
	out<<s.name<<" "<<s.surname<<" "<<s.patronymic<<", group "<<s.group<<endl;
	out<<"     Algebra: "<<s.algebra<<endl;
	out<<"     English: "<<s.english<<endl;
	out<<"     Programming: "<<s.programming<<endl;
	out<<"     Geometry: "<<s.geometry<<endl;
	out<<"     Average: "<<s.average<<endl;
	out<<"     Additional info: "<<s.additional_info<<endl<<endl;
	return out;
}

int getLength(fstream &f1){
	string str1;
	int cntr=0;
	while(!f1.eof()){
		getline(f1, str1);
		++cntr;
	}
	cntr=cntr-1;//because there is one last "<<endl" in the end
	return cntr/10;//because 1 class consists of 10 total strings
}

inline void options(){
	cout<<"Choose your options:"<<endl;
	cout<<"     sort by name/surname/patronymic(1)"<<endl;
	cout<<"     sort by group(2)"<<endl;
	cout<<"     sort by top average(3)"<<endl;
	cout<<"     sort by worst average(4)"<<endl;
	cout<<"     show only good score students(5)"<<endl;
	cout<<"     show only bad score students(6)"<<endl;
	cout<<"     skip this part(7)"<<endl;
}

int checkChoice(){
	int choice_c;
	do{
		cout<<"What do you want to do: edit(check) existing file or create a new one? Enter 1 if edit(check), enter 2 if create new: ";
		cin>>choice_c;
		cout<<endl;
	}while(choice_c<1||choice_c>2);
	return choice_c;
}

int checkChoice2(){
	int choice_c;
	do{
		cout<<"1-do not change, 2 - change: ";
		cin>>choice_c;
		cout<<endl;
	}while(choice_c<1||choice_c>2);
	return choice_c;
}

inline void options2(){
	cout<<"What do you want to change:"<<endl;
	cout<<"   Name(1)"<<endl;
	cout<<"   Surname(2)"<<endl;
	cout<<"   Patronymic(3)"<<endl;
	cout<<"   Group(4)"<<endl;
	cout<<"   Algebra(5)"<<endl;
	cout<<"   English(6)"<<endl;
	cout<<"   Programming(7)"<<endl;
	cout<<"   Geometry(8)"<<endl;
	cout<<"   Additional info(9)"<<endl;
	cout<<"You can exit by entering 10"<<endl;
}

int main() {
	int choice=checkChoice();
	if(choice==1){
		fstream f;
		f.open("NewList.txt");
		if(f){
			int size=getLength(f);
			f.clear();
			f.seekg(0,ios::beg);
			Student s_edit[size];
			getFromFile(f,s_edit,size);
			Student s_sort[size];
			copy(s_edit, s_sort, size);
			cout<<"I have read all info from existing file. Here it is: "<<endl<<endl;
			showStudent(size, s_edit);
			cout<<endl<<"Now these are all options: you can sort it by group, you can sort it by name/surname, you can sort it by top average,you can sort it by worst average.Also i can show students with only good score(>8) and students with bad score(<4)"<<endl;
			options();
			int choice2;
			do{
				do{
					cout<<"Your choice is: ";
					cin>>choice2;
					cout<<endl;
				}while(choice2<1||choice2>7);
				switch(choice2){
					case 1:
						sortByNameSurnamePatronymic(s_sort, size);
						showStudent(size, s_sort);
						break;
					case 2:
						sortByGroup(s_sort, size);
						showStudent(size, s_sort);
						break;
					case 3:
						sortByTopAverage(s_sort, size);
						showStudent(size, s_sort);
						break;
					case 4:
						sortByWorstAverage(s_sort, size);
						showStudent(size, s_sort);
						break;
					case 5:
						showOnlyGood(s_sort, size);
						break;
					case 6:
						showOnlyBad(s_sort, size);
						break;
					case 7:
						break;
					default:
						cout<<"Something is wrong here."<<endl;
						break;
				}
			}while(choice2!=7);
			cout<<endl<<"You decided to exit. Okay. Now you can change any info about any student you want."<<endl;
			cout<<"If you don't want to change anything, enter 1. If you want to change something, enter 2."<<endl;
			int choice3=checkChoice2();
			if(choice3==1){
				cout<<endl<<"Okay. This is the end. Thanks for using this program."<<endl;
				return 0;
			}else{
				int number2;
				again:
				do{
					cout<<"Choose student(enter his number): ";
					cin>>number2;
					cout<<endl;
				}while(number2>size||number2<1);
				//if() or switch again
				options2();
				int choice4;
				do{
					do{
						cout<<"Your choice is: ";
						cin>>choice4;
						cout<<endl;
					}while(choice4>10||choice4<1);
					switch(choice4){
						case 1:
							s_edit[number2-1].changeName();
							break;
						case 2:
							s_edit[number2-1].changeSurname();
							break;
						case 3:
							s_edit[number2-1].changePatronymic();
							break;
						case 4:
							s_edit[number2-1].changeGroup();
							break;
						case 5:
							s_edit[number2-1].changeAlgebra();
							break;
						case 6:
							s_edit[number2-1].changeEnglish();
							break;
						case 7:
							s_edit[number2-1].changeProgramming();
							break;
						case 8:
							s_edit[number2-1].changeGeometry();
							break;
						case 9:
							s_edit[number2-1].changeAdditionalInfo();
							break;
						case 10:
							break;
						default:
							cout<<"Something is wrong here"<<endl;
					}
				}while(choice4!=10);
				f.close();
				remove("NewList.txt");
				ofstream fnew("NewList.txt");
				inputInFile(fnew, s_edit, size);
				cout<<"Info saved. If you want to change info about students once again, enter 2. If not, enter 1 and this program will close. Thanks for using this program."<<endl;
				int choice5;
				do{
					cout<<"Your choice is: ";
					cin>>choice5;
					cout<<endl;
				}while(choice5<1||choice5>2);
				if(choice5==2){
					goto again;
				}else{
					cout<<"This is the end of this program."<<endl;
				}
				return 0;
			}
		}else{
			cerr<<"Error: unable to open file(is missing).";
			return 999;
		}
	}else{
		remove("NewList.txt");
		ofstream list("NewList.txt");
	//	f<<"This text will appear there.";
	//	f.close();
		cout<<"Enter number of students: ";
		int number;
		cin>>number;
		Student s[number];
		cout<<"Now enter all info about students, please"<<endl;
		fillInfo(number, s);
		showStudent(number, s);
		cout<<"Now i will write all students to a file."<<endl;
		inputInFile(list, s, number);
		cout<<"Writing completed, you can check your file. If you want to edit or sort it, please re-run this program and choose 1 on a starting screen."<<endl;
		list.close();
		return 0;
	}
}
