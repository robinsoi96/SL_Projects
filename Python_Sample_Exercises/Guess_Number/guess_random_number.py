#!/usr/bin/env python3

#Import random module to generate random number
import random

#Generate a random integer ranging from 0 to 9
answer = random.randint(0,9)

max_guess = 3
guess = 0
print("You have only 3 guesses for the correct number")
while guess < max_guess:
	ans = int(input("Key in any number [0-9]:"))
	if ans == answer:
		print(f"Congrats! You guessed it! The number is {ans}.")
		break
	guess += 1
	print(f"You have {max_guess - guess} chance(s) left")
else:
	print(f"Sorry, you failed to guess the correct number. The correct number is {answer}")