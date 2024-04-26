import inspect
import os

#Import own module
import Logs

PATH = os.path.dirname(os.path.abspath(__file__))
FILENAME = os.path.abspath(__file__)

Logs.log("Hello")