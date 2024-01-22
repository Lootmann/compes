from .main import extract_contest_id, validation


class TestValidation:
    def test_validation(self):
        """
        with tasks
        """

        url = "https://atcoder.jp/contests/abc284/tasks"
        expect = ["https://atcoder.jp/contests/abc284/tasks", "abc284"]
        got = validation(url)

        assert expect[0] == got[0]
        assert expect[1] == got[1]

    def test_validation_without_tasks(self):
        """
        url without tasks, but validation ok
        """

        url = "https://atcoder.jp/contests/abc284"
        expect = ["https://atcoder.jp/contests/abc284/tasks", "abc284"]
        got = validation(url)

        assert expect[0] == got[0]
        assert expect[1] == got[1]

    def test_validation_with_only_contest_id(self):
        url_format = "https://atcoder.jp/contests/{}/tasks"

        urls = [
            ("abc001", url_format.format("abc001")),
            ("abc999", url_format.format("abc999")),
            ("arc001", url_format.format("arc001")),
            ("arc765", url_format.format("arc765")),
            ("agc123", url_format.format("agc123")),
            ("agc000", url_format.format("agc000")),
            ("alc999", url_format.format("alc999")),
            ("jag2018summer-day2", url_format.format("jag2018summer-day2")),
            ("jag2012autumn", url_format.format("jag2012autumn")),
            ("past16-open", url_format.format("past16-open")),
            ("jag2015spring", url_format.format("jag2015spring")),
            ("joisc2017", url_format.format("joisc2017")),
        ]

        for contest_id, expect_full_url in urls:
            got_full_url, got_contest_id = validation(contest_id)
            assert contest_id == got_contest_id
            assert expect_full_url == got_full_url


class TestExtractContestId:
    def test_extract_contest_id(self):
        urls = [
            ("abc012", "abc012"),
            ("agc001", "agc001"),
            ("arc123", "arc123"),
            ("alc001", "alc001"),
            ("joi2024yo2", ""),
        ]
        for url, expect in urls:
            got = extract_contest_id(url)
            assert got == expect

    def test_extract_does_not_exists_contest_id(self):
        """
        these contest_id does NOT exist
        """
        urls = [
            ("abc999", "abc999"),
            ("bbq012", ""),
            ("sos098", ""),
        ]

        for url, expect in urls:
            got = extract_contest_id(url)
            assert got == expect
