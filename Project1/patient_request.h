/**
 * @file patient_request.h
 * @brief Definition of the patient class for hospital management system
 */

#pragma once
#include <string>
#include <iostream>
using namespace std;

/**
 * @class patient
 * @brief Represents a patient request in the hospital management system
 * 
 * This class stores information about a patient request including
 * type (EP, SP, NP), severity, times, hospital assignment, etc.
 */
class patient
{
private:
	// Patient identification
	int PatientId;           // Unique identifier for the patient
	string Type;             // Patient type (EP: Emergency, SP: Serious, NP: Normal)
	int Severity_number;     // Severity level (higher means more urgent)
	
	// Time tracking
	int request_time;        // When the request was made
	int pickup_time;         // When the patient was picked up
	int assigned_time;       // When a car was assigned
	int FinishTime;          // When treatment was completed
	int CanceLRQT;           // Cancellation request time (if applicable)
	
	// Hospital and transportation
	int HospitalID;          // ID of assigned hospital
	int distance;            // Distance to hospital
	int carid;               // ID of assigned ambulance car
	bool picked;             // Whether patient has been picked up

public:
	// Constructors
	
	/**
	 * @brief Default constructor
	 */
	patient();
	
	/**
	 * @brief Constructor for emergency patients
	 * @param type Patient type (EP)
	 * @param PID Patient ID
	 * @param HID Hospital ID
	 * @param SNU Severity number
	 * @param Dist Distance
	 * @param REQT Request time
	 */
	patient(string type, int PID, int HID, int SNU, int Dist, int REQT);
	
	/**
	 * @brief Constructor for non-emergency patients
	 * @param type Patient type (SP or NP)
	 * @param PID Patient ID
	 * @param HID Hospital ID
	 * @param Dist Distance
	 * @param REQT Request time
	 */
	patient(string type, int PID, int HID, int Dist, int REQT);
	
	/**
	 * @brief Constructor for cancelled requests
	 * @param PID Patient ID
	 * @param HID Hospital ID
	 * @param Cancel Cancellation time
	 */
	patient(int PID, int HID, int Cancel);
	
	// Patient ID methods
	void setpatientID(int ID);
	int getpatientID();
	
	// Hospital ID methods
	void setHID(int HID);
	int getHID();
	
	// Severity methods
	void setSeverity(int S);
	int getSeverity();
	
	// Time methods
	void setRequestTime(int RT);
	int getRequestTime();
	void setPickupTime(int PT);
	void setFinishT(int FT);
	int getFinishT();
	void setassignedtime(int t);
	int getassignedtime();
	void setcanceltime(int z);
	int getcanceltime();
	
	// Car methods
	void setcarid(int x);
	int getcarid();
	
	// Patient status methods
	void setpickedstatus(bool S);
	bool getpickedstatus();
	
	// Other methods
	void setdistance(int D);
	int getdistance();
	void setType(string T);
	string getType();
	
	// Operators
	bool operator<(const patient& other) const;
};

