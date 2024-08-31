#!/bin/bash

git log -n 5 --pretty=format:"%H" | awk '{print $1}'
