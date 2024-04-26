import traceback
import inspect
import os

def log(cmd):
    Source_File = os.path.abspath(str(inspect.getframeinfo(inspect.currentframe().f_back).filename))
    Source_Line_Num = str(inspect.currentframe().f_back.f_lineno)
    print("\n" + Source_File + ", line " + Source_Line_Num + ":\n" + cmd)
