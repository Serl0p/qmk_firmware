#!/usr/bin/env python3
import json, os, sys

def insert_node(root, parts, obj):
    cur = root
    for p in parts:
        if p not in cur["children"]:
            cur["children"][p] = {"children": {}, "type": None, "size": None}
        cur = cur["children"][p]
    cur["type"] = obj.get("type")
    cur["size"] = obj.get("size")

root = {"children": {}, "type": "dir"}
infile = sys.argv[1] if len(sys.argv) > 1 else "tree.ndjson"

with open(infile, "r", encoding="utf-8") as f:
    for line in f:
        if not line.strip():
            continue
        obj = json.loads(line)
        path = os.path.normpath(obj["path"]).lstrip("./")
        parts = path.split(os.sep) if path else []
        insert_node(root, parts, obj)

# Convert children dicts to lists for nicer JSON
def dict_to_list(node):
    children = []
    for name, child in sorted(node["children"].items()):
        entry = {"name": name, "type": child.get("type"), "size": child.get("size")}
        entry.update({"children": dict_to_list(child)}) if child.get("children") else None
        children.append(entry)
    return children

nested = {"name": ".", "type": "dir", "children": dict_to_list(root)}
print(json.dumps(nested, indent=2))
