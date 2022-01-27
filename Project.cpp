
#include<iostream>
#include<string>
#include<cctype>

// violate input (ask for menu)
// files
// function prototype 


int k;
using namespace std;

void intro (){
	cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"|                                                                                                                    |"<<endl;
	cout<<"|                                          Welcome To The Hospital System                                            |"<<endl;
	cout<<"|                                                                                                                    |"<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl<<endl<<endl;
}
void check(string &id){
	bool correct=true;
	for (int i=0 ; i<id.length(); i++){
		if (!(isdigit(id.at(i)))){
			correct=false;
			break;
		}
	}
	if (correct==false){
		cout<<"ID has to be a number !"<<endl;
		cout<<"Re-enter ID: "<<endl;
		cin>>id;
		check(id);
	} 

}


void check(char &gender){
	bool correct=true;
	if (islower(gender)){
		gender=toupper(gender);
	}
	if (gender!='F'&&gender!='M'){
		correct=false;
		if(correct==false){
			cout<<"Invalid input (Note: you have to enter F for female and M for male )"<<endl;
			cout<<endl<<"Re-enter the the gender: "<<endl;
			cin>>gender;
			check(gender);}
		}
}
void check (int &choice){
	bool correct=true;
	if (choice<1||choice>6 &&choice!=999){
		correct=false;
		if(correct==false){
			cout<<"Invalid input (Note: you have to enter a number between 1-6 \"999 to exit\" )"<<endl;
			cout<<endl<<"Re-enter the the choice: "<<endl;
			cin>>choice;
			check(choice);}
	
}
}
void menu ()
{
	cout<<endl;
	cout<<"Please choose the desired task: "<<endl;
	cout<<"------------------------------------------"<<endl;
	cout<<"| 1 | Add new patient                    |"<<endl;
	cout<<"| 2 | Update patient details             |"<<endl;
	cout<<"| 3 | Search for a patient               |"<<endl;
	cout<<"| 4 | Delete an existing patient         |"<<endl;
	cout<<"| 5 | Display & Sort patient information |"<<endl;
	
	cout<<"------------------------------------------"<<endl;
	cout<<"Enter \"999\" to exit"<<endl;
	
	cout<<endl;
}
struct Date
{
	int year,month,day;
};
struct Patient
{
	string name,id, blood;
	int age;
	char gender;
	Date dob;
	string disease;	
};
typedef Patient* PatientPtr;
int Age(int year)
{
	int currentYear=2021;
	return currentYear-year;
	
}

void checkBlood (string &type){
	bool correct=true;
	if (type!="O+"&&type!="O-"&&type!="A+"&&type!="A-"&&type!="B+"&&type!="B-"&&type!="AB+"&&type!="AB-"){
		correct=false;}
		if (correct==false){
			cout<<"Invalid input (Note: you have to enter the type in capital letter including Rh factor)"<<endl;
			cout<<"Re-enter the blood type: "<<endl;
			cin>>type;
			checkBlood(type);}
		}
		
		
void CheckDate( int &day, int &month, int &year )               
{
	bool correct= true;
	
             if (year>=1900&&year<=2021){
			 
			 switch(month) {
			 	
			 	case 2: 
			 	if (day>28)
			 	{
			 		correct= false; 
					  
				 }
				 break;
				 
				 case 4: 
				 case 6: 
				 case 9: 
				 case 11: 
				 if (day>30)
				 {
				 	correct= false; 
				 	
				 }
				 break;
				 
				 case 1: 
				 case 3: 
				 case 5: 
				 case 7: 
				 case 8: 
				 case 10: 
				 case 12: 
				 if (day >31)
				 correct= false; 
				 
				 break;
			}
			
			}
			else correct=false; 
			
			
				 if (correct==false)
				 {
				 		cout<<"The date is invalid "<<endl<<endl;
		                cout<<"Re-enter the date (D M Y)"<<endl; 
		                cin>>day>>month>>year;
		                CheckDate(day,month,year);
				 }
				 
				 			 
}

		

