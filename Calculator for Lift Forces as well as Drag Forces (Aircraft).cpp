//Create an application for Aerospace. Calculate Lift Force as well as drag on an airfoil
//Formula for lift force (FL) is: FL = 0.5 * ρ * V^2 * A * CL, where: 
// FL: Lift Force (Newtons), ρ: Air density (kg/m^3), V: Velocity of the Aircraft (m/s), A: Wing Area (m^2), CL: Lift coefficient (no dimension)

//Formula for drag: FD = 0.5 * ρ * V^2 * A * CD, where: 
//New variables FD: Drag Force (Newtons), CD: Drag coefficient (no dimension)

//Note that this is a simulation only, but it can be used as a basis for aircraft embedded systems


#include <iostream>
#include <chrono>
#include <thread>

class Aircraft {

	//Declare all variables
private: 
	double AirDensity; 
	double Velocity; 
	double WingArea; 
	double LiftCoefficient; 
	double DragCoefficient; 
	double LiftForce; 
	double DragForce; 

	//Avoiod calculating LiftForce and DragForce before calculating them
	//Use LiftForce(0) and DragForce(0) as they have no meaningful value yet and need to be calculated later
public: Aircraft(double _AirDensity, double _Velocity, double _WingArea, double _LiftCoefficient, double _DragCoefficient) : AirDensity(_AirDensity), Velocity(_Velocity), WingArea(_WingArea), LiftCoefficient(_LiftCoefficient), DragCoefficient(_DragCoefficient), LiftForce(0), DragForce(0) { 
		datacollection();   
	}

	void datacollection() { //Make sure that none of the values are negative
		if (AirDensity < 0) AirDensity = 0; 
		if (Velocity < 0) Velocity = 0; 
		if (WingArea < 0) WingArea = 0; 
		if (LiftCoefficient < 0) LiftCoefficient = 0; 
		if (DragCoefficient < 0) DragCoefficient = 0; 
	}

	void updatefromsensors() { 
		//Sensor readings (Simulation only)
		AirDensity = getAirDensity();   
		if (AirDensity < 0) AirDensity = 0; 

		Velocity = getVelocity(); 
		if (Velocity < 0) Velocity = 0; 
	}

	void givendata() {
		//This is the data that is given beforehand and not measured by sensors on the aircraft
		LiftCoefficient = getLiftCoefficient(); 
		if (LiftCoefficient < 0) LiftCoefficient = 0; 

		DragCoefficient = getDragCoefficient(); 
		if (DragCoefficient < 0) DragCoefficient = 0; 

		WingArea = getWingArea(); 
		if (WingArea < 0) WingArea = 0; 
	}

	void calculatedforces() {
		//Calculate Lift Force as well as Drag Force using the formulas given above
		LiftForce = 0.5 * AirDensity * Velocity * Velocity * WingArea * LiftCoefficient; 
		DragForce = 0.5 * AirDensity * Velocity * Velocity * WingArea * DragCoefficient; 
	}

	void printmeasureddata() {
		std::cout << "Air Density (kg/m^3): " << AirDensity << std::endl;  
		std::cout << "Velocity (m/s): " << Velocity << std::endl; 
	}

	void printgivendata() {

		std::cout << "Wing Area (m^2): " << WingArea << std::endl;  
		std::cout << "Lift Coefficient: " << LiftCoefficient << std::endl; 
		std::cout << "Drag Coefficient: " << DragCoefficient << std::endl;   
	}

	void printcalculatedforces() { 
		std::cout << "Lift Force (N): " << LiftForce << std::endl;  
		std::cout << "Drag Force (N): " << DragForce << std::endl; 
	}

private: 
	double getAirDensity() {
		return 1.225; 
	}
	double getVelocity() {
		return 70; 
	}
	double getLiftCoefficient() {
		return 1.2; 
	}
	double getDragCoefficient() {
		return 0.03; 
	}
	double getWingArea() {
		return 16.2; 
	}
};

int main() {
	//Be careful with the order of the values
	Aircraft Prototype(1.225, 70, 16.2, 1.2, 0.03); 

	while (true) {
	
		std::cout << "Operational data: " << std::endl; 

		Prototype.updatefromsensors(); 
		Prototype.printmeasureddata(); 

		std::cout << "------------" << std::endl; 
		std::cout << "Given properties: " << std::endl; 

		Prototype.givendata(); 
		Prototype.printgivendata(); 

		std::cout << "------------" << std::endl;  
		std::cout << "Calculated Forces: " << std::endl;  

		Prototype.calculatedforces(); 
		Prototype.printcalculatedforces(); 

		std::this_thread::sleep_for(std::chrono::seconds(1)); 
		std::cout << "\n" << std::endl;
	}

	return 0; 


}





