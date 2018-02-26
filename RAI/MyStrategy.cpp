#include "MyStrategy.h"

#include <cmath>

using namespace model;
using namespace std;

MyStrategy::MyStrategy() {
    has_bonus[0] = false;
    has_bonus[1] = false;
    move_to_bonus[0] = false;
    move_to_bonus[1] = false;
    prev_tick = 0;
    bigmap.resize(400, vector<int>(400));
    line = 0;
    map.resize(size_t(MAP_SIZE), vector<int>(size_t(MAP_SIZE)));
    make_lines();
    skill_to_learn.resize(25);
    skill_to_learn[0] = SKILL_RANGE_BONUS_PASSIVE_1;
    skill_to_learn[1] = SKILL_RANGE_BONUS_AURA_1;
    skill_to_learn[2] = SKILL_RANGE_BONUS_PASSIVE_2;
    skill_to_learn[3] = SKILL_RANGE_BONUS_AURA_2;
    skill_to_learn[4] = SKILL_ADVANCED_MAGIC_MISSILE;
    skill_to_learn[5] = SKILL_MAGICAL_DAMAGE_BONUS_PASSIVE_1;
    skill_to_learn[6] = SKILL_MAGICAL_DAMAGE_BONUS_AURA_1;
    skill_to_learn[7] = SKILL_MAGICAL_DAMAGE_BONUS_PASSIVE_2;
    skill_to_learn[8] = SKILL_MAGICAL_DAMAGE_BONUS_AURA_2;
    skill_to_learn[9] = SKILL_FROST_BOLT;
    skill_to_learn[10] = SKILL_MAGICAL_DAMAGE_ABSORPTION_PASSIVE_1;
    skill_to_learn[11] = SKILL_MAGICAL_DAMAGE_ABSORPTION_AURA_1;
    skill_to_learn[12] = SKILL_MAGICAL_DAMAGE_ABSORPTION_PASSIVE_2;
    skill_to_learn[13] = SKILL_MAGICAL_DAMAGE_ABSORPTION_AURA_2;
    skill_to_learn[14] = SKILL_SHIELD;
    skill_to_learn[15] = SKILL_STAFF_DAMAGE_BONUS_PASSIVE_1;
    skill_to_learn[16] = SKILL_STAFF_DAMAGE_BONUS_AURA_1;
    skill_to_learn[17] = SKILL_STAFF_DAMAGE_BONUS_PASSIVE_2;
    skill_to_learn[18] = SKILL_STAFF_DAMAGE_BONUS_AURA_2;
    skill_to_learn[19] = SKILL_FIREBALL;
    skill_to_learn[20] = SKILL_MOVEMENT_BONUS_FACTOR_PASSIVE_1;
    skill_to_learn[21] = SKILL_MOVEMENT_BONUS_FACTOR_AURA_1;
    skill_to_learn[22] = SKILL_MOVEMENT_BONUS_FACTOR_PASSIVE_2;
    skill_to_learn[23] = SKILL_MOVEMENT_BONUS_FACTOR_AURA_2;
    skill_to_learn[24] = SKILL_HASTE;
}

//go back
void MyStrategy::back(const Wizard &self, const Game &game, Move &move) {
    int x = int(self.getX());
    int y = int(self.getY());
    int best_x = 200;
    int best_y = 200;
    for (int i = 0; i < MAP_SIZE; ++i) {
        for (int j = 0; j < MAP_SIZE; ++j) {
            if ((i * 4 + x - 800) / 10 >= 0 && (i * 4 + x - 800) / 10 < 400 && (j * 4 + y - 800) / 10 >= 0 &&
                (j * 4 + y - 800) / 10 < 400) {
                if (bigmap[(i * 4 + x - 800) / 10][(j * 4 + y - 800) / 10] > 0) {
                    if (map[i][j] > map[best_x][best_y]) {
                        best_x = i;
                        best_y = j;
                    } else if (bigmap[(best_x * 4 + x - 800) / 10][(best_y * 4 + y - 800) / 10] <= 0) {
                        best_x = i;
                        best_y = j;
                    }
                }
            }
        }
    }
    if (bigmap[(best_x * 4 + x - 800) / 10][(best_y * 4 + y - 800) / 10] > 0) {
        move_to(self, game, move, best_x * 4 + x - 800, best_y * 4 + y - 800);
        return;
    } else {
        in_forest(self);
    }
}

