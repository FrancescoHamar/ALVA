import requests

# Using openweatherapi as weather retrieve and position retrieve for lon and lat.
# Possibly use own set of lon and lat with a relatively big amount of data on known or set locations.


API_ID = ""
lat = ""
lon = ""
city = ""
COMMS_URL = "../frontalcortex/comms/dir.txt"
weatherCALL = f"https://api.openweathermap.org/data/2.5/weather?lat={lat}&lon={lon}&appid={API_ID}"
posCALL = f"http://api.openweathermap.org/geo/1.0/direct?q={city},{state_code},{country_code}&limit={limit}&appid={API_ID}"
connected = False


def load_scope():
    global commsFile

    commsFile = file.open(commsURL, 'r')
    
    if file.read == "weather":
        commsFile.close()
        return 'w'
    else:
        commsFile.close()
        return False


def retrieve_weather():
    global commsFile
    r = requests.get(weatherCALL)

    # Format r
    print(r)
    commsFile = file.open(COMMS_URL, 'w')
    
    if connected:
        commsFile.write("description:"+description)
        commsFile.write("temp:"+temp)
        commsFile.write("air:"+air)
        commsFile.close()
    else:
        commsFile.write("")
        commsFile.close()


def retrieve_pos():
    global lat, lon
    r = requests.get(posCALL)

    # Format r
    print (r)
    lat = ""
    lon = ""


scope = load_scope()

if scope == 'w':
    retrieve_weather()
else:
    commsFile = file.open(commsURL, 'w')
    commsFile.write("failed")
    commsFile.close()
