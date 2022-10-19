/* 
* This is the abstract class Employee, which will be the parent class of Professional and Non-Professional
* Every employee will have different insurance rates, 
* and their salaries (if it is other than hourly, example: monthly) will be converted to an hourly rate;
* 
* CONSTANTS: 
* Professional employees work 8 hours a day which is 40 hours a week
* Non Professional employees work 7 hours a day which is 35 hours a week 
* 
* 
* VACATION EARNED:
* Since Professional employees have days off while non professional ones have hours off,
* the vacation they earn will be calculated in hours (for example, half a day will be equal to 12).
* We will calculate vacation earned on a per week basis.
* How much PTO professional and non pro employees have will be set in the constructor, and their values will be thought of as annual first.
* (For example if they have a PTO value of 360, that is equal to 3 weeks of PTO per year)
* Since we are calculating PTO earned per week, that is 52 pay periods per year.
* So we will divide their user entered annual PTO by 52 to calculate how much PTO they earn per week.
* 
* HEALTHCARE CONTRIBUTION:
* When the class is constructed, the contribution amount will have to be entered by the user and it only takes integer values.
* For example if 80 is entered that means 80% of that employees healthcare will be covered by the company.
*/

class Employee {
private:
	float HourlyRate;
	int WorkingHours;
	float Insurance;
	int Contribution;
	float PTOperYear;
public:
	Employee();
	Employee(float, int);
	float WeeklySalary();
	float HealthCareContribution();
	float VacationEarned(float);

	void setWorkingHours(int n)   { WorkingHours = n; }
	void setHourlyRate(float n)	  { HourlyRate = n; }
	void setInsurance(float n)	  { Insurance = n; }
	float getHourlyRate()		  { return HourlyRate; }
	float getInsurance()		  { return Insurance; }
	int getWorkingHours()		  { return WorkingHours; }

};

/* 
* Non Professional employees are paid an hourly salary, and have their vacation time set in hours.
*/
class NonProfessional : public Employee {
private:
	float HourlySalary;
	float VacationHours;
	const int WorkedHours = 35;
public:
	NonProfessional();
	NonProfessional(float, int, float, float);

	void setVacationHours(float n)	{ VacationHours = n; }
	int getVacationHours()			{ return VacationHours; }

};

/*
* Professional employees have monthly salaries, and their vacation times are set in days, but will be
* calculated in hours.
*/
class Professional : public Employee {
private:
	float MonthlySalary;
	int VacationDays;
	const int WorkedHours = 40;
public:
	Professional();
	Professional(float, int, float, float);

	float calculateHourlyRate(float MonthlySalary) { float HourlySalary = (MonthlySalary * 12 / 52) / 40; return HourlySalary; }
	void setVacationDays(int n)					   { VacationDays = n; }
	void setMonthlySalary (float n)				   { MonthlySalary = n; }
	int getVacationDays()						   { return VacationDays; }
	float getMonthlySalary()					   { return MonthlySalary; }
};