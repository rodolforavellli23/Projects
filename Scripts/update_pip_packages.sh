#!/usr/bin/bash

# Small script to just update pip packages inside a virtual environment
pip list --format=freeze | cut -d "=" -f 1 | xargs pip install -U
