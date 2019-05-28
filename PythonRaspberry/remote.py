import MySQLdb

print ("let's try") 
try:
#  db = MySQLdb.connect("localhost","root","slovenskasmer","db1" )
   db = MySQLdb.connect("91.185.211.101","sato01_golibarrp","JYkW0jJWCroJ","sato01_golibarrp" )
   cursor = db.cursor()
   print ("succesfuly connected to the mysql")
except:
   print ("error while connecting to db1")
