#http://www.penguintutor.com/electronics/rpi-arduino
#http://www.instructables.com/id/Raspberry-Pi-Arduino-Serial-Communication/
#********************************************************************************************
#  find out on which port is arduino:
#            ls /dev/tty*
#   watch which devices appear when you plug in the usb arduino
#********************************************************************************************
# 		on ubuntu instal modul for mysql
#  	 apt-get install python-dev libmysqlclient-dev
#                pip install --upgrade pip
#		 pip install MySQL-python

#		on raspberry install:
#	sudo apt-get install python-mysqldb

#********************************************************************************************
import time 
import serial
import MySQLdb

#definet a serial port
ser = serial.Serial('/dev/ttyUSB0', 9600)


#function for testing and writing to Mysql
def measureValue(line, cusorIn, dbIn):
   measures=line.split(";")
   #testing loop
   for measure in measures:
      fieldValue=measure.split("=")
      field = fieldValue[0]
      value = fieldValue[1]
      print (field + "=" + value)

   #extract the value
   T1 = measures[0]
   T1 = T1.split("=")
   T1 = T1[1]
   print T1
   T2 = measures[1]
   T2 = T2.split("=")
   T2 = T2[1]
   print T2
   H1 = measures[2]
   H1 = H1.split("=")
   H1 = H1[1]
   print H1
   H1_t = measures[3]
   H1_t = H1_t.split("=")
   H1_t = H1_t[1]
   print H1_t
   

   try:
      T1str=str(T1)
      T2str=str(T2)
      cusorIn.execute( 'INSERT INTO db1.klima (T1, T2, H1, H1_t) VALUES (%s,%s,%s,%s)',(T1, T2, H1, H1_t) )
      dbIn.commit()
      print ("succesfuly inserted datas in to the klima") 
   except:
      print ("error while inserting to the db1.klima") 
      
   #print measures[0]
   #print measures[-1] # last element in the array
########################################################################################
#connect to sql
########################################################################################
try:
   db = MySQLdb.connect("localhost","root","slovenskasmer","db1" )
   cursor = db.cursor()
   print ("succesfuly connected to the mysql")
except:
   print ("error while connecting to db1")


########################################################################################
#iternel loop 
########################################################################################
while True:
    ser.readline()
    valueLine = ser.readline()
    print (" Izpis iz ene vrstice ")
    measureValue(valueLine,cursor,db)     #look the elements in the array
    #time.sleep(0.6)