//go forward
void MyStrategy::forward(const Wizard &self, const Game &game, Move &move) {
    if (unit_on_line(self, line)) {
        int u = near_line_point(self) + 4;
        if (u > get_first_bad_wizard_on_line(self)) {
            u = get_first_bad_wizard_on_line(self);
            if (u >= 4) {
                u -= 4;
            } else {
                u = 0;
            }
        }
        while (u < lines[line].size()) {
            if (move_to(self, game, move, lines[line][u].x, lines[line][u].y)) {
                return;
            }
            ++u;
        }
        --u;
        while (u > 0) {
            if (move_to(self, game, move, lines[line][u].x, lines[line][u].y)) {
                return;
            }
            --u;
        }
        in_forest(self);
    } else {
        int u = get_first_minion_on_line(line);
        if (u > 50) {
            u = 48;
        }
        while (u >= 0) {
            if (move_to(self, game, move, lines[line][u].x, lines[line][u].y)) {
                break;
            }
            --u;
        }
        if (u == -1) {
            in_forest(self);
        }
    }
}


//main part of my bot's move
bool MyStrategy::move_to(const Wizard &self, const Game &game, Move &move, int x, int y) {
    double angle = 500;
    int X = x / 10;
    int Y = y / 10;
    int min_i = 10;
    int min_j = 10;
    for (int i = -5; i <= 5; ++i) {
        for (int j = -5; j <= 5; ++j) {
            if (X + i >= 0 && X + i < 400 && Y + j >= 0 && Y + j < 400) {
                if (bigmap[X + i][Y + j] > 0) {
                    if (min_i * min_i + min_j * min_j > i * i + j * j) {
                        min_i = i;
                        min_j = j;
                    }
                }
            }
        }
    }
    if (min_i == 10 && min_j == 10) {
        return false;
    }
    X += min_i;
    Y += min_j;
    while (bigmap[X][Y] != 1) {
        if (X > 0 && Y > 0 && bigmap[X - 1][Y - 1] + 3 == bigmap[X][Y] && bigmap[X - 1][Y - 1] > 0 &&
            bigmap[X][Y] >= 4) {
            --X;
            --Y;
            angle = PI / 4;
        } else if (X > 0 && Y < 399 && bigmap[X - 1][Y + 1] + 3 == bigmap[X][Y] && bigmap[X - 1][Y + 1] > 0 &&
                   bigmap[X][Y] >= 4) {
            --X;
            ++Y;
            angle = -PI / 4;
        } else if (X < 399 && Y > 0 && bigmap[X + 1][Y - 1] + 3 == bigmap[X][Y] && bigmap[X + 1][Y - 1] > 0 &&
                   bigmap[X][Y] >= 4) {
            ++X;
            --Y;
            angle = 3 * PI / 4;
        } else if (X < 399 && Y < 399 && bigmap[X + 1][Y + 1] + 3 == bigmap[X][Y] && bigmap[X + 1][Y + 1] > 0 &&
                   bigmap[X][Y] >= 4) {
            ++X;
            ++Y;
            angle = -3 * PI / 4;
        } else if (X > 0 && bigmap[X - 1][Y] + 2 == bigmap[X][Y] && bigmap[X - 1][Y] > 0 && bigmap[X][Y] >= 3) {
            --X;
            angle = 0;
        } else if (Y > 0 && bigmap[X][Y - 1] + 2 == bigmap[X][Y] && bigmap[X][Y - 1] > 0 && bigmap[X][Y] >= 3) {
            --Y;
            angle = PI / 2;
        } else if (X < 399 && bigmap[X + 1][Y] + 2 == bigmap[X][Y] && bigmap[X + 1][Y] > 0 && bigmap[X][Y] >= 3) {
            ++X;
            angle = PI;
        } else if (Y < 399 && bigmap[X][Y + 1] + 2 == bigmap[X][Y] && bigmap[X][Y + 1] > 0 && bigmap[X][Y] >= 3) {
            ++Y;
            angle = -PI / 2;
        } else {
            angle = 500;
            break;
        }
    }
    if (angle > 400) {
        angle = (PI * (rand() % 1000) / 500) - PI;
        vector<int> actions = self.getRemainingCooldownTicksByAction();
        if (actions[1] == 0) {
            move.setAction(ACTION_STAFF);
        } else {
            move.setAction(ACTION_MAGIC_MISSILE);
        }
    }
    angle -= self.getAngle();
    if (angle > PI) {
        angle -= 2 * PI;
    }
    if (angle < -PI) {
        angle += 2 * PI;
    }
    move.setTurn(angle);
    move.setSpeed(game.getWizardForwardSpeed() * cos(angle));
    move.setStrafeSpeed(game.getWizardStrafeSpeed() * sin(angle));
    return true;
}

