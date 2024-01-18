from setuptools import setup

install_requires = [
    "beautifulsoup4",
    "lxml",
    "requests",
]

packages = [
    "atc",
]

console_scripts = [
    "atc=atc:main",
]

setup(
    name="atc",
    version="0.0.0",
    packages=packages,
    install_requires=install_requires,
    console_scripts=console_scripts,
    entry_points={"console_scripts": console_scripts},
)
