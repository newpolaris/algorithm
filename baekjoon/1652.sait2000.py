import re;s=map(raw_input,['']*input());P=lambda A:len(re.findall('\.\.+',' '.join(A)));print P(s),P(map(''.join,zip(*s)))
