import os
import xml.etree.ElementTree as ET
import time
import glob
import threading
import sys


def task1():
  print("In Task1...")

  path="./TCRunner.sh " + SceneName +" "+ TestScript
  os.system(path)
  time.sleep(1)

def task2():
  print("In Task2...")
  print("Setting Intial Position in Rviz...")     
  os.system('./q_initialPos.sh')
  time.sleep(2)
  print("Setting Goal Position in Rviz...")
  os.system('./q_goalPos.sh')
            


  
def fileCheck(SceneName,fname):

    flag=False
    path="./TCases/"+SceneName
    files=glob.glob(path +"/**/*.py",recursive=True)
    
    for name in files:
      if fname.lower() in name.lower():
        flag=True
      else:
        print("Warning...!!! Enter the correct TestScript Name")
    return flag

def show_report():
  print("in show report")          
  file1 = open("/path.txt","r")
  print("Detection Success Rate(%) of Autoware : ")
  print("Detection Range of LGSVL(meters)      : ")
  print("Detection Range of  Autoware(meters)  : ")

def Poly_Runner(validation,SceneName,TestScript):          
     print("Running Scene",SceneName,TestScript)
     pid = os.getpid()

   #  path1="./checkFile.sh "+ SceneName +" "+ TestScript +" "+str(pid)
    # os.system(path1)
     if True:
          dict={"Detection":"validate_p.sh",
                "Control":"control_validate_p.sh",
                "Localization":"validate_local.sh",
                "PathPlanning":"validate_pathplannerNode.sh"}
        
          nr="./support_files/NodeRunner.sh " + dict[validation]
          os.system(nr)
          reportpath = "./TCReports.sh " + TestScript
          os.system(reportpath)
          #avp
          if avp=="AVP":
            print("Launching Rviz in AVP Demo..")
            os.system('./avp_launch.sh')
            time.sleep(5)       
            '''path="./TCRunner.sh " + SceneName +" "+ TestScript
            os.system(path)
            time.sleep(1)'''
            t1.start()
          if avp=="AVP":   
              print("Setting Intial Position in Rviz...")     
              os.system('./q_initialPos.sh')
              time.sleep(2)
              print("Setting Goal Position in Rviz...")
              os.system('./q_goalPos.sh')
            #t1.start()
           # t2.start()
            #t2.join()
              t1.join()
            
              
          
          time.sleep(30)  
          input("Press Enter to generate report : ")  
          dt={"Detection":"./q_perception_val_script.sh",
              "Control":"./control_val_script.sh",
              "Localization":"./localization_validate.sh",
              "PathPlanning":"./path_planner_validate.sh"}

          os.system(dt[validation]) 
          os.system('./support_files/stop.sh')
          #show_report()      
     else:
        print("Error TestCase file not found...!!!!!")


if __name__ == "__main__":  
 if len(sys.argv) < 2:
   print("\nEnter the test file Name..Eg:-->python mainScript.py test1.xml\n")
 mytree=ET.parse(sys.argv[1])
#mytree=ET.parse('test2.xml')
 myroot=mytree.getroot()
 print("*********************************PolyVerif_Shell***********************************\n")
 print("Ade hasbeen stated please wait for while...")
 print("Once LGSVL started go to any web browser and start localHost http://localhost:8080/#/Simulations\n")
 time.sleep(5)
 os.system('./WUI_start_ade.sh')
 time.sleep(30)
 Testcase=myroot[0].tag
 path=myroot[0][4].attrib
 SceneName=path["name"]
 Ts=myroot[0][1].attrib
 TestScript=Ts["Location"]
 val=myroot[0][2].attrib
 validation=val["Type"]
 avp=myroot[0][3].text

 t1=threading.Thread(target=task1, args=())
 t2=threading.Thread(target=task2, args=())

 Poly_Runner(validation,SceneName,TestScript)
 print(".")
