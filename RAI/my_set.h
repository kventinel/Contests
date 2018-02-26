//
// Created by Rak Alexey on 12/9/16.
//
#pragma once

#ifndef CPP_CGDK_MY_SET_H
#define CPP_CGDK_MY_SET_H

#include "mappoint.h"
#include <vector>
#include <queue>

class my_set{
public:
    my_set() {
        min_vector = 0;
        v.resize(0);
    }

    void insert(int key, mappoint value) {
        while (key >= int(v.size())) {
            v.push_back(std::queue<mappoint>());
        }
        v[key].push(value);
    }

    bool empty() {
        if (!v[min_vector].empty()) {
            return false;
        }
        while(min_vector < v.size() && v[min_vector].empty()) {
            ++min_vector;
        }
        return min_vector >= v.size();
    }

    mappoint begin() {
        mappoint answer = v[min_vector].front();
        v[min_vector].pop();
        return answer;
    }

    ~my_set() {}
private:
    std::vector<std::queue<mappoint>> v;
    int min_vector;
};

#endif //CPP_CGDK_MY_SET_H
