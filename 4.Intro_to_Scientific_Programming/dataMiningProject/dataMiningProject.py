#Description:Data Mining Project

import csv
#name: get_data_list
#param: FILE_NAME  - the file's name you saved for the stock's prices
#brief: get a list of the stock's records' lists
#return: a list of lists  
def get_data_list (FILE_NAME):
	
	myFile = open(str(FILE_NAME))
	
	linesFromFile = csv.reader(myFile)
	next(linesFromFile)
	return linesFromFile

#name: get_monthly_averages
#param: data_list  - the list that you will process
#brief: get a list of the stock's monthly averages and their corresponding dates
#return: a list 
def get_monthly_averages (data_list):
	monthlyAverageList = []
	monthList = []
	yearList = []
	closeList = []

	for currentRow in data_list:
		#print (currentRow)
		month = currentRow[0][5:7]
		year = currentRow[0][0:4]
		close = currentRow[6]
		monthList.append(month)
		yearList.append(year)
		closeList.append(float(close))

	currentMonth = 9
	closeListSum = 0.0
	counter = 0.0
	
	closeAverages = []
	newMonthList = []
	newYearList = []
	for ix in range(0, len(monthList)):
		if(int(monthList[ix]) == currentMonth):
			closeListSum = closeListSum + closeList[ix]
			counter = counter + 1
		else:
			closeAverages.append(float(closeListSum/counter))
			newYearList.append(yearList[ix-1])
			closeListSum = 0.0
			if(currentMonth < 10):
				newMonthList.append("0" + str(currentMonth))
			else:
				newMonthList.append(str(currentMonth))
			if(currentMonth == 1):
				currentMonth = 12
			else:
				currentMonth = currentMonth - 1
			closeListSum = closeListSum + closeList[ix]
			counter = 1.0
	closeAverages.append(float(closeListSum/counter))
	newMonthList.append("0"+str(currentMonth))
	newYearList.append(yearList[ix])

	monthlyAverageList.append("('Month', 'Year', 'Average')")

	for ix in range(0, len(newMonthList)):
		stringToAppend = str(newMonthList[ix]), str(newYearList[ix]),     str("%.2f"% round(closeAverages[ix],2))
		monthlyAverageList.append(stringToAppend)

	return monthlyAverageList 

#name: print_info
#param: monthly_average_list  - the list that you will process
#brief: print the top 6 and bottom 6 months for Google stock
#return: None
def print_info (monthly_average_list):
	for ix in range(0, len(monthly_average_list)):
		print("monthly_average_list["+ str(ix) + "] = " + str(monthly_average_list[ix]))

# call get_data_list function to get the data list, save the return in data_list
# call get_monthly_averages function with the data_list from above, save the 
# return in monthly_average_list
# call print_info function with the monthly_average_list from above 
def main():
	listOfLines = get_data_list("table.csv")
	mAvgList = get_monthly_averages(listOfLines)
	print_info(mAvgList)

if __name__ == '__main__':
	main()

'''
Output:
monthly_average_list[0] = ('Month', 'Year', 'Average')
monthly_average_list[1] = ('09', '2008', '437.70')
monthly_average_list[2] = ('08', '2008', '485.91')
monthly_average_list[3] = ('07', '2008', '510.03')
monthly_average_list[4] = ('06', '2008', '556.32')
monthly_average_list[5] = ('05', '2008', '575.92')
monthly_average_list[6] = ('04', '2008', '497.58')
monthly_average_list[7] = ('03', '2008', '440.33')
monthly_average_list[8] = ('02', '2008', '503.80')
monthly_average_list[9] = ('01', '2008', '611.81')
monthly_average_list[10] = ('12', '2007', '695.40')
monthly_average_list[11] = ('11', '2007', '676.37')
monthly_average_list[12] = ('10', '2007', '635.39')
monthly_average_list[13] = ('09', '2007', '540.43')
monthly_average_list[14] = ('08', '2007', '509.83')
monthly_average_list[15] = ('07', '2007', '532.48')
monthly_average_list[16] = ('06', '2007', '515.02')
monthly_average_list[17] = ('05', '2007', '473.01')
monthly_average_list[18] = ('04', '2007', '472.50')
monthly_average_list[19] = ('03', '2007', '452.91')
monthly_average_list[20] = ('02', '2007', '467.22')
monthly_average_list[21] = ('01', '2007', '490.58')
monthly_average_list[22] = ('12', '2006', '473.50')
monthly_average_list[23] = ('11', '2006', '485.63')
monthly_average_list[24] = ('10', '2006', '440.53')
monthly_average_list[25] = ('09', '2006', '397.06')
monthly_average_list[26] = ('08', '2006', '377.09')
monthly_average_list[27] = ('07', '2006', '403.53')
monthly_average_list[28] = ('06', '2006', '393.59')
monthly_average_list[29] = ('05', '2006', '383.80')
monthly_average_list[30] = ('04', '2006', '413.78')
monthly_average_list[31] = ('03', '2006', '358.87')
monthly_average_list[32] = ('02', '2006', '370.00')
monthly_average_list[33] = ('01', '2006', '445.71')
monthly_average_list[34] = ('12', '2005', '418.95')
monthly_average_list[35] = ('11', '2005', '399.14')
monthly_average_list[36] = ('10', '2005', '322.47')
monthly_average_list[37] = ('09', '2005', '304.24')
monthly_average_list[38] = ('08', '2005', '286.92')
monthly_average_list[39] = ('07', '2005', '298.21')
monthly_average_list[40] = ('06', '2005', '287.55')
monthly_average_list[41] = ('05', '2005', '239.71')
monthly_average_list[42] = ('04', '2005', '199.21')
monthly_average_list[43] = ('03', '2005', '181.16')
monthly_average_list[44] = ('02', '2005', '195.01')
monthly_average_list[45] = ('01', '2005', '192.85')
monthly_average_list[46] = ('12', '2004', '181.77')
monthly_average_list[47] = ('11', '2004', '177.50')
monthly_average_list[48] = ('10', '2004', '153.23')
monthly_average_list[49] = ('09', '2004', '113.23')
monthly_average_list[50] = ('08', '2004', '105.26')
'''
