# Hospital Management System - User Guide

## Introduction

This user guide explains how to operate the Hospital Management System simulation software. The system simulates hospital operations, patient requests, and ambulance dispatch in a multi-hospital environment.

## Running the Program

### Method 1: Using the Batch File
1. Double-click on `run_hospital.bat` in the project folder
2. The batch file will:
   - Copy necessary data files to the executable directory
   - Run the program
   - Return to the command prompt when finished

### Method 2: Manual Execution
1. Open a command prompt
2. Navigate to the project's `x64\Debug` directory
3. Run `phase_1.2.exe`

## Operating the System

### Step 1: Select Input File
When prompted, enter one of the available data files:
- `data.txt` - Standard scenario
- `data2.txt` - Alternative scenario
- `data3.txt` - Minimal test case
- `data4.txt` - Large scenario
- `data5.txt` - Complex scenario
- `data6.txt` - Edge case testing

For example:
```
Enter File Name: data.txt
```

### Step 2: Select Operation Mode
Choose between two modes of operation:
- **Interactive Mode (1)**: The simulation pauses after each time step, allowing you to observe the state of the system
- **Silent Mode (2)**: The simulation runs to completion without pausing and produces a final output file

For example:
```
please enter <1> for interactive mode or <2> for silent mode: 1
```

### Step 3: Observe Simulation (Interactive Mode)
If you selected Interactive Mode:
1. The system will display the current time step
2. Information about each hospital will be shown
3. Lists of patients and ambulance cars will be displayed
4. Press Enter to advance to the next time step
5. Continue until the simulation is complete (100 time steps)

Example output for each time step:
```
the current timestep: 3
======== HOSPITAL #1 DATA ===========
2 EP requests: 14 6
1 SP requests: 12
0 NP requests: 
Free Cars: 1 Scars, 0 Ncars
======== HOSPITAL #2 DATA ===========
...
```

### Step 4: Review Output
After completion, the system generates an `output.txt` file with:
- Patient processing statistics (finish time, patient ID, request time, wait time)
- Summary of simulation results (patients processed, hospital usage, car usage)
- Performance metrics (average wait time, average busy time, utilization percentage)

## Understanding Input Files

Input files follow this format:
1. First line: Number of hospitals
2. Second line: Speed of special cars, speed of normal cars
3. Next lines: Distance matrix between hospitals
4. Next lines: Number of special and normal cars at each hospital
5. Next line: Number of patient requests
6. Request lines:
   - For EP (Emergency): `EP [Time] [PatientID] [HospitalID] [Distance] [Severity]`
   - For SP/NP: `SP/NP [Time] [PatientID] [HospitalID] [Distance]`
7. Next line: Number of cancellation requests
8. Cancellation lines: `[Time] [PatientID] [HospitalID]`

## Troubleshooting

### File Not Found Error
If you get "unable to open file" error:
1. Check that the data files are in the correct directory
2. Try using the full path to the file
3. Run the batch file `run_hospital.bat` which copies files to the correct location

### Program Crashes or Freezes
1. Ensure the input file is formatted correctly
2. Try using a simpler input file (like data3.txt)
3. In interactive mode, avoid pressing keys other than Enter

### Output Issues
1. Check that the program has permission to write to the current directory
2. Ensure enough disk space is available
3. Close any applications that might be locking the output file

## Advanced Usage

### Creating Custom Scenarios
You can create your own input files following the format above. This allows testing different hospital configurations, car allocations, and patient loads.

### Analyzing Results
The output.txt file can be imported into spreadsheet software for further analysis and visualization of the simulation results.

## Support

If you encounter any issues or have questions about the system, please refer to the README.md and ABOUT.md files for additional information on the system design and implementation. 