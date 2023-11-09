#!/usr/bin/python3
max_num = float("-inf")

def is_palindrome(number):
    number = str(number)  # Convert the number to a string
    reversed_number = number[::-1]  # Reverse the string using slicing
    return number == reversed_number

for x in range(100,1000):
  for y in range(100, 1000):
    temp = x * y
    if (is_palindrome(temp)):
      if (max_num < temp):
         max_num = temp
print(max_num)
