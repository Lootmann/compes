"""
get all Contest problmes with online-judge-tools

usage:

    > atc https://atcoder.jp/contests/arc143
    or
    > atc arc143

    > tree arc143

    |- A/test
    |      |- sample-1.in
    |      |- ...
    |- B/test
    |- C/test
    |- D/test
    |- E/test
    |- F/test
"""
import argparse
import re
import subprocess
from pathlib import Path
from typing import List, Tuple

import requests
from bs4 import BeautifulSoup as bs


def create_dirs(task_ids: List[str], contest_id: str) -> List[Path]:
    """
    create each problem task dirs

    |- A
    |- B
    |- C
    ..

    Args:
        task_ids (List[str]): ['A', 'B', ...]
        contest_id (str): 'abc123', 'joi2024yo2', ...

    Returns:
        List[Path]: dir paths
    """
    task_dirpaths = []
    tmp_path = Path(f"./{contest_id}/")

    # create contest dir
    if not tmp_path.exists():
        tmp_path.mkdir()

    for task_id in task_ids:
        task_dirpath = tmp_path / task_id
        task_dirpaths.append(task_dirpath)
        if not task_dirpath.exists():
            task_dirpath.mkdir()

    return task_dirpaths


def get_all_taskIDs(soup: bs) -> List[str]:
    """
    soup is task page html.
    this page shows all task IDs. get All shit.

    Args:
        soup (bs4): tasks page html

    Returns:
        List[str] - ['A', 'B', ...]
    """

    filter = """
    html body div#main-div.float-container div#main-container.container div.row div.col-sm-12
    div.panel.panel-default.table-responsive table.table.table-bordered.table-striped tbody
    """

    table = soup.select(filter)[0]

    """
    table is html:table

    | problem | name | score |
    +---------+------+-------+
    |    A    | hoge |  300  |
    |    B    | hige |  500  |
    |    C    | hage |  700  |
    ...
    """
    # task_id ls left column, so I get all even columns
    task_ids = []

    for idx, td in enumerate(table.find_all("td")):
        if idx % 4 == 0:
            task_ids.append(td.text.strip())

    # when task_IDs has 'Ex', change it for get_sampels
    if "Ex" in task_ids:
        ex = chr(ord("A") + len(task_ids) - 1)
        task_ids.pop()
        task_ids.append(ex)

    return task_ids


def get_all_task_urls(soup: bs) -> List[str]:
    """
    get all task urls

    Args:
        soup (bs4): tasks page html

    Returns:
        List[str]: task urls ['https://atcoder.jp/contests/abc123/task/abc123_c', ...]
    """
    filter = """
    html body div#main-div.float-container div#main-container.container div.row div.col-sm-12
    div.panel.panel-default.table-responsive table.table.table-bordered.table-striped tbody
    """
    task_urls = []
    table = soup.select(filter)[0]

    for idx, a in enumerate(table.find_all("a")):
        if idx % 2 == 0:
            task_urls.append(a.get("href"))

    return task_urls


def get_samples(
    task_dirpaths: List[Path],
    task_urls: List[str],
) -> None:
    """
    get all task testcase

    Args:
        task_dirpaths (List[Path]): ["test/A", "test/B", "test/C", ...]

    Returns:
        List[Path]: Return task_urls ["contests/abcNNN/tasks/abcNNN_X", ...]
    """

    for url, path in zip(task_urls, task_dirpaths):
        task_url = f"https://atcoder.jp{url}"
        test_path = path / "test"

        if test_path.exists():
            print("*", str(path / "test"), "is exists :^)")
        else:
            cmd = subprocess.run(["oj", "d", f"{task_url}"], cwd=str(path))
            print(cmd)


def fetch(url: str) -> bs:
    """
    fetch url html, html to BeautifulSoup object

    Args:
        url (str)

    Returns:
        bs: task page html soup
    """
    res = requests.get(url)
    if res.status_code != 200:
        raise ValueError("url is something with wrong.")

    res.raise_for_status()
    return bs(res.text, "lxml")


def extract_contest_id(url: str) -> str:
    """
    if url has '(abc|arc|agc)[NNN]' N is 0-9 digit
    (named regular contest),
    get contest_id and generate complete url.

    if url has unusual contest_id (jag2018summer, joi2024yo2),
    throw this process.

    Args:
        url (str):

    Returns:
        str: Return usual contest_id
    """
    pattern = r"(abc|arc|agc)\d\d\d"
    found = re.match(pattern, url)

    if found:
        contest_id = found.group()
        return contest_id

    return ""


def validation(url: str) -> Tuple[str, str]:
    """
    url is like
        - abc063
        - https://atcoder.jp/contests/abc063
        - https://atcoder.jp/contests/abc063/tasks
        - https://atcoder.jp/contests/abc063/tasks/abc063_a
        - get-me-pls-abc063

    Args:
        url (str): url or contest_id

    Returns:
        url (str) - https://atcoder.jp/contests/.../tasks
        contest_id (str) - contest_id 'abc123', 'joi2024yo2', 'agc123'
    """
    contest_id = extract_contest_id(url)

    # when url is contest_id
    if contest_id != "":
        url = "https://atcoder.jp/contests/{}/tasks".format(contest_id)
        return url, contest_id

    # url may be 3 patterns
    # 1. unusual and only contest_id  'jag2018summer-day2'
    # 2. unusual full url 'https://atcoder.jp/contests/jag2018summer-day2'
    # 3. wrong url 'http://hogehoge.comcom', 'random-string-here :^)'

    # 1. when url is unusual contest_id, attach url 'https://atcoder.jp/contests{}/tasks'
    if "https" not in url:
        contest_id = url
        return f"https://atcoder.jp/contests/{contest_id}/tasks", contest_id

    # full url
    if "https://atcoder.jp" not in url:
        raise ValueError("Not AtCoder.jp")

    if "/contests" not in url:
        raise ValueError("Not Contest top page url")

    if "/tasks" not in url:
        url += "/tasks"

    # contest_id has many variations.
    # so can't use regular expression extraction.
    contest_id = url.split("/")[-2]

    return url, contest_id


def test_fetch(url: str) -> bs:
    """
    test fetch method
    create cache(just index.html)

    Args:
        url (str): https://atcoder.jp/contests/xxxNNN/tasks

    Returns:
        bs (BeautifulSoup): html soup
    """
    path = Path("index.html")

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


def main():
    # get args
    parser = argparse.ArgumentParser()
    parser.add_argument("url", help="atcoder url")
    args = parser.parse_args()

    # validation
    url, contest_id = validation(args.url)

    print(f"* get samples from {url}")
    print("*")

    # get page
    # FIXME: need better test ways.
    soup = fetch(url)
    # soup = test_fetch(url)

    # get all tasks
    task_IDs = get_all_taskIDs(soup)
    print("* ", task_IDs)

    # get all task urls
    task_urls = get_all_task_urls(soup)
    print(task_urls)

    print("* create_dirs")
    task_dirpaths = create_dirs(task_IDs, contest_id)
    print("* {}".format(", ".join(map(str, task_dirpaths))))
    print("*")

    # get all samples
    print("* get_samples")
    get_samples(task_dirpaths, task_urls)
    print("*")


if __name__ == "__main__":
    main()