//main part
void MyStrategy::move(const Wizard &self, const World &world, const Game &game, Move &move) {
    //clean after last move
    def = false;
    for (int i = 0; i < MAP_SIZE; ++i) {
        for (int j = 0; j < MAP_SIZE; ++j) {
            map[i][j] = 0;
        }
    }
    near_units.clear();
    for (int i = 0; i < 400; ++i) {
        for (int j = 0; j < 400; ++j) {
            bigmap[i][j] = 0;
        }
    }
    unit_for_kill = nullptr;

    //main part
    new_level(self, move);
    get_units(self, world);
    to_kill(self);
    line = new_line(self);
    for (int i = 0; i < MAP_SIZE; ++i) {
        for (int j = 0; j < MAP_SIZE; ++j) {
            int real_x = int(self.getX() + 4 * i - 800);
            int real_y = int(self.getY() + 4 * j - 800);
            if (!(real_x > self.getRadius() && real_x < 4000 - self.getRadius() && real_y > self.getRadius() &&
                  real_y < 4000 - self.getRadius())) {
                map[i][j] = CONFLICT;
            }
            if (real_x < 300) {
                map[i][j] -= 300 - real_x;
            }
            if (real_x > 3700) {
                map[i][j] -= real_x - 3700;
            }
            if (real_y < 300) {
                map[i][j] -= 300 - real_y;
            }
            if (real_y > 3700) {
                map[i][j] -= real_y - 3700;
            }
        }
    }
    make_map(self, world, game);
    if (!bonus(self, world, game, move)) {
        if (unit_for_kill != nullptr) {
            just_do(self, move, game);
        } else {
            forward(self, game, move);
        }
    }
    if (unit_for_kill != nullptr) {
        shoot(self, move);
    }
}

//make hitmaps
void MyStrategy::make_map(const Wizard &self, const World &world, const Game &game) {
    //add minions
    for (size_t i = 0; i < minions.size(); ++i) {
        if (minions[i].getFaction() != FACTION_NEUTRAL) {
            int creepX = int(minions[i].getX() - self.getX());
            int creepY = int(minions[i].getY() - self.getY());
            if (abs(creepX) <= 800 && abs(creepY) <= 800) {
                bad_points(creepX, creepY, int(minions[i].getRadius()));
                if (self.getFaction() == minions[i].getFaction()) {
                    point(creepX, creepY, CREEP, double(minions[i].getLife()) / minions[i].getMaxLife());
                } else {
                    point(creepX, creepY, int(BAD * CREEP), double(minions[i].getLife()) / minions[i].getMaxLife());
                }
            }
        }
    }

    //add buildings
    for (size_t i = 0; i < buildings.size(); ++i) {
        int towerX = int(buildings[i].getX() - self.getX());
        int towerY = int(buildings[i].getY() - self.getY());
        if (abs(towerX) <= 800 && abs(towerY) <= 800) {
            bad_points(towerX, towerY, int(buildings[i].getRadius()));
            if (self.getFaction() == buildings[i].getFaction()) {
                point(towerX, towerY, int(buildings[i].getAttackRange() + self.getRadius()),
                      double(buildings[i].getLife()) / buildings[i].getMaxLife());
            } else {
                point(towerX, towerY, int(BAD * (buildings[i].getAttackRange() + self.getRadius())),
                      double(buildings[i].getLife()) / buildings[i].getMaxLife());
            }
        }
    }

    //add trees
    for (size_t i = 0; i < trees.size(); ++i) {
        int treeX = int(trees[i].getX() - self.getX());
        int treeY = int(trees[i].getY() - self.getY());
        if (abs(treeX) <= 800 && abs(treeY) <= 800) {
            bad_points(treeX, treeY, int(trees[i].getRadius()));
        }
    }

    //add wizards
    for (size_t i = 0; i < wizards.size(); ++i) {
        int wizardX = int(wizards[i].getX() - self.getX());
        int wizardY = int(wizards[i].getY() - self.getY());
        if (wizardX != 0 || wizardY != 0) {
            if (abs(wizardX) <= 800 && abs(wizardY) <= 800) {
                bad_points(wizardX, wizardY, int(wizards[i].getRadius()));
                if (self.getFaction() == wizards[i].getFaction()) {
                    point(wizardX, wizardY, int(wizards[i].getCastRange() + self.getRadius() + 10),
                          double(wizards[i].getLife()) / wizards[i].getMaxLife());
                } else {
                    point(wizardX, wizardY, int(BAD * (wizards[i].getCastRange() + self.getRadius() + 10)),
                          double(wizards[i].getLife()) / wizards[i].getMaxLife());
                }
            }
        }
    }

    //update map

    //best way
    for (size_t i = 0; i < minions.size(); ++i) {
        make_bigmap(minions[i]);
    }
    for (size_t i = 0; i < buildings.size(); ++i) {
        make_bigmap(buildings[i]);
    }
    for (size_t i = 0; i < trees.size(); ++i) {
        make_bigmap(trees[i]);
    }
    for (size_t i = 0; i < wizards.size(); ++i) {
        if (!wizards[i].isMe()) {
            make_bigmap(wizards[i]);
        }
    }

    my_set s;
    s.insert(1, mappoint(int(self.getX() / 10), int(self.getY() / 10)));
    bigmap[self.getX() / 10][self.getY() / 10] = 1;
    while (!s.empty()) {
        mappoint this_point = s.begin();
        int x = this_point.x;
        int y = this_point.y;
        if (y > 0 && bigmap[x][y - 1] == 0) {
            bigmap[x][y - 1] = bigmap[x][y] + 2;
            s.insert(bigmap[x][y - 1], mappoint(x, y - 1));
        }
        if (y > 0 && x > 0 && bigmap[x - 1][y - 1] == 0) {
            bigmap[x - 1][y - 1] = bigmap[x][y] + 3;
            s.insert(bigmap[x - 1][y - 1], mappoint(x - 1, y - 1));
        }
        if (x > 0 && bigmap[x - 1][y] == 0) {
            bigmap[x - 1][y] = bigmap[x][y] + 2;
            s.insert(bigmap[x - 1][y], mappoint(x - 1, y));
        }
        if (x > 0 && y < 399 && bigmap[x - 1][y + 1] == 0) {
            bigmap[x - 1][y + 1] = bigmap[x][y] + 3;
            s.insert(bigmap[x - 1][y + 1], mappoint(x - 1, y + 1));
        }
        if (y < 399 && bigmap[x][y + 1] == 0) {
            bigmap[x][y + 1] = bigmap[x][y] + 2;
            s.insert(bigmap[x][y + 1], mappoint(x, y + 1));
        }
        if (x < 399 && y < 399 && bigmap[x + 1][y + 1] == 0) {
            bigmap[x + 1][y + 1] = bigmap[x][y] + 3;
            s.insert(bigmap[x + 1][y + 1], mappoint(x + 1, y + 1));
        }
        if (x < 399 && bigmap[x + 1][y] == 0) {
            bigmap[x + 1][y] = bigmap[x][y] + 2;
            s.insert(bigmap[x + 1][y], mappoint(x + 1, y));
        }
        if (x < 399 && y > 0 && bigmap[x + 1][y - 1] == 0) {
            bigmap[x + 1][y - 1] = bigmap[x][y] + 3;
            s.insert(bigmap[x + 1][y - 1], mappoint(x + 1, y - 1));
        }
    }
}

