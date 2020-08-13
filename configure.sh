#! /bin/sh

cmake -DGLFW_BUILD_DOCS=OFF -DUSE_ADDER=ON -S . -B out/build
