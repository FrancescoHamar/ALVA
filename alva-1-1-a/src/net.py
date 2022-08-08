import requests
import json

# Using openweatherapi as weather retrieve and position retrieve for lon and lat.
# Possibly use own set of lon and lat with a relatively big amount of data on known or set locations.

API_ID = "3de4f3c1095321c471a8f23f59ee0ec3"  # Not real key, autogenerated values.
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
        retrieve_pos(param)
        retrieve_weather()
    else:
        print("Unsupported scope")


def retrieve_pos(city):
    global lat, lon, connected

    try:
        r = requests.get(f"http://api.openweathermap.org/geo/1.0/direct?q={param}&limit=1&appid={API_ID}")
        # Format r
        print(r.json())

        data = r.json()
        lat = (data[0])["lat"]
        lon = (data[0])["lon"]

        connected = True

    except requests.exceptions.ConnectionError:
        connected = False
        print("Can't Connect (1)")

    print(f"lat: {lat}, lon: {lon}")


def retrieve_weather():
    global connected
    
    if connected:

        try:
            r = requests.get(f"https://api.openweathermap.org/data/2.5/weather?lat={lat}&lon={lon}&appid={API_ID}")

            data = r.json()
            main = ((data["weather"])[0])["main"]
            description = ((data["weather"])[0])["description"]
            temp = (data["main"])["temp"]
            temp_feel = (data["main"])["feels_like"]
            humidity = (data["main"])["humidity"]

            print(f"The weather is {main.lower()}, to be more precise: {description}. The temperature is {temp}, "
                  f"but it feels like {temp_feel}. This is partly due to the {humidity}% humidity.")

        except requests.exceptions.ConnectionError:
            connected = False
            print("Can't Connect (2)")

    else:
        print("Couldn't retrieve location.")


load_dir()
load_module()
