import requests

# Using openweatherapi as weather retrieve and position retrieve for lon and lat.
# Possibly use own set of lon and lat with a relatively big amount of data on known or set locations.

API_ID = ""
DIR_URL = "../frontalcortex/comms/dir.txt"
RES_URL = "../frontalcortex/comms/res.txt"

scope = None
param = None
lat = None
lon = None

connected = False

# weatherCALL = f"https://api.openweathermap.org/data/2.5/weather?lat={lat}&lon={lon}&appid={API_ID}"
# posCALL = f"http://api.openweathermap.org/geo/1.0/direct?q={city},{state_code},{country_code}&limit={limit}
# &appid={API_ID}"


def load_dir():
    global scope
    global param

    commsFile = open(DIR_URL, 'r')

    i = 1
    for line in commsFile:
        if i == 1:
            scope = line
        elif i == 2:
            param = line
        else:
            print(f"Extra line found: {line}")

        i += 1
        print(f"i: {i}, scope: {scope}, param: {param}")

    else:
        commsFile.close()
        return False


def load_module():
    global lat, lon, scope, param

    if scope == "weather\n":
        print("Supported scope")
        lat, lon = retrieve_pos(param)
        retrieve_weather()
    else:
        print("Unsupported scope")


def retrieve_pos(city):
    global lat, lon, connected

    try:
        r = requests.get(f"http://api.openweathermap.org/geo/1.0/direct?q={city}&appid={API_ID}")
        # Format r
        print(r)

        connected = True

    except requests.exceptions.ConnectionError:
        connected = False
        print("Can't Connect (1)")

    return lat, lon


def retrieve_weather():
    global connected
    
    if connected:

        try:
            r = requests.get(f"https://api.openweathermap.org/data/2.5/weather?lat={lat}&lon={lon}&appid={API_ID}")

        except requests.exceptions.ConnectionError:
            connected = False
            print("Can't Connect (2)")

        print(r)
        # Format r

        resFile = open(RES_URL, 'w')
        resFile.write("description:"+description)
        resFile.write("temp:"+temp)
        resFile.write("air:"+air)
        resFile.close()
    else:
        resFile = open(RES_URL, 'w')
        resFile.write("")
        resFile.close()


load_dir()
load_module()
