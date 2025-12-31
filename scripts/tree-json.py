#!/usr/bin/env python3
import os, json, sys

root = sys.argv[1] if len(sys.argv)>1 else "."
for dirpath, dirs, files in os.walk(root):
    depth = dirpath.count(os.sep) - root.count(os.sep)
    print(json.dumps({"path": dirpath, "type":"dir", "depth": depth}))
    for f in files:
        p = os.path.join(dirpath, f)
        try:
            size = os.path.getsize(p)
        except OSError:
            size = None
        print(json.dumps({"path": p, "type":"file", "size": size, "depth": depth+1}))
