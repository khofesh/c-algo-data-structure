#!/bin/sh
make tests
find build/tests/ -type f  -executable -exec sh -c 'exec "$1"' _ {} \;