void addPatient (PatientPtr a,int size,int &num)
{
	if (num<size){
	cout<<endl<<"Enter the patient's national ID:"<<endl;
	cin>>a[num].id;
	check(a[num].id);
	cout<<endl<<"Enter the patient's name (Firstname and lastname):"<<endl;
	cin.ignore(30,'\n');
	getline(cin,a[num].name);
	cout<<endl<<"Enter the patient's gender: (F for female, M for male)"<<endl;
	cin>>a[num].gender;
	check(a[num].gender);
	cout<<endl<<"Enter the patient's blood type: (Ex: A+)"<<endl;
	cin>>a[num].blood;
	checkBlood (a[num].blood);
	cout<<endl<<"Enter the patient's date of birth (D M Y):"<<endl;
	
	cin>>a[num].dob.day>>a[num].dob.month>>a[num].dob.year;
    CheckDate(a[num].dob.day,a[num].dob.month,a[num].dob.year);
	cout<<endl<<"Enter the patient's disease:"<<endl;
	cin.ignore(30,'\n');
	getline(cin,a[num].disease);
	a[num].age=Age(a[num].dob.year);
	num++;
	a++;}
	else{
		cout<<endl<<"The number of patients has reached the maximum !"<<endl;
		cout<<"please delete a patient before adding"<<endl;
	}
	
	
}
void updateMenu()
{
	cout<<"What would you like to update? "<<endl;
	cout<<"1.Modify name "<<endl;
	cout<<"2.Modify gender "<<endl;
	cout<<"3.Modify blood type "<<endl;
	cout<<"4.Modify date of birth "<<endl;
	cout<<"5.Modify disease "<<endl;
	
}
void updatePatient (PatientPtr a,int size,int num)
{
	k=-1;
	string check;
	int choice;
	bool found=false;
	updateMenu();
	cin>>choice;
	cout<<"Enter the patient's ID: "<<endl;
	cin>>check;
	for (int i=0 ; i<num ;i++)
	{
	if(check==a[i].id)
	{
		found=true;
		k=i;}
	}
		
	if (found){
		
	switch (choice)
	{
		case 1:
			cout<<"Enter the new name: "<<endl;
			cin>>a[k].name;
			cout<<a[k].name<<"'s name has been updated"<<endl;
			break;
			case 2:
			cout<<"Enter the gender: "<<endl;
			cin>>a[k].gender;
			cout<<a[k].name<<"'s gender has been updated"<<endl;
			break;
			case 3:
			cout<<"Enter the blood type: "<<endl;
			cin>>a[k].blood;
			cout<<a[k].name<<"'s blood type has been updated"<<endl;
			break;
			case 4:
			cout<<"Enter the date of birth(D M Y):"<<endl;
			cin>>a[k].dob.day>>a[k].dob.month>>a[k].dob.year;
			a[k].age=Age(a[k].dob.year);
			cout<<a[k].name<<"'s date of birth has been updated"<<endl;
			break;
			case 5:
			cout<<"Enter the disease: "<<endl;
			cin>>a[k].disease;
			cout<<a[k].name<<"'s disease has been updated"<<endl;
			break;
			default:
				cout<<"Invalid choice"<<endl;
			
			
		}	
		
	}
	else {
	cout<<"The patient with ID "<<check<<" is not found !"<<endl;}
		
}
void Sorting(PatientPtr a,int size, int num)  {
    int choice;
    cout<<"Do you want to sort in descending '0'or ascending order '1'?"<<endl;
    cin>>choice;
    if(choice==1)
    {
       for (int i=0; i<num-1; i++)
       {
       	for(int j=0 ; j<num-1;j++)
	   
	{
		if (a[j].name>a[j+1].name)
		{
			Patient temp;
			temp=a[j]; 
			a[j]=a[j+1];
			a[j+1]=temp;
		}
	}
       }   
    }
    if(choice==0)
    {
        for(int i=0 ; i<num-1 ;i++){
		
		for(int j=0 ; j<num-1;j++){
                if(a[j].name<a[j+1].name)
                {
                 Patient temp;
			     temp=a[j]; 
			     a[j]=a[j+1];
			     a[j+1]=temp;
                    
                }
            }
        }
         } 
    cout<< " your records have been sorted "<< endl;

    }

	void deletePatient (PatientPtr a,int size,int &num)
	{
	string check;
	int choice;
	bool found=false;
	cout<<"Enter the patient's ID: "<<endl;
	cin>>check;
	for (int i=0 ; i<num ;i++)
	{
	if(check==a[i].id)
	{ 
	found=true;
	k=i;
}
}
	if (found){
		for (int j=k; j<num-1; j++)
		{
		  
		  a[j]=a[j+1];
		  
		}
		cout<<a[k].name<<"'s record has been deleted !"<<endl;
		num--;
		a--;
	}
	else {
		cout<<"The patient with ID "<<check<<" is not found !"<<endl;
	}
}
bool Search(PatientPtr a, int size, int num)
{
	string check;
	int choice;
    cout<<endl<<"Enter the patient's ID (999 to exit): "<<endl;
    cin>>check;
    
	for (int i=0;i<num;i++)
	{
		if (a[i].id==check)
		{
			k=i;	
			return true;
		}
	}
	if (check!="999"){
	cout<<endl<<"The patient is not found !"<<endl;
    Search(a, size,num);
}
	
}



