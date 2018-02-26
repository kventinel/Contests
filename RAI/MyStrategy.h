#pragma once

#ifndef _MY_STRATEGY_H_
#define _MY_STRATEGY_H_

#include "Strategy.h"
#include "my_set.h"
#include "mappoint.h"
#include <vector>

using namespace std;
using namespace model;

class MyStrategy : public Strategy {
public:
    MyStrategy();


    void move(const Wizard &self, const World &world, const Game &game, Move &move) override;
    void just_do(const Wizard &self, Move &move, const Game &game);


    bool move_to(const Wizard &self, const Game &game, Move &move, int x, int y);
    void forward(const Wizard &self, const Game &game, Move &move);
    void back(const Wizard &self, const Game &game, Move &move);


    void make_bigmap(const CircularUnit &unit);
    void make_map(const Wizard &self, const World &world, const Game &game);
    void bad_points(int x, int y, int range);
    void point(int x, int y, int bonus, double procent);


    void to_kill(const Wizard &self);
    void this_to_kill(const Wizard &self, LivingUnit &unit);


    bool bonus(const Wizard &self, const World &world, const Game &game, Move &move);

    void get_units(const Wizard &self, const World &world);

    void shoot(const Wizard &self, Move &move);

    void make_lines();

    bool unit_on_top(const Unit &unit);
    bool unit_on_mid(const Unit &unit);
    bool unit_on_bottom(const Unit &unit);
    bool unit_on_line(const Unit &unit, int choose_line);

    int get_first_minion_on_top();
    int get_first_minion_on_mid();
    int get_first_minion_on_bottom();
    int get_first_minion_on_line(int choose_line);
    int get_first_bad_wizard_on_top(const Wizard &self);
    int get_first_bad_wizard_on_mid(const Wizard &self);
    int get_first_bad_wizard_on_bottom(const Wizard &self);
    int get_first_bad_wizard_on_line(const Wizard& self);

    void in_forest(const Wizard &self);

    void new_level(const Wizard &self, Move &move);

    pair<int, int> near_point(const Wizard &self);

    bool top_half(const Wizard &self);

    mappoint circular_point(const Wizard &self, mappoint goal_point);

    int new_line(const Wizard &self);

    mappoint damage_point(const Wizard &self, const Unit &unit);

    int near_top_point(const Unit &unit);
    int near_mid_point(const Unit &unit);
    int near_bottom_point(const Unit &unit);
    int near_line_point(const Unit &unit);

private:
    bool def;

    const double PI = 3.14159265358979323846;

    const int MAP_SIZE = 401;
    const int CONFLICT = -1000000000;
    const int MAX = 100000;

    //objects range
    const int NEAR_M = 50;

    //objects bonus
    const double BAD = -1.2;
    const int CREEP = 340;

    //bonus
    bool has_bonus[2];
    bool move_to_bonus[2];
    bool unit_in_forest;

    //ticks
    int prev_tick;

    //units
    vector<double> near_units;
    vector<vector<int>> bigmap;
    vector<vector<int>> map;

    vector<Minion> minions;
    vector<Minion> bad_minions;
    vector<Minion> good_minions;
    vector<Minion> neutral_minions;

    vector<Building> buildings;
    vector<Building> bad_buildings;

    vector<Tree> trees;

    vector<Wizard> wizards;
    vector<Wizard> bad_wizards;

    vector<Bonus> bonuses;

    //goal
    LivingUnit* unit_for_kill;

    //line
    int line;
    vector<vector<mappoint>> lines;

    //
    vector<SkillType> skill_to_learn;
};

#endif
