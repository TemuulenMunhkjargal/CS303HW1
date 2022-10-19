#include "Classes.h"
#include <iostream>
using namespace std;

Employee::Employee() {
	WorkingHours = 0;
	HourlyRate = 0;
	Insurance = 0;
	Contribution = 0;
}

Employee::Employee(float insurance,  int contribution) {
	Insurance = insurance;
	Contribution = contribution;
}

// Weekly salary based on how much hours they worked (fixed value at 35 for non pro and 40 for professional)
// times their hourly rate
float Employee::WeeklySalary() {
	float weeklySalary = WorkingHours * HourlyRate;
	return weeklySalary;
}

// Finding the amount the company contributes to an individuals insurance
float Employee::HealthCareContribution() {
	float contribution = (Insurance / 100) * Contribution;
	return contribution;
}


// Since we are calculating weekly vacation earned, and we have annual PTO values from users, we divide them by 52 to find per week PTO.
float Employee::VacationEarned(float PTO) {
	float vacation = PTO / 52;
	return vacation;
}

NonProfessional::NonProfessional() {
	VacationHours = 0;
	setWorkingHours(0);
	setHourlyRate(0);
}

NonProfessional::NonProfessional(float insurance, int contribution, float vacationHours, float hourlyRate) :Employee(insurance,contribution){
	VacationHours = vacationHours;
	HourlySalary = hourlyRate;
	setWorkingHours(WorkedHours);
	setHourlyRate(HourlySalary);
}

Professional::Professional() {
	VacationDays = 0;
	setWorkingHours(0);
	setHourlyRate(0);
}

Professional::Professional(float insurance, int contribution, float vacationDays, float monthlyRate) :Employee(insurance, contribution) {
	VacationDays = vacationDays;
	float hourlyRate = calculateHourlyRate(monthlyRate);
	setHourlyRate(hourlyRate);
	setWorkingHours(WorkedHours);
}
