# Hospital Management System

## Overview
The Hospital Management System is a simulation program designed to model and manage patient transportation and hospital resource allocation. It simulates the handling of different types of patient requests, ambulance dispatching, and hospital capacity management.

## Features
- **Patient Request Management**: Handles emergency, serious, and normal patient requests
- **Ambulance Car Allocation**: Manages different types of ambulance cars (special cars and normal cars)
- **Hospital Resource Management**: Tracks hospital capacities and resource utilization
- **Priority-based Scheduling**: Prioritizes patients based on severity and request type
- **Interactive and Silent Modes**: Two operational modes for different use cases
- **Data Persistence**: Saves simulation results to output files

## Getting Started

### Prerequisites
- Windows operating system
- Visual Studio with C++ support (2019 or later recommended)
- C++11 or later

### Installation
1. Clone the repository or download the source code
2. Open the solution file `Project1.sln` in Visual Studio
3. Build the solution (F7 or Build → Build Solution)
4. Run the program (F5 or Debug → Start Debugging)

### Running the Simulation
1. Use the provided batch file `run_hospital.bat` to run the program with proper file paths
2. When prompted, enter one of the data file names (e.g., `data.txt`, `data2.txt`, etc.)
3. Choose between interactive mode (1) or silent mode (2)
4. For interactive mode, press Enter to advance each time step
5. For silent mode, the simulation will run to completion and generate output

## Input File Format
The system uses text files for input with the following format:

```
<Number of Hospitals>
<Special Car Speed> <Normal Car Speed>
<Distance Matrix>
<Hospital 1 Special Cars> <Hospital 1 Normal Cars>
<Hospital 2 Special Cars> <Hospital 2 Normal Cars>
...
<Number of Requests>
<Request Type> <Request Time> <Patient ID> <Hospital ID> <Distance> [Severity]
...
<Number of Cancellations>
<Cancellation Time> <Patient ID> <Hospital ID>
...
```

## Output
The program generates an `output.txt` file with simulation statistics:
- Patient processing times
- Hospital and car utilization metrics
- Average wait times
- Average busy times
- System utilization percentage

## Project Structure
- `main.cpp`: Entry point for the application
- `Organizer.h/cpp`: Core controller for the system
- `Hospital.h/cpp`: Hospital class with its resources
- `Car.h/cpp`: Ambulance car implementation
- `patient_request.h/cpp`: Patient request handling
- `LinkedQueue.h`: Generic linked queue implementation
- `priQueue.h`: Priority queue implementation
- `UI.h/cpp`: User interface handling

## License
This project is licensed under the terms specified in LICENSE.txt.

## Acknowledgements
Developed as part of a data structures and algorithms educational project. 