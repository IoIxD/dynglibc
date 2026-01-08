# https://www.gnu.org/software/libc/manual/html_node/Function-Index.html
import requests
import time
from bs4 import BeautifulSoup
from bs4.element import Comment

bodies = {}

def get_url(url):
    return requests.get(url, headers={
        "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7",
        "Accept-Encoding": "gzip, deflate, br, zstd",
        "Accept-Language": "en-US,en;q=0.9",
        "Cache-Control": "max-age=0",
        "Connection": "keep-alive",
        "DNT": "1",
        "Host": "www.gnu.org",
        "Referer": "https://kagi.com/",
        "Sec-Fetch-Dest": "document",
        "Sec-Fetch-Mode": "navigate",
        "Sec-Fetch-Site": "cross-site",
        "Sec-Fetch-User": "?1",
        "Upgrade-Insecure-Requests": "1",
        "User-Agent": "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/142.0.0.0 Safari/537.36",
        "sec-ch-ua": "\"Chromium\";v=\"142\", \"Google Chrome\";v=\"142\", \"Not_A Brand\";v=\"99\"",
        "sec-ch-ua-mobile": "?0",
        "sec-ch-ua-platform": "Linux",
    }).text

soup = BeautifulSoup(get_url("https://www.gnu.org/software/libc/manual/html_node/Function-Index.html"), "html.parser")

for td in soup.find_all('td', {'class': 'printindex-index-entry'}):
    a = td.find('a')
    backoff = False
    if(a.find('code') is not None and a.get('href') is not None):
        html_2 = "https://www.gnu.org/software/libc/manual/html_node/" + a.get('href')
        if html_2 not in bodies:
            bodies[html_2] = get_url(html_2)
            backoff = True
        soup2 = BeautifulSoup(bodies[html_2], "html.parser")

        for dt in soup2.find_all('dt', {'class': 'deftypefn'}):
            for span in dt.find_all('span'):
                name = span.find('strong', {'class': 'def-name'})
                if name is not None:
                    if name.text == a.find('code').text:
                        print(span.text.replace(" ¶",";"))
                        break
    if backoff:
        time.sleep(.5)
