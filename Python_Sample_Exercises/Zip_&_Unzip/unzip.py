import shutil
import py7zr
import os
import argparse

parser = argparse.ArgumentParser()
parser.add_argument("--f",metavar=("<local file path to be unzipped>"),required=True)
parser.add_argument("--t",metavar=("<e.g.: zip or 7z ???>"),required=True)
parameter = parser.parse_args()

FILE = parameter.f.strip()
TYPE = parameter.t.strip()

if TYPE == "zip":
    shutil.unpack_archive(FILE, FILE.replace(".zip",""))
elif TYPE == "7z":
    with py7zr.SevenZipFile(FILE, 'w') as archive:
        archive.extractall(path = FILE.replace(".7z",""))
else:
    print("Not supported. This script supports for zip and 7z")