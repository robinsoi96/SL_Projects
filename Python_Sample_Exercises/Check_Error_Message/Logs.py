import traceback

def output(cmd): #This function is used to print output message of the input command
    print("The output of the command is as below:")
    print(cmd.stdout.decode("utf-8"))

def error():
    print("The error message of the command is as below:")
    print(traceback.format_exc())