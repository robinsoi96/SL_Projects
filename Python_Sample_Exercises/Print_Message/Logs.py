import traceback
import inspect

def log(Source_File, cmd):
    print("\n" + Source_File + ", line " + str(inspect.currentframe().f_back.f_lineno) + ":\n" + cmd)