"""
get all Contest problmes with online-judge-tools

usage:

    > pset https://atcoder.jp/contests/arc143
    > arc143/

    > tree arc143
    >
    > |- A/test
    > |      |- sample-1.in
    > |      |- ...
    > |- B/test
    > |- C/test
    > |- D/test
    > |- E/test
    > |- F/test
"""
import argparse
import subprocess
import time
from pathlib import Path
from typing import List

import requests
from bs4 import BeautifulSoup as bs


def create_dirs(task_ids: List[str], contest_id: str) -> List[Path]:
    """
    create each problem task dirs

    |- A
    |- B
    |- C
    ..

    return dir path (Pathlib)

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
    soup is top page html.
    this page shows all task IDs. get All shit.
    """

    filter = """
    html body div#main-div.float-container div#main-container.container div.row div.col-sm-12
    div#contest-statement span.lang span.lang-ja section div.row div.span4
    table.table.table-responsible.table-striped.table-bordered tbody"""

    table = soup.select(filter)[0]

    """
    table is html:table

    | problem | score |
    |---------+-------|
    |    A    |  300  |
    |    B    |  500  |
    |    C    |  700  |
    ...
    """
    # task_id ls left column, so I get all even columns
    task_ids = []

    for idx, td in enumerate(table.find_all("td")):
        if idx % 2 == 0:
            task_ids.append(td.text.strip())

    # when task_IDs has 'Ex', change it for get_sampels
    if "Ex" in task_ids:
        ex = chr(ord("A") + len(task_ids) - 1)
        task_ids.pop()
        task_ids.append(ex)

    return task_ids


def get_samples(
    task_IDs: List[str], task_dirpaths: List[Path], contest_id: str
) -> None:
    """
    :param task_IDs: List[str]       - ['A', 'B', 'C', ...]
    :param task_dirpaths: List[Path] - ["test/A", "test/B", "test/C", ...]
    :param contest_id: str           - abcNNN, arcNNN, agcNNN
    """
    base_url = "https://atcoder.jp/contests/{0}/tasks/{0}_{1}"
    for idx, path in enumerate(task_dirpaths):
        time.sleep(0.5)

        task_url = base_url.format(contest_id, task_IDs[idx].lower())
        test_path = path / "test"

        if test_path.exists():
            print("*", str(path / "test"), "is exists :^)")
        else:
            cmd = subprocess.run(["oj", "d", f"{task_url}"], cwd=str(path))
            print(cmd)


def fetch(url: str):
    """fetch url html"""
    res = requests.get(url)
    if res.status_code != 200:
        raise ValueError("url is something with wrong.")

    res.raise_for_status()
    return bs(res.text, "lxml")


def validation(url: str) -> str:
    if "https://atcoder.jp" not in url:
        raise ValueError("Not AtCoder.jp")

    if "/contests" not in url:
        raise ValueError("Not Contest top page url")

    if "/tasks" not in url:
        raise ValueError("should require url:'/tasks'")

    contest_id = url.split("/")[-2]
    found = False

    for name in ["abc", "arc", "agc"]:
        found |= name in contest_id

    if not found:
        raise ValueError("name is NOT valid name. 'abc', 'arc', 'agc'")

    return url


def main():
    # get args
    parser = argparse.ArgumentParser()
    parser.add_argument("url", help="atcoder url")
    args = parser.parse_args()

    # validation
    url = args.url
    validation(url)

    print(f"* get samples from {url}")
    print("*")

    # get page
    soup = fetch(url)

    # get all tasks
    task_IDs = get_all_taskIDs(soup)
    print("* ", task_IDs)

    # create each task dirs
    contest_id = url.split("/")[-1]

    print("* create_dirs")
    task_dirpaths = create_dirs(task_IDs, contest_id)
    print("* {}".format(", ".join(map(str, task_dirpaths))))
    print("*")

    # get all samples
    print("* get_samples")
    get_samples(task_IDs, task_dirpaths, contest_id)
    print("*")


if __name__ == "__main__":
    main()
