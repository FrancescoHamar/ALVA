import requests


API_ID = ""
commsURL = "../frontalcortex/comms/dir.txt"
weatherCALL = f"https://api.openweathermap.org/data/2.5/weather?lat={lat}&lon={lon}&appid={API key}"
posCALL = f"http://api.openweathermap.org/geo/1.0/direct?q={city name},{state code},{country code}&limit={limit}&appid={API key}"
connected = False
lat = ""
lon = ""


def loadScope():
    commsFile = file.open(commsURL, 'r')
    
    if file.read == "weather":
        commsFile.close()
        return 'w'
    else:
        commsFile.close()
        return False


def retrieveWeather():
    r = requests.get(weatherCALL)

    # Format r
    print(r)
    commsFile = file.open(commsURL, 'w')
    
    if connected:
        commsFile.write("description:"+description)
        commsFile.write("temp:"+temp)
        commsFile.write("air:"+air)
        commsFile.close()
    else:
        commsFile.write("")
        commsFile.close()



def retrievePos():
    r = requests.get(posCALL)

    # Format r
    print (r)
    lat = ""
    lon = ""




scope = loadScope()

if scope == 'w':
    retrieveWeather()
else:
    commsFile = file.open(commsURL, 'w')
    commsFile.write("failed")
    commsFile.close()
