
<!--![SKOMOBO](https://github.com/Ulfasaar/skomobo/raw/New_Architecture/Resources/icon.jpg)-->

<!--[![Build Status](https://travis-ci.org/Ulfasaar/skomobo.svg?branch=master)](https://travis-ci.org/Ulfasaar/skomobo)
[![Coverage Status](https://coveralls.io/repos/github/Ulfasaar/skomobo/badge.svg)](https://coveralls.io/github/Ulfasaar/skomobo)
[![Known Vulnerabilities](https://snyk.io/test/github/ulfasaar/skomobo/badge.svg?targetFile=Code%2FServer%2Fpackage.json)](https://snyk.io/test/github/ulfasaar/skomobo?targetFile=Code%2FServer%2Fpackage.json)
-->

<div align="center">
  <img src="./Resources/icon.jpg" width="492" height="450">
  <br>
  <br>
	<a href="https://travis-ci.org/Ulfasaar/skomobo">
		<img src="https://travis-ci.org/Ulfasaar/skomobo.svg?branch=master">
	</a>
    <a href="https://coveralls.io/github/Ulfasaar/skomobo">
		<img src="https://coveralls.io/repos/github/Ulfasaar/skomobo/badge.svg">
	</a>
    <a href="https://snyk.io/test/github/ulfasaar/skomobo?targetFile=Code%2FServer%2Fpackage.json">
		<img src="https://snyk.io/test/github/ulfasaar/skomobo/badge.svg?targetFile=Code%2FServer%2Fpackage.json">
	</a>
  <br>
  <br>
</div>

# Skomobo:

To unit test the arduino code you need to upload the test.ino file inside the test folder

it is in its own folder to prevent it from being uploaded with the main ino file for production

to test the python code you need to run the test command in the coconuts folder and to add tests add them to the test.py file in side the compiled folder I know its a mess at the moment I'm working on it

## Tools currently in use:

- python 2.7
- vscode with platform io extension
- platform io core
- Nodejs
- pm2
- Typescript
- Coconuts

Future versions of the project will use a provisioning system such as CHEF and a vm using Vagrant. Most likely it will just use chocolatey.
