# Lesson 21 - the python pip package manager 

import requests
from dotenv import load_dotenv
import os
from pprint import pprint

load_dotenv()

def get_current_weather():
    print("\n***Get Current Weather Conditions***\n")

    city = input("Please enter a city name:\n")

    request_url = f'https://api.openweathermap.org/data/2.5/weather?appid={os.getenv("API_KEY")}&q={city}&units=metric'

    weather_data = requests.get(request_url).json()

    pprint(weather_data)

# if __name__ == "__main__":
#     get_current_weather()

get_current_weather()

