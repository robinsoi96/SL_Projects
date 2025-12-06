import sys
import subprocess

#Import own module
import Logs

command = sys.argv[1]
print("Command executed: " + command)
print()

try:
    cmd = subprocess.run(command, shell=True, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    Logs.output(cmd)
except:
    Logs.error()