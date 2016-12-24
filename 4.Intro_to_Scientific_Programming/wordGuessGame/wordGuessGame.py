def printCorrectLetters(s, g):
	for ix in range(0, len(s)):
		if(s[ix] == g[ix]):
			print s[ix],
		else:
			print "-",
	print "\n"
def main():
	secret = raw_input("Player 1, enter a secret word, from 3 - 10 letters: \n")
	print "\n"

	keepGoing = True
	count = 0
	while(keepGoing):
		guess = raw_input("Player 2, enter a guess, it should have " + str(len(secret)) + " letter(s): \n")
		if(len(secret) != len(guess)):
			print "Wrong number of letters!"
		else:
			printCorrectLetters(secret, guess)
		if(guess == secret):
			keepGoing = False
		count = count + 1
		if(count >= 3 and (secret[0] != guess[0])):
			print "The first letter is " + secret[0] 

	print "You got it in " + str(count) + " guess(es)!"

if __name__ == "__main__":
	main()
