#!/usr/bin/env python3
import os
import subprocess as sp

import numpy as np


if __name__ == '__main__':
    path = os.path.dirname(os.path.abspath(__file__))
    sp.call(['g++', '--std=c++17', os.path.join(path, 'E.cpp'), '-o', os.path.join(path, 'e.out')])
    np.random.seed(42)
    tests = 50
    strs = [f'{tests}\n', '86\n']
    ans = []
    for test in range(tests):
        p = np.random.uniform(-3, 3, 100)
        q = np.random.uniform(-3, 3, 10000)
        cheet = np.random.randint(0, 100)
        ans.append(cheet + 1)
        for i in range(100):
            line_probs = np.random.rand(10000)
            res = np.zeros(10000, dtype=int)
            res[line_probs < 1.0 / (1.0 + np.exp(-p[i] + q))] = 1
            if i == cheet:
                cheets = np.random.randint(0, 2, 10000)
                res[cheets == 1] = 1
            strs.append(''.join(map(str, res)) + '\n')
    text = ''.join(strs)
    oup = sp.check_output(os.path.join(path, 'e.out'), input=text.encode('utf-8')).decode('utf-8')
    lines = oup.split('\n')
    cnt = 0
    for a, line in zip(ans, lines):
        if a == int(line.split(' ')[-1]):
            cnt += 1
        print(f'{line} vs {a}')
    print(f'{cnt} from {tests}')
    os.remove(os.path.join(path, 'e.out'))