Release Note v1.1

1. Deliverables
This version has the below package and functionality included –
  • Detection Validation 
  • Control Validation 
  • Localization Validation 
  • Mission Planner Validation 
  • Report Generation 
  • Modified Scenic Integration with AutowareAuto 
  • Modified PythonAPI for lg simulator 
  • API for GPS noise 
  • API for IMU noise 
  • API for LiDAR noise
  • Modified lgsvl Simulator 2020.06 binary
  • Modified avp demo for TalTech map
  • PolyVerification Suite Binary 
  • Test Cases for scenic and python
  • Usage Documentation

This document has the information of installing and setup the component for running Poly_Suite. These libraries and package are need to be install in sequence as mention below.
   
2. Known Issues
  • Some times rviz got crashed
  • Sometimes when we try to run the Scenic scenario, connection to lgsvl simulator freeze so go to the respective terminal and press Ctrl+C button to terminate it and start it again
  • In avp demo, trajectory not followed perfectly by the ego in AutowareAuto
  • Ego in lgsvl and avp demo async sometimes while simulation
  • If lgsvl simulator crashed then click on Stop Ade and Restart it again using the poly_suite
  • The Initial pos and Goal pos in avp demo is static value and it is set for TalTech map. If you have built your own map then need to set the initial and goal position accordingly.

3. References
  • Lgsvl Simulator - https://github.com/lgsvl/simulator/releases/tag/2020.06
  • Scenic - https://scenic-lang.readthedocs.io/en/latest/syntax_guide.html?highlight=facing#specifiers
  • Scenic Tutorial - https://scenic-lang.readthedocs.io/en/latest/tutorials/tutorial.html#tutorial
  • PythonAPI - https://www.svlsimulator.com/docs/python-api/python-api/
  • AutowareAuto avp demo - https://autowarefoundation.gitlab.io/autoware.auto/AutowareAuto/avpdemo.html