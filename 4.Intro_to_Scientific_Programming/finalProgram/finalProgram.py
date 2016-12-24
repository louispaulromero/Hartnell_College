import random

def writeNums(FILE_NAME):
	outFile = open(FILE_NAME, 'w')
	for ix in range(0, 100):
		outFile.write(str(random.randrange(100,200))+ ",")
	
def readNums(FILE_NAME):
	inFile = open(FILE_NAME, 'r')
	newList = inFile.read().split(",")
	
	intList = []
	print("ORIGINAL UNSORTED LIST FROM B")
	for jx in range(0,100):
		intList.append(int(newList[jx]))
	print(intList)
	print("ORIGINAL SORTED LIST FROM B")
	bubbleSort(intList)
	print(intList)
	listOfNumbers = []
	for ix in range(0, 100):
		if(int(newList[ix])% 7 == 0):
			listOfNumbers.append(int(newList[ix]))
		elif(int(newList[ix])% 4 == 0):
			listOfNumbers.append(int(newList[ix]))
	return listOfNumbers

def bubbleSort(LIST_OF_NUMS):
    for nums in range(len(LIST_OF_NUMS)-1,0,-1):
        for ix in range(nums):
            if LIST_OF_NUMS[ix]>LIST_OF_NUMS[ix+1]:
                temp = LIST_OF_NUMS[ix]
                LIST_OF_NUMS[ix] = LIST_OF_NUMS[ix+1]
                LIST_OF_NUMS[ix+1] = temp
    return LIST_OF_NUMS


def findMin(LIST_OF_NUMS):
	minVal = LIST_OF_NUMS[0]
	for ix in range(1, len(LIST_OF_NUMS)):
		if (minVal > LIST_OF_NUMS[ix]):
			minVal = LIST_OF_NUMS[ix]
	return minVal

def findMax(LIST_OF_NUMS):
	maxVal = LIST_OF_NUMS[0]
	for ix in range(1, len(LIST_OF_NUMS)):
		if (maxVal < LIST_OF_NUMS[ix]):
			maxVal = LIST_OF_NUMS[ix]
	return maxVal


def findAvg(LIST_OF_NUMS):
	sum = 0.0
	for ix in range(0, len(LIST_OF_NUMS)):
		sum = sum + LIST_OF_NUMS[ix]
	return float(sum / float(len(LIST_OF_NUMS)))

def medianCalc(LIST_OF_NUMS):
	if(len(LIST_OF_NUMS) % 2 == 0):
		rightIndex = len(LIST_OF_NUMS) / 2 
		leftIndex = (len(LIST_OF_NUMS) / 2) - 1
		median = (LIST_OF_NUMS[rightIndex] + LIST_OF_NUMS[leftIndex])/2
		return median
	else:
		index =len(LIST_OF_NUMS)/2
		median = LIST_OF_NUMS[index]
		return median

def main():

	FILE_NAME = "randomNumbers.txt"
	outFile = open("finalCalc.txt", "w")

	writeNums(FILE_NAME)
	newList = readNums(FILE_NAME)
	print("UNSORTED LIST OF VALUES DIVISIBLE BY 7 AND 4")
	print(newList)

	sortedNewlist = bubbleSort(newList)
	print("SORTED LIST FROM OF VALUES DIVISIBLE BY 7 AND 4")
	print(sortedNewlist)
	mystring = "FOR THE MIN I CAN EASILY SAY THE FIRST ELEMENT OF THE SORTED LIST AND LAST ELEMENT FOR THE MAX, BUT I'M CERTAIN YOU WANT TO SEE THE LOGIC\n"
	print(mystring)
	outFile.write(mystring)

	minimum = findMin(sortedNewlist)
	mystring ="THE MINIMUM IS: " + str(minimum) + "\n"
	print(mystring)
	outFile.write(mystring)

	maximum = findMax(sortedNewlist)
	mystring = "THE MAXIMUM IS: " + str(maximum) + "\n"
	print(mystring)
	outFile.write(mystring)

	average = findAvg(sortedNewlist)
	mystring = "THE AVERAGE IS: " + str(average) + "\n"
	print(mystring)
	outFile.write(mystring)

	median = medianCalc(sortedNewlist)
	mystring = "THE MEDIAN IS: " + str(median) + "\n"
	print(mystring)
	outFile.write(mystring)

if __name__ == '__main__':
	main()

'''
Output:
ORIGINAL UNSORTED LIST FROM B
[144, 107, 184, 100, 133, 168, 166, 133, 164, 197, 183, 127, 116, 118, 148, 165, 164, 172, 145, 158, 193, 106, 183, 115, 175, 152, 171, 197, 162, 181, 155, 104, 109, 151, 196, 124, 100, 111, 137, 160, 125, 144, 115, 174, 177, 190, 198, 182, 117, 153, 142, 174, 115, 102, 196, 165, 119, 120, 108, 110, 124, 184, 168, 113, 146, 160, 165, 138, 141, 199, 199, 192, 190, 109, 199, 156, 136, 106, 145, 143, 159, 195, 166, 129, 168, 133, 138, 166, 137, 179, 127, 127, 147, 156, 142, 120, 122, 139, 178, 172]
ORIGINAL SORTED LIST FROM B
[100, 100, 102, 104, 106, 106, 107, 108, 109, 109, 110, 111, 113, 115, 115, 115, 116, 117, 118, 119, 120, 120, 122, 124, 124, 125, 127, 127, 127, 129, 133, 133, 133, 136, 137, 137, 138, 138, 139, 141, 142, 142, 143, 144, 144, 145, 145, 146, 147, 148, 151, 152, 153, 155, 156, 156, 158, 159, 160, 160, 162, 164, 164, 165, 165, 165, 166, 166, 166, 168, 168, 168, 171, 172, 172, 174, 174, 175, 177, 178, 179, 181, 182, 183, 183, 184, 184, 190, 190, 192, 193, 195, 196, 196, 197, 197, 198, 199, 199, 199]
UNSORTED LIST OF VALUES DIVISIBLE BY 7 AND 4
[144, 184, 100, 133, 168, 133, 164, 116, 148, 164, 172, 175, 152, 104, 196, 124, 100, 160, 144, 182, 196, 119, 120, 108, 124, 184, 168, 160, 192, 156, 136, 168, 133, 147, 156, 120, 172]
SORTED LIST FROM OF VALUES DIVISIBLE BY 7 AND 4
[100, 100, 104, 108, 116, 119, 120, 120, 124, 124, 133, 133, 133, 136, 144, 144, 147, 148, 152, 156, 156, 160, 160, 164, 164, 168, 168, 168, 172, 172, 175, 182, 184, 184, 192, 196, 196]
FOR THE MIN I CAN EASILY SAY THE FIRST ELEMENT OF THE SORTED LIST AND LAST ELEMENT FOR THE MAX, BUT I'M CERTAIN YOU WANT TO SEE THE LOGIC

THE MINIMUM IS: 100

THE MAXIMUM IS: 196

THE AVERAGE IS: 149.243243243

THE MEDIAN IS: 152
'''
