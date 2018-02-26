//
// Created by Rak Alexey on 12/9/16.
//
#pragma once

#ifndef CPP_CGDK_MAPPOINT_H
#define CPP_CGDK_MAPPOINT_H

struct mappoint {
public:
    int x;
    int y;

    mappoint() : x(0), y(0) {}

    mappoint(int x_, int y_) : x(x_), y(y_) {}

    bool operator< (const mappoint& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

#endif //CPP_CGDK_MAPPOINT_H