//for small hitmap
void MyStrategy::bad_points(int x, int y, int range) {
    x += 800;
    y += 800;
    x /= 4;
    y /= 4;
    range /= 4;
    for (int i = -range; i <= range; ++i) {
        for (int j = -range; j <= range; ++j) {
            if (i * i + j * j <= range * range) {
                if (x + i >= 0 && x + i < MAP_SIZE) {
                    if (y + j >= 0 && y + j < MAP_SIZE) {
                        map[x + i][y + j] = CONFLICT;
                    }
                }
            }
        }
    }
}

//for small hitmap
void MyStrategy::point(int x, int y, int bonus, double procent) {
    x += 800;
    y += 800;
    x /= 4;
    y /= 4;
    int min = -abs(bonus) / 4;
    int max = abs(bonus) / 4;
    bonus /= 4;
    while (y + min < 0) {
        ++min;
    }
    while (y + max >= MAP_SIZE) {
        --max;
    }
    for (int i = -abs(bonus); i <= abs(bonus); ++i) {
        if (x + i >= 0 && x + i < MAP_SIZE) {
            for (int j = min; j <= max; ++j) {
                int range = i * i + j * j;
                if (range <= bonus * bonus) {
                    if (map[x + i][y + j] != CONFLICT) {
                        map[x + i][y + j] += bonus * procent;
                    }
                }
            }
        }
    }
}

//find enemies to kill
void MyStrategy::to_kill(const Wizard &self) {
    for (size_t i = 0; i < bad_buildings.size(); ++i) {
        this_to_kill(self, bad_buildings[i]);
    }
    if (unit_for_kill != nullptr && self.getDistanceTo(*unit_for_kill) < 200) {
        return;
    }
    LivingUnit* unit = unit_for_kill;

    for (size_t i = 0; i < bad_wizards.size(); ++i) {
        this_to_kill(self, bad_wizards[i]);
    }
    if (unit_for_kill != nullptr && self.getDistanceTo(*unit_for_kill) < 200) {
        return;
    }
    if (unit == nullptr) {
        unit = unit_for_kill;
    }

    for (size_t i = 0; i < bad_minions.size(); ++i) {
        this_to_kill(self, bad_minions[i]);
    }
    if (unit_for_kill != nullptr && self.getDistanceTo(*unit_for_kill) > 200 && unit != nullptr) {
        unit_for_kill = unit;
    }

    if (unit_for_kill == nullptr && !def) {
        for (size_t i = 0; i < neutral_minions.size(); ++i) {
            this_to_kill(self, neutral_minions[i]);
        }
    }
}

//shoot or go back
void MyStrategy::just_do(const Wizard &self, Move &move, const Game &game) {
    if (self.getLife() < 45) {
        back(self, game, move);
    } else if (map[200][200] >= -100 + 4 * (self.getMaxLife() - self.getLife())) {
        if (unit_for_kill != nullptr && self.getDistanceTo(*unit_for_kill) > self.getCastRange()) {
            move.setSpeed(game.getWizardForwardSpeed());
        } else {
            back(self, game, move);
        }
    } else {
        back(self, game, move);
    }
    shoot(self, move);
}

