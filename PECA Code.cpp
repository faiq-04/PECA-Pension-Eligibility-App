#include <iostream>
#include <string>

using namespace std;
// class personal information
class info	
	{
	private:
		string name;
		int id, birthDate, birthMonth, birthYear;
		
	public:
		//constructor
		info(){
			name;
			id;
			birthDate; 
			birthMonth;
			birthYear;
		}
		//destructor
		~info(){
			
		}
		//setter for info
		void set_info(string n, int i, int b_date, int b_month, int b_year){
			name = n;
			id = i;
			birthDate = b_date;
			birthMonth = b_month;
			birthYear = b_year;
		}
	 
    void showInfo()const{
	cout<<"Name: "<<name<<endl;
	cout<<"Id No: "<<id<<endl;
	cout<<"Date of Birth: " <<birthDate<<"/"<<birthMonth<<"/"<<birthYear<<endl;
	
	}
	
	//ageChecker
	int calculateAge(int pensionYear, int pensionMonth, int pensionDate, int age)const{
         age = pensionYear - birthYear;

        if (pensionMonth < birthMonth || (pensionMonth == birthMonth && pensionDate < birthDate)) {
            age--;
        }
        return age;
    }
    
   
    
     void displayAge(int pensionYear, int pensionMonth, int pensionDate, int age) const {
        int ageYears = calculateAge(pensionYear, pensionMonth, pensionDate, age);
        int months = (pensionMonth >= birthMonth)?(pensionMonth - birthMonth) : (pensionMonth + 12 - birthMonth - 1);
        if (pensionDate < birthDate){
        	months--;
		} 
		 
        cout << ageYears << " years " << months << " months";
    }
};

