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
        •	OS: Ubuntu 14.04 and above 64-bit
    
  Prerequisite: 
	
    •	Ubuntu 18.04 or 20.04
    •	Nodejs 12.16
    •	Python3.8 

  Reference link:  https://github.com/MaheshM99/PolyVerif/tree/release-v1.1

Steps follow to run the poly_suite application,to setup and install poly_suite application please refer all documents from Document directory.

	
    1. Install and setup Nvidia Drivers 
      To setup and install the Nvidia Drivers,please refer the below points –
          Point 1 - Please find the system configuration required as mentioned above.
          Point 2 - Refere below link for Nvidia Drivers driver installation.
          https://docs.nvidia.com/datacenter/tesla/tesla-installation-notes/index.html

    2. Install and setup docker 
        Point 3 - Setup Docker from Docker_Installation_Guide.txt document.
        Point 4 - After successful installation of docker restart system once.

    3. To clone and setup PolyVerif 
        Point 5 - Download Run.sh and Build.sh in home directory.
        Point 6 - Execute the script Run.sh, it will clone and install the PolyVerif dependencies.
        Point 7 - Execute the script Build.sh for building all PolyVerif packages.


    4. Install and run the Poly_Suite framework
      Once the above setup and packages are completed successfully. Please refer the below document to how to use the Suite.
        Point 8 - PolyVerifcation_Suite_UserGuide.docx


Note: Refer Setup_And_Installation.docx for manual installation process.


