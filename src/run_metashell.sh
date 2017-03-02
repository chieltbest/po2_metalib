#!/usr/bin/env bash

metashell --nosplash -- -ftemplate-depth=2048 < metashell_main.cpp |
 sed "s/po2_list::\|push_front_states:://g;s/::/:/g"