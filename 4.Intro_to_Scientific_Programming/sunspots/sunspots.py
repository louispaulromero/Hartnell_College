#Description: Practice reading files and writing to files.

myFile = open('sunspots.txt', 'r')
outFile = open('averages.txt', 'w')
outFile.write("Year Average\n")
listOfLines = myFile.read().splitlines()

for ix in range(0, len(listOfLines)):
	listItem = listOfLines[ix].split()
	print(listItem)
	sum = 0.0
	for jx in range(1, + len(listItem)):
		sum = sum + float(listItem[jx])
		average = sum / (len(listItem)-1)	
	outFile.write(str(listItem[0]) + " " + str("%.2f"% round(average, 2)) + "\n")
