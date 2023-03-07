import random

def guess_the_number():
    print('Welcome to Guess the Number game')
    number = -1
    while number < 0 or number > 30:
       number = int(input("The computer is generating a random number and it\'s \n"
                               "your turn to guess. Please Guess a number between 1-30: "))
       game_start = True
       rand = random.randint(1,30)
       while game_start == True:
            if number > rand:
              print("Your number is too high")
            elif number < rand:
              print("Your number is too low")
            else:
              print("Correct! The random number was", rand)
              game_start = False
            if game_start == True:
              number = int(input("guess again... "))
       again = input('Would you like to play again?')
       if again == ('yes'):
        guess_the_number()
guess_the_number()


