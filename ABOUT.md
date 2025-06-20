# About the Hospital Management System

## Project Purpose

The Hospital Management System is a simulation software designed to model the complexities of emergency medical services (EMS) and hospital resource allocation. It provides a framework for analyzing how different allocation strategies affect patient outcomes, wait times, and system efficiency.

This project demonstrates the application of advanced data structures and algorithms in solving real-world resource allocation problems in the healthcare domain.

## Detailed Functionality

### Patient Classification

The system classifies patients into three categories, each with different handling requirements:

1. **Emergency Patients (EP)**: Highest priority patients requiring immediate attention. These patients are assigned a severity level (1-10, with 10 being most severe).

2. **Serious Patients (SP)**: Medium priority patients needing prompt but not immediate care.

3. **Normal Patients (NP)**: Routine cases that can wait if resources are limited.

### Resource Management

#### Ambulance Cars

Two types of ambulance vehicles are modeled:

- **Special Cars (SC)**: Faster vehicles equipped for more severe cases
- **Normal Cars (NC)**: Standard ambulances for routine transportation

Cars have different speeds, capacities, and capabilities that affect transportation times and patient outcomes.

#### Hospitals

Each hospital in the system maintains:
- A specific number of Special and Normal cars
- Lists of patients currently assigned to the hospital
- Available capacity information

### Simulation Cycle

The system operates in discrete time steps, where at each step:

1. New patient requests are processed based on the input file
2. Available cars are assigned to patients according to priority rules
3. Cars move toward patients and then transport them to hospitals
4. Patients are admitted and treated at hospitals
5. Cars return to their home hospitals
6. Cancellation requests are processed

### Algorithms Implemented

The system utilizes several key algorithms:

- **Priority Queuing**: Ensures the most critical patients are handled first
- **Resource Allocation**: Optimally assigns limited ambulances to patient requests
- **Shortest Path**: Determines optimal routes for ambulances (using distance matrix)
- **Discrete Event Simulation**: Models the passage of time and event sequencing

## Technical Design

### Architecture

The system follows an object-oriented design with these key components:

1. **Organizer**: Central controller that manages the simulation and coordinates all activities
2. **Hospital**: Manages hospital-specific resources and patient lists
3. **Car**: Represents ambulances with their current state and assignments
4. **Patient**: Encapsulates patient data and request information
5. **LinkedQueue/PriQueue**: Custom data structures for efficient request handling

### Data Structures

- **Linked Queues**: Used for standard FIFO operations (first-in, first-out)
- **Priority Queues**: Ensures emergency patients are handled before others
- **Hospital Lists**: Track resource allocation across multiple facilities

### File Handling

The system reads configuration and simulation data from structured text files and outputs results to text files for analysis.

## Educational Value

This project demonstrates:

1. **Data Structure Selection**: How to choose appropriate data structures for different requirements
2. **Algorithm Efficiency**: Balancing computational resources with timely patient care
3. **Object-Oriented Design**: Organizing complex systems into manageable components
4. **Simulation Techniques**: Modeling real-world scenarios with computer programs

## Future Enhancements

Potential areas for expanding the system include:

- Graphical user interface for visualization
- Statistical analysis of simulation outcomes
- Machine learning integration for predictive resource allocation
- Geographic information system (GIS) integration for realistic distance modeling
- Multi-threading for improved performance in large simulations 