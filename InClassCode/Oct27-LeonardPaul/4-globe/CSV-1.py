import csv
import sys

"""l = open('Canucks1.csv', 'r')
csv_l = csv.reader(l)

for x in csv_l:
    print x

l.close
"""

"""d = {}
with open('Python1.csv', 'r') as p:
    print p.readlines()"""

"""f = open('Python1.csv', 'wt')
try:
    fieldnames = ('Title 1', 'Title 2', 'Title 3')
    writer = csv.DictWriter(f, fieldnames=fieldnames)
    headers = dict( (n,n) for n in fieldnames )
    writer.writerow(headers)
    for i in range(10):
        writer.writerow({ 'Title 1':i+1,
                          'Title 2':chr(ord('a') + i),
                          'Title 3':'08/%02d/07' % (i+1),
                          })
finally:
    f.close()

print open('Python1.csv', 'rt').read()"""

"""f = open('Python1.csv', 'rt')
try:
    reader = csv.DictReader(f)
    for row in reader:
        print row
finally:
    f.close()"""

"""reader=csv.reader(open('Canucks1.csv', 'r'))
for row in reader:
    if reader.line_num == 550:
        print row[-2]
        print row[-1]"""

CSVfile = 'Canucks1.csv'

reader = csv.reader(open(CSVfile, 'r'))

#Finds the lines where the regions are listed
"""for line in reader:
    if line == 'Top regions for vancouver canucks':
        print reader.line_num"""

#Gets the name of a country and the instensity modifier for the search 
def GetCountry(line):
    for row in reader:
        if reader.line_num == line:
            country = row[0]
            print country
            countryNum = row[1]
            print countryNum
            #Assign number ID value to each country
            if country == 'Canada':
                countryID = 1
            if country == 'United States':
                countryID = 2
            else:
                countryID = 'no ID'
            print countryID

#Gets the name of most popular cities and sees if they're from a country bigger than one dot
"""def GetCity(line):
    for row in reader:
        if reader.line_num == line:
            city = row[0]
            print country
            #put in split to look for country after the space
            cityCountry = str(row[0])
            cityNum = row[1]
            print countryNum"""

#Gets the date and value on each line
def GetDate(line):
    for row in reader:
        if reader.line_num == line:
            date = str(row[0])[:10]
            print date
            dateYear = date[:4]
            dateMonth = date[5:7]
            dateDay = date[8:10]
            print dateYear
            print dateMonth
            print dateDay
            dateNum = row[1]
            print dateNum
        
        
#Send variables to PD
# example from https://docs.python.org/2/library/socket.html
# use mrpeach on pure data side

import socket               # Import socket module

HOST = ''                   # The remote host is localhost (same computer)
PORT = 7506                 # The same port as used by the server
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT))
s.send('0123456789')
s.send('9876543210')
s.close()


# Echo receive
#import socket

#HOST = ''                 # Symbolic name meaning all available interfaces
#PORT = 50007              # Arbitrary non-privileged port
#s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#s.bind((HOST, PORT))
#s.listen(1)
#conn, addr = s.accept()
#print 'Connected by', addr
#while conn:
#    data = conn.recv(1024)
#    print (data)
#    if not data: break
#    conn.sendall(data)
#conn.close()
