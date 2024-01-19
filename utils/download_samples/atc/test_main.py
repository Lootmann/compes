from .main import validation


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
