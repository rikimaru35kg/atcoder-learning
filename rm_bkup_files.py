import os
import glob

for f in glob.glob("*_bkup"):
    os.remove(f)
