from setuptools import find_packages, setup

setup(
    name="atc",
    version="0.0.3",
    packages=find_packages(),
    install_requires=[
        "beautifulsoup4",
        "lxml",
        "requests",
    ],
    entry_points={"console_scripts": ["atc=atc:main"]},
)
