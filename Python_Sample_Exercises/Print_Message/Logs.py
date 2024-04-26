import traceback
import inspect
import os

def log(cmd):
    print("\n" + os.path.abspath(str(inspect.getframeinfo(inspect.currentframe().f_back).filename)) + ", line " + str(inspect.currentframe().f_back.f_lineno) + ":\n" + cmd)