//it's easy
void MyStrategy::make_bigmap(const CircularUnit &unit) {
    int radius = int(unit.getRadius() + 35);
    int x = int(unit.getX());
    int y = int(unit.getY());
    for (int i = (x - radius) / 10 - 1; i <= (x + radius) / 10 + 1; ++i) {
        if (i >= 0 && i < 400) {
            for (int j = (y - radius) / 10 - 1; j <= (y + radius) / 10 + 1; ++j) {
                if (j >= 0 && j < 400) {
                    if (unit.getDistanceTo(i * 10, j * 10) < radius ||
                        unit.getDistanceTo(i * 10, j * 10 + 10) < radius ||
                        unit.getDistanceTo(i * 10 + 10, j * 10) < radius ||
                        unit.getDistanceTo(i * 10 + 10, j * 10 + 10) < radius) {
                        bigmap[i][j] = -1;
                    }
                }
            }
        }
    }
}

//move to bonus or from bonus ets
bool MyStrategy::bonus(const Wizard &self, const World &world, const Game &game, Move &move) {
    mappoint map_bonus[2]{mappoint(1200, 1200), mappoint(2800, 2800)};
    bool real_bonus[2]{false, false};
    if (world.getTickIndex() - prev_tick > 1000) {
        if (world.getTickIndex() % 2500 < prev_tick % 2500 || move_to_bonus) {
            has_bonus[0] = true;
            has_bonus[1] = true;
        }
        move_to_bonus[0] = false;
        move_to_bonus[1] = false;
    }
    prev_tick = world.getTickIndex();
    if (prev_tick % 2500 < 2200 && prev_tick % 2500 > 0) {
        for (size_t i = 0; i < wizards.size(); ++i) {
            for (size_t j = 0; j < 2; ++j) {
                if (wizards[i].getDistanceTo(map_bonus[j].x, map_bonus[j].y) < 590) {
                    bool bad_bonus = true;
                    for (size_t k = 0; k < bonuses.size(); ++k) {
                        if (bonuses[k].getDistanceTo(map_bonus[j].x, map_bonus[j].y) < 10) {
                            bad_bonus = false;
                            break;
                        }
                    }
                    if (has_bonus[j] && bad_bonus) {
                        has_bonus[j] = false;
                    }
                    if (move_to_bonus[j] && bad_bonus) {
                        move_to_bonus[j] = false;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < bonuses.size(); ++j) {
            if (bonuses[j].getDistanceTo(map_bonus[i].x, map_bonus[i].y) < 10) {
                real_bonus[i] = true;
            }
        }
    }
    if (prev_tick % 2500 == 2200 && prev_tick != 19700) {
        has_bonus[0] = true;
        has_bonus[1] = true;
    }
    pair<int, int> near_point_temp = near_point(self);
    if ((near_point_temp.first != 1 && near_point_temp.second > 38 && near_point_temp.second < 55) ||
        (near_point_temp.first == 1 && near_point_temp.second > 18 && near_point_temp.second < 30)) {
        if (!move_to_bonus[0] && !move_to_bonus[1]) {
            if ((self.getDistanceTo(map_bonus[0].x, map_bonus[0].y) <
                 self.getDistanceTo(map_bonus[1].x, map_bonus[1].y) || !has_bonus[1]) && has_bonus[0] &&
                (top_half(self) || get_first_minion_on_mid() > 20)) {
                move_to_bonus[0] = true;
                has_bonus[0] = false;
            } else if (has_bonus[1] && (!top_half(self) || get_first_minion_on_mid() > 20)) {
                move_to_bonus[1] = true;
                has_bonus[1] = false;
            }
        }
    }
    for (int i = 0; i < 2; ++i) {
        if (move_to_bonus[i]) {
            if (real_bonus[i]) {
                if ((self.getX() - map_bonus[i].x) > 10 || abs(self.getY() - map_bonus[i].y) > 10) {
                    move_to(self, game, move, map_bonus[i].x, map_bonus[i].y);
                    return true;
                } else {
                    move_to_bonus[i] = false;
                }
            } else {
                mappoint move_point = circular_point(self, map_bonus[i]);
                move_to(self, game, move, move_point.x, move_point.y);
                return true;
            }
        }
    }
    return false;
}

//get all visible units
void MyStrategy::get_units(const Wizard &self, const World &world) {
    minions = world.getMinions();
    bad_minions.clear();
    good_minions.clear();
    neutral_minions.clear();
    for (size_t i = 0; i < minions.size(); ++i) {
        if (minions[i].getFaction() != self.getFaction()) {
            if (minions[i].getFaction() == FACTION_NEUTRAL) {
                if (minions[i].getSpeedX() != 0 || minions[i].getSpeedY() != 0 ||
                    minions[i].getRemainingActionCooldownTicks() != 0) {
                    bad_minions.push_back(minions[i]);
                } else {
                    neutral_minions.push_back(minions[i]);
                }
            } else {
                bad_minions.push_back(minions[i]);
            }
        } else {
            good_minions.push_back(minions[i]);
        }
    }

    buildings = world.getBuildings();
    bad_buildings.clear();
    for (size_t i = 0; i < buildings.size(); ++i) {
        if (buildings[i].getFaction() != self.getFaction()) {
            bad_buildings.push_back(buildings[i]);
        }
    }

    trees = world.getTrees();

    wizards = world.getWizards();
    bad_wizards.clear();
    for (size_t i = 0; i < wizards.size(); ++i) {
        if (wizards[i].getFaction() != self.getFaction()) {
            bad_wizards.push_back(wizards[i]);
        }
    }

    bonuses = world.getBonuses();
}

//find enemies for kill
void MyStrategy::this_to_kill(const Wizard &self, LivingUnit &unit) {
    if (self.getDistanceTo(unit) < self.getCastRange() + unit.getRadius() + 10) {
        bool in_forest = false;
        double x1 = self.getX();
        double y1 = self.getY();
        double x2 = unit.getX();
        double y2 = unit.getY();
        double A = y2 - y1;
        double B = x1 - x2;
        double C = x2 * y1 - x1 * y2;
        double C1 = C + 10;
        double C2 = C - 10;
        for (size_t i = 0; i < trees.size(); ++i) {
            double d1 = abs(A * trees[i].getX() + B * trees[i].getY() + C1) / sqrt(A * A + B * B);
            double d2 = abs(A * trees[i].getX() + B * trees[i].getY() + C2) / sqrt(A * A + B * B);
            if ((d1 < trees[i].getRadius() || d2 < trees[i].getRadius()) &&
                self.getDistanceTo(trees[i]) < self.getDistanceTo(unit)) {
                in_forest = true;
            }
        }
        if (unit_for_kill == nullptr) {
            unit_for_kill = &unit;
            unit_in_forest = in_forest;
        } else if (unit_in_forest || !in_forest) {
            if (unit.getLife() < unit_for_kill->getLife()) {
                if (self.getDistanceTo(*unit_for_kill) > 200) {
                    unit_for_kill = &unit;
                    unit_in_forest = in_forest;
                } else if (self.getDistanceTo(unit) < 200) {
                    unit_for_kill = &unit;
                    unit_in_forest = in_forest;
                } else if (unit_for_kill->getLife() == unit.getLife() &&
                           self.getDistanceTo(unit) < self.getDistanceTo(*unit_for_kill)) {
                    unit_for_kill = &unit;
                    unit_in_forest = in_forest;
                }
            } else if (self.getDistanceTo(*unit_for_kill) > 200 && self.getDistanceTo(unit) < 200) {
                unit_for_kill = &unit;
                unit_in_forest = in_forest;
            }
        }
    }
}

//shoot for kill enemies
void MyStrategy::shoot(const Wizard &self, Move &move) {
    if (unit_for_kill != nullptr) {
        bool have_tree = false;
        mappoint shoot_to = damage_point(self, *unit_for_kill);
        double x1 = self.getX();
        double y1 = self.getY();
        double x2 = shoot_to.x;
        double y2 = shoot_to.y;
        double A = y2 - y1;
        double B = x1 - x2;
        double C = x2 * y1 - x1 * y2;
        double C1 = C + 10;
        double C2 = C - 10;
        for (size_t i = 0; i < trees.size(); ++i) {
            double d1 = abs(A * trees[i].getX() + B * trees[i].getY() + C1) / sqrt(A * A + B * B);
            double d2 = abs(A * trees[i].getX() + B * trees[i].getY() + C2) / sqrt(A * A + B * B);
            if ((d1 < trees[i].getRadius() || d2 < trees[i].getRadius()) &&
                self.getDistanceTo(trees[i]) < self.getDistanceTo(x2, y2)) {
                have_tree = true;
            }
        }
        vector<int> actions = self.getRemainingCooldownTicksByAction();
        if (self.getDistanceTo(*unit_for_kill) < 100 && actions[ACTION_STAFF] == 0) {
            move.setAction(ACTION_STAFF);
        } else {
            if (abs(self.getAngleTo(*unit_for_kill)) < 0.10) {
                move.setMinCastDistance(self.getDistanceTo(x2, y2) - 10);
                if (actions[ACTION_FROST_BOLT] == 0 && self.getLevel() >= 10 && self.getMana() >= 36 &&
                    unit_for_kill->getLife() > 12 && !have_tree) {
                    move.setAction(ACTION_FROST_BOLT);
                } else {
                    move.setAction(ACTION_MAGIC_MISSILE);
                }
            }
        }
        move.setCastAngle(self.getAngleTo(x2, y2));
        move.setTurn(self.getAngleTo(x2, y2));
    }
}

//create lines
void MyStrategy::make_lines() {
    lines.resize(3);
    for (int i = 1; i < 39; ++i) {
        lines[0].push_back(mappoint(200, (40 - i) * 100));
        lines[1].push_back(mappoint(i * 100, (40 - i) * 100));
        lines[2].push_back(mappoint(i * 100, 3800));
    }
    for (int i = 3; i < 39; ++i) {
        lines[0].push_back(mappoint(i * 100, 200));
        lines[2].push_back(mappoint(3800, (40 - i) * 100));
    }
}

bool MyStrategy::unit_on_top(const Unit &unit) {
    for (size_t i = 0; i < lines[0].size(); ++i) {
        if (unit.getDistanceTo(lines[0][i].x, lines[0][i].y) < 300) {
            return true;
        }
    }
    return false;
}

int MyStrategy::get_first_minion_on_top() {
    int first_minion = 0;
    for (size_t i = 0; i < good_minions.size(); ++i) {
        if (unit_on_top(good_minions[i])) {
            int u = 0;
            for (size_t j = 1; j < lines[0].size(); ++j) {
                if (good_minions[i].getDistanceTo(lines[0][u].x, lines[0][u].y) >
                    good_minions[i].getDistanceTo(lines[0][j].x, lines[0][j].y)) {
                    u = int(j);
                }
            }
            if (u > first_minion) {
                first_minion = u;
            }
        }
    }
    return first_minion;
}

void MyStrategy::in_forest(const Wizard &self) {
    if (unit_for_kill == nullptr) {
        for (size_t i = 0; i < trees.size(); ++i) {
            if (self.getDistanceTo(trees[i]) < self.getDistanceTo(*unit_for_kill)) {
                unit_for_kill = &trees[i];
            }
        }
    }
}

void MyStrategy::new_level(const Wizard &self, Move &move) {
    vector<SkillType> skills = self.getSkills();
    move.setSkillToLearn(skill_to_learn[skills.size()]);
}

bool MyStrategy::unit_on_mid(const Unit &unit) {
    for (size_t i = 0; i < lines[1].size(); ++i) {
        if (unit.getDistanceTo(lines[1][i].x, lines[1][i].y) < 300) {
            return true;
        }
    }
    return false;
}

int MyStrategy::get_first_minion_on_mid() {
    int first_minion = 0;
    for (size_t i = 0; i < good_minions.size(); ++i) {
        if (unit_on_mid(good_minions[i])) {
            int u = 0;
            for (size_t j = 1; j < lines[1].size(); ++j) {
                if (good_minions[i].getDistanceTo(lines[1][u].x, lines[1][u].y) >
                    good_minions[i].getDistanceTo(lines[1][j].x, lines[1][j].y)) {
                    u = int(j);
                }
            }
            if (u > first_minion) {
                first_minion = u;
            }
        }
    }
    return first_minion;
}

bool MyStrategy::unit_on_bottom(const Unit &unit) {
    for (size_t i = 0; i < lines[2].size(); ++i) {
        if (unit.getDistanceTo(lines[2][i].x, lines[2][i].y) < 300) {
            return true;
        }
    }
    return false;
}

int MyStrategy::get_first_minion_on_bottom() {
    int first_minion = 0;
    for (size_t i = 0; i < good_minions.size(); ++i) {
        if (unit_on_bottom(good_minions[i])) {
            int u = 0;
            for (size_t j = 1; j < lines[2].size(); ++j) {
                if (good_minions[i].getDistanceTo(lines[2][u].x, lines[2][u].y) >
                    good_minions[i].getDistanceTo(lines[2][j].x, lines[2][j].y)) {
                    u = int(j);
                }
            }
            if (u > first_minion) {
                first_minion = u;
            }
        }
    }
    return first_minion;
}

bool MyStrategy::unit_on_line(const Unit &unit, int choose_line) {
    if (choose_line == 0 && unit_on_top(unit)) {
        return true;
    }
    if (choose_line == 1 && unit_on_mid(unit)) {
        return true;
    }
    return (choose_line == 2 && unit_on_bottom(unit));
}

int MyStrategy::get_first_minion_on_line(int choose_line) {
    if (choose_line == 0) {
        return get_first_minion_on_top();
    }
    if (choose_line == 1) {
        return get_first_minion_on_mid();
    }
    return get_first_minion_on_bottom();
}

pair<int, int> MyStrategy::near_point(const Wizard &self) {
    int ii = 0;
    int jj = 0;
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < lines[i].size(); ++j) {
            if (self.getDistanceTo(lines[ii][jj].x, lines[ii][jj].y) >
                self.getDistanceTo(lines[i][j].x, lines[i][j].y)) {
                ii = int(i);
                jj = int(j);
            }
        }
    }
    return pair<int, int>(ii, jj);
}

bool MyStrategy::top_half(const Wizard &self) {
    return self.getX() < 4000 - self.getY();
}

mappoint MyStrategy::circular_point(const Wizard &self, mappoint goal_point) {
    mappoint best_point(goal_point.x + 70, goal_point.y);
    for (int i = 0; i < 360; ++i) {
        int x = int(goal_point.x + 70 * cos((i * PI) / 180));
        int y = int(goal_point.y + 70 * sin((i * PI) / 180));
        if (self.getDistanceTo(x, y) < self.getDistanceTo(best_point.x, best_point.y)) {
            if (x > 0 && x < 4000 && y > 0 && y < 4000) {
                if (bigmap[x / 10][y / 10] > 0) {
                    best_point.x = goal_point.x + int(70 * cos((i * PI) / 180));
                    best_point.y = goal_point.y + int(70 * sin((i * PI) / 180));
                }
            }
        }
    }
    return best_point;
}

int MyStrategy::new_line(const Wizard &self) {
    line = near_point(self).first;
    for (size_t i = 0; i < wizards.size(); ++i) {
        if (wizards[i].getFaction() != self.getFaction()) {
            if (wizards[i].getDistanceTo(400, 3600) < 1500) {
                line = near_point(wizards[i]).first;
                def = true;
            }
        }
    }
    return line;
}

mappoint MyStrategy::damage_point(const Wizard &self, const Unit &unit) {
    int i = 1;
    double x = unit.getX() - self.getX();
    double y = unit.getY() - self.getY();
    while (sqrt(x * x + y * y) / 40 > i) {
        ++i;
        x += unit.getSpeedX();
        y += unit.getSpeedY();
    }
    return mappoint(int(x + self.getX()), int(y + self.getY()));
}

int MyStrategy::get_first_bad_wizard_on_top(const Wizard &self) {
    int first_bad_wizard = int(lines[0].size() - 1);
    for (size_t i = 0; i < wizards.size(); ++i) {
        if (wizards[i].getFaction() != self.getFaction()) {
            if (unit_on_top(wizards[i])) {
                if (near_top_point(wizards[i]) < first_bad_wizard) {
                    first_bad_wizard = near_top_point(wizards[i]);
                }
            }
        }
    }
    return first_bad_wizard;
}

int MyStrategy::near_top_point(const Unit &unit) {
    int u = 0;
    for (int i = 1; i < int(lines[0].size()); ++i) {
        if (unit.getDistanceTo(lines[0][i].x, lines[0][i].y) < unit.getDistanceTo(lines[0][u].x, lines[0][u].y)) {
            u = i;
        }
    }
    return u;
}

int MyStrategy::near_mid_point(const Unit &unit) {
    int u = 0;
    for (int i = 1; i < int(lines[1].size()); ++i) {
        if (unit.getDistanceTo(lines[1][i].x, lines[1][i].y) < unit.getDistanceTo(lines[1][u].x, lines[1][u].y)) {
            u = i;
        }
    }
    return u;
}

int MyStrategy::near_bottom_point(const Unit &unit) {
    int u = 0;
    for (int i = 1; i < int(lines[2].size()); ++i) {
        if (unit.getDistanceTo(lines[2][i].x, lines[2][i].y) < unit.getDistanceTo(lines[2][u].x, lines[2][u].y)) {
            u = i;
        }
    }
    return u;
}

int MyStrategy::get_first_bad_wizard_on_bottom(const Wizard &self) {
    int first_bad_wizard = int(lines[2].size() - 1);
    for (size_t i = 0; i < wizards.size(); ++i) {
        if (wizards[i].getFaction() != self.getFaction()) {
            if (unit_on_bottom(wizards[i])) {
                if (near_bottom_point(wizards[i]) < first_bad_wizard) {
                    first_bad_wizard = near_bottom_point(wizards[i]);
                }
            }
        }
    }
    return first_bad_wizard;
}

int MyStrategy::get_first_bad_wizard_on_mid(const Wizard &self) {
    int first_bad_wizard = int(lines[1].size() - 1);
    for (size_t i = 0; i < wizards.size(); ++i) {
        if (wizards[i].getFaction() != self.getFaction()) {
            if (unit_on_mid(wizards[i])) {
                if (near_mid_point(wizards[i]) < first_bad_wizard) {
                    first_bad_wizard = near_mid_point(wizards[i]);
                }
            }
        }
    }
    return first_bad_wizard;
}

int MyStrategy::get_first_bad_wizard_on_line(const Wizard &self) {
    switch (line) {
        case 0:
            return get_first_bad_wizard_on_top(self);
        case 1:
            return get_first_bad_wizard_on_mid(self);
        default:
            return get_first_bad_wizard_on_bottom(self);
    }
}

int MyStrategy::near_line_point(const Unit &unit) {
    switch(line) {
        case 0:
            return near_top_point(unit);
        case 1:
            return near_mid_point(unit);
        default:
            return near_bottom_point(unit);
    }
}
