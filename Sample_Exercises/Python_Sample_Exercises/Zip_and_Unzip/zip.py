import shutil
import py7zr
import os
import argparse

parser = argparse.ArgumentParser()
parser.add_argument("--f",metavar=("<local file path to be zipped>"),required=True)
parser.add_argument("--t",metavar=("<e.g.: zip or 7z ???>"),required=True)
parameter = parser.parse_args()

FILE = parameter.f.strip()
TYPE = parameter.t.strip()

if TYPE == "zip":
    shutil.make_archive(FILE, format=TYPE, root_dir=FILE)
elif TYPE == "7z":
    with py7zr.SevenZipFile(FILE + ".7z", 'w') as archive:
        archive.writeall(FILE, arcname = FILE.strip("\\")[-1])
else:
    print("Not supported. This script supports for zip and 7z")