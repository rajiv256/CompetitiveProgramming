#!/bin/bash
NAME=$1

mkdir -p $NAME

touch $NAME/1.cpp $NAME/2.cpp $NAME/3.cpp $NAME/4.cpp $NAME/5.cpp

cat templ > $NAME/1.cpp
cat templ > $NAME/2.cpp
cat templ > $NAME/3.cpp
cat templ > $NAME/4.cpp
cat templ > $NAME/5.cpp
