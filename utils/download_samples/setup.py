from setuptools import setup

install_requires = [
    "beautifulsoup4",
    "lxml",
    "requests",
]

packages = [
    "compe",
]

console_scripts = [
    "compe=compe:main",
]

setup(
    name="compe",
    version="0.0.0",
    packages=packages,
    install_requires=install_requires,
    console_scripts=console_scripts,
    entry_points={"console_scripts": console_scripts},
)
