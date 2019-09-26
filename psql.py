import mysql.connector as mysql

db = mysql.connect(
    host = "localhost",
    database = "testdb",
    user = "abhi",
    passwd = "abhi"
)

mycursor = db.cursor()

#mycursor.execute("CREATE DATABASE testdb")

#mycursor.execute("CREATE TABLE rrs ( seatno INT, name VARCHAR(255), source VARCHAR(255), destination VARCHAR(255), PRIMARY KEY(seatno) )")
#
# sql = "INSERT INTO rrs (seatno, name, source, destination) VALUES (%s, %s, %s, %s)"
#
# #val = (1,"Ashutosh","Varanasi","TPJ")
# #val2 = (2,"Abhishek","Gaya","Patna")
# val3 =  (3,"Dhruv","Kanpur","Lucknow")
# #val = [
# # (1,"Ashutosh","Varanasi","TPJ"),
# # (2,"Abhishek","Gaya","Patna"),
# # (3,"Dhruv","Kanpur","Lucknow")
# # ]
#
# #mycursor.executemany(sql,val)
# mycursor.execute(sql,val3)
# db.commit()

#question 2

# sql = "SELECT * FROM rrs where name='Ashutosh'"
#
# mycursor.execute(sql)
#
# myresult = mycursor.fetchall()
#
# for p in myresult:
#     print(p)

#question 3

# sql = "UPDATE rrs SET destination = 'Chennai' WHERE name = 'Ashutosh'"
#
# mycursor.execute(sql)
#
# db.commit()


#question 4
# sql = "DELETE FROM rrs where seatno=1"
#
# mycursor.execute(sql)
#
# db.commit()
