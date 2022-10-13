#!/bin/sh
make test
find build/tests/ -type f  -executable -exec sh -c 'exec "$1"' _ {} \;