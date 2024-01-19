from pathlib import Path

import requests
from bs4 import BeautifulSoup as bs

FILENAME = "index.html"


def test_fetch(url: str) -> bs:
    path = Path(FILENAME)

    if path.exists():
        print("* use cache")
        html = path.read_text()
        soup = bs(html, "lxml")
    else:
        print("* no cache")
        res = requests.get(url)
        if res.status_code != 200:
            raise ValueError("url is something with wrong.")

        res.raise_for_status()
        soup = bs(res.text, "lxml")
        path.write_text(soup.prettify())

    return soup
