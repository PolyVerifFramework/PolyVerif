import time
import sys
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler 


file_path = ""
class Handler(FileSystemEventHandler): 
  
    @staticmethod
    def on_any_event(event): 
        if event.is_directory: 
            return None
  
        elif event.event_type == 'created': 
            # Event is created, you can process it now 
            print("Watchdog received created event - % s." % event.src_path) 
        elif event.event_type == 'modified': 
            # Event is modified, you can process it now 
            print("Watchdog received modified event - % s." % event.src_path) 
            global file_path
            f_path = open('config.txt', 'r')
            path = f_path.readline()
            file_path = path.strip()
            print("read path : ",file_path)
            f_path.close() 

class PublishingSubscriber():
  """
  Create a PublishingSubscriber class, which is a subclass of the Node class.
  """
  #observer 

  def __init__(self):
    self.observer = Observer() 
    self.observer.schedule(Handler(), path='config.txt')
    self.observer.start()
    self.observer.join()



     
def main(args=None):
 
 
  # Create the node
  publishing_subscriber = PublishingSubscriber()
 
  
 
if __name__ == '__main__':
  main()

