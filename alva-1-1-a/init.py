import json


def awake():
    with open("deephippo/tag.json") as tag:
        tag_data = json.load(tag)
        return tag_data["born"]


def birth():
    

awake()