void print (PatientPtr a,int size, int num)
{
	for (int i=0; i<num; i++)
	{
		if (islower(a[i].name[0]))
		{
			a[i].name[0]=toupper(a[i].name[0]);
		}
		
		for (int i=1; i<a[i].name.length(); i++)
		{
		
		if (isupper(a[i].name[i]))
		{
			a[i].name[i]=tolower(a[i].name[i]);
		}
	}
		
	}
	char x;
cout<<"Do you want to sort the record?"<<endl<<"Enter Y for Yes and N for No: "<<endl;
cin>>x;
switch (x){
	case 'Y':
	case 'y':  
	 Sorting(a,size, num);
	 break;
	 
	case 'N':
	case 'n':
	break;
		
		
		
}
  

	for (int i=0; i<num; i++ )
	{
		cout<<"------------------------------------------------------------------------------"<<endl;
		cout<<"|     ID     |     Name     |   Age    |  Gender  | Blood type |   Disease   |"<<endl;
		cout<<"------------------------------------------------------------------------------"<<endl;
		cout<<"| "<<a[i].id<<" | "<<a[i].name<<" |    "<<a[i].age<<"    |    "<<a[i].gender<<"     |     "<<a[i].blood<<"     |     "<<a[i].disease<<"    |"<<endl;
		cout<<"------------------------------------------------------------------------------"<<endl<<endl<<endl;
		
	}
	

}

int checkSize (int size){

	if (size>0&&size!=999){
		return 1;
	}
	if (size==999){
		return 0;
	}
	else if (size<=0){
		cout<<endl<<"number of patients has to be greater than zero !"<<endl;
		cout<<endl<<"Re-enter The maximum number of patients: (999 to exit) "; 
		cin>>size;
		checkSize(size);
	}
}

int main ()
{
	int size, num=0, choice=0; 
	intro();
	cout<<"Enter The maximum number of patients: "; 
	cin>>size;
	if (checkSize(size)){
	PatientPtr record=new Patient [size];
	while (choice!=999){
		menu();
		cin>>choice;
		check (choice);
		
		switch (choice){
			case 1:
				addPatient(record, size, num);
				break;	
				
			case 2:
				updatePatient (record,size, num);
				break;
			
			case 3:
				if (num>0){
				if (Search(record, size, num)&&k!=-1){
				cout<<"The patient's information: "<<endl;
				cout<<"Name: "<<record[k].name<<endl;
				cout<<"Age: "<<record[k].age<<endl;
				cout<<"Gender: "<<record[k].gender<<endl;
				cout<<"Blood type: "<<record[k].blood<<endl;
				cout<<"Disease: "<<record[k].disease<<endl; 
				k=-1;
				}

			}
			else {
				cout<<"There is no patients !"<<endl;
			}
				break;
			
			case 4:
				deletePatient(record, size, num);
				break;
				
				
			case 5:
				print(record, size, num);
				break;
		
		
	}	
}
}
		cout<<endl<<"Thank you for choosing our hospital !"<<endl;

	
	return 0;
}
