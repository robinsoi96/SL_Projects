from artifactory import ArtifactoryPath
import os
import argparse
import re

parser = argparse.ArgumentParser()
parser.add_argument("--link",metavar=("<link>"),required=True)
parser.add_argument("--user",metavar=("<username>"),required=True)
parser.add_argument("--password",metavar=("<password>"),required=True)
parser.add_argument("--path",metavar=("<local download path with filename>"),required=True)
parameter = parser.parse_args()

FILE_LINK = parameter.link.strip()
USERNAME = parameter.user.strip()
PASSWORD = parameter.password.strip()
LOCAL_FILE = parameter.path.strip()

try:
    path = ArtifactoryPath(FILE_LINK,auth(USERNAME,PASSWORD))
    for p in path:
        with p.open() as fd:
            with open(LOCAL_FILE, "wb") as out:
                out.write(fd.read())
except:
    print("Fail to download")