#!/bin/bash

# Auto submit to Github

git add -A

echo "Please enter your submit text below: "

read commit_info

git commit -m "${commit_info}"

echo "Please enter your Username and Password below: "

git push origin master
