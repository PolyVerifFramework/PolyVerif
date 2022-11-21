# PolyVerif

PolyVerif AV Validation Suite

This is Poly-Verification and Validation Suite. Its functionality is to generate the test cases and validate the autonomous stack.
It integrate the Scenic scenario description language with AutowareAuto and helps to generate the random scenario for simulation.
Since we are using lgsvl Simulator and AutowareAuto, it will require a high-end server with Graphics card to run it smoothly. 

This document contains the information of installing and setup the component for running Poly_Suite framework. It requires below setup, libraries and package that are need to be install in sequence as mention below.

The Simulator performance will be very slow if run on a lower PC configuration.

Below is the PC configuration required:
	PC Configuration:
	
  	•	CPU: Intel i7 10700
   	•	GPU: Nvidia RTX 2070 (8GB memory)
    •       OS: Ubuntu 18.04 and above 64-bit
    
  Prerequisite: 
	
    •	Ubuntu
    •	Nodejs 12.16
    •	Python3.8

  Reference link:  https://github.com/MaheshM99/PolyVerif

Steps follow to run the poly_suite application,to setup and install poly_suite application please refer all documents from Document directory.
Note: Refer Scripts directory for Automation installation process.
	
    1. Install and setup AutowareAuto 
      To setup and install the AutowareAuto,please refer the below point –
          Point 1 - Setup Docker from docker-install.txt document.
          Point 2 - Setup and Install AutowareAuto from Setup_And_Installation document.

    2. Install and build lgsvl-msgs
      To setup and install the lgsvl-msgs which is used by the validation stack. Please refer the below point number from the Setup_And_Installation document –
        Point 3 - Install and Setup lgsvl_msgs package

    3. Install and build ros2-lgsvl-bridge
      Install and setup the ros2 lg bridge which will help lg simulator to communicate over the ROS2 bridge. Please refer the below point number from the Setup_And_Installation document –
        Point 4 - Ros2-lgsvl-bridge

    4. Install and setup the LG Simulator 
      Please refer the below point number from the Setup_And_Installation document –
        Point 7 - LGSVL Simulator

    5. Install and setup the PythonAPI
      Install the PythonAPI. We have uploaded the modified version of the PythonAPI which provide the hook of modifying the point cloud data of lidar. Please refer the below point number from the Setup_And_Installation document –
        Point 8 - PythonAPI

    6. Install and setup the Node package
      Install and build the validation node package for detection, control, localization and mission planning for autoware. Please refer the below point numbers from the Setup_And_Installation document –
        Point 10, 11, 12, 13 - Node of Detection, Control, Localization, Mission Planning Validation

    7. Install and run the Poly_Suite framework
      Once the above setup and packages are completed successfully. Please refer the below document to how to use the Suite.
        Point 15 - PolyVerifcation_Suite_UserGuide.docx
