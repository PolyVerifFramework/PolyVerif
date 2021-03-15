#!/usr/bin/env python
from selenium import webdriver 
import time
import webbrowser
from webdriver_manager.firefox import GeckoDriverManager
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
from selenium.common.exceptions import TimeoutException
time.sleep(35);

driver = webdriver.Firefox()
driver.get("http://localhost:8080/#/Simulations")
#driver.refresh()

time.sleep(8)
print("after")
add = "rahulky890@gmail.com"
pas = "rahul@123"
#time.sleep(5)
driver.find_element_by_id('formEmail').send_keys(add)
driver.find_element_by_id('formPassword').send_keys(pas)
driver.find_element_by_xpath("//button[contains(text(),'Sign In')]").click()
time.sleep(2)
driver.find_element_by_xpath('//*[@id="root"]/div/div[1]/div/div[1]/div/ul/li[4]/div').click()
time.sleep(2)

driver.find_element_by_xpath('//*[@id="root"]/div/div[1]/div/div[2]/main/div/div[2]/div/div/div[6]').click()
time.sleep(2)

#ele1 = driver.find_element_by_link_text('API Only')
#ele1.click()
#time.sleep(2)
ele = driver.find_element_by_class_name('Player_simulationPlayer__2bhcn Player_open__vjONf')#'Player_simulationPlayer__2bhcn Player_open__vjONf')#'Player_status__2bPcx'
driver.execute_script("arguments[0].status = 'Running'", ele)
#Player_status__2bPcx
#webbrowser.get("chromium").open("http://localhost:8080/#/Simulations"