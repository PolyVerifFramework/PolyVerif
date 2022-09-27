import threading 
import time

def print1(num):

 print("in print1..",num)

def print2(num):
 print("in print2..",num)
 time.sleep(11)




if __name__ =="__main__":
 t1=threading.Thread(target=print1,args=(10,))
 t2=threading.Thread(target=print2,args=(200,))



 t2.start()
 t1.start()
 t2.join()
 t1.join()

 print("Donee...")





