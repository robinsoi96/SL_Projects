import json
import os

Current_Path = os.getcwd()
JSON_file = Current_Path + "\sample.json"

with open(JSON_file, "r") as file:
    JSON_INFO = json.load(file)
    
print("Name: " + JSON_INFO["Name"])
print("Height: " + JSON_INFO["Info"]["Height"])
print("Weight: " + JSON_INFO["Info"]["Weight"])
print("Hobbies: " + JSON_INFO["Info"]["Hobbies"][0] + " , " + JSON_INFO["Info"]["Hobbies"][1])
print("Travel: " + JSON_INFO["Travel"][0] + " , " + JSON_INFO["Travel"][1])