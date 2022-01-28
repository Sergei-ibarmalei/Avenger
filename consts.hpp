#ifndef CONSTS_HPP
#define CONSTS_HPP

const int S_W {800};
const int S_H {600};

enum class object_position {UP, CENTER, DOWN, EMPTY};
 enum class Move_direction {UP, DOWN, LEFT, RIGHT};
const int SHIP_SPEED {5};
const int UPSHIP {0};
const int CENTERSHIP {1};
const int DOWNSHIP {2};

typedef struct 
{
    int x;
    int y;
}plot_type;


// BORDER
const int LEFT_BORDER  {0};
const int RIGHT_BORDER {S_W};
const int UP_BORDER    {0};
const int DOWN_BORDER  {S_H};

#endif
