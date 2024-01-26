import inspect
import os

PATH = os.path.dirname(os.path.abspath(__file__))
FILENAME = os.path.abspath(__file__)

def err(msg):
    print("\n" + FILENAME + ", line " + str(inspect.currentframe().f_back.f_lineno) + ":\n" + msg)

err("Hello")