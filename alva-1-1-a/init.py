import json
from datetime import datetime


def awake():
    with open("deephippo/tag.json") as tag:
        tag_data = json.load(tag)
        if not tag_data["born"]:
            birth()
        else:
            print("Already Alive :)")
            # main()


def birth():
    with open("deephippo/tag.json") as tag:
        tag_data = json.load(tag)
        tag_data["born"] = True
        now = str(datetime.now())
        tag_data["birthdate"] = now

    with open("deephippo/tag.json", 'w') as tag:
        json.dump(tag_data, tag)


awake()
