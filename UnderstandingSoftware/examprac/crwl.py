import requests
from bs4 import BeautifulSoup

res = requests.get('https://www.naver.com/')
print(res.content)