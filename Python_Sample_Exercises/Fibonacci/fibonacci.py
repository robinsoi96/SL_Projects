def fibonacci(input_num):
	if input_num == 0 or input_num == 1:
		return input_num
	else:
		fib_total = fibonacci(input_num - 1) + fibonacci(input_num - 2)
		return fib_total

input_num = int(input("Enter input number for fibonacci: "))
output_num = fibonacci(input_num)
print(f"Output of fibonacci: {output_num}")