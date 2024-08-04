# Lesson 21 - python pip package manager introduction

# This program was originally written by David Grey for a free tutorial course at freeCodeCamp.org

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

    print(f'\nCurrent weather for {weather_data["name"]}:')
    print(f'\nThe temp is {weather_data["main"]["temp"]:.1f}°C')
    print(
        f'\n{weather_data["weather"][0]["description"].capitalize()} and feels like {weather_data["main"]["feels_like"]:.1f}°C\n')
    pprint(weather_data)

if __name__ == "__main__":
    get_current_weather()
