#!/usr/bin/env python
import comments
import sys
import os
import re
import subprocess

if len(sys.argv) == 1:
    print "python strip.py ""filename"""
    exit(1)
elif not os.path.isfile(sys.argv[1]):
    print sys.argv[1], "file not exist"
    exit(2)

name = sys.argv[1]
with open(name, 'r') as content_file:
    if name.find('.py'):
        filetype = "python"
    elif name.find('.cpp'):
        filetype = "cpp"
    content = content_file.read()
    striper = comments.Comments(filetype)
    content = striper.strip(content)
    # remain only else phase #ifdef~#else~#endif
    s = re.compile(r"#ifdef\s*_DEBUG\s*(.*)#else(.*)#endif", re.DOTALL)
    content = re.sub(s, r"\2", content)
    # remove #ifdef~#endif
    content = re.sub(r"#ifdef\s*_DEBUG(.|\n)*#endif", r"", content)
    process = subprocess.Popen('pbcopy', env={'LANG': 'en_US.UTF-8'}, stdin=subprocess.PIPE)
    process.communicate(content)