//class for service information
class ServiceInfo 
	{
	protected:
    	int appointmentDate, appointmentMonth, appointmentYear;
    	double lastSalary;
    	double totalAllowance;
    	
    public:
    	//constructor
    	ServiceInfo(){
    		appointmentDate, appointmentMonth, appointmentYear;
    		lastSalary;
    		totalAllowance;
    	}
    	
    	//destructor
    	~ServiceInfo(){
    		
		}
    	
    	//setter for serviceinfo
    void setServiceInfo(int a_Day, int a_Month, int a_Year, double salary, double allowance) {
        appointmentDate = a_Day;
        appointmentMonth = a_Month;
        appointmentYear = a_Year;
        lastSalary = salary;
        totalAllowance = allowance;
    }

    void displayServiceInfo() const{
        cout << "Date of Appointment: " << appointmentDate << "/" << appointmentMonth << "/" << appointmentYear << endl;
        cout << "Your last Salary: " << lastSalary << endl;
        cout << "Total Allowance: " << totalAllowance << endl;
    }
		//service calculator
    int calculateServiceMonths(int pensionYear, int pensionMonth, int pensionDate, int age) const {
        int months = (pensionYear - appointmentYear) * 12 + (pensionMonth - appointmentMonth);
        if (pensionDate < appointmentDate){
			months--;
		} 
        return months;
    }
    	
};
//class pension
class peca:public info, public ServiceInfo
	{
	public:
		//peca eligibility checker
		bool checkEligibility(int pensionYear, int pensionMonth, int pensionDate, string &reason)const{
        int age = calculateAge(pensionYear, pensionMonth, pensionDate, age);
        int serviceMonths = calculateServiceMonths(pensionYear, pensionMonth, pensionDate, age);

        if (age<40&&serviceMonths<120) {
            reason = "Your service is less than 10 years AND\nYour age is below 40";
            return false;
        } else if (age<40) {
            reason = "Your age is below 40";
            return false;
        } else if (serviceMonths<120) {
            reason = "Your service is less than 10 years";
            return false;
        }
        return true;
    }

		// pensionCalculator
    double calculatePension(int months) const{
        int limitedServiceMonths=(months>360)?360:months;
        return 0.00167 * limitedServiceMonths * lastSalary;
    }
//gratuitycalculation
    double calculateGratuity(int months)const{
        return 0.075 * lastSalary * months;
    }

    void displayEligibilityAndCalculation(int pensionYear, int pensionMonth, int pensionDate, int age) {
        string reason;
        int serviceMonths = calculateServiceMonths(pensionYear, pensionMonth, pensionDate, age);

        cout << "\nCalculate Pension Estimation:\nYour Service Information....." << endl;
        showInfo();
        displayServiceInfo();
        cout << "Enter Date of Pension\nDay: " << pensionDate << "\nMonth: " << pensionMonth << "\nYear: "<<pensionYear<< endl;

        if (checkEligibility(pensionYear, pensionMonth, pensionDate, reason)) {
            int years = serviceMonths/12;
            int remainingMonths = serviceMonths%12;
            cout<< "\nYour service is: "<<years<< " Years and "<< remainingMonths<<" months ("<<serviceMonths<<" months)"<<endl;
            cout<< "You are eligible to pension"<<endl;
            cout<< "Pension per month: RM "<<calculatePension(serviceMonths)<<endl;
            cout<< "Gratuity: RM "<<calculateGratuity(serviceMonths)<< endl;
        } else
			{
            cout << "\nYour are NOT eligible to pension\n" << reason << endl;
            cout << "Your age is below 40: ";
            displayAge(pensionYear, pensionMonth, pensionDate, age);
            cout << endl;
        }
    }
			//prototype frnd func
    friend void inputPersonalAndServiceData(peca &p);
	
};
		//Input handling
	void birthValidation(int &birthDate, int &birthMonth){
		do
		{
			cout<<"Please enter your birthdate (DD): ";
    		cin>>birthDate;
    		if(birthDate<1||birthDate>31){
    			cout<<"Invalid Date! Please enter between (1-31) ";
			}
		}while(birthDate<1||birthDate>31);
		
		do
		{
			cout<<"Please enter your Month (MM): ";
    		cin>>birthMonth;
			if(birthMonth<1||birthMonth>12){
				cout<<"Invalid Month! Please enter between (1-12) ";
			}	
		}while(birthMonth<1||birthMonth>12);
	}
	
	void appointmentValidation(int &appointmentDate, int &appointmentMonth){
		do{
			 cout<<"Enter appointment Date: ";
    		 cin>>appointmentDate;
			if(appointmentDate<1||appointmentDate>31){
				cout<<"Invalid Date! Please enter between (1-31) ";
			}
		}while(appointmentDate<1||appointmentDate>31);
		
		do{
			cout<<"Enter appointment Month: ";
			cin>>appointmentMonth;
			if(appointmentMonth<1||appointmentMonth>12){
			cout<<"Invalid Month! Please enter between (1-12) ";
			}
		}while(appointmentMonth<1||appointmentMonth>12);
	}

	//inputoutput info
	void inputPersonalAndServiceData(peca &p){
		string name;
		int id, birthDate, birthMonth, birthYear;
		int appointmentDate, appointmentMonth, appointmentYear;
	    double lastSalary;
	    double totalAllowance;
    
    cout<<"======Welcome to PECA checker====== "<<endl<<endl;;
    cout<<"Employee Information "<<endl<<endl;
    cout<<"Please Enter your name: ";
    getline(cin, name);
    cout<<"Please enter your IC NO: ";
    cin>>id;
    
    cout<<"\nYour Date of Birth Information "<<endl;
    birthValidation(birthDate, birthMonth);
    cout<<"Please enter your Year(YY): ";
    cin>>birthYear;
    
    p.set_info(name, id, birthDate, birthMonth, birthYear);
    
    cout<<"\nService Information "<<endl;
    cout<<"\nSet Appointment Date" << endl;
   
    appointmentValidation(appointmentDate, appointmentMonth);
    cout<<"Enter Appointment Year: ";
    cin>>appointmentYear;

    cout<<"\nSet wages information "<<endl;
    cout<<"Enter Latest Salary: ";
    cin>>lastSalary;
    cout<<"Enter Total Allowance: ";
    cin>>totalAllowance;
    p.setServiceInfo(appointmentDate, appointmentMonth, appointmentYear, lastSalary, totalAllowance);
    
	
}

int main(){
	//object pension
	peca Pension;
    inputPersonalAndServiceData(Pension);

    int pensionDate, pensionMonth, pensionYear, age;
    cout<< "\nEnter Date of Pension" << endl;
    cout<< "Enter Pension Date: ";
    cin>> pensionDate;
    cout<< "Enter Pension Month: ";
    cin>> pensionMonth;
    cout<< "Enter Pension Year: ";
    cin>> pensionYear;

    Pension.displayEligibilityAndCalculation(pensionYear, pensionMonth, pensionDate, age);	
	
	
	return 0;
}

